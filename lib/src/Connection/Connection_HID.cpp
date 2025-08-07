#include <Graphiti/Connection/Connection_HID.hpp>
#include <iostream>
#include <windows.h>

GraphitiConnectionHID::GraphitiConnectionHID(const uint16_t vendor_id, const uint16_t product_id)
    : vendor_id_(vendor_id), product_id_(product_id), device_(nullptr) {
}

bool GraphitiConnectionHID::open() {
    if (device_) return true; // Already open

    device_ = hid_open(vendor_id_, product_id_, nullptr);
    if (!device_) {
        std::cerr << "Failed to open HID device (VID: 0x" << std::hex << vendor_id_ 
                    << ", PID: 0x" << product_id_ << ")" << std::endl;
        return false;
    }
    
    // Set non-blocking mode (similar to ASIO behavior)
    hid_set_nonblocking(device_, 1);
    return true;
}

void GraphitiConnectionHID::close() {
    if (device_) {
        hid_close(device_);
    }
}

bool GraphitiConnectionHID::write(const std::vector<unsigned char>& data) {
    if (!device_) {
        std::cerr << "Write failed: Device not open" << std::endl;
        return false;
    }

    std::vector<unsigned char> report(data.size() + 1);
    report[0] = 0x02; //Report ID
    std::copy(data.begin(), data.end(), report.begin() + 1);

    int result = hid_write(device_, report.data(), report.size());
    if (result < 0) {
        const wchar_t* error_message = hid_error(device_);
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, error_message, -1, NULL, 0, NULL, NULL);
        std::string error_string(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, error_message, -1, &error_string[0], size_needed, NULL, NULL);
        std::cerr << "Write failed: " << error_string << std::endl;
        return false;
    }
    return true;
}

std::vector<unsigned char> GraphitiConnectionHID::read(size_t size) {
    std::vector<uint8_t> output;

    while (byteBuffer_.size() < size) {
        readToBuffer(); // fills buffer from HID device
        if (byteBuffer_.empty()) break;
    }

    size_t available = std::min(size, byteBuffer_.size());
    for (size_t i = 0; i < available; ++i) {
        output.push_back(byteBuffer_.front());
        byteBuffer_.pop_front();
    }

    return output;
}

void GraphitiConnectionHID::readToBuffer() {
    std::vector<uint8_t> report(64);
    int result = hid_read(device_, report.data(), report.size());
    if (result <= 0) return;

    for (int i = 0; i < result; ++i) {
        byteBuffer_.push_back(report[i]);
    }
}
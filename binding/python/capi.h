#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
  #ifdef BUILDING_GRAPHITI_DLL
    #define GRAPHITI_API __declspec(dllexport)
  #else
    #define GRAPHITI_API __declspec(dllimport)
  #endif
#else
  #define GRAPHITI_API
#endif

typedef struct GraphitiHandle GraphitiHandle;

GRAPHITI_API GraphitiHandle* graphiti_create();
GRAPHITI_API GraphitiHandle* graphiti_createWithConnection(void* connection);
GRAPHITI_API void graphiti_destroy(GraphitiHandle* handle);

GRAPHITI_API void graphiti_setConnection(GraphitiHandle* handle, void* connection);

GRAPHITI_API bool graphiti_startUpVCP(GraphitiHandle* handle, const char* portName, bool keyEventsBool, bool touchEventsBool);

GRAPHITI_API void graphiti_shutDownVCP(GraphitiHandle* handle, bool keyEventsBool, bool touchEventsBool);

GRAPHITI_API int graphiti_index(GraphitiHandle* handle, int row, int col);

GRAPHITI_API void graphiti_setPin(GraphitiHandle* handle, int row, int col, int height);

GRAPHITI_API void graphiti_clearScreen(GraphitiHandle* handle);

GRAPHITI_API void graphiti_sleep(GraphitiHandle* handle, int time);

GRAPHITI_API void graphiti_startResponseThread(GraphitiHandle* handle);
GRAPHITI_API void graphiti_stopResponseThread(GraphitiHandle* handle);

GRAPHITI_API char* graphiti_getNextOutputEvent(GraphitiHandle* handle);
GRAPHITI_API void graphiti_freeString(char* str);

typedef struct {
    uint8_t* data;    // Pointer to event data
    int length;       // Length of data
    bool has_value;   // Whether optional has value
} DisplayStatusEvent_C;

GRAPHITI_API DisplayStatusEvent_C graphiti_getNextDisplayStatusEvent(GraphitiHandle* handle);
GRAPHITI_API void graphiti_freeDisplayStatusEvent(DisplayStatusEvent_C* event);

// ---- Key Event ----
typedef struct {
    char** keys;      // Array of key strings
    int count;        // Number of keys
    bool has_value;   // Whether optional has value
} KeyEvent_C;

GRAPHITI_API KeyEvent_C graphiti_getNextKeyEvent(GraphitiHandle* handle);
GRAPHITI_API void graphiti_freeKeyEvent(KeyEvent_C* event);

GRAPHITI_API char* graphiti_getNextGestureEvent(GraphitiHandle* handle);

// ---- Draw Event ----
typedef struct {
    int rowID;
    int columnID;
    int height;
    int blinkRate;
} PinInfo_C;

typedef struct {
    PinInfo_C* pins;  // Array of pins
    int length;       // Number of pins
    bool has_value;   // Whether optional has value
} DrawEvent_C;

GRAPHITI_API DrawEvent_C graphiti_getNextDrawEvent(GraphitiHandle* handle);
GRAPHITI_API void graphiti_freeDrawEvent(DrawEvent_C* event);

//ACK & NACK
GRAPHITI_API void graphiti_sendACK(GraphitiHandle* handle);
GRAPHITI_API void graphiti_sendNACK(GraphitiHandle* handle);

GRAPHITI_API void graphiti_getSoftwareVersion(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getHardWareVersion(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getSerialNumber(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getBatteryStatus(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getResolutionInformation(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getDeviceOrientation(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getHeightInformation(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getDeviceName(GraphitiHandle* handle);

GRAPHITI_API void graphiti_updateDisplay(GraphitiHandle* handle, const uint8_t* screen_data, int length);
GRAPHITI_API void graphiti_setDisplay(GraphitiHandle* handle);
GRAPHITI_API void graphiti_clearDisplay(GraphitiHandle* handle);
GRAPHITI_API void graphiti_updateSinglePixel(GraphitiHandle* handle, int row, int column, int height, int blinkRate);
GRAPHITI_API void graphiti_updateSingleRow(GraphitiHandle* handle, int row, const uint8_t* rowData, int length);
GRAPHITI_API void graphiti_updateSingleColumn(GraphitiHandle* handle, int column, const uint8_t* columnData, int length);

GRAPHITI_API void graphiti_getAllPixelsPositionStatus(GraphitiHandle* handle);
GRAPHITI_API void graphiti_getSinglePixelPositionStatus(GraphitiHandle* handle, int row, int column);
GRAPHITI_API void graphiti_getSingleRowPixelPositionStatus(GraphitiHandle* handle, uint8_t row);
GRAPHITI_API void graphiti_getSingleColumnPixelPositionStatus(GraphitiHandle* handle, uint8_t column);

GRAPHITI_API void graphiti_showMessage(GraphitiHandle* handle, const char* message, const uint8_t* selectFlags, int flagLength, int blinkRate);
GRAPHITI_API void graphiti_setCursor(GraphitiHandle* handle, int row, int column, int height, int length, int blinkRate);
GRAPHITI_API void graphiti_sendImageInterruptible(GraphitiHandle* handle, const char* name, const char* filepath);
GRAPHITI_API void graphiti_sendImageBlocking(GraphitiHandle* handle, const char* name, const char* filepath);

GRAPHITI_API void graphiti_setKeyEvent(GraphitiHandle* handle, bool enabled);
GRAPHITI_API void graphiti_setTouchEvent(GraphitiHandle* handle, bool enabled);
GRAPHITI_API void graphiti_getLastTouchPointStatus(GraphitiHandle* handle);
GRAPHITI_API void graphiti_vibratorControlCommand(GraphitiHandle* handle, int frequencyRange, int dutyCycle, int duration);
GRAPHITI_API void graphiti_getDateAndTime(GraphitiHandle* handle);
GRAPHITI_API void graphiti_setDateAndTime(GraphitiHandle* handle, int day, int month, int year, int hour, int minute, int second);

#ifdef __cplusplus
}
#endif
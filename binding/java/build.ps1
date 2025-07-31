# build.ps1 - CMake-based build

# Clean previous builds
Remove-Item -Force -Recurse -ErrorAction SilentlyContinue build, *.dll, *.so, *.class

# Generate JNI headers
javac -h . Graphiti.java

# Configure and build
cmake -B build -G "Ninja" `
    -DCMAKE_BUILD_TYPE=Release `
    -DJava_HOME="$env:JAVA_HOME"

cmake --build build

# Optional: Copy results to current directory
Copy-Item -Path build/libGraphitiJNI.* -Destination .
java

- This folder contains everything used for the java binding

- The java binding uses the C++ portion of the library. Due to the nature of reinterpret cast I was required to include all the headers by including Extension.hpp in internalhandle.hpp. This means that this folder cannot funciton without having a folder of all the headers

- Using build.ps1 one can build the java library assuming the Graphiti library has been built on the computer already

- Due to the complexity of the JNI wrapper, Code to run with java must run in the examplej folder or in this folder with compile_run.ps1 or something similar of running javac command followed by a command that runs the java class files with the library. This is because the files of the library must remain in the same directory setup of binding/jgraphiti in order to function due ot JNI function naming

- However, I assume this also means that the binding folder itself or a folder that is called binding can simply hold the jgraphiti folder and this as a whole(with the header files) could be installed under a user. This kind of improvement would be a very helpful script to write so that the library contents can be abstracted away as to not take up space in a developer's working directory

- As a minimum I have made the jgraphiti folder able to be seperate from the working directory folder of examplej

- compile_run.ps1 was use by me before I made runJava.ps1 in the examplej folder to test the java wrapper

Library details
- The Java library does not support the functions setConnection or createWithConnection due to the difficulties of passing the Connection object. This means that connections with the device must be made with startUp where the connection handled internally. Functions like setConnection and createWithConnection could be made that use strings to keep this functionality. But since the connection classes for  Bluetooth is not currently developed, I felt it best to keep things this way for now until a function can be made in Connection that would work for all three connection types (VCP, HID, and Bluetooth). Since this change to Connection would not add any funcitonality without Bluetooth support I do not see it as a high priorty atm.

Using the code
- use .\build.ps1 to build the library
- 
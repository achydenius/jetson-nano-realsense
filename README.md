# Minimal Intel RealSense & NVIDIA Jetson Nano setup

Uses [RealSense SDK](https://github.com/IntelRealSense/librealsense) for accessing RealSense devices, such as D435 depth camera. [Raylib](https://www.raylib.com) setup is also included for creating interactive graphics. Besides Jetson Nano, the development can also be done with MacOS for a bit nicer dev experience.

## MacOS dependency installation:

- Install RealSense SDK with `brew install realsense`
- Install Raylib with `brew install raylib`

## Jetson Nano (JetPack 4.3) dependency installation:

- Install RealSense SDK with instructions [here](https://github.com/IntelRealSense/librealsense/blob/master/doc/installation_jetson.md)
- Build and install Raylib with the CMake instructions [here](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#user-content-build-raylib-using-cmake)
- Update library path with running `echo "/usr/local/lib" | sudo tee -a /etc/ld.so.conf.d/local.conf` and `sudo ldconfig`

## Building and running the example app:

Build with `make` and run with `./main`.

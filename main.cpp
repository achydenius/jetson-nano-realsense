#include <librealsense2/rs.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    rs2::context ctx;
    auto list = ctx.query_devices();
    if (list.size() == 0) {
        throw std::runtime_error("No device detected.");
    }
    
    rs2::device dev = list.front();
    std::cout << "Device found: " << dev.get_info(RS2_CAMERA_INFO_NAME) << std::endl;

    return 0;
}

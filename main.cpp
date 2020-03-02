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

    rs2::pipeline pipe(ctx);
    rs2::config config;
    config.enable_stream(RS2_STREAM_DEPTH, 0, 848, 480, RS2_FORMAT_Z16, 30);
    pipe.start(config);

    while (true) {
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::depth_frame depth = frames.get_depth_frame();

        float width = depth.get_width();
        float height = depth.get_height();
        float dist = depth.get_distance(width / 2, height / 2);

        std::cout << "The camera is facing an object " << dist << " meters away" << std::endl;
    }

    pipe.stop();

    return EXIT_SUCCESS;
}

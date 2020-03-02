#include <librealsense2/rs.hpp>
#include <iostream>

class Sensor {
    const int width;
    const int height;
    const int fps;
    rs2::context context;
    rs2::device device;
    rs2::pipeline pipe;
    float scale;

public:
    struct Frame {
        const uint16_t* data;
        int width;
        int height;
    };

    Sensor(int width, int height, int fps = 30) : width(width), height(height), fps(fps) {
        rs2::device_list list = context.query_devices();
        if (list.size() == 0) {
            throw std::runtime_error("No device detected.");
        }
        device = list.front();
        std::cout << "Device found: " << device.get_info(RS2_CAMERA_INFO_NAME) << std::endl;

        scale = getDepthScale();

        rs2::config config;
        config.enable_stream(RS2_STREAM_DEPTH, 0, width, height, RS2_FORMAT_Z16, fps);
        pipe.start(config);
        std::cout << "Stream started." << std::endl;
    }

    ~Sensor() {
        pipe.stop();
    }

    float getScale() {
        return scale;
    }

    Frame getFrame() {
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::depth_frame depth = frames.get_depth_frame();
        return {
            reinterpret_cast<const uint16_t*>(depth.get_data()),
            depth.get_width(),
            depth.get_height()
        };
    }

private:
    float getDepthScale() {
        for (rs2::sensor& sensor : device.query_sensors()) {
            // Check if the sensor if a depth sensor
            if (rs2::depth_sensor depth = sensor.as<rs2::depth_sensor>()) {
                return depth.get_depth_scale();
            }
        }
        throw std::runtime_error("Device does not have a depth sensor.");
    }
};

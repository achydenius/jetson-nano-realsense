#include <raylib.h>
#include "Sensor.h"

int main(int argc, char* argv[]) {
    Sensor sensor(424, 240);

    InitWindow(640, 480, "jetson-nano-realsense");

    while (!WindowShouldClose()) {
        Sensor::Frame frame = sensor.getFrame();
        float scale = frame.data[(frame.height / 2 * frame.width) + (frame.width / 2)] * sensor.getScale();
        if (scale < 0.1) {
            scale = 0.1;
        }
        if (scale > 1.0) {
            scale = 1.0;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(320, 240, scale * 200, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}

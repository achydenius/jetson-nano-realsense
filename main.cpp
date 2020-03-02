#include <iostream>
#include <GLFW/glfw3.h>
#include "Sensor.h"

int main(int argc, char* argv[]) {
    Sensor sensor;

    if (!glfwInit()) {
        throw std::runtime_error("GLFW could not be initialized.");
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "jetson-nano-realsense", 0, 0);
    if (!window) {
        throw std::runtime_error("GLFW window could not be opened.");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        Sensor::Frame frame = sensor.getFrame();
        float scale = frame.data[(frame.height / 2 * frame.width) + (frame.width / 2)] * sensor.getScale();

        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
	
        glScalef(scale, scale, scale);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(0.5, -0.5);
            glVertex2f(-0.5, -0.5);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}

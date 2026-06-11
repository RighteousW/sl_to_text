#include "window.h"

#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>

static void draw_texture(GLFWwindow* window, unsigned int texture) {
    int width = 0;
    int height = 0;
    glfwGetFramebufferSize(window, &width, &height);

    const float image_width = width * 0.7f;
    const float image_height = height * 0.7f;

    const float left = -1.0f;
    const float top = 1.0f;
    const float right = -1.0f + (image_width / width) * 2.0f;
    const float bottom = 1.0f - (image_height / height) * 2.0f;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f); glVertex2f(left,  top);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(right, top);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(right, bottom);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(left,  bottom);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

int run_window() {
    if (!glfwInit()) {
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "SL to Text", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    unsigned int texture = 0;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    cv::Mat frame;
    cv::Mat rgb;

    while (!glfwWindowShouldClose(window)) {
        camera >> frame;

        if (frame.empty()) {
            break;
        }

        cv::cvtColor(frame, rgb, cv::COLOR_BGR2RGB);

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            rgb.cols,
            rgb.rows,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            rgb.data
        );

        draw_texture(window, texture);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }

    glDeleteTextures(1, &texture);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

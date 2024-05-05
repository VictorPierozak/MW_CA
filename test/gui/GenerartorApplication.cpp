#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>
#include <nanogui/formhelper.h>
#include"gui.hpp"

using namespace nanogui;

// Function to handle window closing event
static void windowCloseCallback(GLFWwindow* window) {
  Screen* screen = static_cast<Screen*>(glfwGetWindowUserPointer(window));
  screen->set_visible(false);
}

int main(int argc, char** argv) {
  // Initialize GLFW
  nanogui::init();
  GeneratorApplication gen(500, 500, "Generator");

  gen.set_visible(true);
  gen.perform_layout();
  nanogui::mainloop();
  nanogui::shutdown();
  return 0;
}

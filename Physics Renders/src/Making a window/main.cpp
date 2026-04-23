#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

int main()
{
    
    glfwInit();     // Initialise glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);      //Configure glfw to a certain major version (3.x)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);      //Configure glfw to a certain minor version (x.3)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){   //Checks if GLAD is configured
        cout << "Failed to init GLAD" << endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(2560,1440, "LearnOpenGL", NULL, NULL); // Creates a window at 1440p

    if (window == NULL){    // Checks if window has appeared
        cout << "Failed to create window" << endl;
        glfwTerminate();
        return -1;
    }

    return 0;
}
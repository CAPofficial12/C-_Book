#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

void frame_resize(GLFWwindow* window, int width, int height){
    glViewport(0,0,width, height);
}


int input(GLFWwindow *window, int value){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS){
        value += 0.1;
    } else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
        value -= 0.1;
    }

    return value;
}


int main()
{
    double red = 1.0f;

    glfwInit();                                                                // Initialise glfw

    if(!glfwInit()){                                                           //Check if GLFW was Initialised
        cout << "GLFW not Init";
        glfwTerminate();
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                             //Configure glfw to a certain major version (3.x)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                             //Configure glfw to a certain minor version (x.3)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800,800, "LearnOpenGL", NULL, NULL); // Creates a window at 1440p
    if (!window){                                                              // Checks if window has appeared
        cout << "Failed to create window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){                   //Checks if GLAD is configured
        cout << "Failed to init GLAD" << endl;
        glfwTerminate();
        return -1;
    }


    glViewport(0,0,800,600);                                                    //Sets location of bottom left corner and size of the window
    glfwSetFramebufferSizeCallback(window, frame_resize);                       //Executes Resize

    while (!glfwWindowShouldClose(window)){                                     // Checks whether the cross has been clicked
        
        red = input(window, red);

        glClearColor(0.3f, 0.2f, red, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);                                                //switchs the pixel colours each frame
        glfwPollEvents();                                                       //checks if any interrupts have occured
    }

    glfwTerminate();
    return 0;
}
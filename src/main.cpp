#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
float changeColor(GLFWwindow *window, char color, float ogColor);
float clearColor(GLFWwindow* window, float ogColor);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 700, "Triangle", NULL, NULL);

    if(window == NULL){
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Error initialize GLAD\n";
        glfwTerminate();
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    glViewport(0, 0, 800, 800);

    float r{0.f}, g{0.f}, b{0.f};

    while(!glfwWindowShouldClose(window)){
        
        processInput(window);

        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Modify color
        r += changeColor(window, 'r', r);
        g += changeColor(window, 'g', b);
        b += changeColor(window, 'b', b);

        // Clear board when we press SPACE
        r = clearColor(window, r);
        g = clearColor(window, g);
        b = clearColor(window, b);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (r >= 0.9f)
            r = 0.f;
        if (g >= 0.9f)
            g = 0.f;
        if (b >= 0.9f)
            b = 0.f;
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

float changeColor(GLFWwindow *window, char color, float ogColor)
{   
    switch(color){
        case 'r':
            if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS){
                return 0.01f;
            }
            break;
        case 'g':
            if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
            {
                return 0.01f;
            }
            break;
        case 'b':
            if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
            {
                return 0.01f;
            }
            break;

        default:
            break;
    }
    return 0.f;
}

float clearColor(GLFWwindow *window, float ogColor)
{
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        return 0.0f;
    }
    else{
        return ogColor;
    }
}

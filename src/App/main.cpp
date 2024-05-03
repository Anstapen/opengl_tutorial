#include "main.h"


#include <iostream>


#include "glad/glad.h"
#include "GLFW/glfw3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);


static float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n";

static unsigned int VBO;
static unsigned int simple_vertex_shader;
static unsigned int simple_fragment_shader;
static unsigned int simple_shader_program;


int main(int, char**)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create the window */
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if(!window)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD!" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Create a Vertex Buffer */
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    /* Copy our vertices into the Vertex Buffer */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Create the Shader Object */
    simple_vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    /* Set the source code of the shader */
    glShaderSource(simple_vertex_shader, 1, &vertexShaderSource, NULL);

    /* Compile it */
    glCompileShader(simple_vertex_shader);

    /* Check if the compilation was successful */
    int return_val;
    glGetShaderiv(simple_vertex_shader, GL_COMPILE_STATUS, &return_val);

    if(!return_val)
    {
        char log[512];
        glGetShaderInfoLog(simple_vertex_shader, 512, NULL, log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << log << std::endl;
    }

    simple_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(simple_fragment_shader, 1, &fragmentShaderSource, NULL);

    glCompileShader(simple_fragment_shader);

    /* Check if the compilation was successful */
    glGetShaderiv(simple_fragment_shader, GL_COMPILE_STATUS, &return_val);

    if(!return_val)
    {
        char log[512];
        glGetShaderInfoLog(simple_vertex_shader, 512, NULL, log);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << log << std::endl;
    }

    simple_shader_program = glCreateProgram();

    glAttachShader(simple_shader_program, simple_vertex_shader);
    glAttachShader(simple_shader_program, simple_fragment_shader);
    glLinkProgram(simple_shader_program);

    glGetProgramiv(simple_shader_program, GL_COMPILE_STATUS, &return_val);

    if(!return_val)
    {
        char log[512];
        glGetProgramInfoLog(simple_shader_program, 512, NULL, log);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << log << std::endl;
    }

    glUseProgram(simple_shader_program);


    /* Endless rendering loop */

    while(!glfwWindowShouldClose(window))
    {
        /* Clear the screen */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        /* Input */
        processInput(window);

        /* Rendering */

        /* Event Handling */
        glfwSwapBuffers(window);

        /* Buffer Swap*/
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
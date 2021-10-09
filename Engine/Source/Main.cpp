#include "PCH.h"

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

int main()
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "OpenGL", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    const GLubyte *glVersion = glGetString(GL_VERSION);
    std::cout << glVersion << "\n";

    float vertices[] = {
             -0.5f, -0.5f,
              0.5f, -0.5f,
              0.5f, -0.5f,
             -0.5f,  0.5f
    };

    unsigned int indices[] = {           // note that we start from 0!
            0, 1, 3,                    // first Triangle
            1, 2, 3                     // second Triangle
    };

    //Vertex Array Object
    //VertexArray VAO;

    unsigned int vao;
    glad_glGenVertexArrays(1, &vao);
    glad_glBindVertexArray(vao);

    //Vertex Buffer Object
    VertexBuffer VBO(vertices, 4 * 2 *(sizeof(float)));
    glad_glEnableVertexAttribArray(0);
    glad_glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);

    //Index Buffer Object
    IndexBuffer IBO(indices, 6);

    Shader shader("Resources/Shaders/VertexShader.shader", "Resources/Shaders/FragmentShader.shader");
   shader.SetUniform4f("u_Color", 1.0f, 2.0f, 0.0f, 3.0f);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glad_glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
#include "PCH.h"

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Macro.h"

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
              0.5f,  0.5f,
             -0.5f,  0.5f
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    //Vertex Array Object
    //VertexArray VAO;

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //Vertex Buffer Object
    VertexBuffer VBO(vertices, 4 * 2 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);

    //Index Buffer Object
    IndexBuffer IBO(indices, 6);

    Shader shader("Resources/Shaders/VertexShader", "Resources/Shaders/FragmentShader");
    shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0.0f, 0.0f);
    shader.Bind();

    glDeleteProgram(vao);
    VBO.unBind();
    IBO.unBind()
;
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        glUseProgram(vao);

        IBO.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
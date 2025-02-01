#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

typedef unsigned int u_int;

u_int width = 800, height = 800;

float verts[] = 
{
    // POSITION             //COLORS    
     0.5,   0.5,  0.0,  //WHITE
     0.5,  -0.5,  0.0,  //RED
    -0.5,  -0.5,  0.0,  //GREEN
    -0.5,   0.5,  0.0,  //BLUE
};

u_int idxs[] = 
{
    0, 1, 2,
    2, 3, 0,
};

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, " ", nullptr, nullptr);
    if(window == NULL)
    {
        std::cout << "WINDOW CREATION FAILED" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));

    u_int vao, vbo, ibo;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idxs), idxs, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    while(!(glfwWindowShouldClose(window)))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2, 0.1, 0.3, 1.0);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, sizeof(idxs)/sizeof(u_int), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
    glfwDestroyWindow(window);
    glfwTerminate();

}
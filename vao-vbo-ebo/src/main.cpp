#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

typedef unsigned int u_int;

u_int width = 800, height = 800;

int main()
{
    if(glfwInit()){std::cout << "Hello World" << std::endl;}
}
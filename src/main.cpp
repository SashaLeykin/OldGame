#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, "ru");
    //������ GLFWwindow ������������� ��� ����, ��� � ��������. ��� ��������� � ������� 
    //glfwCreateWindow � ������������ � ������� glfwDestroyWindow.
    GLFWwindow* window;

    /* Initialize the library ���������������� ���������� */
    //��� ������� �������������� ���������� GLFW. ������ ��� ����� ����� ������������
    //����������� ������� GLFW, GLFW ������ ���� ���������������, � ����� ����������� ������ 
    //���������� GLFW ������ ���� ��������, ����� ���������� ����� �������,     ���������� �� ����� 
    //��� ����� �������������.
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context
    ��������  ���� �������� ������ � ��� �������� OpenGL
    glfwCreateWindow - glfw ������� ����*/
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        //glfwTerminate - glfw ���������, ��������� ������ ���������� GLFW.
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current ������� �������� ���� �������
    glfwMakeContextCurrent - glfw ������� �������� �������*/
    glfwMakeContextCurrent(window);

    //������������� glad
    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD! �� ���� ��������� GLAD!" << std::endl;
        return -1;
    }
    //������� �� ����� ������� ������ OpenGL
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

    //��������� ����� ���� ������� glClearColor ������ ������ �������� ��� �������� �������.
    glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window ����, ���� ������������ �� ������� ����
    glfwWindowShouldClose - ���� glfw ������ ���������*/
    while (!glfwWindowShouldClose(window))
    {
        /* Render here ������ ����� glClear ������������� ������� ������� ��������� ���� 
        �� ��������, ����� ��������� � ������� glClearColor, glClearDepth � glClearStencil.*/
       glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers �������� ������� �������� � ������ ������*/
        glfwSwapBuffers(window);

        /* Poll for and process events ����� � ��������� �������*/
        //������� glfwPollEvents ���������, ������������ �� �����-���� ������� 
        //(��������, ������� ����� � ���������� ��� �������� ����), 
        //��������� ��������� ���� � �������� �������
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
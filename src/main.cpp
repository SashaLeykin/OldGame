#include <GLFW/glfw3.h>

int main(void)
{
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

    /* Loop until the user closes the window ����, ���� ������������ �� ������� ����
    glfwWindowShouldClose - ���� glfw ������ ���������*/
    while (!glfwWindowShouldClose(window))
    {
        /* Render here ������ �����*/
       //glClear(GL_COLOR_BUFFER_BIT);

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
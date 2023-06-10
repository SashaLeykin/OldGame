#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

//���������� ���������� ��� ������� ����
int g_windowSizeX = 640;
int g_windowSizeY = 480;

//������� ��� ��������� ������� ����
void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    //������� glViewport ������������� ������� ���������, ������ ����� ���� �������������� 
    //������� ��������� � ��������.
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

//������� ��� ������� �������
void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    setlocale(LC_ALL, "ru");    

    /* Initialize the library ���������������� ���������� */
    //��� ������� �������������� ���������� GLFW. ������ ��� ����� ����� ������������
    //����������� ������� GLFW, GLFW ������ ���� ���������������, � ����� ����������� ������ 
    //���������� GLFW ������ ���� ��������, ����� ���������� ����� �������,     ���������� �� ����� 
    //��� ����� �������������.
    if (!glfwInit())
    {
        std::cout << "glfwInit failed! glfw ������ �������������!" << std::endl;
        return -1;
    }

    //����� ��� �������� ��������� OpenGL(������� ������ openGL 4.6)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            
    //������ GLFWwindow ������������� ��� ����, ��� � ��������. ��� ��������� � ������� 
    //glfwCreateWindow � ������������ � ������� glfwDestroyWindow.
    GLFWwindow* pWindow;
    /* Create a windowed mode window and its OpenGL context
    ��������  ���� �������� ������ � ��� �������� OpenGL
    glfwCreateWindow - glfw ������� ����*/
    pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Old Game", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed! glfw ������� ���� �� �������!" << std::endl;
        //glfwTerminate - glfw ���������, ��������� ������ ���������� GLFW.
        glfwTerminate();
        return -1;
    }

    //����������� ������� ��� ��������� ������� ���� � ������� �������
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current ������� �������� ���� �������
    glfwMakeContextCurrent - glfw ������� �������� �������*/
    glfwMakeContextCurrent(pWindow);

    //������������� glad
    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD! �� ���� ��������� GLAD!" << std::endl;
        return -1;
    }
    //������� �� ����� ������� ������ OpenGL   
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    //��������� ����� ���� ������� glClearColor ������ ������ �������� ��� �������� �������.
    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the window ����, ���� ������������ �� ������� ����
    glfwWindowShouldClose - ���� glfw ������ ���������*/
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here ������ ����� glClear ������������� ������� ������� ��������� ���� 
        �� ��������, ����� ��������� � ������� glClearColor, glClearDepth � glClearStencil.*/
       glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers �������� ������� �������� � ������ ������*/
        glfwSwapBuffers(pWindow);

        /* Poll for and process events ����� � ��������� �������*/
        //������� glfwPollEvents ���������, ������������ �� �����-���� ������� 
        //(��������, ������� ����� � ���������� ��� �������� ����), 
        //��������� ��������� ���� � �������� �������
        glfwPollEvents();
    }
    //glfwTerminate - glfw ���������, ��������� ������ ���������� GLFW. ����������� �������
    glfwTerminate();
    return 0;
}
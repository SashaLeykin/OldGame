#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

//Глобальные переменные для размера окна
int g_windowSizeX = 640;
int g_windowSizeY = 480;

//функция для изменения размера окна
void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    //Функция glViewport устанавливает область просмотра, Нижний левый угол прямоугольника 
    //области просмотра в пикселях.
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

//функция для нажатия клавишь
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

    /* Initialize the library Инициализировать библиотеку */
    //Эта функция инициализирует библиотеку GLFW. Прежде чем можно будет использовать
    //большинство функций GLFW, GLFW должен быть инициализирован, а перед завершением работы 
    //приложения GLFW должен быть завершен, чтобы освободить любые ресурсы,     выделенные во время 
    //или после инициализации.
    if (!glfwInit())
    {
        std::cout << "glfwInit failed! glfw Ошибка инициализации!" << std::endl;
        return -1;
    }

    //опции для создания контекста OpenGL(указана версия openGL 4.6)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            
    //Объект GLFWwindow инкапсулирует как окно, так и контекст. Они создаются с помощью 
    //glfwCreateWindow и уничтожаются с помощью glfwDestroyWindow.
    GLFWwindow* pWindow;
    /* Create a windowed mode window and its OpenGL context
    Создание  окна оконного режима и его контекст OpenGL
    glfwCreateWindow - glfw Создать окно*/
    pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Old Game", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed! glfw Создать окно не удалось!" << std::endl;
        //glfwTerminate - glfw Завершить, Завершает работу библиотеки GLFW.
        glfwTerminate();
        return -1;
    }

    //регистрация функций для изменения размера окна и нажатии клавиши
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current Сделать контекст окна текущим
    glfwMakeContextCurrent - glfw Сделать контекст текущим*/
    glfwMakeContextCurrent(pWindow);

    //инициализация glad
    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD! Не могу загрузить GLAD!" << std::endl;
        return -1;
    }
    //выводим на экран консоли версию OpenGL   
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    //изменение цвета окна Функция glClearColor задает четкие значения для цветовых буферов.
    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the window Цикл, пока пользователь не закроет окно
    glfwWindowShouldClose - Окно glfw должно закрыться*/
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here Рендер здесь glClear устанавливает область битовой плоскости окна 
        на значения, ранее выбранные с помощью glClearColor, glClearDepth и glClearStencil.*/
       glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers Поменять местами передний и задний буфера*/
        glfwSwapBuffers(pWindow);

        /* Poll for and process events Опрос и обработка событий*/
        //Функция glfwPollEvents проверяет, инициированы ли какие-либо события 
        //(например, события ввода с клавиатуры или движения мыши), 
        //обновляет состояние окна и вызывает функцию
        glfwPollEvents();
    }
    //glfwTerminate - glfw Завершить, Завершает работу библиотеки GLFW. Освобождаем ресурсы
    glfwTerminate();
    return 0;
}
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, "ru");
    //Объект GLFWwindow инкапсулирует как окно, так и контекст. Они создаются с помощью 
    //glfwCreateWindow и уничтожаются с помощью glfwDestroyWindow.
    GLFWwindow* window;

    /* Initialize the library Инициализировать библиотеку */
    //Эта функция инициализирует библиотеку GLFW. Прежде чем можно будет использовать
    //большинство функций GLFW, GLFW должен быть инициализирован, а перед завершением работы 
    //приложения GLFW должен быть завершен, чтобы освободить любые ресурсы,     выделенные во время 
    //или после инициализации.
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context
    Создание  окна оконного режима и его контекст OpenGL
    glfwCreateWindow - glfw Создать окно*/
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        //glfwTerminate - glfw Завершить, Завершает работу библиотеки GLFW.
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current Сделать контекст окна текущим
    glfwMakeContextCurrent - glfw Сделать контекст текущим*/
    glfwMakeContextCurrent(window);

    //инициализация glad
    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD! Не могу загрузить GLAD!" << std::endl;
        return -1;
    }
    //выводим на экран консоли версию OpenGL
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

    //изменение цвета окна Функция glClearColor задает четкие значения для цветовых буферов.
    glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window Цикл, пока пользователь не закроет окно
    glfwWindowShouldClose - Окно glfw должно закрыться*/
    while (!glfwWindowShouldClose(window))
    {
        /* Render here Рендер здесь glClear устанавливает область битовой плоскости окна 
        на значения, ранее выбранные с помощью glClearColor, glClearDepth и glClearStencil.*/
       glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers Поменять местами передний и задний буфера*/
        glfwSwapBuffers(window);

        /* Poll for and process events Опрос и обработка событий*/
        //Функция glfwPollEvents проверяет, инициированы ли какие-либо события 
        //(например, события ввода с клавиатуры или движения мыши), 
        //обновляет состояние окна и вызывает функцию
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
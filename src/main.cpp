#include <GLFW/glfw3.h>

int main(void)
{
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

    /* Loop until the user closes the window Цикл, пока пользователь не закроет окно
    glfwWindowShouldClose - Окно glfw должно закрыться*/
    while (!glfwWindowShouldClose(window))
    {
        /* Render here Рендер здесь*/
       //glClear(GL_COLOR_BUFFER_BIT);

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
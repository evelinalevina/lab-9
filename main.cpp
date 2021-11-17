#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Лабораторная работа 9");
    sf::CircleShape shape1(100.f);
    shape1.setFillColor(sf::Color::Green);
    int shape1_x = 0, shape1_y = 0;
    shape1.setPosition(shape1_x, shape1_y);

    sf::CircleShape shape2(50.0);
    shape2.setFillColor(sf::Color::Red);
    int shape2_x = 0, shape2_y = 225;
    shape2.setPosition(shape2_x, shape2_y);

    sf::CircleShape shape3(120.0);
    shape3.setFillColor(sf::Color::Yellow);
    int shape3_x = 0, shape3_y = 350;
    shape3.setPosition(shape3_x, shape3_y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape1_x++;
        if (shape1_x > 600)
            shape1_x = 600;
       
        shape1.setPosition(shape1_x, shape1_y);
        shape2_x++;
        if (shape2_x > 700)
            shape2_x = 700;
        
        shape2.setPosition(shape2_x, shape2_y);
        shape3_x++;
        if (shape3_x > 560)
            shape3_x = 560;
        
        shape3.setPosition(shape3_x, shape3_y);

        // Очистить окно от всего
        window.clear();

        // Перемещение фигуры в буфер
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);

        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(1ms);
    }

    return 0;


}
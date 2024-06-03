#include <SFML/Graphics.hpp> // Подключаем заголовочный файл для работы с графикой
#include <SFML/Main.hpp> // Подключаем заголовочный файл для основной функциональности SFML
#include <SFML/Window.hpp> // Подключаем заголовочный файл для работы с окнами
#include <SFML/System.hpp> // Подключаем заголовочный файл для системных функций
#include <iostream> // Подключаем заголовочный файл для ввода-вывода

// Абстрактный базовый класс Shape, содержащий чисто виртуальную функцию draw
class Shape {
public:
    virtual void draw(sf::RenderWindow& window) = 0; // Чисто виртуальная функция для рисования фигуры
};

// Класс Triangle, наследующий класс Shape
class Triangle : public Shape {
public:
    void draw(sf::RenderWindow& window) override { // Переопределение функции draw для треугольника
        sf::ConvexShape triangle; // Создаем объект ConvexShape для треугольника
        triangle.setPointCount(3); // Устанавливаем количество вершин (3 для треугольника)
        triangle.setPoint(0, sf::Vector2f(100, 100)); // Устанавливаем первую вершину
        triangle.setPoint(1, sf::Vector2f(200, 100)); // Устанавливаем вторую вершину
        triangle.setPoint(2, sf::Vector2f(150, 50)); // Устанавливаем третью вершину
        triangle.setFillColor(sf::Color::White); // Задаем цвет заливки (белый)
        window.draw(triangle); // Рисуем треугольник в окне
    }
};

// Класс Rectangle, наследующий класс Shape
class Rectangle : public Shape {
public:
    void draw(sf::RenderWindow& window) override { // Переопределение функции draw для прямоугольника
        sf::RectangleShape rectangle(sf::Vector2f(120, 80)); // Создаем объект RectangleShape с размерами 120x80
        rectangle.setPosition(100, 200); // Устанавливаем позицию прямоугольника
        rectangle.setFillColor(sf::Color::yellow); // Задаем цвет заливки (желтый)
        window.draw(rectangle); // Рисуем прямоугольник в окне
    }
};

// Класс Circle, наследующий класс Shape
class Circle : public Shape {
public:
    void draw(sf::RenderWindow& window) override { // Переопределение функции draw для круга
        sf::CircleShape circle(96); // Создаем объект CircleShape с радиусом 96
        circle.setPosition(300, 300); // Устанавливаем позицию круга
        circle.setFillColor(sf::Color::violet); // Задаем цвет заливки (фиолетовый)
        window.draw(circle); // Рисуем круг в окне
    }
};

int main() {
    // Создаем окно размером 600x600 пикселей с заголовком "Inheritance and Graphics"
    sf::RenderWindow window(sf::VideoMode(600, 600), "Inheritance and Graphics");

    // Создаем объекты фигур
    Triangle triangle;
    Rectangle rectangle;
    Circle circle;

    // Главный цикл приложения, который продолжается, пока окно открыто
    while (window.isOpen()) {
        sf::Event event; // Создаем объект для обработки событий
        while (window.pollEvent(event)) { // Проверяем все события, произошедшие с окном
            if (event.type == sf::Event::Closed) // Если событие - закрытие окна
                window.close(); // Закрываем окно
        }

        window.clear(); // Очищаем окно перед рисованием
        triangle.draw(window); // Рисуем треугольник
        rectangle.draw(window); // Рисуем прямоугольник
        circle.draw(window); // Рисуем круг
        window.display(); // Отображаем содержимое окна на экране
    }

    return 0; // Завершаем программу
}
#include <SFML/Graphics.hpp>

//Задание 12
//Разработать при помощи библиотеки SFML минимальную программу, которая будет позволять:
//Запускать изменение фигуры на экраен по нажатию одной клавиши и останавливать по другой

//Вариант 4
//Изменяем горизонтальный размер прямоугольника

int x = 50;
int y = 50;
bool t = false;

int main() {
	RenderWindow window(VideoMode(800, 600), "rectangle");
	window.clear(Color::White);

	RectangleShape rectangle(Vector2f(x , y));
	rectangle.setFillColor(Color::Black);
	rectangle.move(150, 150);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();


			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::D) t = true;
				if (event.key.code == Keyboard::A) t = false;
			}
		}


		if (t)
			rectangle.scale(1.0002, 1);
		window.draw(rectangle);
		sleep(milliseconds(10));

		window.display();
	}
}

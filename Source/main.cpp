#include <iostream>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"
#include "imgui-SFML.h"
#include "imgui.h"

void UpdateBackgroundColor(sf::Color &backgroundColor, const sf::Time &deltaTime)
{
	
	float colorChangeSpeed = 70.0f;

	
	backgroundColor.r =
		static_cast<sf::Uint8>(std::min(255.f, backgroundColor.r + colorChangeSpeed * deltaTime.asSeconds()));
	backgroundColor.g =
		static_cast<sf::Uint8>(std::min(255.f, backgroundColor.g + colorChangeSpeed * deltaTime.asSeconds()));
	backgroundColor.b =
		static_cast<sf::Uint8>(std::min(255.f, backgroundColor.b + colorChangeSpeed * deltaTime.asSeconds()));
	std::cout << "R: " << static_cast<int>(backgroundColor.r) << " G: " << static_cast<int>(backgroundColor.g)
			  << " B: " << static_cast<int>(backgroundColor.b) << std::endl;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "changing the background");
	window.setFramerateLimit(60);
	if (!ImGui::SFML::Init(window))
	{
		std::cout << "ImGui initialization failed\n";
		return -1;
	}

	sf::Clock deltaClock;
	sf::Color background_color = sf::Color::Red; // Начальный цвет фона

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(window, event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time deltaTime = deltaClock.restart();
		ImGui::SFML::Update(window, deltaTime);

		UpdateBackgroundColor(background_color, deltaTime);
		window.clear(background_color); // Устанавливаем цвет фона

		ImGui::SFML::Render(window);

		window.display();
	}
	ImGui::SFML::Shutdown();

	return 0;
}

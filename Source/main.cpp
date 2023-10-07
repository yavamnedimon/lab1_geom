#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"


void HandleUserInput(sf::RenderWindow& window, const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		window.close();
		break;
	default:
		break;
	}
}

void Update(sf::RenderWindow& window, const sf::Time& deltaClock)
{
	// Make some time-dependent updates, like: physics, gameplay logic, animations, etc.
}
sf::Sprite sprite;
sf::Texture spriteTexture;
sf::Image spriteImage;

void Render(sf::RenderWindow& window)
{
	// Draw some sfml/opengl items
	static sf::CircleShape circle = []()
	{
		sf::CircleShape circle;
		circle.setRadius(50);
		circle.setPosition(200, 200);
		circle.setFillColor(sf::Color::White);
		return circle;
	}();
	window.draw(circle);
	window.draw(sprite);
}

void RenderGui(sf::RenderWindow& window)
{
	ImGui::Begin("Default window");
	ImGui::End();
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Geometry modeling 1");
	window.setFramerateLimit(60);
	if (!ImGui::SFML::Init(window))
	{
		std::cout << "ImGui initialization failed\n";
		return -1;
	}

	spriteImage.create(200, 200);
	for (int x = 0; x < spriteImage.getSize().x; ++x)
	{
		for (int y = 0; y < spriteImage.getSize().y; ++y)
		{
			spriteImage.setPixel(x, y, sf::Color(rand()%255, rand()%255, rand()%255));
		}	
	}

	spriteTexture.loadFromImage(spriteImage);
	sprite.setTexture(spriteTexture);
	sprite.setPosition(400, 400);

	sf::Clock deltaClock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(window, event);
			HandleUserInput(window, event);
		}

		sf::Time deltaTime = deltaClock.restart();
		ImGui::SFML::Update(window, deltaTime);
		Update(window, deltaTime);

		window.clear();

		RenderGui(window);
		Render(window);

		ImGui::SFML::Render(window);

		window.display();
	}
	ImGui::SFML::Shutdown();

	return 0;
}

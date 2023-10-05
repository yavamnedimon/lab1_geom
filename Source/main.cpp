#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics/RenderWindow.hpp"
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

void Render(sf::RenderWindow& window)
{
	
}

void RenderGui(sf::RenderWindow& window)
{
	ImGui::Begin("Hello, world!");
		
	if (ImGui::Button("Look at this pretty button"))
		std::cout << "Button pressed\n";
    	
	ImGui::Text("Look at this pretty text");
	ImGui::End();
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Geometry modeling 1");
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
    {
        std::cout << "ImGui initialization failed\n";
        return -1;
    }
	
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
    	
    	Render(window);
    	
    	RenderGui(window);
        ImGui::SFML::Render(window);
    	
        window.display();
    }
    ImGui::SFML::Shutdown();
	
	return 0;
}

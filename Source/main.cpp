#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "Graphics/RFSprite.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"


float CircleFunc(sf::Vector2f spacePos)
{
    return std::powf(1, 2) - std::powf(spacePos.x, 2) - std::powf(spacePos.y, 2);
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometry modeling 1");
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
    {
        std::cout << "ImGui initialization failed\n";
        return -1;
    }
    
    RFSprite functionCanvas(window.getSize());

    while (window.isOpen())
    {
		static sf::Clock deltaClock;
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Right)
            {
            	functionCanvas.Update(&CircleFunc);
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // ImGui::Begin("Hello, world!");
        // ImGui::Button("Look at this pretty button");
        // ImGui::End();

        window.clear();
        window.draw(functionCanvas);
      
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();


	functionCanvas.SaveTo("Canvas.png");
	
	return 0;
}

#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometry modeling 1");
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
    {
        std::cout << "ImGui initialization failed\n";
        return -1;
    }
    
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
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");

    	if (ImGui::Button("Look at this pretty button"))
    		std::cout << "Button pressed\n";
    	
		ImGui::Text("Look at this pretty text");
        ImGui::End();

        window.clear();
      
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
	
	return 0;
}

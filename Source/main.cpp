#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
        return -1;
    
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    sf::Image textureImage;
    textureImage.create(window.getSize().x, window.getSize().y);
    for (unsigned i = 0; i < window.getSize().x; ++i)
    {
        for (unsigned j = 0; j < window.getSize().y; ++j)
        {
            textureImage.setPixel(i, j, sf::Color(80, 40, 40));
        }
    }
    
    texture.loadFromImage(textureImage);
  
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
  
    sf::Sprite background(texture);
    // sprite.setPosition(200, 200);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(background);
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

#pragma once
#include <functional>
#include <filesystem>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class RFSprite: public sf::Drawable
{
public:
    RFSprite(sf::Vector2u size);

	void Update(std::function<float(sf::Vector2f spacePos)> RFunction);
	bool SaveTo(const std::filesystem::path& path) const;
	

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


private:
	sf::Sprite _sprite;
    sf::Texture _texture;
};

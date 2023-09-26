#include "RFSprite.h"
#include <SFML/Graphics/RenderTarget.hpp>


RFSprite::RFSprite(sf::Vector2u size)
{
    _texture.create(size.x, size.y);
	_sprite.setTexture(_texture);
}

void RFSprite::Update(std::function<float(sf::Vector2f spacePos)> RFunction)
{
	sf::Image image(_texture.copyToImage());

	for (unsigned j = 0; j < image.getSize().y; ++j)
	{
		sf::Vector2f spacePos;
		spacePos.y = static_cast<float>(j * 2) / static_cast<float>(image.getSize().y) - 1.f;
		for (unsigned i = 0; i < image.getSize().x; ++i)
		{
			spacePos.x = static_cast<float>(i * 2) / static_cast<float>(image.getSize().x) - 1.f;
			const float val = RFunction(spacePos);
			if (val >= 0.f)
				image.setPixel(i, j, sf::Color(100, 30, 30));
			else
				image.setPixel(i, j, sf::Color(30, 30, 100));
		}
	}
	
	_texture.update(image);
}

void RFSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_sprite);
}

bool RFSprite::SaveTo(const std::filesystem::path& path) const
{
	return _texture.copyToImage().saveToFile(path.string());
}
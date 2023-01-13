#include "../header/sprite_factory.hpp"

namespace project
{
    SpriteFactory::SpriteFactory(const sf::Texture& texture):texture_(texture) {}
    sf::Sprite SpriteFactory::make_from_texture(int top, int left, int width, int height) const
    {
        sf::IntRect rect;
        rect.top = top;
        rect.left = left;
        rect.width = width;
        rect.height = height;

        return sf::Sprite(texture_, rect);
    }
    
    sf::Vector2u SpriteFactory::size() const
    {
        return texture_.getSize();
    }
};

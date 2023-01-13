#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
namespace project
{
    class SpriteFactory final
    {
        private:
            const sf::Texture& texture_;
        public:
            SpriteFactory(const sf::Texture& texture);
            sf::Sprite make_from_texture(int top, int left, int width, int height) const;
            sf::Vector2u size() const;
    };
};

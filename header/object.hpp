#pragma once

#include "../interface/object.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace project
{
    class Object : public IObject
    {
        sf::Sprite sprite_;

        public:
            Object(sf::Sprite);
            std::unique_ptr<IObject> clone() const override;
            FRect getGlobalBounds() const override;
            void move(float, float) override;
            void move(const Vec&) override;
            void setPosition(float, float) override;
            void setPosition(const Vec&) override;
            Vec getPosition() const override;
            void draw(sf::RenderTarget* target) const override;
    };
};

#pragma once

namespace sf
{
    class RenderTarget;
};

namespace project
{
    class IDrawable
    {
        public:
            virtual void draw(sf::RenderTarget* target) const = 0;
            virtual ~IDrawable() = default;
    };
};

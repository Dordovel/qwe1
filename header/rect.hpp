#pragma once

#include <SFML/Graphics/Rect.hpp>

namespace project
{
    class FRect : public sf::Rect<float>
    {
        public:
            FRect() = default;
            FRect(const FRect&) = default;
            FRect& operator = (const FRect&) = default;

            FRect(FRect&&) = default;
            FRect& operator = (FRect&&) = default;

            FRect(sf::Rect<float>&& r):sf::Rect<float>(r){}
            FRect& operator = (sf::Rect<float>&& e){sf::Rect<float>::operator=(e); return *this;};
    };

    class IRect : public sf::Rect<int>
    {
        public:
            IRect() = default;
            IRect(const IRect&) = default;
            IRect& operator = (const IRect&) = default;

            IRect(IRect&&) = default;
            IRect& operator = (IRect&&) = default;

            IRect(sf::Rect<int>&& r):sf::Rect<int>(r){}
            IRect& operator = (sf::Rect<int>&& e){sf::Rect<int>::operator=(e); return *this;};
    };
};

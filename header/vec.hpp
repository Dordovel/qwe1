#pragma once

#include <SFML/System/Vector2.hpp>
#include <algorithm>
namespace project
{
    class Vec : public sf::Vector2f
    {
        public:
            Vec(const Vec&) = default;
            Vec& operator = (const Vec&) = default;

            Vec(Vec&&) = default;
            Vec& operator = (Vec&&) = default;

            Vec(const sf::Vector2f& r):sf::Vector2f(r){}
            Vec& operator = (const sf::Vector2f& e){sf::Vector2f::operator=(e); return *this;};

            Vec(sf::Vector2f&& r):sf::Vector2f(std::move(r)){}
            Vec& operator = (sf::Vector2f&& e){sf::Vector2f::operator=(std::move(e)); return *this;};
    };
};

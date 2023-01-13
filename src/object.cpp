#include "../header/object.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include "../header/rect.hpp"
#include "../header/vec.hpp"

namespace project
{
    Object::Object(sf::Sprite sprite):sprite_(std::move(sprite))
    {}

    std::unique_ptr<IObject> Object::clone() const
    {
        return std::make_unique<Object>(*this);
    }

    FRect Object::getGlobalBounds() const
    {
        return FRect(sprite_.getGlobalBounds());
    }

    void Object::setPosition(float x, float y)
    {
        sprite_.setPosition(x, y);
    }

    void Object::setPosition(const Vec& v)
    {
        sprite_.setPosition(v);
    }

    Vec Object::getPosition() const
    {
        return sprite_.getPosition();
    }

    void Object::move(float x, float y)
    {
        sprite_.move(x, y);
    }

    void Object::move(const Vec& v)
    {
        sprite_.move(v);
    }

    void Object::draw(sf::RenderTarget* target) const
    {
        target->draw(sprite_);
    }
};

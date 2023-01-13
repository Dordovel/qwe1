#include "../header/main.hpp"
#include "dynamic.hpp"
#include "keyboard.hpp"
#include "rect.hpp"
#include "vec.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace project
{

    Main::Main(std::unique_ptr<IDynamic> sprite): d_(nullptr), sprite_(std::move(sprite)){}

    void Main::init(float rectLeft, float rectTop, float rectWidth, float rectHeight)
    {
        update_view(rectLeft, rectTop, rectWidth, rectHeight);

        float y = view_.height;
        float height = sprite_->getGlobalBounds().height;

        sprite_->setPosition(0, y - height);
    }

    void Main::add_sublayout(ILayout* other)
    {
        if(!other) return;
        d_ = other;
    }

    void Main::update(float dt)
    {
        FRect bounds = sprite_->getGlobalBounds();
        if(false == view_.contains(bounds.left + bounds.width, bounds.top))
        {
            Keyboard::on_key_event(Keyboard::Keys::VK_RIGHT, false);
        }

        if(false == view_.contains(bounds.left, bounds.top))
        {
            Keyboard::on_key_event(Keyboard::Keys::VK_LEFT, false);
        }

        sprite_->update(dt);
    }
    
    void Main::update_view(float rectLeft, float rectTop, float rectWidth, float rectHeight)
    {
        view_ = sf::FloatRect{rectLeft, rectTop, rectWidth, rectHeight};
    }

    void Main::draw(sf::RenderTarget* target) const
    {
        sprite_->draw(target);
        if(d_) d_->draw(target);
    }
};

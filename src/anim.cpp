#include "../header/anim.hpp"
#include "rect.hpp"
#include "vec.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace project
{
    Anim::Anim(sf::Sprite sprite): sprite_(std::move(sprite)), total_(0), loop_(true), play_(true){}

    std::unique_ptr<IDynamic> Anim::clone() const
    {
        return std::make_unique<Anim>(*this);
    }

    FRect Anim::getGlobalBounds() const
    {
        return sprite_.getGlobalBounds();
    }

    void Anim::move(float x, float y)
    {
        sprite_.move(x, y);
    }

    void Anim::move(const Vec& v)
    {
        sprite_.move(v);
    }

    void Anim::setPosition(float x, float y)
    {
        sprite_.setPosition(x, y);
    }

    void Anim::setPosition(const Vec& v)
    {
        sprite_.setPosition(v);
    }

    Vec Anim::getPosition() const
    {
        return sprite_.getPosition();
    }

    void Anim::draw(sf::RenderTarget* target) const
    {
        target->draw(sprite_);
    }

    void Anim::update(float dt)
    {
        if(!play_) return;

        total_ += dt;
        double progress = total_;
        for(auto& frame : timeline_)
        {
            progress -= (frame).duration;  

            if (progress <= 0.0)
            {
                sprite_.setTextureRect(frame.rect);  
                break;
            }

            if(loop_ && (&frame == &timeline_.back()))
            {
                total_ = 0.0;
            }
        }
    }

    void Anim::loop(bool loop)
    {
        loop_ = loop;
    }

    void Anim::play(bool play)
    {
        play_ = play;
    }

    void Anim::set(sf::Sprite sprite)
    {
        sprite_ = std::move(sprite);
    }

    void Anim::addFrame(IRect frame, float duration)
    {
        timeline_.emplace_back(Frame{frame, duration});
    }
};

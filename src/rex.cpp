#include "../header/rex.hpp"
#include "../header/keyboard.hpp"
#include "vec.hpp"
#include <cmath>
#include <iostream>

float gravity = 1000.f;
bool jmp = false;
float last = MAXFLOAT;

namespace project
{
    Rex::Rex(Anim sprite): default_(std::move(sprite)), currentFrame_(&default_){}

    std::unique_ptr<IDynamic> Rex::clone() const
    {
        return std::make_unique<Rex>(*this);
    }

    FRect Rex::getGlobalBounds() const
    {
        return currentFrame_->getGlobalBounds();
    }

    void Rex::move(float x, float y)
    {
        currentFrame_->move(x, y);
    }

    void Rex::move(const Vec& v)
    {
        currentFrame_->move(v);
    }

    void Rex::setPosition(float x, float y)
    {
        currentFrame_->setPosition(x, y);
    }

    void Rex::setPosition(const Vec& v)
    {
        currentFrame_->setPosition(v);
    }

    Vec Rex::getPosition() const
    {
        return currentFrame_->getPosition();
    }

    void Rex::draw(sf::RenderTarget* target) const
    {
        currentFrame_->draw(target);
    }

    void Rex::bindAnim(Keyboard::Keys, Anim)
    {
    }

    void Rex::changeAnim(Keyboard::Keys key)
    {
        auto it = anims_.find(key);
        if(it != anims_.end() && &it->second != currentFrame_)
        {
            decltype(currentFrame_) last = currentFrame_;
            currentFrame_ = &it->second;
            currentFrame_->setPosition(last->getPosition());
        }
    }

    void Rex::update(float dt)
    {
        if(Keyboard::is_key_pressed(Keyboard::Keys::VK_RIGHT))
        {
            changeAnim(Keyboard::Keys::VK_RIGHT);
            move(300 * dt, 0);
        }

        if(Keyboard::is_key_pressed(Keyboard::Keys::VK_LEFT))
        {
            changeAnim(Keyboard::Keys::VK_LEFT);
            move(-300 * dt, 0);
        }

        if(Keyboard::is_key_pressed(Keyboard::Keys::VK_SPACE))
        {
            changeAnim(Keyboard::Keys::VK_SPACE);
            if(!jmp)
            {
                jmp = true;
                last = currentFrame_->getPosition().y;
            }
            currentFrame_->move(0, (gravity * -1) * dt);
        }
        else
        {
            if(jmp)
            {
                currentFrame_->move(0, gravity * dt);
            }

            Vec pos = currentFrame_->getPosition();

            if(last < pos.y)
            {
                currentFrame_->setPosition(pos.x, last);
                last = MAXFLOAT;
                jmp = false;
            }
        }

        currentFrame_->update(dt);
    }
};

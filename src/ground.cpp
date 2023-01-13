#include "../header/ground.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "../header/rect.hpp"
#include <cmath>

namespace project
{
    bool Ground::is_finish(const IObject& sprite, const sf::FloatRect& rect)
    {
        sf::FloatRect spriteCurrentBound = sprite.getGlobalBounds();
        return rect.contains(
                                (spriteCurrentBound.left + spriteCurrentBound.width),
                                    (spriteCurrentBound.top + spriteCurrentBound.height) - 20
                            );
    }

    void Ground::add_sublayout(ILayout* other)
    {
        if(!other) return;

        d_ = other;
        sf::FloatRect layoutBound = layout_[0].first->getGlobalBounds();
        sf::FloatRect bound = {view_.left,
                                view_.top,
                                view_.width,
                                (view_.height - layoutBound.height)};

        d_->init(bound.left, bound.top, bound.width, bound.height);
    }

    Ground::Ground(std::unique_ptr<IObject> sprite):d_(nullptr)
    {
        layout_[0] = {sprite->clone(), true};
        layout_[1] = {std::move(sprite), false};
    }

    void Ground::init(float rectLeft, float rectTop, float rectWidth, float rectHeight)
    {
        update_view(rectLeft, rectTop, rectWidth, rectHeight);

        float y = view_.height;
        float height = layout_[0].first->getGlobalBounds().height;

        layout_[0].first->setPosition(0, y - height);
    }

    void Ground::update(float dt)
    {
        if(is_finish(*layout_[0].first, view_) && false == layout_[1].second)
        {
            sf::FloatRect spriteCurrentBound = layout_[0].first->getGlobalBounds();
            sf::Vector2f tail = sf::Vector2f(std::ceil(spriteCurrentBound.left + spriteCurrentBound.width) - 0.1, spriteCurrentBound.top);
            layout_[1].first->setPosition(tail.x, tail.y);
            layout_[1].second = true;
            std::swap(layout_[0], layout_[1]);
        }

        for (auto& layout : layout_)
        {
            if(layout.first->getGlobalBounds().intersects(view_))
            {
                layout.first->move(-300.f * dt, 0);
            }
            else {
                layout.second = false;
            }
        }

        if(d_) d_->update(dt);
    }

    void Ground::update_view(float rectLeft, float rectTop, float rectWidth, float rectHeight)
    {
        view_ = sf::FloatRect{rectLeft, rectTop, rectWidth, rectHeight};
        if(d_) d_->update_view(rectLeft, rectTop, rectWidth, rectHeight);
    }

    void Ground::draw(sf::RenderTarget* target) const
    {
        for (const auto& layout : layout_)
        {
            if(layout.second)
                layout.first->draw(target);
        }

        if(d_) d_->draw(target);
    }
};

#pragma once

#include "../interface/object.hpp"
#include "sprite_factory.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <array>
#include <memory>
#include "../interface/layout.hpp"

namespace project
{
    class Ground final : public ILayout
    {
        private:
            sf::FloatRect view_;
            std::array<std::pair<std::unique_ptr<IObject>, bool>, 2> layout_;

            bool is_finish(const IObject& sprite, const sf::FloatRect& rect);

            ILayout* d_;

        public:
            Ground(std::unique_ptr<IObject>);
            void init(float rectLeft, float rectTop, float rectWidth, float rectHeight) override;
            void add_sublayout(ILayout* other);
            void update(float dt) override;
            void update_view(float rectLeft, float rectTop, float rectWidth, float rectHeight) override;
            void draw(sf::RenderTarget* target) const override;
    };
};

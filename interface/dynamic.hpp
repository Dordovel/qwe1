#pragma once

#include "drawable.hpp"
#include "transform.hpp"
#include <memory>

namespace project
{
    class IDynamic : public IDrawable, public ITransform
    {
        public:
            virtual void update(float dt) = 0;
            virtual std::unique_ptr<IDynamic> clone() const = 0;
            virtual ~IDynamic() = default;
    };
};

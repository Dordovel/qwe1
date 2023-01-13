#pragma once

#include "drawable.hpp"
#include "transform.hpp"
#include <memory>

namespace project
{
    class IObject : public IDrawable, public ITransform
    {
        public:
            virtual std::unique_ptr<IObject> clone() const = 0;
            virtual ~IObject() = default;
    };
};

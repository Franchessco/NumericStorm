#pragma once
#include "Parameters.hpp"

namespace NumericStorm
{
    namespace Fitting
    {
        template<typename T_p, size_t s_p>
        class Bounds : public Parameters<T_p, s_p> {
        public:
            template<class ... Args>
            Bounds(Args... args) 
                :Parameters<T_p, s_p>(args...) {}

            Bounds(std::array<T_p, s_p> parameters) 
                :Parameters<T_p, s_p>(parameters) {}

        };
    }
}
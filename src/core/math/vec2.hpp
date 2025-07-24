/* ---------------------------------------------------
   Copyright (c) 2025 Soviet-Cat. All Rights Reserved.
   See LICENSE file for details.
   --------------------------------------------------- */

#pragma once

#ifdef EXPORT
    #define KRATOS __declspec(dllexport)
#else
    #define KRATOS __declspec(dllimport)
#endif

#include <stdexcept>
#include <string>
#include <vector>

namespace Kratos::core::math
{
    template<typename T>
    struct KRATOS vec2
    {
        T x, y;

        vec2() : x(0), y(0) {}
        vec2(T x, T y) : x(x), y(y) {}
        vec2(const vec2& vec) = default;
        vec2(vec2&& vec) noexcept = default;
        ~vec2() = default;

        T& operator[](size_t i)
        {
            if (i > 1) throw std::out_of_range("Index out of range.");
            return (&x)[i];
        }

        const T& operator[](size_t i) const
        {
            if (i > 1) throw std::out_of_range("Index out of range.");
            return (&x)[i];
        }

        explicit operator T*()
        {
            return &x;
        }

        explicit operator const T*() const
        {
            return &x;
        }

        explicit operator std::vector<T>() const
        {
            return {x, y};
        }

        explicit operator std::string() const
        {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }
    };
}
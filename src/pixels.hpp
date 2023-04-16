#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r, g, b, a;
};

struct RGB
{
    uint8_t r, g, b;
};

struct Luma
{
    uint8_t gray;
};

template <typename A, typename B>
A from(const B& stuff);

template <>
RGBA from(const RGBA& stuff) // Spécialisation
{
    return stuff;
}

template <>
RGB from(const RGB& stuff)
{
    return stuff;
}

template <>
Luma from(const Luma& stuff)
{
    return stuff;
}

template <>
RGB from(const RGBA& stuff) // Spécialisation
{
    return { stuff.r, stuff.g, stuff.b };
}

template <>
RGBA from(const RGB& stuff) // Spécialisation
{
    return { stuff.r, stuff.g, stuff.b, 255 };
}

template <>
Luma from(const RGB& stuff) // Spécialisation
{
    return { lib::rgb_to_grayscale(stuff.r, stuff.g, stuff.b) };
}

template <>
RGB from(const Luma& stuff) // Spécialisation
{
    auto res = lib::grayscale_to_rgb(stuff.gray);
    return { res[0], res[1], res[2] };
}

template <>
Luma from(const RGBA& stuff) // Spécialisation
{
    return from<Luma, RGB>(from<RGB, RGBA>(stuff));
}

template <>
RGBA from(const Luma& stuff) // Spécialisation
{
    return from<RGBA, RGB>(from<RGB, Luma>(stuff));
}

RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    auto [r, g, b, a] = lib::mix_color(lhs.r, lhs.g, lhs.b, lhs.a, rhs.r, rhs.g, rhs.b, rhs.a);
    return { r, g, b, a };
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    return from<RGB, RGBA>(from<RGBA, RGB>(lhs) + rhs);
}

RGB operator+(const Luma& lhs, const RGBA& rhs)
{
    return from<RGB, RGBA>(from<RGBA, Luma>(lhs) + rhs);
}

RGB operator+(const RGBA& lhs, const RGB& rhs)
{
    return from<RGB, RGBA>(lhs + from<RGBA, RGB>(rhs));
}

RGB operator+(const RGB& lhs, const RGB& rhs)
{
    return from<RGB, RGBA>(from<RGBA, RGB>(lhs) + from<RGBA, RGB>(rhs));
}

RGB operator+(const Luma& lhs, const RGB& rhs)
{
    return from<RGB, RGBA>(from<RGBA, Luma>(lhs) + from<RGBA, RGB>(rhs));
}

// mask operator
template <typename A>
RGBA operator+(const A& lhs, const Luma& mask)
{
    RGBA pix = from<RGBA, A>(lhs);
    pix.a    = ((lhs.a * mask.gray) / 255);
    return pix;
}
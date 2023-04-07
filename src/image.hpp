#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>

template <typename P, size_t W, size_t H>
struct Image
{
private:
    std::array<std::array<P, W>, H> pixels;

public:
    Image() = default;
    Image(const P& value)
    {
        for (size_t i = 0; i < H; ++i)
        {
            for (size_t j = 0; j < W; ++j)
            {
                pixels[i][j] = value;
            }
        }
    }
    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)>& functor)
    {
        for (size_t i = 0; i < H; ++i)
        {
            for (size_t j = 0; j < W; ++j)
            {
                // pixels[i][j] = functor(i, j);
                setPixel(i, j, functor(i, j));
            }
        }
    }

    // Accesseur en lecture
    const P& getPixel(size_t i, size_t j) const { return pixels[i][j]; }

    // Accesseur en écriture
    void setPixel(size_t i, size_t j, const P& value) { pixels[i][j] = value; }

    P& operator()(const size_t i, const size_t j) { return pixels[i][j]; }

    const P& operator()(const size_t i, const size_t j) const { return getPixel(i, j); }
};

template <typename A, typename B, size_t W, size_t H>
Image<A, W, H> operator+(const Image<A, W, H>& im1, const Image<B, W, H>& im2)
{
    Image<A, W, H> im;
    for (size_t i = 0; i < W; ++i)
    {
        for (size_t j = 0; j < H; ++j)
        {
            im(i, j) = im1(i, j) + im2(i, j);
        }
    }
    return im;
}
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
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                pixels[i][j] = value;
            }
        }
    }

    const P& operator()(const size_t i, const size_t j) const { return pixels[j][i]; }
    P&       operator()(const size_t i, const size_t j) { return pixels[j][i]; }

    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)>& functor)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                pixels[j][i] = functor(i, j);
                //(*this)(i,j) = functor(i, j);
            }
        }
    }
};

template <typename A, typename B, size_t W, size_t H>
Image<A, W, H> operator+(const Image<A, W, H>& im1, const Image<B, W, H>& im2)
{
    Image<A, W, H> im;
    for (size_t j = 0; j < H; ++j)
    {
        for (size_t i = 0; i < W; ++i)
        {
            im(i, j) = im1(i, j) + im2(i, j);
        }
    }
    return im;
}

template <size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<Luma, W, H>& lhs, const Image<RGBA, W, H>& rhs)
{
    Image<RGB, W, H> im;
    for (size_t j = 0; j < H; ++j)
    {
        for (size_t i = 0; i < W; ++i)
        {
            im(i, j) = lhs(i, j) + rhs(i, j);
        }
    }
    return im;
}
template <size_t W, size_t H>
Image<RGB, W, H> operator+(const Image<Luma, W, H>& lhs, const Image<RGB, W, H>& rhs)
{
    Image<RGB, W, H> im;
    for (size_t j = 0; j < H; ++j)
    {
        for (size_t i = 0; i < W; ++i)
        {
            im(i, j) = lhs(i, j) + rhs(i, j);
        }
    }
    return im;
}
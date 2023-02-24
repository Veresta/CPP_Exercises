#pragma once

#include "Leaf.hpp"

#include <iostream>
#include <string>

class IntLeaf : public Leaf
{
private:
    int _data;

public:
    IntLeaf(const int val)
        : Leaf { NodeKind::INT }
        , _data { val }
    {}
    std::string                     print() const override { return std::to_string(_data); }
    int                             data() const;
    static std::unique_ptr<IntLeaf> make_ptr(const int val);
};

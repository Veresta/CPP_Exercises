#include "IntLeaf.hpp"

int IntLeaf::data() const
{
    return _data;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(const int val)
{
    return std::make_unique<IntLeaf>(val);
}
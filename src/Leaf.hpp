#pragma once

#include "Node.hpp"

class Leaf : public Node
{
private:
public:
protected:
    Leaf(NodeKind kind)
        : Node { kind }
    {}
};
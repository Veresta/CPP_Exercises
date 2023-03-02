#pragma once

#include "Node.hpp"

#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<NodePtr> _array;

public:
    ArrayNode()
        : Node { NodeKind::ARRAY }
    {}
    std::string                       print() const override;
    static std::unique_ptr<ArrayNode> make_ptr(std::vector<NodePtr> data = {});
    int                               child_count() const { return _array.size(); };
    void                              push_back(NodePtr ptr);
    size_t                            height() const override;
    size_t                            node_count() const override;
};

#include "ArrayNode.hpp"

std::string ArrayNode::print() const
{
    if (_array.size() == 0)
    {
        return "[]";
    }
    std::string result = "[";
    for (unsigned int i = 0; i < _array.size() - 1; i++)
    {
        result += _array.at(i)->print() + ",";
    }
    result += _array.at(_array.size() - 1)->print();
    result += "]";
    return result;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr(std::vector<NodePtr> data)
{
    auto res    = std::make_unique<ArrayNode>();
    res->_array = std::move(data);
    return res;
}

void ArrayNode::push_back(NodePtr ptr)
{
    _array.push_back(std::move(ptr));
}

size_t ArrayNode::height() const
{
    if (this->child_count() == 0)
        return 0u;
    size_t result = 0;
    for (const auto& child : _array)
    {
        size_t child_height = child->height();
        if (child_height > result)
            result = child_height;
    }
    return result + 1;
}

size_t ArrayNode::node_count() const
{
    size_t result = 1;
    for (const auto& child : _array)
    {
        result += child->node_count();
    }
    return result;
}
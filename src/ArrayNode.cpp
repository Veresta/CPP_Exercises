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
#include "ObjectNode.hpp"

std::string ObjectNode::print() const
{
    std::string result = "{";
    bool        first  = true;
    for (auto const& el : _data)
    {
        if (first)
            first = false;
        else
            result += ",";
        result += '"' + el.first + "\":";
        result += el.second->print();
    }
    result += '}';
    return result;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr(std::map<std::string, NodePtr> data)
{
    auto res   = std::make_unique<ObjectNode>();
    res->_data = std::move(data);
    return res;
}

size_t ObjectNode::height() const
{
    if (this->child_count() == 0)
        return 0u;
    size_t result = 0;
    for (const auto& child : _data)
    {
        size_t child_height = child.second->height();
        if (child_height > result)
            result = child_height;
    }
    return result + 1;
}

size_t ObjectNode::node_count() const
{
    size_t result = 1;
    for (const auto& child : _data)
    {
        result += child.second->node_count();
    }
    return result;
}
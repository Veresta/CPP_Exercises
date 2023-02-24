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
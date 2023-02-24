#include "StringLeaf.hpp"

std::string StringLeaf::print() const
{
    std::string result;
    result += '"';
    for (char c : _data)
    {
        if (c == '\\' || c == '"')
        {
            result += '\\';
        }
        result += c;
    }
    result += '"';
    return result;
}

std::string StringLeaf::data() const
{
    return _data;
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(const std::string& val)
{
    return std::make_unique<StringLeaf>(val);
}
#pragma once

#include "Leaf.hpp"
class StringLeaf : public Leaf
{
private:
    std::string _data;

public:
    StringLeaf(const std::string& value)
        : Leaf { NodeKind::STRING }
        , _data { value }
    {}

    std::string                        print() const override;
    std::string                        data() const;
    static std::unique_ptr<StringLeaf> make_ptr(const std::string& val);
};

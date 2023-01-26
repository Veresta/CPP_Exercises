#pragma once

#include "PlushStore.hpp"
#include <string>
#include <ostream>

class Kid
{
private:
    std::string _name;
    int _money;

public:
    Kid(const std::string name, const int money)
        : _name{name},
          _money{money} {}

    std::string get_name() const { return _name; }
    int get_money() const { return _money; }

    friend std::ostream &operator<<(std::ostream &stream, const Kid &kid)
    {
        return stream << kid._name << " has " << kid._money << " euros.";
    }

    void buy_plush(PlushStore &store)
    {
        const auto plush = store.buy(this->get_money());
        if (plush != std::nullopt)
        {
            _money -= plush->get_cost();
        }
    }
};

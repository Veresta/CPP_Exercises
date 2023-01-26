#pragma once

#include "Plush.hpp"
#include <string>
#include <list>
#include <algorithm>
#include <optional>

class PlushStore
{
private:
    std::string _name;
    int _wealth_amout = 0;
    int _stock = 0;
    int _debt = 0;
    int _exp = 0;
    std::list<Plush> _store;

public:
    PlushStore(std::string name)
        : _name{name}
    {
    }

    std::string get_name() const { return _name; }
    int get_wealth_amount() const { return _wealth_amout; }
    int get_stock_size() const { return _stock; }
    void loan(const int amount)
    {
        _wealth_amout += amount;
        _debt += ((amount * 10) / 100) + amount;
    }
    int get_debt_amount() { return _debt; }

    int make_plush(const int plush_price)
    {
        if (plush_price > _wealth_amout && _wealth_amout == 0)
        {
            return 0;
        }
        if (plush_price > _wealth_amout)
        {
            _stock += 1;
            auto tmp = _wealth_amout;
            _wealth_amout = 0;
            _exp++;
            _store.emplace_back(tmp + _exp);
            return tmp + _exp;
        }
        _stock += 1;
        _wealth_amout -= plush_price;
        _exp++;
        _store.emplace_back(plush_price + _exp);
        return plush_price + _exp;
    }
    int get_experience() const { return _exp; }

    std::optional<Plush> buy(const int money)
    {
        if (_store.size() == 0)
        {
            return {}; // std::optional<Plush>();
        }
        auto min_it = std::min_element(_store.begin(), _store.end(), ComparePlush());
        auto min_peluche = *min_it;
        if (money < min_peluche.get_cost())
        {
            return {}; // std::optional<Plush>();
        }
        _stock--;
        _wealth_amout += min_peluche.get_cost();
        _store.erase(min_it);
        return std::optional<Plush>(min_peluche);
    }

    struct ComparePlush
    {
        bool operator()(const Plush &a, const Plush &b) const
        {
            return a.get_cost() < b.get_cost();
        }
    };
};

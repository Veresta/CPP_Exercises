#pragma once

class Plush
{
private:
    int _cost;

public:
    Plush()
        : _cost{10}
    {
    }

    Plush(const int price)
        : _cost{price} {}

    int get_cost() const { return this->_cost; }
    void set_cost(const int prix)
    {
        this->_cost = prix;
    }
};
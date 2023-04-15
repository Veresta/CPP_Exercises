#include "ex1.hpp"

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2)
{
    auto i2 = list2.begin();
    for (auto i1 = list1.begin(); i1 != list1.end() || i2 != list2.end(); ++i1, ++i2)
    {
        concatenate(*i1, *i2);
    }
}

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2)
{
    auto i2 = list2.begin();
    for (auto i1 = list1.begin(); i1 != list1.end() || i2 != list2.end(); ++i1, ++i2)
    {
        concatenate(*i1, std::move(*i2));
    }
}
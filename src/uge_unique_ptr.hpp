#pragma once
#include <memory>

namespace uge {
template <typename T>
class unique_ptr
{
public:
    unique_ptr()
        : _ptr { nullptr }
    {}
    unique_ptr(T* ptr)
        : _ptr { ptr }
    {}
    unique_ptr(const unique_ptr<T>& other)
    {
        if (other.get() != nullptr)
            _ptr = new T { *(other._ptr) };
        else
            _ptr = nullptr;
    }

    unique_ptr(unique_ptr<T>&& other)
        : _ptr { other._ptr }
    {
        other._ptr = nullptr;
    }

    unique_ptr<T>& operator=(uge::unique_ptr<T>&& other)
    {
        if (this != &other)
        {
            if (_ptr != nullptr)
                delete _ptr;
            _ptr       = other._ptr;
            other._ptr = nullptr;
        }
        return (*this);
    }

    T& operator*() { return *_ptr; }

    T* get() const { return _ptr; }

    ~unique_ptr()
    {
        if (_ptr != nullptr)
            delete _ptr;
    }

private:
    T* _ptr;
};

} // namespace uge
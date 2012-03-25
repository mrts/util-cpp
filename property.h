#ifndef UTILCPP_PROPERTY_H__
#define UTILCPP_PROPERTY_H__

namespace utilcpp
{

// TODO: support mutable getters if need arises

template <typename T>
const T& default_get(const T& value)
{ return value; }

template <typename T>
T& default_set(T& value, const T& rhs)
{ return value = rhs; }

template <typename T,
          const T& (*get)(const T&) = default_get<T>,
          T& (*set)(T&, const T&) = default_set<T> >
class property
{
public:
    operator const T& () const
    { return get(_value); }

    T& operator= (const T& rhs)
    { return set(_value, rhs); }

private:
    T _value;
};

}

#endif /* UTILCPP_PROPERTY_H */

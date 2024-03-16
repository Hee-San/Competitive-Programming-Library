#include "monoids/monoid.hpp"

template <class T>
struct min_monoid : public Monoid<T> {
public:
    T unit() override { return numeric_limits<T>::max(); }
    T mult(const T& a, const T& b) override { return min(a, b); }
};

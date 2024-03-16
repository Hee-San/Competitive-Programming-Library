#include "monoids/monoid.hpp"

template <class T>
struct plus_monoid : public Monoid<T> {
public:
    T unit() override { return T(); }
    T mult(const T& a, const  T& b) override { return a + b; }
};

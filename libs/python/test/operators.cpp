// Copyright David Abrahams 2002. Permission to copy, use,
// modify, sell and distribute this software is granted provided this
// copyright notice appears in all copies. This software is provided
// "as is" without express or implied warranty, and with no claim as
// to its suitability for any purpose.
#include <string>
#include <boost/python/operators2.hpp>
#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include "test_class.hpp"

using namespace boost::python;

typedef test_class<> X;

X operator-(X const& l, X const& r) { return X(l.value() - r.value()); }
X operator-(int l, X const& r) { return X(l - r.value()); }
X operator-(X const& l, int r) { return X(l.value() - r); }

X operator-(X const& x) { return X(-x.value()); }

X& operator-=(X& l, X const& r) { l.set(l.value() - r.value()); return l; }

bool operator<(X const& x, X const& y) { return x.value() < y.value(); }
bool operator<(X const& x, int y) { return x.value() < y; }
bool operator<(int x, X const& y) { return x < y.value(); }

X abs(X x) { return X(x.value() < 0 ? -x.value() : x.value()); }

BOOST_PYTHON_MODULE_INIT(operators_ext)
{
    module("operators_ext")
        .add(
            class_<X>("X")
            .def_init(args<int>())
            .def("value", &X::value)
            .def(self - self)
            .def(self - int())
            .def(other<int>() - self)
            .def(-self)
            .def(self < other<int>())
            .def(self < self)
            .def(1 < self)
            .def(self -= self)
            .def(abs(self))
            )
        .add(
            class_<test_class<1> >("Z")
            .def_init(args<int>())
            .def(int_(self))
            .def(float_(self))
            )
        ;
}

#include "module_tail.cpp"

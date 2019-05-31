#include <boost/fusion/tuple.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/adapted.hpp>
#include <string>
#include <iostream>

struct s {
    int *i;
    double d;
    std::string s;
};

BOOST_FUSION_ADAPT_STRUCT(s,
    (int*, i)
    (double, d)
    (std::string, s)
)

int main()
{
    boost::fusion::tuple<int*, double, const char*> t{ nullptr, 3.14, "Hello" };
    boost::fusion::for_each(t, [](auto t){ std::cout << t << '\n'; });

    boost::fusion::for_each(s{ nullptr, 3.14, "Hello" }, [](auto t){ std::cout << t << '\n'; });
}

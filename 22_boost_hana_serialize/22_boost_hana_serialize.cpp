#include <boost/hana.hpp>
#include <string>
#include <iostream>

struct person {
    BOOST_HANA_DEFINE_STRUCT(person,
        (std::string, name),
        (int, age)
    );
};

template <class T>
void serialize(const T &t)
{
    boost::hana::for_each(t, [](auto pair){ std::cout << boost::hana::second(pair) << '\n'; });
}

int main()
{
    person tom{ "Tom", 35 };
    serialize(tom);
}

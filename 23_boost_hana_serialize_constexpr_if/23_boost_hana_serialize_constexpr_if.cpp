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
    if constexpr (boost::hana::Foldable<T>::value)
        boost::hana::for_each(t, [](auto pair){ std::cout << boost::hana::second(pair) << '\n'; });
    else
        std::cout << t << '\n';
}

int main()
{
    person tom{ "Tom", 35 };
    serialize(tom);

    std::string s{"String"};
    serialize(s);

    int i{1};
    serialize(i);
}

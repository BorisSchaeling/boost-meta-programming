#include <boost/hana.hpp>
#include <string>
#include <type_traits>
#include <iostream>

struct person {
    BOOST_HANA_DEFINE_STRUCT(person,
        (std::string, name),
        (int, age)
    );
};

template <class T>
typename std::enable_if<!boost::hana::Foldable<T>::value>::type serialize(T t) { std::cout << t << '\n'; }

template <class T>
typename std::enable_if<boost::hana::Foldable<T>::value>::type serialize(T t) { boost::hana::for_each(t, [](auto pair){ std::cout << boost::hana::second(pair) << '\n'; }); }

int main()
{
    person tom{ "Tom", 35 };
    serialize(tom);

    std::string s{"String"};
    serialize(s);

    int i{1};
    serialize(i);
}

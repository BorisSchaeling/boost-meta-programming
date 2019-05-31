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

template <bool Foldable>
struct serialize_impl
{
    static void invoke(auto t) { std::cout << t << '\n'; }
};

template <>
struct serialize_impl<true>
{
    static void invoke(auto t) { boost::hana::for_each(t, [](auto pair){ std::cout << boost::hana::second(pair) << '\n'; }); }
};

template <class T>
void serialize(T t) { serialize_impl<boost::hana::Foldable<T>::value>::invoke(t); }

int main()
{
    person tom{ "Tom", 35 };
    serialize(tom);

    std::string s{"String"};
    serialize(s);

    int i{1};
    serialize(i);
}

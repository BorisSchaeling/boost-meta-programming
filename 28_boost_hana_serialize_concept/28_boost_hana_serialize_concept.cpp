#include <boost/hana.hpp>
#include <string>
#include <type_traits>
#include <iostream>

struct person {
    std::string name;
    int age;

    void serialize(std::ostream &os) const
    {
        os << name << '\n' << age << '\n';
    }
};

template <class T>
struct serializable_impl : std::false_type
{};

template <>
struct serializable_impl<person> : std::true_type
{};

template <class T>
struct Serializable : boost::hana::integral_constant<bool, serializable_impl<T>::value>
{};

template <class T>
void serialize(const T &t)
{
    if constexpr (Serializable<T>::value)
        t.serialize(std::cout);
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

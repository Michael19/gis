#include <iostream>

using namespace std;


class A{
public:
    bool operator== (const A& rhs) const;
    friend class std::hash<A>;

private:
    int x_;
    std::string  y;
};
namespace std
{
    template<>
    class hash<A> {
    public:
        size_t operator()(const A& rhs) const
        {
            size_t val = 0;
            val += hash<int>()(rhs.x_) * 31;
            val+=hash<string>()(rhs.y) * 59;

            return val;
        };
    };
}


int main()
{
    cout << "Hello World!" << endl;

    std::hash<A> hash_a;
    A temp;
    size_t t = hash_a(temp);
    std::cout << t << std::endl;

    return 0;
}


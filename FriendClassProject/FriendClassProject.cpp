#include <iostream>

class Second;

class First
{
    int field;
public:
    First(int field = 0) : field{ field } {};

    /*void PrintSecondNumber(Second second)
    {
        std::cout << second.number << "\n";
    }*/

    friend class Second;
    friend void func(First first);
};

void func(First first)
{
    std::cout << first.field << "\n";
}


class Second
{
    int number;
public:
    Second(int number = 0) : number{ number } {}
    void PrintFirstField(First first)
    {
        std::cout << first.field << "\n";
    }

    friend class First;
};

int main()
{
    First f(10);
    Second s(20);
    s.PrintFirstField(f);
    func(f);
}

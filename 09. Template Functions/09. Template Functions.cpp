#include <iostream>

using namespace std;

template <typename type> type MyMax(type Number1, type Number2)
{
    return (Number1 > Number2) ? Number1 : Number2;
}

int main()
{
    cout << MyMax<int>(3, 7) << endl;  // Calling MyMax Function for int

    cout << MyMax<float>(5.3, 2.4) << endl;     // Calling MyMax for flaot

    cout << MyMax<char>('a', 'b') << endl;  // Calling MyMax for char
}


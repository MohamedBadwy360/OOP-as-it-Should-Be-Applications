#include <iostream>

using namespace std;

template <class Type> class Calculator
{
private:

    Type _Number1, _Number2;

public:

    Calculator(Type Number1, Type Number2)
    {
        _Number1 = Number1;
        _Number2 = Number2;
    }

    Type Add()
    {
        return _Number1 + _Number2;
    }

    Type Subtract()
    {
        return _Number1 - _Number2;
    }

    Type Multiply()
    {
        return _Number1 * _Number2;
    }

    Type Divide()
    {
        return _Number1 / _Number2;
    }

    void PrintResult()
    {
        cout << "Numbers are : " << _Number1 << " & " << _Number2 << endl;
        cout << _Number1 << " + " << _Number2 << " = " << Add() << endl;
        cout << _Number1 << " - " << _Number2 << " = " << Subtract() << endl;
        cout << _Number1 << " * " << _Number2 << " = " << Multiply() << endl;
        cout << _Number1 << " / " << _Number2 << " = " << Divide() << endl;
    }

};

int main()
{
    Calculator<int> IntCal(20, 10);

    Calculator<float> FloatCal(7.5, 2.5);

    cout << "Int Result: \n\n";
    IntCal.PrintResult();

    cout << "\nFloat Result:\n\n";
    FloatCal.PrintResult();
}


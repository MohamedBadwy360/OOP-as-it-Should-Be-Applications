#include <iostream>
#include "ClsInputValidate.h"
//#include "ClsDate.h"

int main()

{
    cout << ClsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << ClsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << ClsInputValidate::IsDateBetween(ClsDate(),
        ClsDate(8, 10, 2023),
        ClsDate(31, 10, 2023)) << endl;

    cout << ClsInputValidate::IsDateBetween(ClsDate(),
        ClsDate(31, 10, 2023),
        ClsDate(8, 10, 2023)) << endl;

    cout << "\nPlease Enter a Number:\n";
    int x = ClsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "x=" << x;

    cout << "\nPleasClsInputValidatee Enter a Number between 1 and 5:\n";
    int y = ClsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "y=" << y;

    cout << "\nPlease Enter a Double Number:\n";
    double a = ClsInputValidate::ReadDblNumber("Invalid Number, Enter again:\n");
    cout << "a=" << a;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double b = ClsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "b=" << b;

    cout << endl << ClsInputValidate::IsValideDate(ClsDate(35, 12, 2022)) << endl;

    system("pause>0");

    return 0;
}
#include <iostream>
#include "clsBankClient.h"

using namespace std;

int main()
{
    clsBankClient Client1 = clsBankClient::Find("A103");
    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("65");
    Client2.Print();
}

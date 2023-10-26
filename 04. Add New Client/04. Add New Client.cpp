#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter First Name: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter Last Name: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account Number is already used. Choose Another Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(Client);

    clsBankClient::enSaveResults SaveResults;

    SaveResults = Client.Save();

    switch (SaveResults)
    {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount is saved successfuly\n";
            break;
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            cout << "\nError account was not saved because account number is used!\n";
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            break;
    }
}

int main()
{
    AddNewClient();

    system("pause>0");
}

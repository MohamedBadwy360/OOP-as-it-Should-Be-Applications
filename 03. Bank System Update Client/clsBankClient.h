#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode {EmptyMode, UpdateMode};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToCLientObject(string Line, string Separator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Separator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string ClientRecord = "";

		ClientRecord += Client.FirstName + Separator;
		ClientRecord += Client.LastName + Separator;
		ClientRecord += Client.Email + Separator;
		ClientRecord += Client.Phone + Separator;
		ClientRecord += Client.AccountNumber() + Separator;
		ClientRecord += Client.PinCode + Separator;
		ClientRecord += to_string(Client.AccountBalance);

		return ClientRecord;
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCLientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	static void _SaveCLientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		string DataLine;

		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> vClients;

		vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCLientsDataToFile(vClients);
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	// Read Only Property
	string AccountNumber()
	{
		return _AccountNumber;
	}

	// Property Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	// Property Get
	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	// Property Set
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	// Property Get
	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	void Print()
	{
		cout << "\n\tClient Card";
		cout << "\n____________________________";
		cout << "\nFirst Name : " << FirstName;
		cout << "\nLast Name  : " << LastName;
		cout << "\nFull Name  : " << FullName();
		cout << "\nEmail      : " << Email;
		cout << "\nPhone      : " << Phone;
		cout << "\nAcc Number : " << _AccountNumber;
		cout << "\nPin Code   : " << _PinCode;
		cout << "\nAcc Balance: " << _AccountBalance;
		cout << "\n____________________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCLientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToCLientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);

		return(!Client.IsEmpty());
	}

	enum enSaveResults {svFailedEmptyObject, svSucceeded};

	enSaveResults Save()
	{
		switch (_Mode)
		{
			case enMode::EmptyMode:
				return enSaveResults::svFailedEmptyObject;
				break;
			case enMode::UpdateMode:
				_Update();
				return enSaveResults::svSucceeded;
				break;
		}
	}
};


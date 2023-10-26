#pragma once

#include <iostream>
#include "ClsDate.h"

using namespace std;

class ClsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int number, int from, int to)
	{
		return !(number < from || number > to);
	}

	static bool IsNumberBetween(float number, float from, float to)
	{
		return !(number < from || number > to);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(ClsDate date, ClsDate from, ClsDate to)
	{
		if (ClsDate::IsDate1BeforeDate2(to, from))
			ClsDate::SwapDates(to, from);

		return !(ClsDate::IsDate1BeforeDate2(date, from) || ClsDate::IsDate1BeforeDate2(to, date));
	}

	static int ReadIntNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		int number;

		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}

		return number;
	}

	static int ReadIntNumberBetween(int from, int to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		int number = ReadIntNumber();

		while (!(IsNumberBetween(number, from, to)))
		{
			cout << errorMessage;
			number = ReadIntNumber();
		}

		return number;
	}

	static double ReadDblNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		double number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return number;
	}

	static double ReadDblNumberBetween(double from, double to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		double number = ReadDblNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << errorMessage;
			number = ReadDblNumber();
		}
		return number;
	}

	static bool IsValideDate(ClsDate date)
	{
		return ClsDate::IsValidDate(date);
	}
};


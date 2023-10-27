#pragma once

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class clsString
{
private:

	string _value;

public:

	clsString()
	{
		_value = "";
	}

	clsString(string value)
	{
		_value = value;
	}

	void SetValue(string value)
	{
		_value = value;
	}

	string GetValue()
	{
		return _value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string value;

	static string ReadString(string message)
	{
		string sentence;
		cout << message << endl;
		getline(cin, sentence);

		return sentence;
	}

	static char ReadCharacter()
	{
		char character;
		cout << "Enter a character: \n";
		cin >> character;

		return character;
	}

	static short Length(string sentence)
	{
		return sentence.length();
	}

	short Length()
	{
		return _value.length();
	}

	static string LowerAllLettersOfWord(string sentence)
	{
		for (short i = 0; i < sentence.length(); i++)
		{
			sentence[i] = tolower(sentence[i]);
		}

		return sentence;
	}

	void LowerAllLettersOfWord()
	{
		_value = LowerAllLettersOfWord(_value);
	}

	static string UpperAllLettersOfWord(string sentence)
	{
		for (short i = 0; i < sentence.length(); i++)
		{
			sentence[i] = toupper(sentence[i]);
		}

		return sentence;
	}

	void UpperAllLettersOfWord()
	{
		_value = UpperAllLettersOfWord(_value);
	}

	static string UpperFirstLetterOfEachWord(string sentence)
	{
		bool is_first_letter = true;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && is_first_letter)
			{
				sentence[i] = toupper(sentence[i]);
			}

			is_first_letter = (sentence[i] == ' ') ? true : false;
		}

		return sentence;
	}

	void UpperFirstLetterOfEachWord()
	{
		_value = UpperFirstLetterOfEachWord(_value);
	}

	static string LowerFirstLetterOfEachWord(string sentence)
	{
		bool is_first_letter = true;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && is_first_letter)
			{
				sentence[i] = tolower(sentence[i]);
			}

			is_first_letter = (sentence[i] == ' ') ? true : false;
		}

		return sentence;
	}

	void LowerFirstLetterOfEachWord()
	{
		_value = LowerFirstLetterOfEachWord(_value);
	}

	static char InvertCharacterCase(char character)
	{
		if (isupper(character))
			return tolower(character);
		else
			return toupper(character);
	}

	static string InvertAllStringCharactersCase(string sentence)
	{
		for (int i = 0; i < sentence.length(); i++)
		{
			sentence[i] = InvertCharacterCase(sentence[i]);
		}

		return sentence;
	}

	void InvertAllStringCharactersCase()
	{
		_value = InvertAllStringCharactersCase(_value);
	}

	static short CountUpperLetters(string sentence)
	{
		short counter = 0;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (isupper(sentence[i]))
				counter++;
		}

		return counter;
	}

	short CountUpperLetters()
	{
		return CountUpperLetters(_value);
	}

	static short CountLowerLetters(string sentence)
	{
		short counter = 0;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (islower(sentence[i]))
				counter++;
		}

		return counter;
	}

	short CountLowerLetters()
	{
		return CountLowerLetters(_value);
	}

	static short CountLetter(string sentence, char character, bool match_case = true)
	{
		int counter = 0;

		if (match_case)
		{
			for (int i = 0; i < sentence.length(); i++)
			{
				if (sentence[i] == character)
					counter++;
			}
		}
		else
		{
			for (int i = 0; i < sentence.length(); i++)
			{
				if (tolower(sentence[i]) == tolower(character))
					counter++;
			}
		}

		return counter;
	}

	short CountLetter(char character, bool match_case = true)
	{
		return CountLetter(_value, character, match_case);
	}

	static bool IsVowel(char character)
	{
		character = tolower(character);

		return (character == 'a' || character == 'e' || character == 'i' || character == 'u' || character == 'o');
	}

	static short CountVowels(string sentence)
	{
		short counter = 0;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (IsVowel(sentence[i]))
				counter++;
		}

		return counter;
	}

	short CountVowels()
	{
		return CountVowels(_value);
	}

	static void PrintVowels(string sentence)
	{
		cout << "Vowel Characters: \n";

		for (short i = 0; i < sentence.length(); i++)
		{
			if (IsVowel(sentence[i]))
				cout << sentence[i] << "  ";
		}

		cout << endl;
	}

	void PrintVowels()
	{
		return PrintVowels(_value);
	}

	static void PrintEachWordInString(string sentence)
	{
		string delim = " ";
		string word;

		short pos = 0;

		while ((pos = sentence.find(delim)) != std::string::npos)
		{
			word = sentence.substr(0, pos);

			if (word != "")
				cout << word << endl;

			sentence.erase(0, pos + delim.length());
		}

		if (sentence != "")
			cout << sentence << endl;
	}

	void PrintEachWordInString()
	{
		return PrintEachWordInString(_value);
	}

	static short CountWordsInString(string sentence)
	{
		string delim = " ";
		string word;

		short counter = 0;  // because of last word
		short pos = 0;

		while ((pos = sentence.find(delim)) != std::string::npos)
		{
			word = sentence.substr(0, pos);

			if (word != "")
				counter++;

			sentence.erase(0, pos + delim.length());
		}

		if (sentence != "")
			counter++;

		return counter;
	}

	short CountWordsInString()
	{
		return CountWordsInString(_value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split(string delim)
	{
		return Split(_value, delim);
	}

	static string TrimLeft(string sentence)
	{
		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ')
				return sentence.substr(i, sentence.length() - i);
		}

		return "";
	}

	void TrimLeft()
	{
		_value = TrimLeft(_value);
	}

	static string TrimRight(string sentence)
	{
		for (short i = sentence.length() - 1; i >= 0; i--)
		{
			if (sentence[i] != ' ')
				return sentence.substr(0, i + 1);
		}

		return "";
	}

	void TrimRight()
	{
		_value = TrimRight(_value);
	}

	static string Trim(string sentence)
	{
		return TrimLeft(TrimRight(sentence));
	}

	void Trim()
	{
		_value = Trim(_value);
	}

	static string Join(vector <string>& words, string delim = " ")
	{
		string sentence = "";

		for (string& word : words)
		{
			sentence += word + delim;
		}

		return (sentence.substr(0, sentence.length() - delim.length()));
	}

	static string Join(string arrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string JoinReverseString(vector <string>& words, string delim = " ")
	{
		string sentence = "";

		vector<string>::iterator iter = words.end();

		while (iter != words.begin())
		{
			iter--;
			sentence += *iter + delim;
		}

		return (sentence.substr(0, sentence.length() - delim.length()));
	}

	static string ReverseWordsInString(string sentence)
	{
		vector<string> splitted_string;
		splitted_string = Split(sentence, " ");

		return JoinReverseString(splitted_string);
	}

	void ReverseWordsInString()
	{
		_value = ReverseWordsInString(_value);
	}

	static string ReplaceWords(string sentence, string replaced_word, string replacing_word)
	{
		short pos = sentence.find(replaced_word);

		while (pos != std::string::npos)
		{
			sentence.replace(pos, replaced_word.length(), replacing_word);

			pos = sentence.find(replaced_word);
		}

		return sentence;
	}

	string ReplaceWords(string replaced_word, string replacing_word)
	{
		return ReplaceWords(_value, replaced_word, replacing_word);
	}

	static string RemovePunctuations(string sentence)
	{
		string new_sentence = "";
		for (short i = 0; i < sentence.length(); i++)
		{
			if (!ispunct(sentence[i]))
				new_sentence += sentence[i];
		}

		return new_sentence;
	}

	void RemovePunctuations()
	{
		_value = RemovePunctuations(_value);
	}

};


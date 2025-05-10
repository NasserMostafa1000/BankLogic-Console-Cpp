#pragma once
#include <string>
#include <vector>
using namespace std;
class ClsString
{
private:
	string _Value;

public:

	static vector<string> split(string S1, string Delim)
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

		if (!S1.empty())
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}
	vector <string>splitString(string distance)
	{
		return split(_Value, distance);
	}
	static bool IsVowel(char ch1)
	{
		ch1 = tolower(ch1);
		return ch1 == 'a' || ch1 == 'i' || ch1 == 'u' || ch1 == 'o' || ch1 == 'e';
	}
	static string JoinString(vector<string>joinString, string dilm)

	{
		//تحويل الفيكتور الي جمله استرينج
		//return vector to string
		string sentence = "";
		for (string& n : joinString)
		{
			sentence += n + dilm;
		}
		return sentence.substr(0, sentence.length() - dilm.length());

	}
	static string InvertAllCharOfSentence(string s1)
	{
		//#include <string>
		for (int i = 0; i < s1.length(); i++)
		{
			isupper(s1[i]) ? tolower(s1[i]) : toupper(s1[i]);
		}
		return s1;
	}
	void InvertAllCharOfSentence()
	{
		 _Value= InvertAllCharOfSentence(_Value);
	}
	static string upperAllString(string s1)
	{
		for (char i = 0; i < s1.length(); i++)
		{
			s1[i] = toupper(s1[i]);

		}
		return s1;
	}
	void upperAllString( )
	{
		 _Value=upperAllString(_Value);
	}
	static string lowerAllString(string s1)
	{
		for (char i = 0; i < s1.length(); i++)
		{
			s1[i] = tolower(s1[i]);

		}
		return s1;
	}
	void lowerAllString()
	{
		 _Value=lowerAllString(_Value);
	}
	static string trimRight(string s1)
	{
		for (char i = 0; i < s1.length(); i++) {
			if (s1[i] != ' ') {
				return s1 = s1.substr(i, s1.length());
			}
		}
		return "";

	}
	void trimRight()
	{
		 _Value= trimRight(_Value);

	}
	static string trimLeft(string s1)
	{
		for (char i = s1.length() - 1; i >= 0; i--) {
			if (s1[i] != ' ') {
				return s1 = s1.substr(0, i + 1);
			}
		}
		return "";
	}
	void trimLeft()
	{
		 _Value = trimLeft(_Value);
	}
	static string reverseALlWordsInString(string s1)
	{
		string s2 = "";
		vector<string>vWords = split(s1, " ");
		vector<string>::iterator iter = vWords.end();
		while (iter != vWords.begin()) {
			iter--;
			s2 += *iter + " ";
		}

		return s2 = s2.substr(0, s2.length() - 1);
	}
	void reverseALlWordsInString()
	{
	 	_Value = reverseALlWordsInString(_Value);
	}
	static string trim(string s1) {
		return trimRight(trimLeft(s1));
	}
	void trim() {
		 _Value = trimRight(trimLeft(_Value));
	}
	static string removePunctuation(string s1)
	{
		string s2 = " ";
		for (char i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
			{
				s2 += s1[i];
			}
			else
				s2 += " ";

		}
		return s2;
	}
	void removePunctuation()
	{
		 _Value = removePunctuation(_Value);
	}
	static short countTheVowelLettersOnString(string s1)
	{
		short count = 0;
		for (short  i = 0; i < s1.length(); i++) {
			if (ClsString::IsVowel(s1[i])) {
				count++;
			}
		}
		return count;
	}
	short countTheVowelLettersOnString()
	{
		return countTheVowelLettersOnString(_Value);
	}
	static char convertChar(char s1)
	{
		return isupper(s1) ? tolower(s1) : toupper(s1);
	}
	static string replaceWordOnSentence(string s1, string TheWordWillChange, string dillm, string TheWordToInsert, bool matchCase = true)
	{
		vector<string>vsentence = split(s1, dillm);
		for (string& s : vsentence)
		{
			if (matchCase)
			{
				if (s == TheWordWillChange)
				{
					s = TheWordToInsert;
				}
			}
			else
			{
				if (lowerAllString(s) == lowerAllString(TheWordWillChange))
				{
					s = TheWordToInsert;
				}
			}
		}
		return JoinString(vsentence, dillm);

	}
	void replaceWordOnSentence(string TheWordWillChange, string TheWordToInsert)
	{
		_Value = replaceWordOnSentence(_Value, TheWordWillChange, " ", TheWordToInsert);
	}
	
};


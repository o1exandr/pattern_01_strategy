/*
Завдання 1. Скласти програму, яка буде сортувати контейнер слів різними способами:
o	за алфавітом;
o	за кількістю букв(якщо кількість букв однакові, то першим має йти слово менше за алфавітом)
Використати патерн Стратегія.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

// загальний спосіб вирішення проблеми
class NameStrategy
{
protected:
	vector<string> words = {"car", "true", "cat", "table", "arm", "line", "auto"};
public:
	virtual void sortWords() = 0;
	void print(vector<string> words)
	{
		for (auto elem : words)
			cout << elem << "\t";
		cout << endl;
	}
};

// Конкретні рецепти вирішення
// за алфавітом
class ByAlphabeth : public NameStrategy
{
public:

	void sortWords()
	{
		sort(words.begin(), words.end());
		cout << "By alphabeth:\t";
		print(words);
	}
};

//за довжиною
class ByLength : public NameStrategy
{
public:

	void sortWords()
	{
		sort(words.begin(), words.end(), [](string &str1, string &str2) {if (str1.length() == str2.length()) return str1 < str2; else return str1.length() < str2.length(); });		
		cout << "By length:\t";
		print(words);
	}
};


// Контекст керує стратегією («Посередник»)
// «Стан» - якщо можлива зміна стратегії за життя контексту
class Context
{
private:
	NameStrategy & strategy;
public:
	Context(NameStrategy& strat) : strategy(strat) {}
	void sortWords() { strategy.sortWords(); } 
};

int main()
{
	ByAlphabeth alphabeth;
	ByLength length;

	Context c1(alphabeth), c2(length);
	c1.sortWords();
	c2.sortWords();


	cout << endl;
	system("pause");
	return 0;
}
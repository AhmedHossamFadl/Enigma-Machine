#include "plugBoard.h"

bool plugBoard::validInput(char first,char second)
{
	map<char, char>::iterator itr = board.begin();
	for (itr;itr != board.end();itr++)
	{
		if (first == itr->first || first==itr->second)
			return false;
		if (second == itr->first || second==itr->second)
			return false;
	}
	return true;
}
void plugBoard::setPlugBoard()
{
	cout << "Enter the Plugboard settings (13 Pairs):" << endl;
	char firstLetter, secondLetter;
	for (int i = 0;i < 13;i++)
	{
		cin >> firstLetter >> secondLetter;
		while (!validInput(firstLetter, secondLetter))
		{
			cout << "One of the letters is already paired, input another pair :" << endl;
			cin >> firstLetter >> secondLetter;
		}
		firstLetter = tolower(firstLetter);
		secondLetter = tolower(secondLetter);
		board.insert(make_pair(firstLetter, secondLetter));
	}
}
char plugBoard::swap(char letter)
{
	map<char, char>::iterator itr = board.begin();
	for (itr;itr != board.end();itr++)
	{
		if (letter == itr->first)
			return itr->second;
		if (letter == itr->second)
			return itr->first;
	}
}
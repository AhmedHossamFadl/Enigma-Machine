#include "machine.h"

machine::machine():leftRotor(3),middleRotor(2),rightRotor(1)
{
	fstream read;
	int x, y;
	read.open("Reflector.txt");
	while (!read.eof())
	{
		read >> x >> y;
		reflector.push_back(make_pair(x, y));
	}
	read.close();

	char small, capital;
	int number;
	read.open("LetterToNumbersMap.txt");
	while (!read.eof())
	{
		read >> small >> capital >> number;
		letterToNumberMap.insert(make_pair(make_pair(small, capital), number));
	}
	read.close();
	cout << "Please enter the rotor positions from left to right separated by a comma : " << endl;
	int firstPos, secondPos, thirdPos;
	char comma;
	cin >> firstPos >> comma >> secondPos >> comma >> thirdPos;
	leftRotor.setRotorPosition(firstPos);
	middleRotor.setRotorPosition(secondPos);
	rightRotor.setRotorPosition(thirdPos);
	system("cls");
	PlugBoard.setPlugBoard();
	system("cls");
}
void machine::rotateRotors()
{
	rightRotor.rotate();
	if (rightRotor.position() == 1)
	{	
		middleRotor.rotate();
		if (middleRotor.position() == 1)
		{
			leftRotor.rotate();
		}
	}
}
char machine::encrypt_decrypt(char letter)
{
	char outputLetter;
	int outputLetterNum;
	outputLetter = tolower(letter);
	outputLetter = PlugBoard.swap(letter);
	outputLetterNum = switchToNumber(outputLetter);
	outputLetterNum = passOnRotors(outputLetterNum);
	outputLetter = switchToLetter(outputLetterNum);
	outputLetter = PlugBoard.swap(outputLetter);
	rotateRotors();
	return outputLetter;
}
int machine::switchToNumber(char letter)
{
	map< pair<char, char>, int > ::iterator itr = letterToNumberMap.begin();
	for (itr;itr != letterToNumberMap.end();itr++)
	{
		if (itr->first.first == letter || itr->first.second == letter)
			return itr->second;
	}
}
char machine::switchToLetter(int letter)
{
	map< pair<char, char>, int > ::iterator itr = letterToNumberMap.begin();
	for (itr;itr != letterToNumberMap.end();itr++)
	{
		if (itr->second==letter)
			return itr->first.first;
	}
}
int machine::passOnReflector(int letter)
{
	vector< pair<int, int> > ::iterator itr = reflector.begin();
	for (itr;itr != reflector.end();itr++)
	{
		if (itr->first == letter)
			return itr->second;
		if (itr->second == letter)
			return itr->first;
	}
}
int machine::passOnRotors(int letter)
{
	letter = rightRotor.returnConnected(letter);
	letter = middleRotor.returnConnected(letter);
	letter = leftRotor.returnConnected(letter);
	letter = passOnReflector(letter);
	letter = leftRotor.returnConnectedReversed(letter);
	letter = middleRotor.returnConnectedReversed(letter);
	letter = rightRotor.returnConnectedReversed(letter);
	return letter;
}

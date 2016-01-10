#include "rotor.h"

rotor::rotor(int rotorNumber)
{
	rotorPosition = 0;
	fstream read;
	int x, y;
	if (rotorNumber == 1)
		read.open("FirstRotor.txt");
	else if (rotorNumber == 2)
		read.open("SecondRotor.txt");
	else if (rotorNumber == 3)
		read.open("ThirdRotor.txt");
	while(!read.eof())
	{	
		read >> x >> y;
		wiring.push_back(make_pair(x, y));
	}
	read.close();
}
int rotor::position()
{
	return rotorPosition;
}
void rotor::rotate()
{
	vector< pair <int, int> >::iterator itr = wiring.begin();
	for (itr;itr != wiring.end();itr++)
	{
		if (itr->first == 26 && itr->second == 26)
		{
			itr->first = 1;
			itr->second = 1;
			continue;
		}
		if (itr->first == 26)
		{
			itr->first = 1;
			itr->second++;
			continue;
		}
		if (itr->second == 26)
		{
			itr->second = 1;
			itr->first++;
			continue;
		}
		itr->first++;
		itr->second++;
	}
	rotorPosition++;
	if (rotorPosition == 27)
		rotorPosition = 1;

	cout << rotorPosition << endl;
}
void rotor::setRotorPosition(int position)
{
	for (int i = 1;i <= position;i++)
		rotate();
}
int rotor::returnConnected(int letter)
{
	vector< pair <int, int> >::iterator itr = wiring.begin();
	for (itr;itr != wiring.end();itr++)
	{
		if (itr->first == letter)
			return itr->second;
	}
}
int rotor::returnConnectedReversed(int letter)
{
	vector< pair <int, int> >::iterator itr = wiring.begin();
	for (itr;itr != wiring.end();itr++)
	{
		if (itr->second == letter)
			return itr->first;
	}
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <fstream>
#include "rotor.h"
#include "plugBoard.h"

using namespace std;

class machine
{
	vector< pair<int, int> > reflector;
	map< pair<char, char>, int > letterToNumberMap;
	plugBoard PlugBoard;
	rotor leftRotor, middleRotor, rightRotor;
	int switchToNumber(char);
	char switchToLetter(int);
	int passOnRotors(int);
	int passOnReflector(int);
	void rotateRotors();
public:
	machine();
	char encrypt_decrypt(char);
};


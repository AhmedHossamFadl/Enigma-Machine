#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

class plugBoard
{
	map<char, char> board;
public:
	void setPlugBoard();
	bool validInput(char,char);
	char swap(char);
};


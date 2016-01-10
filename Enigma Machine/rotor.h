#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <fstream>


using namespace std;

class rotor
{
	vector< pair<int, int> > wiring;
	int rotorPosition;
public:
	rotor(int);
	void setRotorPosition(int);
	int returnConnected(int);
	int returnConnectedReversed(int);
	int position();
	void rotate();
};

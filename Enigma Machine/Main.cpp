#include "machine.h"
int main()
{
	machine Enigma;
	string s, q;
	cin.ignore();
	getline(cin, s);
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == ' ')
		{
			q += s[i];
			continue;
		}
		q+= Enigma.encrypt_decrypt(s[i]);
	}
	cout << q << endl;
	s = "";
	q = "";
	cin.ignore();
	getline(cin, s);
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == ' ')
		{
			q += s[i];
			continue;
		}
		q += Enigma.encrypt_decrypt(s[i]);
	}
	cout << q << endl;
}

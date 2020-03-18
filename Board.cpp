#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char cha1 = '1';
char cha2 = 'A';

bool oddeven(int x)
{
	if(x%2 != 0) return true;
	else return false;
}

bool space(int x, int y)
{
	if((x%5 == 1 || x%5 == 2 || x%5 == 3 || x%5 ==4) && oddeven(y)) return true;
	else return false;
}

void makeBoard()
{
	cout << "     ";
	for(int k=0; k<8; k++)
	{
		cout << cha2 << "    ";
		cha2++;
	}
	cout << endl;
	for(int i=0; i<17; i++)
	{
		cout << " ";
		if(oddeven(i))
		{
			cout << cha1;
			cha1++;
		}
		else cout << " ";
		cout << " ";
		for(int j=0; j<41; j++)
		{
			if (space(j, i)) cout << " ";
			else cout << "Ø";
		}
		cout << endl;
	}
}

int main()
{
	makeBoard();
}
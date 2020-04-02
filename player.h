#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class Player{
	public:
		int number;
		vector<int*> ptr;
		
		Player(int);
		bool checkWhoPieces(string);
		
};

Player::Player(int n){
	number = n; 
}

bool Player::checkWhoPieces(string C){ //A-H [][0-7], 1-8 [7-0][]
	int temp = int(toupper(C[0]))-65 ;
	int temp2 = (49-int(C[1]))+7;
	int *ptr = NULL;
}

//bool checkMove()

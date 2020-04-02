#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

class Player{
	public:
		int number;
		vector<int*> ptr;
		Player(int);
};

Player::Player(int n){
	number = n; 
}

//bool checkWhoPieces()

//bool checkMove()

#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Player{
	public:
		int number;
		vector<int*> ptr;
		
		Player(int);
		bool checkWhoPieces(string,int [][8]);
		bool checkmove(string,string,int);
};

Player::Player(int n){
	number = n; 
}

bool Player::checkWhoPieces(string C,int B[][8]){ //A-H [][0-7], 1-8 [7-0][]
	int temp2 = int(toupper(C[0]))-65 ;
	int temp = (49-int(C[1]))+7;
	int *P = &B[temp][temp2];
	vector<int*>::iterator it; 
	it = find(ptr.begin(),ptr.end(),P);
	if (it != ptr.end()){
    	cout << "Element found in myvector: " << *it << "\n"; //? test
    	return true;
	}else{
    	cout << "Element not found in myvector\n";//? test 
		return false;
	} 
	
}

//bool checkMove()
/*bool Player::checkmove(string com,int board[][8]){
	
	//pawn
	if(board[com[0]-45][com[1]])
    

}*/

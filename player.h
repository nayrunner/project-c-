#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Player{
	public:
		int number;
		vector<int*> ptr;
		
		Player(int);
		bool checkWhoPieces(string,int [][8]);
		bool checkmove(string,string,int);
        bool checkblock(string,string,int ,int [][8]);
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
    	return true;
	}else{
		return false;
	} 	
}


bool Player::checkmove(string move,string com,int pieces){
//   cout<<pieces<<"\nmove[0] is "<<move[0]<<"\ncom[0] is "<<com[0]<<"\nmove[1] is "<<move[1]<<"\ncom[1] is "<<com[1]<<"\n";

    if(move == com){return false;}
    // move(0) = แถว , move(1)= บรรทัด

	//* Rook R (เรือ)
/*
   -2   -1   0    +1   +2
===========================
||   ||   || * ||   ||   || -2
===========================
||   ||   || * ||   ||   || -1
===========================
|| * || * || N || * || * ||  0
===========================
||   ||   || * ||   ||   || +1
===========================
||   ||   || * ||   ||   || +2
===========================
*/
	if(pieces == 1){
		if(move[0]== com[0]){return true;} //? if same columb = true
		else{if(move[1] == com[1]){return true;} // if? not same columb but same row = true
		     else {return false;}	}	}
    if(pieces == -1){
		if(move[0]== com[0]){return true;}
		else{if(move[1] == com[1]){return true;}
		     else {return false;}	}	}
	
	//*Knight N (ม้า)
/*
   -2   -1   0    +1   +2
===========================
||   || 1 ||   || 5 ||   || -2
===========================
|| 3 ||   ||   ||   || 7 || -1
===========================
||   ||   || N ||   ||   ||  0
===========================
|| 4 ||   ||   ||   || 8 || +1
===========================
||   || 2 ||   || 6 ||   || +2
===========================
*/
//? com[0] = columb , com[1] = row
	if (pieces == 2){
		if( move[0]== (com[0]-1) && move[1] == (com[1]-2) ){return true;}  //pos 1
		else{if( move[0]== (com[0]-1) && move[1] == (com[1]+2) ){return true;} //pos 2
		     else{if( move[0]== (com[0]-2) && move[1] == (com[1]-1) ){return true;} //pos 3
			      else{if( move[0]== (com[0]-2) && move[1] == (com[1]+1) ){return true;} //pos 4
				       else{if( move[0]== (com[0]+1) && move[1] == (com[1]-2) ){return true;} //pos 5
					        else{if( move[0]== (com[0]+1) && move[1] == (com[1]+2) ){return true;}//pos 6
							     else{if( move[0]== (com[0]+2) && move[1] == (com[1]-1) ){return true;}//pos 7
								      else{if( move[0]== (com[0]+2) && move[1] == (com[1]+1) ){return true;}//pos 8
									       else{return false;}}}}}}}}
	}
    if (pieces == -2){
		if( move[0]== (com[0]-1) && move[1] == (com[1]-2) ){return true;}
		else{if( move[0]== (com[0]-1) && move[1] == (com[1]+2) ){return true;}
		     else{if( move[0]== (com[0]-2) && move[1] == (com[1]-1) ){return true;}
			      else{if( move[0]== (com[0]-2) && move[1] == (com[1]+1) ){return true;}
				       else{if( move[0]== (com[0]+1) && move[1] == (com[1]-2) ){return true;}
					        else{if( move[0]== (com[0]+1) && move[1] == (com[1]+2) ){return true;}
							     else{if( move[0]== (com[0]+2) && move[1] == (com[1]-1) ){return true;}
								      else{if( move[0]== (com[0]+2) && move[1] == (com[1]+1) ){return true;}
									       else{return false;}}}}}}}}
	}
    
    //*Bishop B (โคน)
/*
   -2   -1   0    +1   +2
===========================
||   ||   ||   ||   ||   || -2
===========================
||   || * || * || * ||   || -1
===========================
||   ||   || B ||   ||   ||  0
===========================
||   || * ||   || * ||   || +1
===========================
||   ||   ||   ||   ||   || +2
===========================
*/
if(pieces == 3){ //Player 1
        if( move[1] == (com[1]+1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) ){return true;}
        else{
            if(move[1] == (com[1]-1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) && move[0] != com[0] ){return true;}
            else{return false;}
        }
    }   
    if(pieces == -3){ //Player 2
        if( move[1] == (com[1]-1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) ){return true;}
        else{
            if(move[1] == (com[1]+1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) && move[0] != com[0] ){return true;}
            else{return false;}
        }
    }

    //*Queen Q (เม็ด)
/*
   -2   -1   0    +1   +2
===========================
||   ||   ||   ||   ||   || -2
===========================
||   || * ||   || * ||   || -1
===========================
||   ||   || Q ||   ||   ||  0
===========================
||   || * ||   || * ||   || +1
===========================
||   ||   ||   ||   ||   || +2
===========================
*/
    if(pieces == 4){
        if( move[0] == com[0]+1 || move[0] == com[0]-1 ){
            if( move[1] == com[1]+1 || move[1] == com[1]-1){return true;}
            else{return false;}
        }else{return false;}
    }
    if(pieces == -4){
        if( move[0] == com[0]+1 || move[0] == com[0]-1 ){
            if( move[1] == com[1]+1 || move[1] == com[1]-1){return true;}
            else{return false;}
        }else{return false;}
    }

    //*King K (ขุน)
/*
   -2   -1   0    +1   +2
===========================
||   ||   ||   ||   ||   || -2
===========================
||   || * || * || * ||   || -1
===========================
||   || * || K || * ||   ||  0
===========================
||   || * || * || * ||   || +1
===========================
||   ||   ||   ||   ||   || +2
===========================
*/
    if(pieces == 5){
        if( move[0] == com[0] || move[0] == com[0]+1 || move[0] == com[0]-1){
            if( move[1] == com[1] || move[1] == com[1]+1 || move[1] == com[1]-1){return true;}
            else{return false;}
        }else{return false;}
    }
    if(pieces == -5){
        if( move[0] == com[0] || move[0] == com[0]+1 || move[0] == com[0]-1){
            if( move[1] == com[1] || move[1] == com[1]+1 || move[1] == com[1]-1){return true;}
            else{return false;}
        }else{return false;}
    }

    //*Pawn P (เบี้ย)
/*
   -2   -1   0    +1   +2
===========================
||   ||   ||   ||   ||   || -2
===========================
||   || X || * || X ||   || -1
===========================
||   ||   || P ||   ||   ||  0
===========================
||   ||   ||   ||   ||   || +1
===========================
||   ||   ||   ||   ||   || +2
===========================
*/
    if(pieces == 6){
        if(move[0] == com[0]){
            if(move[1] == com[1]+1) return true;
            else return false;
        }else{return false;}
    }
    if(pieces == -6){
        if(move[0] == com[0]){
            if(move[1] == com[1]-1) return true;
            else return false;
        }else{return false;}
    }

    //* Flipped F (เบี้ยหงาย)
/*
   -2   -1   0    +1   +2
===========================
||   ||   ||   ||   ||   || -2
===========================
||   || * ||   || * ||   || -1
===========================
||   ||   || F ||   ||   ||  0
===========================
||   || * ||   || * ||   || +1
===========================
||   ||   ||   ||   ||   || +2
===========================
*/
    if(pieces == 7){
        if( move[0] == com[0]+1 || move[0] == com[0]-1 ){
            if( move[1] == com[1]+1 || move[1] == com[1]-1){return true;}
            else{return false;}
        }else{return false;}
    }
    if(pieces == -7){
        if( move[0] == com[0]+1 || move[0] == com[0]-1 ){
            if( move[1] == com[1]+1 || move[1] == com[1]-1){return true;}
            else{return false;}
        }else{return false;}
    }
}

bool Player::checkblock(string com,string move,int pieces,int B[][8]){
    //for rook//
    if(pieces==1){
    if(move[1]>com[1]){
    for(int i = 0;i<move[1]-com[1];i++){
    int x = int(toupper(move[0]))-65 ;
	int y = (49-int(move[1]))+7+i;
	int *board = &B[y][x];
	vector<int*>::iterator check; 
	check = find(ptr.begin(),ptr.end(),board);
	if (*check != board || *check == 0){
    	
	}else{
		return false;
	}}
    }else{for(int i = 0;i<com[1]-move[1];i++){
    int x = int(toupper(move[0]))-65 ;
	int y = (49-int(move[1]))+7-i;
	int *board = &B[y][x];
	vector<int*>::iterator check; 
	check = find(ptr.begin(),ptr.end(),board);
	if (*check != board || *check == 0){
    	
	}else{
		return false;
	}}
    }
    
    if(move[0]>com[0]){
    for(int i = 0;i<move[0]-com[0];i++){
    int x = int(toupper(move[0]))-65+i ;
	int y = (49-int(move[1]))+7;
	int *board = &B[y][x];
	vector<int*>::iterator check; 
	check = find(ptr.begin(),ptr.end(),board);
	if (*check != board || *check == 0){
    	
	}else{
		return false;
	}}
    }else{for(int i = 0;i<com[0]-move[0];i++){
    int x = int(toupper(move[0]))-65-i ;
	int y = (49-int(move[1]))+7;
	int *board = &B[y][x];
	vector<int*>::iterator check; 
	check = find(ptr.begin(),ptr.end(),board);
	if (*check != board || *check == 0){
    	
	}else{
		return false;
	}}
    }
    return true;
    }
    
    //for others
    else
    {
    int x = int(toupper(move[0]))-65 ;
	int y = (49-int(move[1]))+7;
	int *board = &B[y][x];
	vector<int*>::iterator check; 
	check = find(ptr.begin(),ptr.end(),board);
	if (*check != board || *check == 0){
    	return true;
	}else{
		return false;
	} 
    }
    
}

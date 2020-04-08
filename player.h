#include<iostream>
#include<string>
#include<vector>
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
    	//cout << "Element found in myvector: " << *it << "\n"; //? test
    	return true;
	}else{
    	//cout << "Element not found in myvector\n";//? test
		return false;
	} 
	
}

bool Player::checkmove(string move,string com,int pieces){
   
    if(move == com){return false;}
    // move(0) = แถว , move(1)= บรรทัด

	//*Rook R (เรือ)
	if(pieces == 1){
		if(move[0]== com[0]){return true;}
		else{if(move[1] == com[1]){return true;}
		     else {return false;}	}	}
    if(pieces == -1){
		if(move[0]== com[0]){return true;}
		else{if(move[1] == com[1]){return true;}
		     else {return false;}	}	}
	
	//*Knight N (ม้า)
	if (pieces == 2){
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
    if(pieces == 3){
        if( move[1] == (com[1]-1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) ){return true;}
        else{
            if(move[1] == (com[1]+1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) && move[0] != com[0] ){return true;}
            else{return false;}
        }
    }   
    if(pieces == -3){
        if( move[1] == (com[1]+1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) ){return true;}
        else{
            if(move[1] == (com[1]-1) && move[0] <= (com[0]+1) && move[0] >= (com[0]-1) && move[0] != com[0] ){return true;}
            else{return false;}
        }
    }

    //*Queen Q (เม็ด)
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
    if(pieces == 6){
        if(move[0] == com[0]){
            if(move[1] == com[1]-1) return true;
            else return false;
        }else{return false;}
    }
    if(pieces == -6){
        if(move[0] == com[0]){
            if(move[1] == com[1]+1) return true;
            else return false;
        }else{return false;}
    }

    //* Flipped F (เบี้ยหงาย)
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

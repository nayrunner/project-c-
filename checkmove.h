#include"player.h"

bool Player::checkmove(string move,string com,int pieces){
    if(move == com){return false;}

	//rook
	if(pieces == 1){
		if(move[0]== com[0]){return true;}
		else{if(move[1] == com[1]){return true;}
		     else {return false;}	}	}
    if(pieces == -1){
		if(move[0]== com[0]){return true;}
		else{if(move[1] == com[1]){return true;}
		     else {return false;}	}	}
	
	//knight
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
	

}
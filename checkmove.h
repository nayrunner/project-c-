bool Player::checkmove(string move,string com,int pieces){
	
	cout<< pieces <<com[0]<<com[1];
    

    if(move == com){return false;}
    // move(0) = แถว , move(1)= บรรทัด

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
    
    //bishop
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

    //queen
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

    //king
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

    //pawn
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
}
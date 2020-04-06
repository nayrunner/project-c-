bool Player::checkmove(string move,string com,int pieces){
	
	cout<< pieces <<com[0]<<com[1];
    

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
	
	//*Knight N (ม้า) (ที่ไม่เอาไว้ดูด)
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
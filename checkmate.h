bool checkmate(int P,int b[][8]){
	int check=0;
	
	//player2's turn check all player1's pieces
	if(P==1){
		int check=0;
	for (int columb = 0; columb < 8; columb++)
	{
		for(int row = 0; row < 8; row++)
		{
			//ม้า
			if(b[row][columb]==2){
				if( b[row-2][columb-1] == -5 ||  b[row-1][columb-2] == -5 || b[row+2][columb+1] == -5 || b[row+1][columb+2] == -5 || b[row+2][columb-1] == -5 || b[row-1][columb+2] == -5 ||  b[row-2][columb+1] == -5 || b[row+1][columb-2] == -5 ){
					check = 1;
				}
			}

			//โคน
			if(b[row][columb]==3){
				if( b[row-1][columb-1] == -5 || b[row-1][columb] == -5 || b[row-1][columb+1] == -5 || b[row+1][columb-1] == -5 ||  b[row+1][columb+1] == -5 ){
					check = 1;
				}
			}

			//เม็ด
			if(b[row][columb]==4){
				if( b[row-1][columb-1] == -5 || b[row-1][columb+1] == -5 || b[row+1][columb-1] == -5 || b[row+1][columb+1] == -5 ){
					check = 1;
				}
			}

			//ขุน
			if(b[row][columb]==5){
				if( b[row-1][columb-1] == -5 || b[row-1][columb] == -5 || b[row-1][columb+1] == -5 || b[row][columb-1] == -5 || b[row][columb+1] == -5 || b[row+1][columb-1] == -5 || b[row+1][columb] == -5 || b[row+1][columb+1] == -5 ){
					check = 1;
				}
			}

			//เบี้ยควํ่า
			if(b[row][columb]==6){
				if( b[row-1][columb-1] == -5 || b[row-1][columb] == -5 || b[row-1][columb+1] == -5 ){
					check = 1;
				}
			}

			//เบี้ยหงาย
			if(b[row][columb]==7){
				if( b[row-1][columb-1] == -5 || b[row-1][columb+1] == -5 || b[row+1][columb-1] == -5 || b[row+1][columb+1] == -5 ){
					check = 1;
				}
			}

			//เรือ
			if(b[row][columb]==1){
				//ขวา
				for(int i=0;i<8;i++){
					if(b[row][columb+i] != -5 && b[row][columb+i] != 0){break;}
					else{if(b[row][columb+i]==-5){check = 1;}}
				}
				//ซ้าย
				for(int i=0;i<8;i++){
					if(b[row][columb-i] != -5 && b[row][columb-i] != 0){break;}
					else{if(b[row][columb-i]==-5){check = 1;}}
				}
			    //บน
				for(int i=0;i<8;i++){
					if(b[row+i][columb] != -5 && b[row+i][columb] != 0 ){break;}
					else{if(b[row+i][columb]==-5){check = 1;}}
				}
				//ล่าง
				for(int i=0;i<8;i++){
					if(b[row-i][columb] != -5 && b[row-i][columb] != 0 ){break;}
					else{if(b[row-i][columb]==-5){check = 1;}}
				}
			}


		}
	}
	}
	
	//player1's turn check all player2's pieces
	if(P==2){
		int check=0;
	for (int columb = 0; columb < 8; columb++)
	{
		for(int row = 0; row < 8; row++)
		{
			//ม้า
			if(b[row][columb]==-2){
				if( b[row-2][columb-1] == 5 ||  b[row-1][columb-2] == 5 || b[row+2][columb+1] == 5 || b[row+1][columb+2] == 5 || b[row+2][columb-1] == 5 || b[row-1][columb+2] == 5 ||  b[row-2][columb+1] == 5 || b[row+1][columb-2] == 5 ){
					check = 1;
				}
			}

			//โคน
			if(b[row][columb]==-3){
				if( b[row+1][columb-1] == 5 || b[row+1][columb] == 5 || b[row+1][columb+1] == 5 || b[row-1][columb-1] == 5 ||  b[row-1][columb+1] == 5 ){
					check = 1;
				}
			}

			//เม็ด
			if(b[row][columb]==-4){
				if( b[row-1][columb-1] == 5 || b[row-1][columb+1] == 5 || b[row+1][columb-1] == 5 || b[row+1][columb+1] == 5 ){
					check = 1;
				}
			}

			//ขุน
			if(b[row][columb]==-5){
				if( b[row-1][columb-1] == 5 || b[row-1][columb] == 5 || b[row-1][columb+1] == 5 || b[row][columb-1] == 5 || b[row][columb+1] == 5 || b[row+1][columb-1] == 5 || b[row+1][columb] == 5 || b[row+1][columb+1] == 5 ){
					check = 1;
				}
			}

			//เบี้ยควํ่า
			if(b[row][columb]==-6){
				if( b[row+1][columb-1] == 5 || b[row+1][columb] == 5 || b[row+1][columb+1] == 5 ){
					check = 1;
				}
			}

			//เบี้ยหงาย
			if(b[row][columb]==-7){
				if( b[row-1][columb-1] == 5 || b[row-1][columb+1] == 5 || b[row+1][columb-1] == 5 || b[row+1][columb+1] == 5 ){
					check = 1;
				}
			}

			//เรือ
			if(b[row][columb]==-1){
				//ขวา
				for(int i=0;i<8;i++){
					if(b[row][columb+i] != 5 && b[row][columb+i] != 0){break;}
					else{if(b[row][columb+i]==5){check = 1;}}
				}
				//ซ้าย
				for(int i=0;i<8;i++){
					if(b[row][columb-i] != 5 && b[row][columb-i] != 0){break;}
					else{if(b[row][columb-i]==5){check = 1;}}
				}
			    //บน
				for(int i=0;i<8;i++){
					if(b[row+i][columb] != 5 && b[row+i][columb] != 0 ){break;}
					else{if(b[row+i][columb]==5){check = 1;}}
				}
				//ล่าง
				for(int i=0;i<8;i++){
					if(b[row-i][columb] != 5 && b[row-i][columb] != 0 ){break;}
					else{if(b[row-i][columb]==5){check = 1;}}
				}
			}


		}
	}
	}
	
	if(check == 1){return false;}
	else
	{
		return true ;
	}
	
}
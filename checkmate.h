bool checkmate(int P,int b[][8]){
	if(P==1){
	for (int columb = 0; columb < 8; columb++)
	{
		for(int row = 0; row < 8; row++)
		{
			//ม้า
			if(b[row][columb]==2){
				if( b[row-2][columb-1] == -5 ||  b[row-1][columb-2] == -5 || b[row+2][columb+1] == -5 || b[row+1][columb+2] == -5 || b[row+2][columb-1] == -5 || b[row-1][columb+2] == -5 ||  b[row-2][columb+1] == -5 || b[row+1][columb-2] == -5 ){
					return false;
				}
			}

			//เม็ด
			
		}
	}
	}
	
}
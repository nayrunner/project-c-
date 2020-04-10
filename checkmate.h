int x = int(toupper(move[0]))-65 ;
	int y = (49-int(move[1]))+7;
	int *board = &B[y][x];
	vector<int*>::iterator check; 
	check = find(ptr.begin(),ptr.end(),board);
	if (*check != board || *check == 0){
    	//cout << "Element found in myvector: " << **check << "\n"; //? test
    	return true;
	}else{
    	//cout << "Element not found in myvector"<< zptr.end() << "\n";//? test
		return false;
	} 

|| P.checkblock(com,move,B[row][columb],B)== false
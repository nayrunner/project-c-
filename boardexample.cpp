#include<iostream>
using namespace std;

void makeLine();
void insertPiece(int [][8]);
void makeBoard(int [][8]);
char NtoP(int);

int main(){
	int board[8][8] = {
		-1,-2,-3,-4,-5,-3,-2,-1,
		 0, 0, 0, 0, 0, 0, 0, 0,
		-6,-6,-6,-6,-6,-6,-6,-6,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 6, 6, 6, 6, 6, 6, 6, 6,
		 0, 0, 0, 0, 0, 0, 0, 0,
		 1, 2, 3, 5, 4, 3, 2, 1,
	};
	makeBoard(board);
/*
	cout << "\n";
	cout << "      A    B    C    D    E    F    G    H   \n";
	cout << "   ==========================================\n";
	cout << " 8 || R || N || B || Q || K || B || N || R ||\n";
	cout << "   ==========================================\n";
	cout << " 7 ||   ||   ||   ||   ||   ||   ||   ||   ||\n";
	cout << "   ==========================================\n";
	cout << " 6 || P || P || P || P || P || P || P || P ||\n";
	cout << "   ==========================================\n";
	cout << " 5 ||   ||   ||   ||   ||   ||   ||   ||   ||\n";
	cout << "   ==========================================\n";
	cout << " 4 ||   ||   ||   ||   ||   ||   ||   ||   ||\n";
	cout << "   ==========================================\n";
	cout << " 3 || p || p || p || p || p || p || p || p ||\n";
	cout << "   ==========================================\n";
	cout << " 2 ||   ||   ||   ||   ||   ||   ||   ||   ||\n";
	cout << "   ==========================================\n";
	cout << " 1 || r || n || b || k || q || b || n || r ||\n";
	cout << "   ==========================================\n";
*/
	
}

/* function */ 
void makeLine(){
		cout << "   =========================================\n";
	}

void insertPiece(int B[][8]){ 	//! i is row , j is columb
	int count = 8;
	for(int i = 0; i < 8 ; i++){
		cout << count;
		for(int j = 0;j < 8; j++){
			cout << " || " << NtoP(B[i][j]);
		}
		cout << " ||";
		count--;
		cout << "\n";
		makeLine();
	}
}

void makeBoard(int B[][8]){
	cout << "     A    B    C    D    E    F    G    H   \n";
	makeLine();
	insertPiece(B);
}

char NtoP(int N) {  //TODO NtoP is Number to Pieces
	switch(N){
		/*Player 2*/
		case -1: return 'r'; break; 
		case -2: return 'n'; break;
		case -3: return 'b'; break;
		case -4: return 'q'; break;
		case -5: return 'k'; break;
		case -6: return 'p'; break;
		case -7: return 'f'; break;
		/*Player 1*/
		case 1: return 'R'; break;
		case 2: return 'N'; break;
		case 3: return 'B'; break;
		case 4: return 'Q'; break; 
		case 5: return 'K'; break;
		case 6: return 'P'; break;
		case 7: return 'F'; break;
		default: return ' '; break;
	}
}

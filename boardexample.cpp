#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Player{
	public:
		int number;
		vector<int*> Pptr;
		Player(int);
};

void makeLine();
void insertPiece(int [][8]);
void drawBoard(int [][8]);
char NtoP(int);
void Initial(int [][8],int,Player);

int main(){
	int board[8][8] = {
	/*   0  1  2  3  4  5  6  7  */
  /*0*/	-1,-2,-3,-4,-5,-3,-2,-1, 
  /*1*/	 0, 0, 0, 0, 0, 0, 0, 0,
  /*2*/	-6,-6,-6,-6,-6,-6,-6,-6,
  /*3*/	 0, 0, 0, 0, 0, 0, 0, 0,
  /*4*/	 0, 0, 0, 0, 0, 0, 0, 0,
  /*5*/	 6, 6, 6, 6, 6, 6, 6, 6,
  /*6*/	 0, 0, 0, 0, 0, 0, 0, 0,
  /*7*/	 1, 2, 3, 5, 4, 3, 2, 1,
	};
	
	Player p1(1); Player p2(2);
	int turn = 0;
	
	while(true){
		string comd1,comd2;
		drawBoard(board);
		cout << "Input Player 1 command: ";
		getline(cin,comd1);
		cout << "Input Player 2 command: ";
		getline(cin,comd2);
		turn++;
	}
	
}

/* function */ 
Player::Player(int n){
	number = n; 
}

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

void drawBoard(int B[][8]){
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

void Initial(int B[][8],int r,Player p){
	for(int j = 0;j < 8;j++) p.Pptr.push_back(&B[r][j]);
}


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

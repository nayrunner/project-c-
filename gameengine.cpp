#include"player.h"
#include"startmenu.h"
#include"how2play.h"
#include"checkmate.h"
using namespace std;

void makeLine();
void insertPiece(int [][8]);
void drawBoard(int [][8]);
char NtoP(int);
bool checkIsLegit(string);
void inputCommand(Player &,Player &,int [][8],bool &);
int TranslateCom(string);
void Move(string,string,Player &,Player &,int [][8]);
bool isLose(Player);

void testPtr(Player);	//! DebugFunction NOT-IN-FINAL-VERSION
void testAddress(int [][8]); //! DebugFunction NOT-IN-FINAL-VERSION



int main()
{   //start manu
    char command;
    grandopening();
    while(true){
        cout << "Type your command: ";
        cin >> command;
        command = toupper(command);
        //if ('P')
        if(command == 'P'){
			cout<<"\n====================================================\n\n";
            break;
        }
        //else if('H')
        if(command == 'H'){tutorial();
        grandopening();}
    }
    //game start

	int board[8][8] = {
//!	     A  B  C  D  E  F  G  H  
	/*   0  1  2  3  4  5  6  7  */
  /*0*/	-1,-2,-3,-4,-5,-3,-2,-1, //! 8
  /*1*/	 0, 0, 0, 0, 0, 0, 0, 0, //! 7
  /*2*/	-6,-6,-6,-6,-6,-6,-6,-6, //! 6
  /*3*/	 0, 0, 0, 0, 0, 0, 0, 0, //! 5
  /*4*/	 0, 0, 0, 0, 0, 0, 0, 0, //! 4
  /*5*/	 6, 6, 6, 6, 6, 6, 6, 6, //! 3
  /*6*/	 0, 0, 0, 0, 0, 0, 0, 0, //! 2 
  /*7*/	 1, 2, 3, 5, 4, 3, 2, 1, //! 1
	};
	
	Player p1(1); Player p2(2);
	/*line 1*/
	p1.ptr.push_back(&board[7][0]);
	p1.ptr.push_back(&board[7][1]); 
	p1.ptr.push_back(&board[7][2]);
	p1.ptr.push_back(&board[7][3]);
	p1.ptr.push_back(&board[7][4]);
	p1.ptr.push_back(&board[7][5]);
	p1.ptr.push_back(&board[7][6]);
	p1.ptr.push_back(&board[7][7]);
	/*line 3*/
	p1.ptr.push_back(&board[5][0]);
	p1.ptr.push_back(&board[5][1]);
	p1.ptr.push_back(&board[5][2]);
	p1.ptr.push_back(&board[5][3]);
	p1.ptr.push_back(&board[5][4]);
	p1.ptr.push_back(&board[5][5]);
	p1.ptr.push_back(&board[5][6]);
	p1.ptr.push_back(&board[5][7]);
	/* line 8*/
	p2.ptr.push_back(&board[0][0]);
	p2.ptr.push_back(&board[0][1]);
	p2.ptr.push_back(&board[0][2]);
	p2.ptr.push_back(&board[0][3]);
	p2.ptr.push_back(&board[0][4]);
	p2.ptr.push_back(&board[0][5]);
	p2.ptr.push_back(&board[0][6]);
	p2.ptr.push_back(&board[0][7]);
	/* line 6*/
	p2.ptr.push_back(&board[2][0]);
	p2.ptr.push_back(&board[2][1]);
	p2.ptr.push_back(&board[2][2]);
	p2.ptr.push_back(&board[2][3]);
	p2.ptr.push_back(&board[2][4]);
	p2.ptr.push_back(&board[2][5]);
	p2.ptr.push_back(&board[2][6]);
	p2.ptr.push_back(&board[2][7]);
	
	//testAddress(board); //debugFunc
	//testPtr(p1); //debugFunc
	bool Turn = true; //TODO if false=player2,true=player1
	while(true){
		drawBoard(board);
		if(Turn){ //player1
			if(isLose(p1)) {
				break;
				cout << "Player 2 WINS !!!\n";	
			}
			if(checkmate(2,board)==false){
				cout<<"Your king can be eaten.\n";
			}
			inputCommand(p1,p2,board,Turn);
		}else{ //player2
			if(isLose(p2)){
				break;
				cout << "Player 1 WINS !!!\n";
			}
			if(checkmate(1,board)==false){
				cout<<"Your king can be eaten.\n";
			}
			inputCommand(p2,p1,board,Turn);
		}
	}
	
}

//* Function *//

void makeLine(){
		cout << "   =========================================\n";
	}

void insertPiece(int B[][8]){ 	//? i is row , j is column
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

bool checkIsLegit(string s){
	if(s.size() == 2){
		int temp = int(toupper(s[0]));
		int temp2 = int(s[1]);
		if(temp >= 65 && temp <= 72){ //? ASCII A = 65 ,H = 72
			if(temp2 >= 49 && temp2 <= 56){ //? ASCII 1 = 49, 8 = 56
				return true;
			}else{
				cout << "Invalid Position.\n";
				return false;
			}
		}else{
			cout << "Invalid Position.\n";
			return false;
		}
	}else if(s == "C"){
		cout << "Cancelled.\n";
		return false;
	}
	else{
		cout << "Invalid Input.\n";
		return false;
	}
}

void inputCommand(Player &P,Player &O,int B[][8],bool &T){ 
	string com;
	cout << "[Player " << P.number << "] select your piece: "; //? input Position 
	cin >> com; //TODO 1st InputCommand
	if(checkIsLegit(com)){ //? if checkIsLegit True CheckPiece next
		if(P.checkWhoPieces(com,B)){	
			string move;
			bool CP = true; //? CP = checkpoint
			while(CP == true){
				cout << "[Player " << P.number << "] Cancel[C]/Make your move: ";//? input move position
				cin >> move; //TODO 2nd InputCommand
				if(checkIsLegit(move) == true || move == "C") CP = false;
			}
			int row = (TranslateCom(com)/10)-1;
			int columb = TranslateCom(com)%10;
			
			if(P.checkmove(move,com,B[row][columb],B) == false) {
				if(move != "C") cout << "Invalid Move.\n";
			}
			else{
				if(P.checkblock(com,move,B[row][columb],B)== false) cout << "Blocked\n";
				else{
					Move(com,move,P,O,B);
					if(P.number == 1) T = false;
					else T = true; 
				}
			}
		}else{
			cout << "This isn't your pieces!'\n";
		}
	}
}

int TranslateCom(string C){ //TODO change Position's string to Int
	int com_0,com_1; //! com_1 is ROW , com_0 is COLUMB
	com_0 = int(toupper(C[0]))-65; 
	com_1 = ((49-int(C[1]))+7)+1; //! com_1 need to +1 becuz if It's 0,Return Value error
	int z = (com_1*10)+com_0;
	return z;
}

void Move(string com,string move,Player &P,Player &O,int B[][8]){  //TODO P = Player , O = Opponent
	int PosA = TranslateCom(com); 
	int PosB = TranslateCom(move);
	int ROW_PosB = (PosB/10)-1;
	int j,k;
	int *ptrA = &B[(PosA/10)-1][PosA%10];
	int *ptrB = &B[(PosB/10)-1][PosB%10];
	if(*ptrB != 0){
		for(int i = 0;i < O.ptr.size();i++){
			if(ptrB == O.ptr[i]) k = i;
		}
		O.ptr.erase(O.ptr.begin()+k);
		//killfeed add
	}
	int temp = *ptrA;
	for(int i = 0;i < P.ptr.size();i++){
		if(ptrA == P.ptr[i]) j = i;
	}
	*ptrA = 0;
	*ptrB = temp; 
	if(temp == 6 && ROW_PosB == 2){
		*ptrB = 7;
	}
	if(temp == -6 && ROW_PosB == 5){
		*ptrB = -7;
	}
	P.ptr[j] = ptrB;
}

bool isLose(Player P){
	for(int i = 0;i < P.ptr.size();i++){
		if(5 == abs(*P.ptr[i])) return false;
	}
	return true;
}

//*! DebugFunction NOT-IN-FINAL-VERSION *//
void testPtr(Player p){	
	for(int i=0;i < 16 ;i++) cout << p.ptr[i] <<"\n";
	cout << "Player " << p.number << " Pieces\n";
}

void testAddress(int B[][8]){    
	cout << "\n";
	for(int i = 0; i < 8 ; i++){
		for(int j = 0;j < 8; j++){
			cout << " || " << &B[i][j];
		}
		cout << " ||";
		cout << "\n";
	}
	cout << "-------------------------------------------------------------------\n";
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

#include<iostream>

int board[8][8];
class Piece{

        public:
        //ตัวแปรเก็บสีดำ,ขาว
        char Color,strtCol,destCol;
        //bool isLegalMove;
        int strtRow,destRow;
        //1. มี bool isEmt ว่าไปที่เป้าหมายได้ไหม โดยมี input คือ สี,แถวและหลักเริ่มต้น,แถวและหลักเป้าหมาย,กระดาน
        //ถ้าเดินได้ ให้เช็คต่อว่าชิ้นนั้นเดินไม่ผิดกติกา ถ้าเดินไม่ได้ return 0
        bool isEmt(char Color,int strtRow,char strtCol,int destRow,char destCol,board[8][8]){
            Piece *pDest = board[destRow][destCol];
            //ถ้าเป้าหมายเป็นที่ว่าง หรือ มีชิ้นฝั่งตรงข้าม
            if(pDest == 0 or Color !=  pDest->Color){
                //เช็คว่าชิ้นนั้นๆถูกกฎรึเปล่า
                return isLegalMove(char Color,int strtRow,char strtCol,int destRow,char destCol,board[8][8]);
            }

        }
};
bool Piece::isLegalMove(char Color,int strtRow,char strtCol,int destRow,char destCol,board[8][8])(){
    {
        Piece *pDest = board[destRow][destCol];
        if(pDest == 0){

        }
    }
};
int main()
{
    
}
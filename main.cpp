#include<iostream>
#include<string>
#include"grandopening.h"
#include"tutorial.h"
using namespace std;
int main()
{
    char command;
    grandopening();
    while(true){
        cout << "type your command: ";
        cin >> command;
        command = toupper(command);
        //if ('P')
        
        //else if('H')
        if(command == 'H'){tutorial();
        grandopening();}

        //else if('E')
        if(command == 'E'){break;}
        //else    
        
    }
}


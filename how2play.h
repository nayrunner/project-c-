#include<iostream>
#include<string>
using namespace std;

void tutorial(){
    string pieces;
    cout<<"_____________________________________________________________________\n\n\n";
    cout<<"[pawn,queen,bishop,knight,rook,king,flipped] and [exit] to end the tutorial\n\n\n";
    cout<<"_____________________________________________________________________\n\n\n";

while(true){
    cout<<"Which pieces do you want to know its moves? : ";
    cin>>pieces;

    cout<<"_____________________________________________________________________\n\n\n";
    
    //tutorial
    if (pieces == "pawn")
    {   
        cout<<"=====================\n"<<"|   | X | * | X |   |\n"<<"=====================\n"<<"|   |   | P |   |   |\n"<<"=====================\n"<<"|   |   |   |   |   |\n"<<"=====================";    
    }

    if(pieces == "queen")
    {
        cout<<"=====================\n|   | * |   | * |   |\n=====================\n|   |   | Q |   |   |\n=====================\n|   | * |   | * |   |\n=====================\n";

    }

    if(pieces == "bishop")
    {
        cout<<"=====================\n|   | * | * | * |   |\n=====================\n|   |   | B |   |   |\n=====================\n|   | * |   | * |   |\n=====================\n";
    }

    if(pieces == "knight")
    {
        cout<<"=====================\n|   | * |   | * |   |\n=====================\n| * |   |   |   | * |\n=====================\n|   |   | N |   |   |\n=====================\n| * |   |   |   | * |\n=====================\n|   | * |   | * |   |\n=====================\n";
    }

    if(pieces == "rook")
    {
        cout<<"=====================\n|   |   | * |   |   |\n=====================\n|   |   | * |   |   |\n=====================\n| * | * | R | * | * |\n=====================\n|   |   | * |   |   |\n=====================\n|   |   | * |   |   |\n=====================\n";
    }

    if(pieces == "king")
    {
        cout<<"=====================\n|   |   |   |   |   |\n=====================\n|   | * | * | * |   |\n=====================\n|   | * | K | * |   |\n=====================\n|   | * | * | * |   |\n=====================\n|   |   |   |   |   |\n=====================\n";
    }

    if(pieces == "flipped")
    {
        cout<<"=====================\n|   | * |   | * |   |\n=====================\n|   |   | F |   |   |\n=====================\n|   | * |   | * |   |\n=====================\n";

    }

    if (pieces == "exit"){break;}


    
    cout<<"\n\n_____________________________________________________________________\n\n";
}

}

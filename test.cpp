#include <cstdlib>
#include <iostream>
using namespace std;

int main() { 
    char a[8];
    int i = 0;
   
    while(true){
    cout<<"55555\n";
    cin>>a[i];
    for (int j = 0; j < 8; j++)
    {
       cout<<a[j];
    }
    cout<<"\n";
    
    
    if(a[i]=='1'){std::system("cls");}
    i++;
    }
    return 0;
}
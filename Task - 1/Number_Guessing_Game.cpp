#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(static_cast<unsigned int>(time(0)));
    int number=rand()%101;
    int guess;
    cout<<"Guess a number between 1 to 100 \n";
    do{
        cin>>guess;
        if(guess>number){
            cout<<"Your Guess is higher than the number\n";
        }
        else if(guess<number){
            cout<<"Your Guess is lower than the number\n";
        }
    }while(guess!=number);
    cout<<"Your Guess is correct! The number is "<<number<<endl;
    return 0;
}
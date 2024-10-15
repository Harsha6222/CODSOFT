#include<bits/stdc++.h>
using namespace std;

class Play{
    public:
    vector<vector<char>> box;
    string outline;
    int grid;
    bool win=false;

    Play(): box(3,vector<char>(3,'\0')),outline("------------"){
        
    }
    int col(int grid){
        return (grid-1)%3;
    }
    int row(int grid){
        return (grid-1)/3;
    }
    void print(){
        for(int i=0;i<3;i++){
            cout<<outline<<endl;
            for(int j=0;j<3;j++){
                cout<<"| "<<box[i][j]<<" ";
            }
            cout<<" |\n";
        }
        cout<<outline<<endl;
    }
    void check() {
        for(int i=0;i<3;i++){
            if(box[i][0]!='\0' && box[i][0]==box[i][1] && box[i][2]==box[i][0]){
                cout<<"Player "<<box[i][0]<<" wins!\n";
                win=true;
                return;
            }
        }
        for(int i=0;i<3;i++){
            if(box[0][i]!='\0' && box[0][i]==box[1][i] && box[2][i]==box[0][i]){
                cout<<"Player "<<box[0][i]<<" wins!\n";
                win=true;
                return;
            }
        }
        if(box[0][0]!='\0' && box[0][0]==box[1][1] && box[1][1]==box[2][2]){
            cout<<"Player "<<box[1][1]<<" wins!\n";
            win=true;
            return;
        }
        if(box[0][2]!='\0' && box[0][2]==box[1][1] && box[1][1]==box[2][0]){
            cout<<"Player "<<box[1][1]<<" wins!\n";
            win=true;
            return;
        }
        for(auto& row:box){
            int cnt=count(row.begin(),row.end(),'\0');
            if(cnt>0) return;
        }
        cout<<"It's a draw!!!\n";
    }
    int select(){
        do{
            cin>>grid;
            if(grid>9 || grid<1) cout<<"Enter Valid grid number : ";
            else if(occupied(grid)) cout<<"Grid is Occupied, Please select another grid: ";
        }while(grid>9 || grid<1 || occupied(grid));
        return grid;
    }
    bool occupied(int grid){
        return box[row(grid)][col(grid)]!='\0';
    }
    void Playx(){
        cout<<"Player X turn(Enter grid number): ";
        grid=select();
        int r=row(grid),c=col(grid);
        box[r][c]='X';
        print();
    }
    void Playo(){
        cout<<"Player O turn(Enter grid number): ";
        grid=select();
        int r=row(grid),c=col(grid);
        box[r][c]='O';
        print();
    }
    void start(){
        for(int i=0;i<9;i++){
            if(i%2==0) Playx();
            else Playo();
            check();
            if(win) return;
        }
    }
};

int main(){
    char choice='y';
    do{
        Play game;
        game.start();
        cout<<"Do you want to play again? (y/n) : ";
        cin>>choice;
    }while(choice=='y');
    return 0;
}

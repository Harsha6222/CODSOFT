#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string>> Tasks;
string status="pending";

void AddTask(){
    cout<<"Enter Task Name to Add : ";
    string task;
    cin.ignore();
    getline(cin,task);
    Tasks.push_back({task,status});
    cout<<"Task Added Successfully!\n";
}
void ViewTasks(){
    if(Tasks.empty()){
        cout<<"No Tasks to display\n";
    }
    else{
        for(int i=0;i<Tasks.size();i++){
            cout<<i+1<<". "<<Tasks[i].first<<" - "<<Tasks[i].second<<endl;
        }
    }
}
void MarkTask(){
    if(Tasks.empty()){
        cout<<"There are no tasks to mark as completed\n";
        return;
    }
    cout<<"Enter Task number to mark as Completed : ";
    int number;
    cin>>number;
    if(number>Tasks.size() ){
        cout<<"Invalid Task number/Task number not found!\n";
    }
    else{
        Tasks[number-1].second="Completed";
        cout<<"Marked task "<<number<<" as Completed\n";
    }
}
void RemoveTask(){
    if(Tasks.empty()){
        cout<<"There are no tasks to be removed\n";
        return;
    }
    cout<<"Enter Task number to Remove the task : ";
    int number;
    cin>>number;
    if(number>Tasks.size()){
        cout<<"Invalid Task number/Task number not found!\n";
    }
    else{
        Tasks.erase(Tasks.begin()+number-1);
        cout<<"Task removed Successfully\n";
    }
}

int main(){
    cout<<"Main Menu\n";
    cout<<"1.Create/Add a Task\n2.View Tasks\n3.Mark a Task as Completed\n4.Remove a Task\n5.Exit\n";
    cout<<"Enter Your Choice : ";
    int choice;
    cin>>choice;
    while(choice){
        switch(choice){
            case 1:
                AddTask();
                break;
            case 2:
                ViewTasks();
                break;
            case 3:
                MarkTask();
                break;
            case 4:
                RemoveTask();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Enter Valid Option\n";
        }
        cout<<"\nMain Menu\n";
        cout<<"1.Create/Add a Task\n2.View Tasks\n3.Mark a Task as Completed\n4.Remove a Task\n5.Exit\n";
        cout<<"Enter Your Choice : ";
        cin>>choice;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long double operand1;
    long double operand2;
    char op;
    cout<<"Please enter the first number, the operator, and the second number : ";
    cin>>operand1>>op>>operand2;
    long double result;
    switch(op){
        case '+':
            result=operand1+operand2;
            break;
        case '-':
            result=operand1-operand2;
            break;
        case '*':
            result=operand1*operand2;
            break;
        case '/':
            if(operand2==0){
                cout<<"Zero division error";
                return 0;
            }
            else{
                result=operand1/operand2;
            }
            break;
        default:
            cout<<"\nInvalid Input";
            return 0;
    }
    if(result == static_cast<long long>(result)){
        cout<<static_cast<long long>(result);
    }
    else{
        cout<<fixed<<setprecision(3)<<result<<endl;
    }
    return 0;
}
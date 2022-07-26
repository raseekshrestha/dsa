#include <iostream>
using namespace std;
#include <stack>
#include<math.h>

bool isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$' || ch == '^'){
        return true;
    }
    else{
        return false;
    }
}

bool isOperand(char ch){
    if (ch >='0' && ch <= '9'){
        return true;
    }
    else{
        return false;
    }
}

float calculate(float a,float b,char op){
    if (op =='+'){
        return a+b;
    }
    else if (op == '-'){
        return a - b;
    }
    else if (op == '*'){
        return a * b;
    }
    else if (op == '/'){
        return a / b;
    }
    else if (op == '^' || op == '$'){
        return pow(a,b);
    }
}

void solvePostfix(string postfix){
    stack<float> stack;
    float a,b,res;
    for (int i=0;i<postfix.length();i++){
        if (isOperand(postfix[i])){
            stack.push(float(postfix[i]-'0'));
        }
        else if (isOperator(postfix[i])){
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            res = calculate(b,a,postfix[i]);
            stack.push(res);
        }
    }
    cout << "the result is : "<< stack.top();


}

int main(){
    string eqn;
    cout << "Postfix Expression: "; cin >> eqn;
    solvePostfix(eqn);
}
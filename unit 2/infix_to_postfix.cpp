#include <iostream>
using namespace std;
#include <stack>

int precedent(char op){
    if (op == '^' || op =='$'){return 3;}
    else if (op == '*' || op =='/'){return 2;}
    else if (op == '+' || op =='-'){return 1;}
}

void infixToPostfix(string exp){
    stack<char> stk;
    string postfixExp;
    for (int i=0;i<exp.length();i++){
        if ((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9')){
            postfixExp += exp[i];
        }
        else if (exp[i] == '('){
            stk.push(exp[i]);
        }
        else if (exp[i] == ')'){
            while (stk.top() != '('){
                postfixExp += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            if (stk.empty() || stk.top()=='('){
                stk.push(exp[i]);
            }
            else{
                if (precedent(stk.top()) >= precedent(exp[i])){
                    postfixExp += stk.top();
                    stk.pop();
                    stk.push(exp[i]);
                }
                else{
                    stk.push(exp[i]);
                    
                }
            }
        }

    }

    cout << postfixExp <<endl;
}

int main(){
    // infixToPostfix("(A+B*C+D)");
    infixToPostfix("(a+(b/c-(d*e$f)+g)*h)");
}
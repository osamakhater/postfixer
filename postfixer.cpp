#include <stddef.h>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;


bool is_op(string str){
    string ops[6] = {"+", "-", "x", "/", "(", ")"};
    if(str.length() > 1){
        return false;
    }
    else{
        for(int i = 0; i < 6; i++){
            if(str == ops[i]){
                return true;
            };
        };
        return false;
    };
};

int order_of_op(string str, stack<string> operators){
    if(operators.size() == 0){
        return 0;
    }
    else if(str[0] == ')'){
        return 1;
    }
    else{
        return 2;
    }
};
queue <string> postfixer(string expression){
    string element = "";
    queue<string> postfix_expression;
    stack<string> operators;
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] != ' '){
            element += expression[i];
        };
        if(expression[i] == ' ' || i == expression.length() - 1){
            if(is_op(element)){
                int order = order_of_op(element, operators);
                if(order == 0){
                    operators.push(element);
                }
                else if(order == 1){
                    string popped = operators.top();
                    while(popped[0] != '('){
                        postfix_expression.push(popped);
                        operators.pop();
                        popped = operators.top();
                    };
                }
                else if(order == 2){
                    string top = operators.top();
                    while(top[0] == 'x' || top[0] == '/'){
                        postfix_expression.push(top);
                        operators.pop();
                        top = operators.top();
                    };
                    operators.push(element);
                };
                
            }
            else{
                postfix_expression.push(element);
            };
            element = ""; 
        }
        
    };
    while(!operators.empty()){
        postfix_expression.push(operators.top());
        operators.pop();
    }
    
    return postfix_expression;
};
int main(){
    string expression;
    cout << "Input an infix expression: ";
     getline(cin, expression);
    /*cout << "\n" << expression << "\n";*/
   /*string expression = "1 + 3 x 3 / 4 + 5";*/
    queue<string> final = postfixer(expression);
    while(!final.empty()){
        cout << final.front() << " ";
        final.pop();
    };

    
};




#include <iostream>
#include <stdlib.h>
using namespace std;

class STACK{
    int top;
    char operandStack[20];

    public:
        STACK(){
            top=-1;
        }
        
        void push(char c){
            if(top==19) cout<<"Stack overflow\n";
            else operandStack[++top]=c;
        }

        char pop(){
            if(top==-1) cout<<"Stack underflow\n";
            else return operandStack[top--];
        }
        
        int isOperator(char c){
            switch(c){
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                case ')':
                case '$':
                case '^': return 1;
                default: return 0;
            }
        }

        int stackPrecedence(char c){
            switch(c){
                case '+':
                case '-': return 2;
                case '*':
                case '/': return 4;
                case '$':
                case '^': return 6;
                case '(': return 0;
            }
        }

        int inputPrecedence(char c){
            switch(c){
                case '+':
                case '-': return 1;
                case '*':
                case '/': return 3;
                case '$':
                case '^': return 7;
                case '(': return 9;
                case ')': return 0;
            }
        }

        void infixToPostfix(char infix[],char postfix[]){
            char c;
            int i=0,j=0;

            while((c=infix[i++])!='\0'){
                if(!isOperator(c)){
                    postfix[j++] =c;
                }else{
                    while(top!=-1 && stackPrecedence(operandStack[top])>inputPrecedence(c)){
                        if(c==')'){
                            while(operandStack[top] != '(') {
                                postfix[j++]=pop();
                            }
                            pop();//remove "(" also
                            break;//breaks while loop at line no. 72
                        }else{
                            postfix[j++]=pop();
                        }
                    }
                    if(c!=')'){
                        push(c);
                    }    
                }
            }
            while(top!=-1){
                postfix[j++]=pop();
            }
            postfix[j]='\0';
        }
};

int main(){
    STACK S;
    char infix[30],postfix[30];
    int choice;
    while(1){
        cout<<"\n0.Exit\n1.Conversion\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 0: exit(0);
            case 1: cout<<"Enter the infix expression:";
                    cin>>infix;
                    S.infixToPostfix(infix,postfix);
                    cout<<"Postfix expression: "<<postfix<<endl;
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}
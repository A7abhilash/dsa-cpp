#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class STACK{
    int topOfOperator;
    char operatorStack[20];
    int topOfOperand;
    char operandStack[20][20];

    public:
        STACK(){
            topOfOperator=-1;
            topOfOperand=-1;
        }
        
        void pushOperator(char c){
            if(topOfOperator==19) cout<<"Stack overflow\n";
            else operatorStack[++topOfOperator]=c;
        }

        char popOperator(){
            if(topOfOperator==-1) cout<<"Stack underflow\n";
            else return operatorStack[topOfOperator--];
        }

        void pushOperand(char c[]){
            if(topOfOperand==19) cout<<"Stack overflow\n";
            else strcpy(operandStack[++topOfOperand],c);
        }

        char* popOperand(){
            if(topOfOperand==-1) cout<<"Stack underflow\n";
            else{
                char *c=operandStack[topOfOperand--];
                return c;
            }
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

        void newitem(){
            char *oprnd2= popOperand();
            char *oprnd1= popOperand();
            char opr= popOperator();
            char exp[20],temp[2];
            temp[0]=opr;temp[1]='\0';
            strcpy(exp,temp);
            strcat(exp,oprnd1);
            strcat(exp,oprnd2);
            pushOperand(exp);
        }

        void infixToPrefix(char infix[],char prefix[]){
            char c,temp[2];
            int i=0,j=0;
            
            while((c=infix[i++])!='\0'){
                if(!isOperator(c)){
                    temp[0]=c,temp[1]='\0';
                    pushOperand(temp);
                }else{
                    while(topOfOperator!=-1 && stackPrecedence(operatorStack[topOfOperator])>inputPrecedence(c)){
                        if(c==')'){
                            while(operatorStack[topOfOperator]!='('){
                                newitem();
                            }
                            popOperator();
                            break;
                        }else{
                            newitem();
                        }
                    }
                    if(c!=')'){
                        pushOperator(c);
                    }
                }
            }
            while(topOfOperator!=-1){
                newitem();
            }
            strcpy(prefix,operandStack[topOfOperand]);
        }
};

int main(){
    STACK S;
    char infix[30],prefix[30];
    int choice;
    while(1){
        cout<<"\n0.Exit\n1.Conversion\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 0: exit(0);
            case 1: cout<<"Enter the infix expression:";
                    cin>>infix;
                    S.infixToPrefix(infix,prefix);
                    cout<<"Prefix expression: "<<prefix<<endl;
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}
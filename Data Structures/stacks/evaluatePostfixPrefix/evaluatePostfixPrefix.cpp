#include <iostream>
#include <stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

class STACK{
    int top;
    float operandStack[20];

    public:
        STACK(){
            top=-1;
        }
        
        void push(float n){
            if(top==19) cout<<"Stack overflow\n";
            else operandStack[++top]=n;
        }

        float pop(){
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

        float compute(float a,float b,char optr){
            switch(optr){
                case '+': return a+b;
                case '-': return a-b;
                case '*': return a*b;
                case '/': return a/b;
                case '$': 
                case '^': return pow(a,b);
                default:  printf("Invalid expression\n");
            }
        }

        void evaluatePostfix(char postfix[]){
            char c;
            float oprnd1,oprnd2,result;
            int i=0;

            while((c=postfix[i++])!='\0'){
                if(!isOperator(c)){
                    push(c-'0');
                }else{
                    oprnd2=pop();
                    oprnd1=pop();
                    result=compute(oprnd1,oprnd2,c);
                    push(result);
                }
            }

            result=pop();
            if(top!=-1) cout<<"Invalid expression\n";
            else cout<<"Value: "<<result<<endl;
            clearStack();
        }

        void evaluatePrefix(char prefix[]){
            char c;
            float oprnd1,oprnd2,result;
            int i=strlen(prefix)-1;
            
            while(i>=0){
                c = prefix[i];
                if(!isOperator(c)){
                    push(c-'0');
                }else{
                    oprnd1=pop();
                    oprnd2=pop();
                    result=compute(oprnd1,oprnd2,c);
                    push(result);
                }
                i--;
            }

            result=pop();
            if(top!=-1) cout<<"Invalid expression\n";
            else cout<<"Value: "<<result<<endl;
            clearStack();
        }

        /*Make sure stack is clear before attempting to evaluate
        new expression because in this class will be using 
        single object to implement two different operations*/
        void clearStack(){
            while(top!=-1) pop();
        }
};

int main(){
    STACK S;
    char expression[30];
    int choice;
    while(1){
        cout<<"\n0.Exit\n1.Evaluate Postfix expression\n2.Evaluate Prefix expression\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 0: exit(0);
            case 1: cout<<"Enter the postfix expression:";
                    cin>>expression;
                    S.evaluatePostfix(expression);
                    break;
            case 2: cout<<"Enter the prefix expression:";
                    cin>>expression;
                    S.evaluatePrefix(expression);
                    break;
            default:printf("Enter proper choice\n");
        }
    }
    return 0;
}
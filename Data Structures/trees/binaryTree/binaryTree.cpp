#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class NODE{
    public:
        int data;
        NODE* left;
        NODE* right;

        NODE(){
            left=NULL;
            right=NULL;
        }
};
typedef class NODE* node;

class BinaryTree{
    node root;

    public:
        BinaryTree(){
            root=NULL;
        }

        void insertNewNode(){
            int i;
            char direction[10];
            node newNode= new NODE();
            cout<<"Enter the data:";
            cin>>newNode->data;
            newNode->left=newNode->right=NULL;
            if(root==NULL){
                printf("New node inserted as the root\n");
                root=newNode;
                return;
            }
            direct: cout<<"Enter the direction:";
            cin>>direction;
            node currentNode=root,previousNode=NULL;
            for(i=0;i<strlen(direction);i++){
                previousNode=currentNode;
                if(currentNode==NULL) break;
                if(direction[i]=='L' || direction[i]=='l') currentNode=currentNode->left;
                else if(direction[i]=='R' || direction[i]=='r') currentNode=currentNode->right;
                else break;
            }
            if(i!=strlen(direction) || currentNode!=NULL){
                cout<<"Invalid direction or node already exit at given direction. Try new direction.\n";
                goto direct;
            }
            if(direction[i-1]=='L' || direction[i-1]=='l') previousNode->left=newNode; 
            else if(direction[i-1]=='R' || direction[i-1]=='r') previousNode->right=newNode; 
            cout<<"New node inserted\n";
        }
        
        void inOrder(node R){
            if(R==NULL) return;
            inOrder(R->left);
            cout<<R->data<<" ";
            inOrder(R->right);
        }
        void postOrder(node R){
            if(R==NULL) return;
            postOrder(R->left);
            postOrder(R->right);
            cout<<R->data<<" ";
        }
        void preOrder(node R){
            if(R==NULL) return;
            cout<<R->data<<" ";
            preOrder(R->left);
            preOrder(R->right);
        }

        void displayTree(){
            if(root==NULL){
                printf("Tree is empty\n");
                return;
            }
            cout<<"\nInOrder Traversal: "; inOrder(root);
            cout<<"\nPostOrder Traversal: "; postOrder(root);
            cout<<"\nPreOrder Traversal: "; preOrder(root);
            cout<<"\n";
        }

        node searchNode(node R,int data,node *parentNode){
            if(R==NULL) return NULL;
            node nodeToBeSearched=NULL;
            if(R->data==data){
                nodeToBeSearched=R;
            }
            if(nodeToBeSearched==NULL){
                *parentNode=R;
                nodeToBeSearched=searchNode(R->left,data,parentNode);
            }
            if(nodeToBeSearched==NULL){
                *parentNode=R;
                nodeToBeSearched=searchNode(R->right,data,parentNode);
            }
            return nodeToBeSearched;
        }

        void search(){
            if(root==NULL){
                cout<<"Tree is empty\n";
                return;
            }
            int data;
            cout<<"Enter the data of the node to be searched:";
            cin>>data;
            if(root->data==data){
                cout<<"Searching node data = "<<data<<" and it is the root of the tree\n";
            }else{
                node parentNode=NULL;
                node nodeToBeSearched = searchNode(root,data,&parentNode);

                if(nodeToBeSearched==NULL){
                    cout<<"Node with data = "<<data<<" doesn't exist in the tree\n";
                }else{
                    cout<<"Searching node data = "<<nodeToBeSearched->data<<" and it's parent node data = "<<parentNode->data<<endl;
                }
            }
        }

        void deleteNode(){
            if(root==NULL){
                cout<<"Tree is empty\n";
                return;
            }
            int data;
            cout<<"Enter the data of the node to be deleted:";
            cin>>data;

             //* If the node to be deleted is the root and has children.
            if(root->data==data && (root->left!=NULL || root->right!=NULL)){
                cout<<"Root node can't be deleted unless it has no child.\n";
                return;
            }
            //*CASE 1: If the node to be deleted is the root and has no children.
            if(root->data==data && root->left==NULL && root->right==NULL){
                cout<<"Deleted root node with data = "<<root->data<<endl;
                delete root;
                root=NULL;
                return;
            }
            
            //*Search the node
            node parentNode;
            node nodeToBeDeleted=searchNode(root,data,&parentNode);
            if(nodeToBeDeleted==NULL){
                cout<<"Node with data = "<<data<<" doesn't exist in the tree\n";
                return;
            }else{
                cout<<"Deleting node data = "<<nodeToBeDeleted->data<<" and it's parent node data = "<<parentNode->data<<endl;
            }

            //*CASE 2: If the node to be deleted is a leaf node.
            if(nodeToBeDeleted->left==NULL && nodeToBeDeleted->right==NULL){
                if(nodeToBeDeleted==parentNode->left) parentNode->left=NULL;
                else parentNode->right=NULL;
                delete nodeToBeDeleted;
            }

            //*CASE 3: If the node to be deleted has only one child
            else if((nodeToBeDeleted->left!=NULL && nodeToBeDeleted->right==NULL)
                ||(nodeToBeDeleted->left==NULL && nodeToBeDeleted->right!=NULL)){
                    //* If the node has left child node
                    if(nodeToBeDeleted->right==NULL){
                        if(nodeToBeDeleted==parentNode->left) parentNode->left=nodeToBeDeleted->left;
                        else parentNode->right=nodeToBeDeleted->left;
                    }
                    //* If the node has right child node
                    else{
                        if(nodeToBeDeleted==parentNode->left) parentNode->left=nodeToBeDeleted->right;
                        else parentNode->right=nodeToBeDeleted->right;
                    }
                delete nodeToBeDeleted;
            }
            
            //*CASE 4: If node to be deleted has 2 children
            else{
                node IS=nodeToBeDeleted->right, ISP = nodeToBeDeleted;
                //? IS= inorder successor, ISP= inorder successor's parent.
                while(IS->left!=NULL){
                    ISP=IS;
                    IS=IS->left;
                }
                nodeToBeDeleted->data=IS->data;
                if(IS->left==NULL && IS->right==NULL){
                    if(IS==ISP->left) ISP->left=NULL;
                    else ISP->right=NULL;
                }else{
                    if(IS==ISP->left) ISP->left=IS->right;
                    else ISP->right=IS->right;
                }
                delete IS;
            }
            cout<<"Node deleted with data: "<<data<<endl;
        }

        int heightOfTree(node R){
            if(R==NULL) return 0;
            
            int leftHeight=heightOfTree(R->left);
            int rightHeight=heightOfTree(R->right);

            if(leftHeight>rightHeight) return leftHeight+1;
            return rightHeight+1;
        }

        void findHeight(){
            if(root==NULL){
                cout<<"Tree is empty\n";
                return;
            }
            cout<<"Height of the tree is: "<<heightOfTree(root)-1<<endl;
        }
};

int main(){
    BinaryTree BT;
    int choice;

    while(1){
        cout<<"\n0.Exit\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Find height\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 0: exit(0);
            case 1: BT.insertNewNode(); break;
            case 2: BT.displayTree(); break;
            case 3: BT.search(); break;
            case 4: BT.deleteNode(); break;
            case 5: BT.findHeight(); break;
            default: cout<<"Enter proper choice\n";
        }
    }
    return 0;
}
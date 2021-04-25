#include<iostream>
using namespace std;

//Create a node
class Node {
	public:
		int data;
		Node* next;
		
		Node(){
			data=0;
			next=NULL;
		}
};
typedef class Node* node;

//Create a Singly Linked List:
class SLL {
	public:
	    node head=new Node();
		
	    SLL(){
			head->data=0;
    	    head->next=NULL;
	    }

		void insertFront()	{
			node n =new Node();
			cout<<"Enter the data to be inserted: ";
			cin>>n->data;
			
			n->next=head->next;
			head->next=n;
			head->data++;
			cout<<"New node inserted at front!\n";
		}

		void insertRear(){
			node n =new Node();
			cout<<"Enter the data to be inserted: ";
			cin>>n->data;
			
			if(head->next==NULL){
				head->next=n;
			}else{
				node temp=head->next;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=n;
			}
			head->data++;
			cout<<"New node inserted at rear!\n";
		}

		void insertByPosition(){
			int position;
			cout<<"Enter the postion of new node to be inserted: ";
			cin>>position;

			if(position>=1 && position<=head->data+1){
				if(position==1) return insertFront();
				if(position==head->data+1) return insertRear();

				head->data++;
				int count=1;
				node n=new Node();
				cout<<"Enter the data to be inserted: ";
				cin>>n->data;

				node temp=head->next, ptr=NULL;
				while(count<position){
					ptr=temp;
					temp=temp->next;
					count++;
				}
				ptr->next=n;
				n->next=temp;
				cout<<"New node inserted!\n";
			}else{
				cout<<"Invalid position!\n";
			}
		}

		void deleteFront(){
			if(head->data==0){
				cout<<"List is empty\n";
				return;
			}
			node temp=head->next;
			cout<<"Front node deleted with data: "<<temp->data<<endl;
			head->next=temp->next;
			head->data--;
			delete temp;
		}

		void deleteRear(){
			if(head->data==0){
				cout<<"List is empty\n";
				return;
			}

			node temp=head->next;
			if(temp->next==NULL){
				head->next=NULL;
			}else{
				node ptr=NULL;
				while(temp->next!=NULL){
					ptr=temp;
					temp=temp->next;
				}
				ptr->next=NULL;
			}
			cout<<"Rear node deleted with data: "<<temp->data<<endl;
			head->data--;
			delete temp;
		}

		void deleteByPosition(){
			if(head->data==0){
				cout<<"List is empty\n";
				return;
			}

			int position;
			cout<<"Enter the postion of node to be deleted: ";
			cin>>position;

			if(position>=1 && position<=head->data){
				if(position==1) return deleteFront();
				if(position==head->data) return deleteRear();

				head->data--;
				int count=1;
				node temp=head->next, ptr=NULL;
				while(count<position){
					ptr=temp;
					temp=temp->next;
					count++;
				}
				ptr->next=temp->next;
				cout<<"Node deleted with data: "<<temp->data<<endl;
				delete temp;
			}else{
				cout<<"Invalid position!\n";
			}
		}

		void searchNode(){
			if(head->data==0){
				cout<<"List is empty\n";
				return;
			}

			int data,position=1;
			cout<<"Enter the data to be searched: ";
			cin>>data;

			node temp=head->next;
			while(temp!=NULL && temp->data!=data){
				temp=temp->next;
				position++;
			}
			if(temp==NULL){
				cout<<"Node with data: "<<data<<" doesn't exist\n";
			}else{
				cout<<"Node with data: "<<data<<" exists at position: "<<position<<endl;;
			}
		}

		void displayList(){
			if(head->data==0){
				cout<<"List is empty\n";
				return;
			}

			cout<<"\nNo. of nodes in the list: "<<head->data<<endl;
			node temp=head->next;
			cout<<"head-->";
			while(temp!=NULL){
				cout<<temp->data<<"-->";
				temp=temp->next;
			}
			cout<<"NULL\n";
		}
};	


int main(){
    SLL S;
    int option;
    while(1)
    {
        cout<<"\n1.Insert Front \n";
        cout<<"2.Insert Rear \n";
        cout<<"3.Insert at a particular position \n";
        cout<<"4.Delete Front \n";
        cout<<"5.Delete Rear \n";
        cout<<"6.Delete at a particular position \n";
        cout<<"7.Search node of a particular data \n";
        cout<<"8.Display list \n";
        cout<<"\nSelect the operation to perform. Enter 0 to exit: ";
        
        cin>>option;
        switch(option)
        {	
            case 0: exit(0);
			case 1: S.insertFront();
					S.displayList(); 
					break;
			case 2: S.insertRear();
					S.displayList(); 
					break;
			case 3: S.insertByPosition();
					S.displayList(); 
					break;
			case 4: S.deleteFront();
					S.displayList(); 
					break;
			case 5: S.deleteRear();
					S.displayList(); 
					break;
			case 6: S.deleteByPosition();
					S.displayList(); 
					break;
			case 7: S.searchNode();
					S.displayList(); 
					break;
			case 8: S.displayList(); 
					break;
            default: cout<<"\n Enter proper option \n";
        }
    }
	return 0;
}

#include<iostream>
using namespace std;

/*  Create a node.
    Create a Circular Linked List:
        1.Check whether node exist or not
        2.Appending a Node
        3.Prepending a Node
        4.Inserting a Node after a particular KEY
        5.Deleting a node of a particular KEY
        6.Updating a node of a particular KEY
        7.Displaying our Doubly Linked Lists' Nodes
*/

class Node {
	public:
		int key;
		int data;
		Node* next;
	
		Node()
		{
			key=0;
			data=0;
			next=NULL;	
		}
		Node(int k,int d)
		{
			key=k;
			data=d;
		}
};
typedef Node* node;

class CLL {
	public:
		node head;
		
		CLL()
		{
			head=NULL;
		}
		
		//1.Check whetehr the node exists using key value.
		node nodeExists(int k)
		{
			node temp=NULL;
			node ptr=head;
			
			if(ptr==NULL)
			{
				return temp;
			}
			else
			{
				do
				{
					if(ptr->key==k)
					{
						temp=ptr;
					}
					ptr=ptr->next;
					
				}while(ptr!=head);
			return temp;
			}
		}
		
		//2.Append a node to the list.
		void appendNode(node n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exists with the key value:"<<n->key<<". Append another Node with unique key value. \n";
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					n->next=head;
					cout<<"Node Appended \n";
				}
				else
				{
					node ptr=head;
				
					while(ptr->next!=head)
					{
						ptr=ptr->next;
					}
					ptr->next=n;
					n->next=head;
					cout<<"Node Appended \n";
				}
			}
		}
		
		//3.Prepend a Node to the list.
		void prependNode(node n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exists with the key value:"<<n->key<<". Prepend another Node with unique key value. \n";
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					n->next=head;
					cout<<"Node Appended \n";
				}
				else
					{
					node ptr=head;
					
					while(ptr->next!=head)
					{
						ptr=ptr->next;
					}
				
					ptr->next=n;
					n->next=head;
					head=n;
					cout<<"Node Prepended \n";
					}
			}
		}
		
		//4.Insert a Node after a particular Key.
		void insertNodeAfter(int k,node n)
		{
			node ptr=nodeExists(k);
			
			if(ptr==NULL)
			{
				cout<<"No Node exists with the key value:"<<k<<endl;
			}
			else
			{
				if(nodeExists(n->key)!=NULL)
				{
					cout<<"Node already exists with the key value:"<<n->key<<". Insert another Node with unique key value. \n";
				}
				else
				{
					if(ptr->next==head)
					{
						n->next=head;
						ptr->next=n;
						cout<<"Node Inserted at the end. \n";
					}	
					else
					{
						n->next=ptr->next;
						ptr->next=n;
						cout<<"Node Inserted in between.\n";
					}
				}
			}
		}
		
		//5.Delete a node of a particular Key.
		void deleteNodeByKey(int k)
		{
			node ptr=nodeExists(k);
			
			if(ptr==NULL)
			{
				cout<<"No Node exists with the key value:"<<k<<endl;
			}
			else
			{
				//deleting first node;			
				if(ptr==head)
				{
					if(head->next==NULL)
					{
						head=NULL;
						cout<<"Node Unlinked... List is empty. \n";
					}	
					else
					{
						node ptr1=head;   //ptr1 is a temporary pointer of this else block.
						
						while(ptr1->next!=head)
						{
							ptr1=ptr1->next;
						}
						
						ptr1->next=head->next;
						head=head->next;
						cout<<"Node Unlinked with the key value:"<<k<<endl;
					}
				}
				//deleting any node other than first node;
				else
				{
					node temp=NULL;
					node prevptr=head;
					node currentptr=head->next;
					
					while(currentptr!=NULL)
					{
						if(currentptr->key==k)
						{
							temp=currentptr;
							currentptr=NULL;
						}
						else
						{
							prevptr=prevptr->next;
							currentptr=currentptr->next;
						}
					}
					
					prevptr->next=temp->next;
					cout<<"Node Unlinked with the key value:"<<k<<endl;
				}
			}
		}
		
		//6.Update a Node of a particular Node.
		void updateNodeByKey(int k,int d)
		{
			node ptr=nodeExists(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"Node has been successfully Updated. \n";
			}
			else 
			{
				cout<<"Node doesnt exists with the key value:"<<k<<endl;
			}
		}
		
		//7.Display our Double Linked Lists' Nodes.
		void printList()
		{
			if(head==NULL)
			{
				cout<<"List is empty. \n";
			}
			else
			{
				cout<<"\nHead address:"<<head<<endl;
				cout<<"Circular Linked Lists' Nodes: \n";
				
				node temp=head;
				
				do
				{
					cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<")-->";
					temp=temp->next;
				}while(temp!=head);
				
				cout<<endl;
			}
		}
};
	
int main()
{
	CLL obj;
	int option;
	int key1,k1,data1;
	
	while(1)
    {
        cout<<"\nSelect the operation to perform. Enter 0 to exit \n";
        cout<<"1.Append Node \n";
        cout<<"2.Prepend Node \n";
        cout<<"3.Insert Node after a particular KEY \n";
        cout<<"4.Delete Node of a particular KEY \n";
        cout<<"5.Update node of a particular KEY \n";
        cout<<"6.Display all Nodes \n";
        
        cin>>option;
        node n1=new Node();
        
        switch(option)
        {
            case 0:exit(0);
            case 1:
                cout<<"\n Append Node Operation \nEnter key & data of the Node to be Appended \n";
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.appendNode(n1);                                                
                break;
            case 2:
                cout<<"\n Prepend Node Operation \nEnter key & data of the Node to be Prepended \n";
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.prependNode(n1);     
                break;
            case 3:
                cout<<"\n Insert Node Operation \n Enter the key value after which you want to insert new Node: \n";
                cin>>k1;
                cout<<"Enter the key & data of new node: \n";
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"\n Delete Node Operation \n Enter the key of node to be deleted: \n";
                cin>>k1;
                obj.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"\n Update Node Operation \n Enter the key and new data to be updated: \n";
                cin>>key1>>data1;
                obj.updateNodeByKey(key1,data1);                
                break;
            case 6:
                obj.printList();
                break;
            default: cout<<"\n Enter proper option \n";
        }
    }
	return 0;
}	 

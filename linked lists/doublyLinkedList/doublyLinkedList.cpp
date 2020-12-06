#include<iostream>
using namespace std;

/*  Create a node.
    Create a Doubly Linked List:
        1.Check whether node exist or not
        2.Appending a Node
        3.Prepending a Node
        4.Inserting a Node after a particular KEY
        5.Deleting a node of a particular KEY
        6.Updating a node of a particular KEY
        7.Displaying our Doubly Linked Lists' Nodes
*/


class Node{
	
	public:
		int key;
		int data;
		Node* previous;
		Node* next;
		
		Node()
		{
			key=0;
			data=0;
			next=NULL;
			previous=NULL;
		}
		Node(int k,int d)
		{
			key=k;
			data=d;
		}
};
typedef Node* node;

class DLL {
	
	public:
	node head;
	
	DLL()
	{
		head=NULL;
	}
	DLL(node n)
	{
		head=n;
	}
	
	//1.Check whether the node exist using key value.
	node nodeExist(int k)
	{
		node temp=NULL;
		node ptr=head;
		
		while(ptr!=NULL)
		{
			if(ptr->key==k)
			{
				temp=ptr;
			}
			ptr=ptr->next;
		}
		return temp;
	}
	
	//2.Append a node to the list.
	void appendNode(node n)
	{
		if(nodeExist(n->key)!=NULL)
		{
			cout<<"Node already exists with the key value:"<<n->key<<". Append another Node with different key value. \n";
		}
		else
		{
			if(head==NULL)
			{
				head=n;
				cout<<"Node Appended \n";
			}
			else
			{
				node ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				n->previous=ptr;
				cout<<"Node Appended \n";
			}
		}
	}
	
	//3.Prepend a node to the list.
	void prependNode(node n)
	{
		if(nodeExist(n->key)!=NULL)
		{
			cout<<"Node already exists with the key value:"<<n->key<<". Prepend another Node with different key value. \n";
		}
		else
		{
			if(head==NULL)
			{
				head=n;
				cout<<"Node Appended \n";
			}
			else
			{
			head->previous=n;
			n->next=head;
			head=n;
			cout<<"Node Prepended \n";
			}
		}
	}
	
	//4.Insert a node after a particular key.
	void insertNodeAfter(int k,node n)
	{
		node ptr=nodeExist(k);
		if(ptr==NULL)
		{
			cout<<"No node exist with key value:"<<k<<endl;
		}
		else
		{
			if(nodeExist(n->key)!=NULL)
			{
				cout<<"Node already exists with the key value:"<<n->key<<". Insert another Node with different key value. \n";
			}
			else
			{
				node nextNode=ptr->next;
				
				//inserting at the end(appending)
				if(nextNode==NULL)
				{
					ptr->next=n;
					n->previous=ptr;
					cout<<"Node Inserted \n";
				}
				
				//inserting in between
				else
				{
					n->next=nextNode;
					nextNode->previous=n;
					n->previous=ptr;
					ptr->next=n;
					cout<<"Node Inserted";
				}
			}
		}
	}
	
	//5.Delete a node of a particular key(unlink).
	void deleteNodeByKey(int k)
	{
		node ptr=nodeExist(k);
		if(ptr==NULL)
		{
			cout<<"No node exist with the key value:"<<k<<endl;
		}
		else 					
		{
			//deleting at the start
			if(head->key==k)
			{
				head=head->next;
				cout<<"Node has been unlinked at the start with key value:"<<k<<endl;
			}
			else
			{
				node nextNode=ptr->next;
				node prevNode=ptr->previous;
				
				//deleting at the end
				if(nextNode==NULL)
				{
					prevNode->next=NULL;
					cout<<"Node has been unlinked at the end with key value:"<<k<<endl;
				}
				
				//deleting in between
				else
				{
					prevNode->next=nextNode;
					nextNode->previous=prevNode;
					cout<<"Node has been unlinked with the key value:"<<k<<endl;
				}
			}
		}
	}
	
	//6.Updating a Node of a particular key.
	void updateNodeByKey(int k,int d)
	{
		node ptr=nodeExist(k);
		if(ptr!=NULL)
		{
			ptr->data=d;
			cout<<"Node has been succesfully updated \n";
		}
		else
		{
			cout<<"No Node exist with the key value:"<<k<<endl;
		}
	}
	
	//7.Displaying our Doubly Linked Lists' Nodes.
	void printList()
	{
		if(head==NULL)
		{
			cout<<"List is empty \n";
		}
		else
		{
			cout<<"Doubly Linked Lists' Nodes: \n";
			node temp=head;
			
			while(temp!=NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<")<-->";
				temp=temp->next;
			}
		}
	}	
};

int main()
{
	DLL obj;
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


#include<iostream>
using namespace std;

/*  ~Create a node
    ~Create a Singly Linked List:
        1.Check whether node exist or not
        2.Appending a Node
        3.Prepending a Node
        4.Inserting a Node after a particular KEY
        5.Deleting a node of a particular KEY
        6.Updating a node of a particular KEY
        7.Displaying our Singly Linked Lists' Nodes
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
			data=k;
		}
};
typedef class Node* node;

class SLL {
	public:
	    node head;
	    
	    SLL()
	    {
    	    head=NULL;
	    }
	    SLL(node n)
	    {
	        head=n;
	    }
		
	    //1. To check if the node exists using key value.
	    node nodeExists(int k)
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
	    
	    //2.Append a node to the list at the end.
	    void appendNode(node n)
	    {
	        if(nodeExists(n->key)!=NULL)
	        {
	            cout<<"Node already exists with key value:"<<n->key<<". Append another node with different key value \n";
	        }
	        else 
	        {   
	        	if(head==NULL)
	        	{
	        		head=n;
	        	//	cout<<"Node Appended \n";	        		
	        	}
	        	else
	        	{
	        		node ptr=head;
	        		while(ptr->next!=NULL)
	        		{
	        			ptr=ptr->next;
	        		}
	        		ptr->next=n;
	        	//	cout<<"Node Appended \n";
	        	}
	        	cout<<"Node APPENDED \n";
	        }
	    } 
	    
	    //3.Prepend a node to the list at the first.
	    void prependNode(node n)
	    {
	    	if(nodeExists(n->key)!=NULL)
	        {
	            cout<<"Node already exists with key value:"<<n->key<<". Prepend another node with different key value \n";
	        }
	        else 
	        {
	        	n->next=head;
	        	head=n;
	        	cout<<"Node PREPENDED \n";
	        }
	    }
	    
	    //4.Inserting a node after a particular node(using key) in the list.
	    void insertNodeAfter(int k,node n) //Here k is the key value after which new node has to be inserted.
	    {
	    	node ptr=nodeExists(k);
	    	if(ptr==NULL)
	    	{
	    		cout<<"No node exists with key value:"<<k<<endl;
	    	}
	    	else
	    	{
	    		if(nodeExists(n->key)!=NULL)
	       		{
	        	    cout<<"\n Node already exists with key value:"<<n->key<<". Insert another node with different key value \n";
	            }
	        	else
	        	{
	        		n->next=ptr->next;
	        		ptr->next=n;
	        		cout<<"\nNode INSERTED \n";
	        	}
	    	}
	    }
	    
	    //5.Delete a node of a particular key
	    void deleteNodeByKey(int k)
	    {
	    	if(head==NULL)
	    	{
	    		cout<<"List is already empty \n";
	    	}
	    	else if(head!=NULL)
	    	{
				//Front node deletion.
	    		if(head->key==k)
	    		{
					node ptr=head;
	    			head=head->next;
	    			cout<<"Node UNLINKED with the key value:"<<k<<endl;
					delete ptr;
	    		}
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
	    		    if(temp!=NULL)
	    		    {
	    		        prevptr->next=temp->next;
	    		        cout<<"Node UNLINKED with key value:"<<k<<endl;
						delete temp;
	    	        }
	    	        else
	       	        {
	    		        cout<<"Node doesnt exist with key value:"<<k<<endl;
	    		    }
	    		}
	    	}
	    }
	    
	    //6.Update a node(using their key).
	    void updateNodeByKey(int k,int d)
	    {
	        node ptr=nodeExists(k);
	        if(ptr!=NULL)
	        {
	            ptr->data=d;
	            cout<<"Node data is UPDATED succesfully \n";
	        }
	        else
	        {
	            cout<<"Node doesnt exist with key value:"<<k<<endl;
	        }
	    }
	    
	    //7.Display all nodes of the list
	    void printList()
	    {
	        if(head==NULL)
	        {
	            cout<<"List is empty \n";
	        }
	        else
	        {
	            cout<<" \nSingly Linked Lists Nodes:";
	            node temp=head;
	            
	            while(temp!=NULL)
	            {
	                cout<<"("<<temp->key<<","<<temp->data<<")-->";
	                temp=temp->next;
	            }
	        }
	    }
};


int main()
{
    SLL s;
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
                s.appendNode(n1);                                                
                break;
            case 2:
                cout<<"\n Prepend Node Operation \nEnter key & data of the Node to be Prepended \n";
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                s.prependNode(n1);     
                break;
            case 3:
                cout<<"\n Insert Node Operation \n Enter the key value after which you want to insert new Node: \n";
                cin>>k1;
                cout<<"Enter the key & data of new node: \n";
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                s.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"\n Delete Node Operation \n Enter the key of node to be deleted: \n";
                cin>>k1;
                s.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"\n Update Node Operation \n Enter the key and new data to be updated: \n";
                cin>>key1>>data1;
                s.updateNodeByKey(key1,data1);                
                break;
            case 6:
                s.printList();
                break;
            default: cout<<"\n Enter proper option \n";
        }
    }
return 0;
}

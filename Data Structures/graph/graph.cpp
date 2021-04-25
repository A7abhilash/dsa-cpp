#include<iostream>
#include<stdlib.h>
using namespace std;

typedef class Graph graph;
class Graph{
    public:
        //for graph
        int V=-1;
        int matrix[20][20];

        //for queue
        int queue[20];
        int front=-1;
        int rear=-1;

        //for traversal
        int isVisited[20];
        
        void insertNewVertex(){
            if(V==19){
                cout<<"Graph matrix is full\n";
            }
            V++;
            for(int i=0;i<=V;i++){
                matrix[V][i]=0;
            }
            cout<<"New vertex: "<<V<<" added\n";
        }

        void insertNewEdge(){
            int i,u,v;
            cout<<"Enter new edge(from-->to): ";
            cin>>u>>v;

            if(u>=0 && u<=V && v>=0 && v<=V){
                if(matrix[u][v]==1){
                    printf("Edge already exists\n");
                }else{
                    matrix[u][v]=1;
                    matrix[v][u]=1;
                    printf("New edge(undirected) added between vertex: %d and vertex: %d.\n",u,v);
                }
            }else{
                printf("Invalid edge\n");
            }
        }
         
        void DFS(int u){
            cout<<u<<" ";
            isVisited[u]=1;

            for(int v=0;v<=V;v++){
                if(isVisited[v]==0 && matrix[u][v]==1){
                    DFS(v);
                }
            }
        }

        void DFSTraversal(){
            for(int i=0;i<=V;i++){
                isVisited[i]=0;
            }
            
            for(int i=0;i<=V;i++){
                if(isVisited[i]==0){
                    DFS(i);
                }
            }
        }   

        void BFS(int u){
            queue[++rear]=u;//Enqueue

            while(front!=rear){
                int v=queue[++front];//Dequeue
                cout<<v<<" ";
                isVisited[v]=1;

                for(int i=0;i<=V;i++){
                    if(isVisited[i]==0 && matrix[v][i]==1){
                        queue[++rear]=i;//Enqueue
                        isVisited[i]=1;
                    }
                }
            }
        }

        void BFSTraversal(){
            for(int i=0;i<=V;i++){
                isVisited[i]=0;
            }
            
            for(int i=0;i<=V;i++){
                queue[i]=0;
            }

            BFS(0);
        }        

        void displayGraph(){
            if(V==-1){
                printf("No graph exits\n");
                return;
            }
            printf("DFS: "); DFSTraversal();
            printf("\nBFS: "); BFSTraversal();
            printf("\n");
        }
};

int main(){
    graph G;

    int choice;
    while(1){
        printf("\n0.Exit\n1.Insert new vertex\n2.Insert new edge\n3.Display graph\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0: exit(0);
            case 1: G.insertNewVertex();break;
            case 2: G.insertNewEdge();break;
            case 3: G.displayGraph(); break;
            default: printf("Enter proper choice\n");
        }
    }
    return 0;
}
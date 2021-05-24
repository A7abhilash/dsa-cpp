#include<iostream>
#include<stdlib.h>
using namespace std;

//structure for graph
struct Graph{
    int V;
    int E;
    int matrix[20][20];
    int inDegree[20];
};
typedef struct Graph graph;

graph insertNewVertex(graph G){
    if(G.V==19){
		cout << "Graph matrix is full\n";
	}else{
        G.V++;
        for(int i=0;i<=G.V;i++){
            G.matrix[G.V][i]=0;
        }
		G.inDegree[G.V] = 0;
		cout << "New vertex: " << G.V << " added\n";
	}
    return G;
}

graph insertNewEdge(graph G){
    int i,u,v;
    cout<<"Enter new edge(from-->to): ";
    scanf("%d%d",&u,&v);

    if(u>=0 && u<=G.V && v>=0 && v<=G.V){
        if(G.matrix[u][v]==1){
            cout<<"Edge already exists\n";
        }else{
            G.matrix[u][v]=1;
			G.inDegree[v]++;
			cout << "New edge(directed) added from vertex: " << u << " to vertex: "<<v<< endl;
			G.E++;
        }
    }else{
		cout << "Invalid edge\n";
	}
    return G;
}

void topologicalSort(graph G){
    if(G.V==-1 || G.E==0){
		cout << "No graph exits\n";
		return;
    }

	int stack[G.V], top = -1;
	int topologicalOrder[G.V], order = -1;
	int i, u, v;

    for (u = 0; u <= G.V; u++){
        if(G.inDegree[u]==0){
            stack[++top] = u;
        }
    }

	for (i = 0; i <= G.V; i++){
		while(top!=-1){
			int w = stack[top--];
			topologicalOrder[++order] = w;

			for (v = 0; v <= G.V; v++){
                if(G.matrix[w][v]==1 && --G.inDegree[v]==0){
                    stack[++top] = v;
                }
            }
        }
    }

    // printf("Order: %d\n", order);
    if(order != G.V){
		cout << "Graph has cycle\n";
	}else{
		cout << "Topological Sort: ";
		for (i = 0; i <= G.V; i++){
			cout << topologicalOrder[i] << " ";
		}
		cout << endl;
	}
}

int main(){
    graph G;
    G.V=-1;
    G.E=0;

    int choice;
    while(1){
		cout << "\n0.Exit\n1.Insert new vertex\n2.Insert new edge\n3.Topological Sort\nEnter your choice:";
		cin >> choice;
		switch(choice){
            case 0: exit(0);
            case 1: G=insertNewVertex(G);break;
            case 2: G=insertNewEdge(G);break;
            case 3: topologicalSort(G); break;
            default:
				cout << "Enter proper choice\n";
		}
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;



struct Edge
{
    int a, b, wt;
};

struct Graph
{
    int v, e;
    struct Edge* edge;
};

struct Graph* create(int v, int e)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->v = v;
    graph->e = e;
 
    graph->edge = 
       (struct Edge*) malloc( graph->e * sizeof( struct Edge ) );
 
    return graph;
}
 
void print(int dist[], int n)
{
    cout<<"\nVertex Distance from Source";
    for (int i = 0; i < n; ++i)
        cout<<" \n"<< i<<"   \t"<<dist[i];
}
 
void func(struct Graph* graph, int src)
{
    int v = graph->v;
    int e = graph->e;
    int dist[e];
 	int i,j,x,y,wt;
 	
    for (i = 0; i < v; i++)
        dist[i]   = INT_MAX;
        
    dist[src] = 0;
 
    for (i = 1; i <= v-1; i++)
    {
        for (j = 0; j < e; j++)
        {
            x = graph->edge[j].a;
            y = graph->edge[j].b;
            wt = graph->edge[j].wt;
            if (dist[x] != INT_MAX && dist[x] + wt < dist[y])
                dist[y] = dist[x] + wt;
        }
    }
 
    for (i = 0; i < e; i++)
    {
        x = graph->edge[i].a;
        y = graph->edge[i].b;
        wt = graph->edge[i].wt;
        if (dist[x] != INT_MAX && dist[x] + wt < dist[y])
            cout<<"Graph contains negative weight cycle";
    }
 
    print(dist, v);
 
    return;
}
 
int main()
{
   
    int V,l,E,i,x,y,z;
    cout<<"Enter the number of vertices and edges\n";
    cin>>V>>E;
     int start_s=clock();

    struct Graph* graph = create(V, E);
    
 	cout<<"Enter the source vertex, destination vertex and weight of the edge\n";
 	for(i=0;i<E;i++)
 	{
 		cin>>x>>y>>z;
 		graph->edge[i].a=x;
 		graph->edge[i].b=y;
 		graph->edge[i].wt=z;
	}
 	
 
    func(graph, 0);
    int stop_s=clock();
	cout << "\n\nTime taken for execution: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << endl;

 
    return 0;
}

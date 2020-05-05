#include<bits/stdc++.h>
#define INF 900000
using namespace std;

// a class Edge which contains the following parameters: from node, to node and edge weight.
class Edge{

    public:
    int from, to;
    double cost;

    Edge(int f, int t, double c){
        from = f;
        to = t;
        cost = c;
    }
};

// edge creation, where each node in the graph is connected to an 'Edge' object which contains the nodes between which the edge is connected and the weight of the edge.
void createEdge(vector<vector<Edge> >& graph, int from, int to, double cost){
    graph[from].push_back(Edge(from, to, cost));
}

vector<double> bellmanFordSolver(vector<vector<Edge> > graph, int V, int s){
    vector<double> dist(V);
    for(int i = 0; i < V; i++)
        dist[i] = INF;
    // distance to start node is declared as 0.
    dist[s] = 0;

    // If a better distance from start node to given node is calculated it is updated with that value
    for(int i = 0; i < V - 1; i++)
        for(vector<Edge> edges: graph)
            for(auto edge: edges) 
                if(dist[edge.to] > dist[edge.from] + edge.cost)
                    dist[edge.to] = dist[edge.from] + edge.cost;

    // once a negative cycle is encountered, the distance values to the given node from the start node is set to negative infinity.
    for(int i = 0; i < V - 1; i++)
        for(vector<Edge> edges: graph)
            for(auto edge: edges) 
                if(dist[edge.to] > dist[edge.from] + edge.cost)
                    dist[edge.to] = -INF;
    return dist;
}

int main(){
    int E = 10;
    int V = 9;
    int start = 0;
    vector<vector<Edge> > graph;
    graph.resize(10);
    createEdge(graph, 0, 1, 1);
    createEdge(graph, 1, 2, 1);
    createEdge(graph, 2, 4, 1);
    createEdge(graph, 4, 3, -3);
    createEdge(graph, 3, 2, 1);
    createEdge(graph, 1, 5, 4);
    createEdge(graph, 1, 6, 4);
    createEdge(graph, 5, 6, 5);
    createEdge(graph, 6, 7, 4);
    createEdge(graph, 5, 7, 3);

    vector<double> d = bellmanFordSolver(graph, V, start);

    for(int i = 0; i < V; i++)
        cout<<"Distance between start node "<<start<<" and "<<i<<"th node is: "<<d[i]<<endl;
}
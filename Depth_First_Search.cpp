#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *adj;
    int V;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    // adjacency list creation
    void Edge(int u, int v){
        adj[u].push_back(v);
    }
    // recursive function for dfs: you start at a node, traverse the depth of the graph to visit all nodes, and then backtrack to repeat the process until all nodes are visited.
    void dfsRecursive(int s, bool visited[]){
        visited[s] = 1;
        cout<< s <<" ";
        list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); i++){
            if(!visited[*i])
                dfsRecursive(*i, visited);
        }

    }
    void DFS(int s){
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = 0;
        dfsRecursive(s, visited);
    }
};

int main(){
    Graph g(5);
    g.Edge(0,1);
    g.Edge(0,2);
    g.Edge(1,3);
    g.Edge(2,1);
    g.Edge(2,3);
    g.Edge(3,4);
    cout<<"Traversal Order:";
    g.DFS(0);
}
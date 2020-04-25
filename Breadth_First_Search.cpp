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

    void Edge(int u, int v){
        adj[u].push_back(v);
    }

    void BFS(int s){
        bool *visited = new bool[V];
        // marking all nodes as unvisited at first
        for(int i = 0; i < V; i++)
            visited[i] = 0;
        // an iterator to traverse through each row of the adjacency list
        list<int>::iterator i;
        // marking the start node as visited, because that's where we start
        visited[s] = 1;
        // a queue, essentially
        list<int> q;
        q.push_back(s);
        // iterate through the adjacency list until queue is empty. Once the first node is visited, the nodes connected to the start node are visited, then the nodes at the next level and so on.
        while(!q.empty()){
            s = q.front();
            q.pop_front();
            cout << s <<" ";
            // iterating through each row of the adjacency list
            for(i = adj[s].begin(); i != adj[s].end(); i++){
                // if the node has not been visited yet, mark it as visited, and push the node to a queue
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push_back(*i);
                }
            }
        }
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
    g.BFS(0);
}
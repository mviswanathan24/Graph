#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    // adjacency list creation
    void Edge(int u, int v){
        adj[u].push_back(v);
    }
    // similar implementation to DFS, but the depth of the graph is traversed, and the nodes visited are stored in a stack.
    void topSort(){
        bool *visited = new bool[V];
        stack<int> s;
        for(int i = 0; i < V; i++)
            visited[i] = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i])
                topSortRecursive(i, visited, s);
        }
        // the stack values are popped to get a topological ordering.
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    // recursive function to traverse the depth of the graph, and store the nodes visited in a stack.
    void topSortRecursive(int i, bool visited[], stack<int> &s){
        visited[i] = true;
        list<int>::iterator k;
        for(k = adj[i].begin(); k != adj[i].end(); k++){
            if(!visited[*k])
                topSortRecursive(*k, visited, s);
        }
        s.push(i);
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
    cout<<"Topological Sort Ordering:";
    g.topSort();
}
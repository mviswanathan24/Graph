#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, int parent, vector<int> &bridge, vector<bool> &visited, vector<int> &low_link, vector<int> &ids, int id);

void createEdge(vector<vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<int> bridgeDetection(vector<vector<int>> &graph, vector<int> &bridge, int V){

    int id = 0;
    vector<bool> visited(V);
    vector<int> low_link(V);
    vector<int> ids(V);

    for(int i = 0; i < V; i++){
        visited[i] = 0;
        low_link[i] = 0;
        ids[i] = 0;
    }

    for(int i = 0; i < V; i++)
        if(!visited[i])
            dfs(graph, i, -1, bridge, visited, low_link, ids, id);

    return bridge;
}

void dfs(vector<vector<int>> &graph, int node, int parent, vector<int> &bridge, vector<bool> &visited, vector<int> &low_link, vector<int> &ids, int id){
    visited[node] = 1;
    id++;
    low_link[node] = id;
    ids[node] = id;

    for(int x : graph[node]){
        if(x == parent)
            continue;
        if(!visited[x]){
            dfs(graph, x, node, bridge, visited, low_link, ids, id);
            low_link[node] = min(low_link[node], low_link[x]);
            if(ids[node] < low_link[x]){
                bridge.push_back(node);
                bridge.push_back(x);
            }
        }
        else
            low_link[node] = min(low_link[node], ids[x]); 
    }
}

int main(){
    int V = 9;
    vector<vector<int> > graph;
    graph.resize(V);
    createEdge(graph, 0, 1);
    createEdge(graph, 0, 2);
    createEdge(graph, 1, 2);
    createEdge(graph, 2, 3);
    createEdge(graph, 3, 4);
    createEdge(graph, 2, 5);
    createEdge(graph, 5, 6);
    createEdge(graph, 6, 7);
    createEdge(graph, 7, 8);
    createEdge(graph, 8, 5);

    vector<int> bridge;

    bridge = bridgeDetection(graph, bridge, V);

    for (int i = 0; i < bridge.size() / 2; i++) {
      int node1 = bridge[2*i];
      int node2 = bridge[2*i+1];
      cout<<"Bridge between nodes: " << node1 <<" and "<<node2 <<endl;
    }
}
#include<bits/stdc++.h>
#define INF 90000
#define V 5
using namespace std;

// Function prototype that prints the least possible distance between two nodes.
void distances(int dp[V][V]);

// Function prototype to retrace the path
vector<int> pathReconstruction(int start, int end);

// next is used to reconstruct path
int next[V][V];
// dp is used to store distances between each pair of nodes
int dp[V][V];

// The function Floyd_Warshall calculates the least possible distance between two nodes.
void Floyd_Warshall(int graph[V][V]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            ::next[i][j] = 0;
        }
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            ::dp[i][j] = graph[i][j];
            if(graph[i][j] != INF){
                ::next[i][j] = j;
            }
        }
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(::dp[i][k] + ::dp[k][j] < ::dp[i][j]){
                    ::dp[i][j] = ::dp[i][k] + ::dp[k][j];
                    ::next[i][j] = ::next[i][k];
                }
            }
        }
    }
    distances(dp);
}

// if no path exists between two distinct nodes, the output is INF, else the min distance is printed.
void distances(int dp[V][V]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dp[i][j] == INF)
                cout<< "INF" << "    ";
            else
                cout<< dp[i][j] <<"    ";
        }
        cout<< endl;
    }
}

// function to enable to retrace the nodes the algorithm has followed to obtain the minimum path length between two selected nodes.
vector<int> pathReconstruction(int start, int end){
    vector<int> path;
    if(::dp[start][end] == INF)
        return path;
    int i = start;
    for(; i != end; i = ::next[i][end]){
        if(i == -1)
            return vector<int>();
        path.push_back(i);
    }
    if(::next[i][end] == -1)
        return vector<int>();
    path.push_back(end);
    return path;
}

int main(){
    // Enter the number of nodes in your graph
    vector<int> path;
    int adj_matrix[V][V] = {{0, 5, 7, INF, INF},
                            {INF, 0 , 1, 1, INF},
                            {INF, INF, 0, 4, INF},
                            {INF, INF, INF, 0, 2},
                            {INF, INF, INF, INF, 0}};
    Floyd_Warshall(adj_matrix);              
    path = pathReconstruction(0, 3);  
    cout << "The reconstructed path is:"<<endl;
    for(int i = 0; i < path.size(); i++)
        cout<<path[i]<<" ";
    cout<<endl;
}
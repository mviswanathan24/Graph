#include<bits/stdc++.h>
#define INF 90000
#define V 5
using namespace std;

// Function prototype that prints the least possible distance between two nodes.
void distances(int dp[V][V]);

// The function Floyd_Warshall calculates the least possible distance between two nodes.
void Floyd_Warshall(int graph[V][V]){
    int dp[V][V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            dp[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dp[i][k] + dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
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

int main(){
    // Enter the number of nodes in your graph
    int adj_matrix[V][V] = {{0, 5, 7, INF, INF},
                            {INF, 0 , 1, 9, INF},
                            {INF, INF, 0, 4, INF},
                            {INF, INF, INF, 0, 2},
                            {INF, INF, INF, INF, 0}};
    Floyd_Warshall(adj_matrix);                
}
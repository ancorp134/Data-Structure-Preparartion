#include<bits/stdc++.h>
using namespace std;

// Adjacency Matrix 

int main(){

    int n,m;   // n: number of nodes , m: number of edges
    cin>>n>>m;
    
    int adj[n+1][m+1];  // declearing 2d matrix assuming 1 based index nodes.

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v ;  // taking input of edges.

        adj[u][v]=1;  // for directed graph
        adj[v][u]=1;
    }

}

// Adjacency list

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
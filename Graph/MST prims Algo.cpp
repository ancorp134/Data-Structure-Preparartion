#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> par(n+1,-1);

    key[1]=0;
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    pq.push({0,1});

    while(!pq.empty()){
        auto it= pq.top();
        int node=it.second;
        pq.pop();
        
        mst[node]=true;

        for(auto j: adj[node]){
            int f=j.first;
            int fw=j.second;

            if( !mst[f] && fw<key[f]){
                par[f]=node;
                key[f]=fw;
                pq.push({key[f],f});
            }    
        }
    }

    vector<pair<pair<int,int> ,int >> res;

    for(int i=2;i<=n;i++){
        res.push_back({{par[i],i},key[i]});
    }

    for(auto i:res){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    }

}
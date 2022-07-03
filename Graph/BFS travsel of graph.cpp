#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1 , false);

    vector<int> res;

    for (int i = 1; i <=n; i++)
    {
        if (!vis[i])
        {
            queue<int> que;
            que.push(i);
            vis[i]=true;
            while (!que.empty())
            {
                int node = que.front();
                que.pop();
                res.push_back(node);
                

                for (auto p : adj[node]){
                    if(!vis[p])
                        que.push(p);
                    vis[p] = true;
                }
            }
        }
    }
    for (auto i : res){
        cout << i << " ";
    }
}
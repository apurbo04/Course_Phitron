#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N];
int parent[N];
vector<int> adj[N];

void bfs(int s)
{
        vis[s] = true;

        queue<int> q;
        q.push(s);
        q.push(7);

        while (!q.empty())
        {
                int node = q.front();
                q.pop();
                
                for (int child : adj[node])
                {
                        if (!vis[child])
                        {
                                q.push(child);
                                parent[child] = node;
                                vis[child] = true;
                        }
                }
        }
}
int main()
{
        int n, e;
        cin >> n >> e;
        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        for (int i = 0; i < e; i++)
        {
                int x, y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }

        bfs(1);

        int dis = 4;
        vector<int> path;
        while (dis != -1)
        {
                path.push_back(dis);
                dis = parent[dis];
        }
        reverse(path.begin(), path.end());

        for (auto p : path)
        {
                cout << p << " ";
        }
        cout << endl; 
        return 0;
}
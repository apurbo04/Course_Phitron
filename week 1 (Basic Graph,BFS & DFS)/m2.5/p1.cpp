#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int level[1005];
bool vis[1005];
int parent[1005];
void bfs(int src)
{
        queue<int> q;
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
                int par = q.front();
                q.pop();
                for (int child : v[par])
                {
                        q.push(child);
                        vis[child] = true;
                        parent[child] = par;
                        level[child] = level[par] + 1;
                }
        }
}
int main()
{
        int n, e;
        cin >> n >> e;
        while (e--)
        {
                int a, b;
                cin >> a >> b;
                v[a].push_back(b);
                v[b].push_back(a);
        }
        int q;
        cin >> q;
        while (q--)
        {
                int src, des;
                cin >> src >> des;
                memset(vis, false, sizeof(vis));
                memset(level,-1,sizeof(level));
                memset(parent, -1, sizeof(parent));
                bfs(src);
                int x = des;
                vector<int> path;
                while (x != -1)
                {
                        path.push_back(x);
                        x = parent[x];
                }
                if (!path.empty())
                        cout << path.size() - 1 << endl;
                else
                        cout << "-1" << endl;
        }
        return 0;
}
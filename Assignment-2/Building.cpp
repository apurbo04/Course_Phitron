#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
        for (int i = 1; i <= n; i++)
        {
                parent[i] = -1;
                group_size[i] = 1;
        }
}
int dsu_find(int node)
{
        if (parent[node] == -1)
                return node;
        int leader = dsu_find(parent[node]);
        parent[node] = leader;
        return leader;
}
void dsu_union_by_size(int node1, int node2)
{
        int leaderA = dsu_find(node1);
        int leaderB = dsu_find(node2);
        if (group_size[leaderA] > group_size[leaderB])
        {
                parent[leaderB] = leaderA;
                group_size[leaderA] += group_size[leaderB];
        }
        else
        {
                parent[leaderA] = leaderB;
                group_size[leaderB] += group_size[leaderA];
        }
}
class Edge
{
public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
                this->u = u;
                this->v = v;
                this->w = w;
        }
};
bool cmp(Edge a, Edge b)
{
        return a.w < b.w;
}
int main()
{
        int n, e;
        cin >> n >> e;
        dsu_initialize(n);
        vector<Edge> edgeList;
        while (e--)
        {
                long long u, v, w;
                cin >> u >> v >> w;
                edgeList.push_back(Edge(u, v, w));
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        long long cost = 0;
        for (Edge ed : edgeList)
        {
                int lU = dsu_find(ed.u);
                int lV = dsu_find(ed.v);
                if (lU == lV)
                        continue;
                else
                {
                        dsu_union_by_size(ed.u, ed.v);
                        cost += ed.w;
                }
        }

        int real_leader = dsu_find(1);
        bool connected = true;
        for (int i = 1; i <= n; i++)
        {
                if (dsu_find(i) != real_leader)
                        connected = false;
        }
        if (connected)
                cout << cost;
        else
                cout << -1;

        return 0;
}
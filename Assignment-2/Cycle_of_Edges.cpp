#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int parent[N];
void dsu_initialize(int n)
{
        for (int i = 1; i <= n; i++)
        {
                parent[i] = -1;
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
void dsu_union(int lA, int lB)
{
        if (lA != lB)
                parent[lA] = lB;
}
int main()
{
        int n, e;
        cin >> n >> e;
        dsu_initialize(n);
        int edge_cnt = 0;
        while (e--)
        {
                int a, b;
                cin >> a >> b;
                int lA = dsu_find(a);
                int lB = dsu_find(b);
                if (lA == lB)
                        edge_cnt++;
                else
                        dsu_union(lA, lB);
        }
        cout << edge_cnt;
        return 0;
}
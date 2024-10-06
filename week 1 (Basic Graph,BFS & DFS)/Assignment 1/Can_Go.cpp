#include <bits/stdc++.h>
using namespace std;

int n, m;
char graph[1001][1001];
bool vis[1001][1001];
int a1, a2, b1, b2;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y)
{
        if (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == 'B') )
                return true;
        return false;
}

void dfs(int si, int sj)
{
        vis[si][sj] = true;
        for (int i = 0; i < 4; i++)
        {
                int ci = si + dx[i];
                int cj = sj + dy[i];
                if (valid(ci, cj) && !vis[ci][cj])
                {
                        vis[ci][cj] = true;
                        dfs(ci, cj);
                }
        }
}
int main()
{
        cin >> n >> m;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        cin >> graph[i][j];
                        if (graph[i][j] == 'A')
                        {
                                a1 = i;
                                a2 = j;
                        }
                        else if (graph[i][j] == 'B')
                        {
                                b1 = i;
                                b2 = j;
                        }
                }
        }
        dfs(a1, a2);

        if (vis[b1][b2] || a1 == b1 && a2 == b2)
                cout << "YES";
        else
                cout << "NO";
        return 0;
}
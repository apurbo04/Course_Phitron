#include <bits/stdc++.h>
using namespace std;

char graph[10001][10001];
bool vis[10001][10001];

int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1}; 

int n, m;

bool valid(int x, int y)
{
        if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.')
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
                if (valid(ci, cj) == true && vis[ci][cj] == false)
                {
                        vis[ci][cj] = true;
                        dfs(ci, cj);
                }
        }
}

int main()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        cin >> graph[i][j];
                }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        if (graph[i][j] == '.' && vis[i][j] == false)
                        {
                                dfs(i, j);
                                cnt++;
                        }
                }
        }
        cout << cnt << endl;
        return 0;
}
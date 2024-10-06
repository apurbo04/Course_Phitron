#include <bits/stdc++.h>
using namespace std;

char graph[10001][10001];
bool vis[10001][10001];

int dx[4] = {-1, 0, 1, 0}; // row move
int dy[4] = {0, 1, 0, -1}; // colomn move

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

void bfs(int si, int sj)
{
        queue<pair<int, int>> q;
        q.push({si, sj});
        vis[si][sj] = true;
        while (!q.empty())
        {
                pair<int, int> node = q.front();
                q.pop();
                int nrow = node.first;
                int ncol = node.second;

                for (int i = 0; i < 4; i++)
                {
                        int ci = nrow + dx[i]; // child row
                        int cj = ncol + dy[i]; // child column
                        if (valid(ci, cj) == true && vis[ci][cj] == false)
                        {
                                vis[ci][cj] = true;
                                q.push({ci, cj});
                                bfs(ci, cj);
                        }
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

        dfs(0, 0);

        if (vis[4][0])
                cout << "Possible";
        else
                cout << "Impossible";
        return 0;
}
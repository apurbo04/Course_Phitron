#include <bits/stdc++.h>
using namespace std;

char graph[10001][10001];
bool vis[10001][10001];

int dist[10001][10001]; // level

int dx[4] = {-1, 0, 1, 0}; // row move
int dy[4] = {0, 1, 0, -1}; // colomn move

int n, m;

bool valid(int x, int y)
{
        if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.')
                return true;
        return false;
}

void bfs(int si, int sj)
{
        queue<pair<int, int>> q;
        q.push({si, sj});
        vis[si][sj] = true;
        dist[si][sj] = 0;

        while (!q.empty())
        {
                pair<int, int> node = q.front();
                q.pop();
                int nrow = node.first;
                int ncol = node.second;
                // parent ase (nrow,ncol) coordinate e
                for (int i = 0; i < 4; i++)
                {
                        int ci = nrow + dx[i]; // child row
                        int cj = ncol + dy[i]; // child column
                        if (valid(ci, cj) == true && vis[ci][cj] == false)
                        {
                                vis[ci][cj] = true;
                                dist[ci][cj] = dist[nrow][ncol] + 1;
                                q.push({ci, cj});
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

        int sr, sc;
        cin >> sr >> sc;
        int dr, dc;
        cin >> dr >> dc;

        bfs(sr, sc);

        if (vis[dr][dc])
                cout << "Shortest distance: " << dist[dr][dc];
        else
                cout << "Impossible";
        return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char a[N][N];
bool vis[N][N];

int n, m;
int cnt = 0;
char graph[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int x, int y)
{
        return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.');
}
vector<int> v;
void dfs(int si, int sj)
{
        vis[si][sj] = true;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if (valid(ci, cj) && !vis[ci][cj])
                {
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
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        if (graph[i][j] == '.' && vis[i][j] == false)
                        {
                                dfs(i, j);
                                v.push_back(cnt);
                                cnt = 0;
                        }
                }
        }
        sort(v.begin(),v.end());
        if(!v.empty())
        cout<<v.front();
        else cout<<-1;
        return 0;
}
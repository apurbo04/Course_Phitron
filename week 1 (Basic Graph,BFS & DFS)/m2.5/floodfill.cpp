class Solution {
public:
 
bool vis[1001][1001];
 
int n  , m ; 
 
vector<vector<int>>img ; 
int valid_int ;
int clr ; 
 
int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move
 
 
bool valid(int x, int y)
{
 
 
    cout << n << " " << m << endl ;
 
 
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && img[x][y]==valid_int)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    img[si][sj] = clr ;
 
    cout << si << " " << sj << endl ;
 
 
 
    for (int i = 0; i < 4; i++)
    {
 
        int ci = si + dx[i]; // children er row
        int cj = sj + dy[i]; // children er column
       // cout << ci << " " << cj << " " <<  valid(ci,cj) << endl ;
 
        if (valid(ci, cj) && vis[ci][cj] == false)
        {
            vis[ci][cj] = true;
 
 
            img[ci][cj] = clr ;
            dfs(ci, cj);
        }
    }
}
 
 
 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
 
        memset(vis,false,sizeof(vis)) ;
 
        img = image ;
 
        vector<int> a = img[0] ;
 
 
         n = img.size() ;
         m = a.size() ;
 
         valid_int = image[sr][sc] ;
 
        clr = color ;
       // cout << n << " " << m << endl ;
 
        dfs(sr,sc) ;
 
        return img ;
 
 
 
 
 
 
 
    }
};
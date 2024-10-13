#include <bits/stdc++.h>
using namespace std;
int subset_sum(int n, int a[], int s)
{
        if (n == 0)
        {
                if (s == 0)
                        return 1;
                else
                        return 0;
        }
        if (dp[n][s] != -1)
                return dp[n][s];
        if (a[n - 1] <= s)
        {
                int op1 = subset_sum(n - 1, a, s - a[n - 1]);
                int op2 = subset_sum(n - 1, a, s);
                return dp[n][s] = op1 + op2;
        }
        else
                return dp[n][s] = subset_sum(n - 1, a, s);
}
int main()
{
        int n;
        cin >> n;
        int a[n], s = 0;
        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
                s += a[i];
        }
        int dp[n + 1][s + 1];
        for (int i = 1; i <= s; i++)
        {
                dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= s; j++)
                {
                        if (a[i - 1] <= j)
                        {
                                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                        }
                        else
                        {
                                dp[i][j] = dp[i - 1][j];
                        }
                }
        }
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {
                for (int j = 0; j <= s; j++)
                {
                        if (dp[i][j] == 1)
                                v.push_back(j);
                }
        }
        int ss = INT_MIN;
        int sd = INT_MAX;
        for (int val : v)
        {
                int s1 = val;
                int s2 = s - s1;
                sd = min(sd, abs(s1 - s2));
                ss = max(ss, abs(s1 + s2));
        }
        int sk = (ss+sd)/2;
        for (int i = 0; i <= n; i++)
        {
                for (int j = 0; j <= sk; j++)
                {
                        dp[i][j] = -1;
                }
        } 
        cout << subset_sum(n, dp, sk);
        return 0;
}
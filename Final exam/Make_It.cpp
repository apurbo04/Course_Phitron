#include <bits/stdc++.h>
using namespace std;
int input;
int dp[100005];

bool rec(int n)
{
        if (n > input)
                return false;
        if (n == input)
                return true;

        if (dp[n] != -1)
                return dp[n];
                
        dp[n] = rec(n +3) || rec(n * 2);
        return rec(n +3) || rec(n * 2);
}
int main()
{
        int t;
        cin >> t;
        while (t--)
        {
                cin >> input;
                memset(dp, -1, sizeof(dp));
                bool flag = rec(1);
                if (flag)
                        cout << "YES" << endl;
                else
                        cout << "NO" << endl;
        }
        return 0;
}
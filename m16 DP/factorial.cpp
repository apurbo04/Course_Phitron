#include <bits/stdc++.h>
using namespace std;
//O(n)
int fact(int n)
{
        if (n == 0)
                return 1;  
        int ans = fact(n - 1);
        return ans * n;
}
int main()
{
        int n;
        cin >> n;
        int ans=1;
        // cout << fact(n) << endl;

        //O(n)
        for (int i = 1; i <= n; i++)
        {
                ans*=i;
        }
        cout<<ans;
        return 0;
}
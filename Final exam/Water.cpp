#include <bits/stdc++.h>
using namespace std;

int main()
{
        int t;
        cin >> t;
        while (t--)
        {
                int n;
                cin >> n;
                int a[n];
                int x = INT_MIN;
                int y = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                        cin >> a[i];
                        if (a[i] > x)
                                x = a[i];
                }
                for (int i = 0; i < n; i++)
                {
                        if (a[i] != x)
                        {
                                if (a[i] > y)
                                        y = a[i];
                        }
                }
                for (int i = 0; i < n; i++)
                {
                        if (a[i] == x || a[i] == y)
                                cout << i << " ";
                }
                cout << endl;
        }
        return 0;
}
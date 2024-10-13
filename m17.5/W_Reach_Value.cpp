#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll x;
bool check(ll t)
{
        if (t > x)
                return false;
        else if (t == x)
                return true;
        else
                return check(t * 10) || check(t * 20);
}
int main()
{
        ll t;
        cin >> t;
        while (t--)
        {
                cin >> x;
                check(1) ? cout << "YES\n" : cout << "NO\n";
        }
}

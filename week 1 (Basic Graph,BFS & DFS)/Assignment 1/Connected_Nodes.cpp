#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, e;
        cin >> n >> e;
        vector<int> ar[n];
        while (e--)
        {
                int a, b;
                cin >> a >> b;
                ar[a].push_back(b);
                ar[b].push_back(a);
        }

        int q;
        cin >> q;
        while (q--)
        {
                set<int, greater<int>> s;
                int x;
                cin >> x;
                for (int i = 0; i < ar[x].size(); i++)
                {
                        s.insert(ar[x][i]);
                }
                if (!s.empty())
                        for (auto ans : s)
                                cout << ans << " ";
                else
                        cout << "-1";
                cout << endl;
        }
        return 0;
}
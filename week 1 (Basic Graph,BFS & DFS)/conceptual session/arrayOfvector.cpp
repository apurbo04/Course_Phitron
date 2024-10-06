#include<bits/stdc++.h>
using namespace std;

/*
undirected graph
3 3

0 1
0 2
1 2

*/

vector<int> arr[100]; 

int main()
{

        int n,e;
        cin>>n>>e;
        while(e--)
        {
                int v,u;
                cin>>v>>u;

                arr[u].push_back(v);
                arr[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
                cout<<i<<" => ";
                for (int j= 0; j < arr[i].size(); j++)
                {
                        cout<<arr[i][j]<<" ";
                }
                cout<<endl;
        }
        
        return 0;
}
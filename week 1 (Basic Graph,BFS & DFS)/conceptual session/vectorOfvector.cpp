#include<bits/stdc++.h>
using namespace std;

int main()
{
        vector<vector<int>> arr1;
        
        arr1.push_back(vector<int>({1,2,3}));
        arr1.push_back(vector<int>({4,5,6}));

        cout<<arr1.size()<<endl;   //row size of arr1
        cout<<arr1[0].size()<<endl;  //colum size of arr1 
       
        arr1[0].push_back(9);
        for (int i = 0; i < arr1.size(); i++)
        {
                for (int j = 0; j < arr1[i].size(); j++)
                {
                        cout<<arr1[i][j]<<" ";
                }
                cout<<endl;
        }
        
        return 0;
}
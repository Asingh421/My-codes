#include <bits/stdc++.h>
using namespace std;
int max_sum(int arr[][4],int l,int x,int y,int r)
{
          if(x==r)
            return arr[x][y];
          else
            {int a1=max_sum(arr,l+1,x+1,y,r)+arr[x][y];
             int a2=max_sum(arr,l+1,x+1,y+1,r)+arr[x][y];
             //cout<<a1<<" ";
             return max(a1,a2);
            }




}
int main()
  {int arr[4][4]={{8, 0, 0,0},
                      {-4, 4, 0,0},
                      {2, 2, 6,0},{1,1,1,1}};
    cout<<max_sum(arr,0,0,0,3);
    //cout<<"YES";
  }

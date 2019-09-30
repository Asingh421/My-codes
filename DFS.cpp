#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int color[6], d[6], pi[6], f[6];
int t;
void DFS_visit(int n,int u)
     {color[u]=2;
     cout<<u<<" ";
      t++;
      d[u]=t;
      for(int i=0;i<n;i++)
        {if(arr[u][i]==1)
            {if(color[i]==1)
                {pi[i]=u;
                 DFS_visit(n,i);}

          color[u]=3;
          f[u]=(++t);}

        }

     }

void DFS(int n)
  {for(int i=0;i<n;i++)
     {color[i]=1;
      pi[i]=-1;}
      t=0;
   for(int i=0;i<n;i++)
     {if(color[i]==1)
        DFS_visit (n, i);
     }

    }



int main()
 {
    int n,m;
  cin>>n>>m;
  //int arr[n][n];
  for(int i=0;i<100;i++)
     {for(int j=0;j<n;j++)
       {arr[i][j]=0;}
      }
  for(int i=0;i<m;i++)
     {int x,y;
      cin>>x>>y;
       arr[x][y]=1;
     }
  //int color[n],d[n],pi[n],f[n];//white=1,grey=2,black=3
  DFS(n);
  for(int i=0;i<n;i++)
  {
      cout<<d[i]<<" "<<f[i]<<" "<<pi[i]<<endl;
  }

 }

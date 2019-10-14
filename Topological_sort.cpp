/*Topological sort*/
#include<bits/stdc++.h>
using namespace std;
int arr[100][100],color[100],pi[100],d[100],f[100],n,t;
stack<int> s;
void dfs_visit(int u)
  {color[u]=2;
   t++;
   d[u]=t;

   for(int i=0;i<n;i++)
     {if(arr[u][i]==1&&color[i]==1)
        {
          dfs_visit(i);
        }

     }
     t++;
     f[u]=t;
     color[u]=3;
     s.push(u);

   }
void dfs()
  {for(int i=0;i<n;i++)
    {
      color[i]=1;

    }
    t=0;
    for(int i=0;i<n;i++)
    {if(color[i]==1)
       dfs_visit(i);

    }

  }


int main()
 {cin>>n;
  int e;
  cin>>e;
 for(int i=0;i<e;i++)
  {int x,y;
   cin>>x>>y;
   arr[x][y]=1;

  }
  dfs();
  while(!s.empty())
   {cout<<s.top()<<" ";
    s.pop();
   }
 }

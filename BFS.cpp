#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int n,m;
  cin>>n>>m;
  int arr[n][n];
  for(int i=0;i<n;i++)
     {for(int j=0;j<n;j++)
       {arr[i][j]=0;}
      }
  for(int i=0;i<m;i++)
     {int x,y;
      cin>>x>>y;
       arr[x][y]=1;
     }
  int color[n],d[n],pi[n];//white=1,grey=2,black=3
     for(int i=1;i<n;i++)
       {color[i]=1;
        d[i]=INT_MAX;
        pi[i]=-1;
        }
        color[0]=2;
        d[0]=0;
        pi[0]=-1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
           {int u=q.front();
            q.pop();
            for(int i=0;i<n;i++)
             {if(arr[u][i]!=0)
                {if(color[i]==1)
                  {color[i]=2;
                   d[i]=d[u]+1;
                   pi[i]=u;
                   q.push(i);
                  }

                }

             }
             color[u]=3;

           }
           for(int i=1;i<n;i++)
           {
               cout<<"Distance of vertex"<<i<<"from vertex 0 is"<<d[i]<<endl;
           }
           int dist;
           cout<<"ENTER where you want to reach"<<endl;
           cin>>dist;
           cout<<dist<<"<-";
           while(dist!=0)
           {cout<<pi[dist]<<"<-";
            dist=pi[dist];

           }

 }

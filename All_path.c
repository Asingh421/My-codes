#include <stdio.h>
#include <stdlib.h>
#define M 100000
int arr[100][100],color[100],pi[100],n,e,key[100],v,u,d[100],flow=0,f[100][100],rgraph[100][100],S,T,path_index=0;
int q[100],front=0,rear=0,path[100];
void dfs_visit(int s,int t)
{color[s]=2;
 path[path_index]=s;
 path_index++;
 if(s==T)
 {
     for(int i=0;i<path_index;i++)
     {printf("%d ",path[i]);

     }
     printf("\n");
 }

 for(int i=0;i<n;i++)
   {if(color[i]==1&&arr[s][i]!=0)
      {
       dfs_visit(i,t);
       pi[i]=s;

      }


    }

    color[s]=1;
    path_index--;


}
 int main()
   {int x,y;
       scanf("%d",&n);
    for(int i=0;i<8;i++)
       {
          {scanf("%d%d",&x,&y);
           arr[x][y]=1;
           arr[y][x]=1;
           //rgraph[i][j]=arr[i][j];
           }
        }

        for(int i=0;i<n;i++)
         {
          color[i]=1;
         }
         S=0,T=5;
        dfs_visit(0,5);


   }



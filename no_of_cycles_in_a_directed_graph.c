#include <stdio.h>
#include <stdlib.h>
int arr[100][100],d[100],f[100],color[100],pi[100],n,t,front=0,rear=0,size=0,stack[100],scc=0,cycle=0;

void dfs()
  {for(int i=0;i<n;i++)
    {color[i]=1;
     pi[i]=-1;
    }
    for(int i=0;i<n;i++)
      {if(color[i]==1)
        dfs_visit(i);
       }

  }

void dfs_visit(int u)
  {color[u]=2;
   t++;
   d[u]=t;
   for(int i=0;i<n;i++)
    {if(arr[u][i]==1)
       {if(color[i]==1)
         {         pi[i]=u;
             dfs_visit(i);
         }

      else if(color[i]==2&&pi[u]!=i)
        {cycle++;
         printf("%d->",u);

         for(int j=u;j!=i;)
          {printf("%d->",pi[j]);
           j=pi[j];
          }
          printf("\n");
        }
       }
    }
    color[u]=3;
    t++;
    f[u]=t;

  }

  int main()
   {int e;
    printf("Enter no of verte:");
    scanf("%d",&n);
    printf("Enter no of edges:");
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {int x,y;
     scanf("%d%d",&x,&y);
     arr[x][y]=1;
     arr[y][x]=1;


    }
     dfs();
     printf("NO of cycles are:%d",cycle);
   }

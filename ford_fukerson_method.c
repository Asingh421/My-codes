/*Name:Abhay Singh
  Roll no:1801CS66*/
#include <stdio.h>
#include <stdlib.h>
#define M 100
#define INT_MAX 1000000
int arr[M][M],color[M],n,pi[M],d[M],brr[M][M],m=0;
int q[M],front=0,end=0;
int min(int a,int b)
{if(a<b)
  return a;
  else
    return b;

}
int bfs(int s,int t)
  {for(int i=1;i<=n;i++)
     {pi[i]=-1;
      color[i]=1;
     }
    color[s]=2;
    q[end]=s;
    end++;
    while(front!=end)
     {int u=q[front];
        for(int i=1;i<=n;i++)
        {if(brr[u][i]!=0&&color[i]==1)
             {q[end]=i;
             end++;
             color[i]=2;
             pi[i]=u;}


        }
        front++;

     }
     if(color[t]==2)
        return 1;
     else
        return 0;

  }
int ford_fukerson()
  {for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
     brr[i][j]=arr[i][j];
    }
    int s=1,t=6;
   while(bfs(1,6))
   {int path_flow=INT_MAX;
     for(int i=t;i!=s;i=pi[i])
         {path_flow=min(path_flow,brr[pi[i]][i]);}
     for(int i=t;i!=s;i=pi[i])
         {brr[pi[i]][i]-=path_flow;
          brr[i][pi[i]]+=path_flow;
         }
       m+=path_flow;
   }

  }

   int main()
    { n=6;
    // Let us create a graph shown in the above example
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
             scanf("%d",&arr[i][j]);
                      ford_fukerson();
    for(int i=1;i<=n;i++)
        {for(int j=1;j<=n;j++)
            {
              printf("%d ",brr[i][j]);

            }
            printf("\n"); }
    printf( "The maximum possible flow is %d" ,m);

    return 0;
   }


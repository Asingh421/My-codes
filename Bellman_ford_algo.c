/*Name:Abhay Singh
  Roll no:1801CS66*/
#include <stdio.h>
#include <stdlib.h>
#define M 100
#define INT_MAX 1000000
int arr[M][M],color[M],n,pi[M],w=0,e,d[M];
//function two find minimum of two numbers
struct edge
  {int start;
   int end;
   int weight;
  };
void bellman(struct edge ed[])
  {//printf("%d ",ed[0].weight);
      for(int i=0;i<n;i++)
    {d[i]=INT_MAX;}
    d[0]=0;
    for(int i=0;i<n-1;i++)
      {for(int j=0;j<e;j++)
        {int a=ed[j].start;
         int b=ed[j].end;
         if(d[b]>d[a]+ed[j].weight&&d[a]!=INT_MAX)
             d[b]=d[a]+ed[j].weight;
        }

      }
      for(int j=0;j<e;j++)
      {int a=ed[j].start;
       int b=ed[j].end;
       if(d[b]>(d[a]+ed[j].weight))
          return;

      }

   }
int main()
{printf("Enter no of vertex:");
 scanf("%d",&n);
 printf("Enter no of edges:");
 scanf("%d",&e);

 struct edge ed[e];
 for(int i=0;i<e;i++)
   {int a,b,w;
    scanf("%d%d%d",&a,&b,&w);
    ed[i].start=a;
    ed[i].end=b;
    ed[i].weight=w;

   }
 for(int i=0;i<=n;i++)
   {for(int j=0;j<=n;j++)
     {
       arr[i][j]=0;
     }

   }

     bellman(ed);
   //qsort(ed,e,sizeof(ed[1]),comp);
//printf("%d",ed[0].start);

   //printf("Require edges and their edge weight are:\n");
   printf("vertx  weight\n");
   for(int i=0;i<n;i++)
   {
       printf("%d %d\n",i,d[i]);
   }

  // printf("\nMINIMUM COST OF TREE=%d",w);

}

/*Name:Abhay Singh
  Roll no:1801CS66*/
#include <stdio.h>
#include <stdlib.h>
#define M 100
int arr[M][M],color[M],n,pi[M],w=0,e;
//function two find minimum of two numbers
struct edge
  {int start;
   int end;
   int weight;
  };
int comp(const void *p,const void *q)
  {int l = ((struct edge *)p)->weight;
    int r = ((struct edge *)q)->weight;
    return (l - r);

  }
void makeset()
  {for(int i=0;i<n;i++)
     {
      arr[i][i]=1;
     }

  }
int findset(int v)
    {for(int i=0;i<n;i++)
        {if(arr[i][v]==1)
            return i;

        }
    }
void union_set(int u,int v)
   {if(u<v)
      {for(int i=0;i<n;i++)
         {if(arr[v][i]==1)
             {arr[u][i]=1;
              arr[v][i]=0;
            }

         }

      }
    if(u>v)
      {for(int i=0;i<n;i++)
         {if(arr[u][i]==1)
             {arr[v][i]=1;
              arr[u][i]=0;
             }

         }

      }

   }
void kruskal(struct edge ed[])
    {makeset();
     for(int i=0;i<e;i++)
       {if(findset(ed[i].start)!=findset(ed[i].end))
            {
             pi[ed[i].end]=ed[i].start;

             printf("  %d    %d    %d\n",ed[i].start,ed[i].end,ed[i].weight);
             w+=ed[i].weight;
            }


         union_set(findset(ed[i].start),findset(ed[i].end));}

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
 for(int i=0;i<n;i++)
   {for(int j=0;j<n;j++)
     {
       arr[i][j]=0;
     }

   }

   qsort(ed,e,sizeof(ed[0]),comp);


   printf("Require edges and their edge weight are:\n");
   printf("Start end weight\n");
   kruskal(ed);
   printf("\nMINIMUM COST OF TREE=%d",w);

}

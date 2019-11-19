/*Name:Abhay Singh
  Roll no:1801CS66*/
#include <stdio.h>
#include <stdlib.h>
int arr[100][100],d[100],f[100],color[100],pi[100],n,t,front=0,rear=0,size=0,stack[100],scc=0;
int brr[100][100],d1[100],f2[100],color1[100],pi1[100],n,t1,s[100],f1=0,e1=0;
void push(int a)
   {
    stack[rear]=a;
    rear++;
    size++;
    }
void dfs()
   {int i;
       for( i=1;i<=n;i++)
      {color[i]=1;
       pi[i]=-1;

      }
      t=0;
    for( i=1;i<=n;i++)
     {if(color[i]==1)
       {
        dfs_visit(i);
       }

     }

   }
 void dfs_visit(int u)
   {int i;
       color[u]=2;
    t++;
    d[u]=t;
    for( i=1;i<=n;i++)
      {if(arr[u][i]==1)
          {if(color[i]==1)
             {pi[i]=u;
              dfs_visit(i);}

          }}
        color[u]=3;
        t++;
        f[u]=t;
        push(u);

      }

 void dfs1()
   {int i,j,k;
     for(i=1;i<=n;i++)
      {color1[i]=1;
       pi1[i]=-1;

      }
      t1=0;
    for( i=1;i<=n;i++)
     { j=stack[rear];


       rear--;
      if(color1[j]==1)
       {
        dfs_visit1(j);
           printf("\n");
           for( k=f1;k<e1;k++)
             printf("%d ",s[k]);
           f1=e1;
           scc++;



       }

     }

   }
 void dfs_visit1(int u)
   {int i;
    color1[u]=2;
    t1++;
    d1[u]=t1;
    for( i=1;i<=n;i++)
      {if(brr[u][i]==1)
          {if(color1[i]==1)
             {pi1[i]=u;
              dfs_visit1(i);}

          }}
        color1[u]=3;
        t1++;
        f2[u]=t1;
        s[e1]=u;
        e1++;




      }



int main()
{int i;
 printf("Enter no of vertex:");
 scanf("%d",&n);
 int v;
 printf("Enter no of edges:");
 scanf("%d",&v);
 printf("Enter edges:\n");
 for( i=1;i<=v;i++)
 {int x,y;
  scanf("%d%d",&x,&y);
  arr[x][y]=1;
  brr[y][x]=1;

 }




 dfs();



printf("Strongly Connected Components are\n");
dfs1();

printf("\nNo of strongly connected component=%d\n",scc);


}

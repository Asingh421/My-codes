/*Name:Abhay Singh
  Roll no:1801CS66*/
#include <stdio.h>
#include <stdlib.h>
#define M 100
#define INT_MAX 1000000
int arr[M][M],color[M],n,pi[M],w=0,e,d[M];
//function two find minimum of two numbers
int min(int a,int b)
 {if(a<b)
    return a;
  else
    return b;

 }
void floyd_wars()
 {for(int k=1;k<=n;k++)
   {for(int i=1;i<=n;i++)
      {for(int j=1;j<=n;j++)
         {arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);}
       }
    }

 }
int main()
{printf("Enter no of vertex:");
 scanf("%d",&n);
 printf("Enter no of edges:");
 scanf("%d",&e);

 for(int i=1;i<=n;i++)
 {for(int j=1;j<=n;j++)
    {if(i==j)
      arr[i][j]=0;
    else
      arr[i][j]=INT_MAX;
    }

 }
 for(int i=0;i<e;i++)
   {int a,b,w;
    scanf("%d%d%d",&a,&b,&w);
     arr[a][b]=w;
    }

     floyd_wars();
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
  {
      printf("%d ",arr[i][j]);
  }
 printf("\n");
}


}

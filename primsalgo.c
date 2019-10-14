#include <stdio.h>
#include <stdlib.h>
#define M 1000000
int arr[100][100],color[100],pi[100],key[100], n;
int min_ver()
{int min=M,mini=-1;
  for(int i=0;i<n;i++)
   {if(color[i]==1&&key[i]<min)
     {min=key[i];
      mini=i;

     }

   }

 return mini;
}
void prim()
  {for(int i=0;i<n;i++)
     {color[i]=1;
      pi[i]=-1;
      key[i]=M;
      }

      key[0]=0;
      pi[0]=-1;
      int min_v;
      for(int i=0;i<n-1;i++){

      min_v=min_ver();
      color[min_v]=2;

      {for(int j=0;j<n;j++)
         {if(color[j]==1&&arr[min_v][j]!=0&&arr[min_v][j]<key[j])
            {key[j]=arr[min_v][j];
             pi[j]=min_v;


            }

         }

      }

  }}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
      scanf("%d",&arr[i][j]);

    }
    prim();

        printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", pi[i], i, arr[i][pi[i]]);

}

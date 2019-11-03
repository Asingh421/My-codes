#include<bits/stdc++.h>
#define M 100
#define INT_MAX 1000000

using namespace std;

int arr[M][M],color[M],n,pi[M],w=0,e,d[M],h[M],brr[M][M];
struct edge
  {int start;
   int end;
   int weight;

  };

int min_ver()
{int min=M,mini=-1;
for(int i=1;i<=n;i++)
{if(color[i]==1&&d[i]<min)
{min=d[i];
 mini=i;
}
}
return mini;
}

void dijkstra(int s)
{for(int i=1;i<=n;i++)
{color[i]=1;
pi[i]=-1;
d[i]=INT_MAX;
}
d[s]=0;
pi[s]=-1;
int min_v;
for(int i=1;i<=n-1;i++){
min_v=min_ver();
color[min_v]=2;
{for(int j=1;j<=n;j++)
        {if(color[j]==1&&arr[min_v][j]<INT_MAX&&arr[min_v][j]+d[min_v]<d[j])
          {d[j]=arr[min_v][j]+d[min_v];
           pi[j]=min_v;

          }

        }
}
               }
     }


int bellman(struct edge ed[])
  {//printf("%d ",ed[0].weight);
      for(int i=0;i<=n;i++)
        {h[i]=INT_MAX;}
        h[0]=0;
    for(int i=0;i<=n-1;i++)
      {
        for(int j=0;j<e+n;j++)
        {int a=ed[j].start;
         int b=ed[j].end;
         if(h[b]>h[a]+ed[j].weight&&h[a]!=INT_MAX)
             {h[b]=h[a]+ed[j].weight;

                 }
        }

      }
      for(int j=0;j<e+n;j++)
      {int a=ed[j].start;
       int b=ed[j].end;
       if(h[b]>(h[a]+ed[j].weight))
          {//cout<<a<<j<<" "<<d[b]<<" "<<d[a]+ed[j].weight<<" "<<d[a];

              return 0;}

      }
     return 1;
   }
int main()
{printf("Enter no of spaceport:");
scanf("%d",&n);
printf("Enter no of flight:");
scanf("%d",&e);
for(int i=0;i<=n;i++)
{for(int j=0;j<=n;j++)
{if(i==j)
  arr[i][j]=0;
  else
    arr[i][j]=3*INT_MAX;

}
}
struct edge ed[M];
printf("Enter source destination and time:\n");

for(int i=0;i<e;i++)
{int a,b,w;
 scanf("%d%d%d",&a,&b,&w);
 ed[i].start=a;
 ed[i].end=b;
 ed[i].weight=w;

}
int vert=1;
for(int i=e;i<=e+n;i++)
{
 ed[i].start=0;
 ed[i].end=vert;
 ed[i].weight=0;
 vert++;

}

bellman(ed);
for(int i=1;i<=n;i++)
{
    cout<<h[i]<<" ";

}
cout<<endl;

for(int i=0;i<e;i++)
{if(h[ed[i].start]<INT_MAX&&h[ed[i].end]<INT_MAX)
    arr[ed[i].start][ed[i].end]=ed[i].weight+h[ed[i].start]-h[ed[i].end];
 ed[i].weight=arr[ed[i].start][ed[i].end];

}

for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
  {cout<<arr[i][j]<<" ";

  }
 cout<<endl;
}
cout<<endl;

for(int i=1;i<=n;i++)
{dijkstra(i);
 for(int j=1;j<=n;j++)
 {
      cout<<d[j]<<" "<<h[j]<<" "<<h[i];

       brr[i][j]=d[j]+h[j]-h[i];
       cout<<brr[i][j]<<"-";
 }
cout<<endl;
}
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
  {if(i!=j&&brr[i][j]==0)
      brr[i][j]=INT_MAX;
  }

}
printf("Distance MAtrix is\n");
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
{
 printf("%d ",brr[i][j]);
}

printf("\n");

}

int min_n=0,mini=INT_MAX;

for(int i=1;i<=n;i++)
{int sum=0;
for(int j=1;j<=n;j+=1)
{
{sum+=brr[i][j];
}
}
if(sum<mini)
{mini=sum;
min_n=i;
}

}
printf("\nSource vertex must be:%d",min_n);
}






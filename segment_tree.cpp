 /*===================*\
|ID : harryPotter_421  |
|      LANG: C++       |
\*====================*/
#include <iostream>
#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define ld  double
#define mp make_pair
#define f(j,m,n) for(lli j=m;j<n;j++)
#define harry ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define forn(n) for(i=0;i<n;i++);
using namespace std;




int query(int l,int r,int *st,int node,int start,int end)
                 {//cout<<start<<" "<<end<<endl;

                  if(r<start || end<l)
                       return 0;
                  if(l<=start && r>=end)
                     {return st[node];}
                  int mid=(start+end)/2;
                  int a=query(l,r,st,2*node+1,start,mid);
                  int b=query(l,r,st,2*node+2,mid+1,end);
                  //cout<<a<<" "<<b<<" "<<start<<" "<<end<<endl;
                  return a+b;
                 }





void updateutil(int arr[],int n,int start,int end,int node,int i,int *st,int diff)
                   {if(start==end)
                        {
                         arr[i]+=diff;
                         st[node]+=diff;
                        }
                    else
                        {int mid=(start+end)/2;
                         if(start<=i && i <=mid)
                              updateutil(arr,n,start,mid,2*node+1,i,st,diff);
                         else
                             updateutil(arr,n,mid+1,end,2*node+2,i,st,diff);
                         st[node]=st[2*node+1]+st[2*node+2];

                        }

                   }

int update(int arr[],int n,int i,int *st,int val)
               {
                   int diff=val-arr[i];

                   updateutil(arr,n,0,n-1,0,i,st,diff);
               }





int  constructstutil(int arr[],int n,int node,int start,int end,int *st)
                    {if(start==end)
                         {
                             st[node]=arr[start];
                             return st[node];

                         }
                     else
                        {int mid=(start+end)/2;
                         int a=constructstutil(arr,n,2*node+1,start,mid,st);
                         int b=constructstutil(arr,n,2*node+2,mid+1,end,st);
                         st[node]=a+b;
                         return st[node];
                        }

                    }
int *constructst(int arr[],int n)
               {
                int x=(int)(ceil(log2(n)));
                int sz=2*(int)pow(2,x)-1;
                int *st=new int[sz];
                constructstutil(arr,n,0,0,n-1,st);

                for(int i=0;i<sz;i++)
                     cout<<st[i]<<" ";
                return st;
               }

main()
   {
    int n,d;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
         cin>>arr[i];
    int *st=constructst(arr,n);
    cout<<endl;
    cout<<query(1,3,st,0,0,n-1)<<endl;
    update(arr,n,1,st,6);
    cout<<arr[1]<<" "<<query(1,3,st,0,0,n-1)<<endl;

  }
















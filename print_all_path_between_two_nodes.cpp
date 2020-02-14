#include <iostream>
#include<bits/stdc++.h>
#define M 1000000000+7
#define INT_MAX 100000000001
#define lli  long long int
#define pb push_back
#define f(j,m,n) for(lli j=m;j<n;j++)
using namespace std;
vector<int> li[200005];
vector<int> v,p;
int freq[200005];
int color[200005],sum=0;
int dfs_visit(int s,int t)
  {color[s]=1;
      if(s==t)
       {v.pb(sum);
        for(int i=0;i<p.size();i++)
            {cout<<p[i]<<" ";
             freq[p[i]]++;}
            cout<<endl;
        }

      else{
   for(int i=0;i<li[s].size();i++)
      {if(color[li[s][i]]==0)
           {sum++;
            p.pb(li[s][i]);
            dfs_visit(li[s][i],t);
           }

      }}
      sum--;
      p.pop_back();
      color[s]=0;

  }
void dfs(int s,int t,int n)
   {for(int i=1;i<=n;i++)
        {color[i]=0;
        freq[i]=0;}
    dfs_visit(s,t);

   }
int main()
  {ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   lli n,m,q,x,y;
   cin>>n>>m;
   for(lli i=0;i<m;i++)
      {cin>>x>>y;
      li[x].pb(y);
      li[y].pb(x);}
      cin>>q;
      for(int j=0;j<q;j++)
        {sum=0;
         int ti=0;
         p.clear();
         v.clear();
         cin>>x>>y;
         dfs(x,y,n);
         //cout<<li[x].size()<<" ";
         cout<<v.size()<<endl;
         for(int i=0;i<v.size();i++)
             cout<<v[i]<<" ";
          cout<<endl;
          for(int i=1;i<=n;i++)
              {if(freq[i]==v.size()&&i!=y)
              ti++;}
         cout<<endl;
        }
    }

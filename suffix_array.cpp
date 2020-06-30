/*===================*\
|ID : harryPotter_421  |
|      LANG: C++       |
\*====================*/
#include <iostream>
#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define ld  double
#define f(j,m,n) for(lli j=m;j<n;j++)
#define harry ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define forn(n) for(i=0;i<n;i++);
using namespace std;



int main()
        {
          string s;
          cin>>s;
          s+='$';
          lli n=s.length();
          lli c[n],p[n];
          vector<pair<char,lli>> a(n);
          for(lli i=0;i<n;i++)
             {
              a[i]={s[i],i};
             }
          sort(a.begin(),a.end());
          for(lli i=0;i<n;i++)
                p[i]=a[i].second;
          c[p[0]]=0;
          for(lli i=1;i<n;i++)
             {if(a[i].first==a[i-1].first)
                  c[p[i]]=c[p[i-1]];
              else
                  c[p[i]]=c[p[i-1]]+1;
             }
          lli k=0;
          while(1<<k<n)
               {vector<pair<pair<lli,lli>,lli>> v(n);
                 for(lli i=0;i<n;i++)
                    v[i]={{c[i],c[(i+(1<<k))%n]},i};
                 sort(v.begin(),v.end());
                 for(lli i=0;i<n;i++)
                    p[i]=v[i].second;

                 c[p[0]]=0;
                 for(lli i=1;i<n;i++)
                   {if(v[i].first==v[i-1].first)
                       c[p[i]]=c[p[i-1]];
                    else
                       c[p[i]]=c[p[i-1]]+1;
                   }
                  k++;

                }
            for(lli i=0;i<n;i++)
                  cout<<p[i]<<" ";



        }










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
        {lli n;
         cin>>n;
         string s;
         cin>>s;
         lli ans=0;
         for(lli i=0;i<n;i++)
         {lli a=s[i]-'0'
         if(s[i]%2==0)
              ans+=(i+1);
         }
         cout<<ans;
        }










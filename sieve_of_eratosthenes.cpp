/*===================*\
|ID : harryPotter_421  |
|      LANG: C++       |
\*====================*/
#include <iostream>
#include<bits/stdc++.h>
#define INT_MAX 100000000001
#define lli long long int
#define ld long double
#define pb push_back
#define f(j,m,n) for(lli j=m;j<n;j++)
#define harry() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
lli sieve[10005];

void sieve_er(lli n)
   {for(int i=2;i<=n+1;i++)
       sieve[i]=1;

    for(int i=2;i*i<=n;i++)
       {if(sieve[i]==1)
            {
              for(int j=i*i;j<=n;j+=i)
                    sieve[j]=0;
            }

       }


    }
int main()
  {
      harry();
      lli t,n;
      cin>>t;
      for(lli j=0;j<t;j++)
         {cin>>n;
          sieve_er(n);
          for(int i=2;i<=n;i++)
               {if(sieve[i])
                  cout<<i<<" ";}
                  cout<<endl;
         }
    }

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
int prime[1000005];

void seive(lli n)     //to generate all prime no less than or equal to n
           {prime[0]=0;
            prime[1]=0;
            for(lli i=2;i<=n;i++)
                 prime[i]=1;
            for(lli i=2;i<=sqrt(n);i++)
               {if(prime[i])
                    {
                        for(lli j=i*i;j<=n;j+=i)
                             prime[j]=0;
                    }

               }
             }
vector<lli> prime_factor(lli n)             //Tp generate all prime factors of a given number n
                   {if(n==1)
                       {vector<lli> v;
                        v.pb(1);
                        return v;}
                     if(prime[n])
                       {
                         vector<lli> v;
                         v.pb(1);
                         v.pb(n);
                         return v;
                        }
                    else
                        {
                          for(lli i=2;i<=sqrt(n);i++)
                                {if(prime[i]&&n%i==0)
                                    {

                                       vector<lli> vec=prime_factor(n/i);
                                       vec.pb(i);
                                       return vec;
                                    }

                                }


                        }

                      }



lli GCD(lli a,lli b)   //program to find GCD of two integer
          {if(b==0)
               return a;
           else
              {
               return GCD(b,a%b);
              }

           }


int main()
        {
            lli n,a,b;
             cin>>n;
             seive(n+1);
             for(lli i=0;i<n;i++)   //printing all prime less than n
             {
                 if(prime[i])
                     cout<<i<<" ";
             }
             cout<<endl;
             vector<lli> v=prime_factor(n);
             sort(v.begin(),v.end());
             map<lli,lli> mp;
             for(lli i=1;i<v.size();i++)
                   mp[v[i]]++;

             for(lli i=0;i<v.size();i++)//printing all prime factors of n
                 cout<<v[i]<<" ";
                 cout<<endl;
                 lli sum=1;
             for (auto x:mp)    //printing no of divisors of n
                 {
                  sum=sum*(x.second+1);
                 }
                 cout<<sum<<endl;
             cin>>a>>b;
             cout<<GCD(max(a,b),min(a,b)); //printing GCD of two no
             cout<<endl;
             cout<<(a*b)/(GCD(a,b)); // printing LCM of a and b
             cout<<endl;
        }








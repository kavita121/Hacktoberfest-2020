//noldbach problem 17A codeforces
//accepted

#include<bits/stdc++.h>
#define ll long long

using namespace std;

void sieve(vector<bool> &primes)
{
    int i, j, n=primes.size();
    if(primes.size()>=2)
        primes[1] = primes[0] = false;
    for(i=2; i*i<=n; i++)
    {
        if(primes[i])
        {
            for(j=i*i; j<n; j+=i)
                primes[j]=false;
        }
    }
}

int main()
{
    int n, k, i;
    cin>>n>>k;
    vector<bool> is_prime(n+1, true);
    sieve(is_prime);
    vector<int> prime;
    for(i=0; i<=n; i++)
        if(is_prime[i])
        {
            prime.push_back(i);
        }
    int c=0;
    for(i=prime.size()-1; i>0; i--)
    {
        for(int j=i-1; j>0; j--)
        {
            if(prime[j]+prime[j-1] == (prime[i]-1))
            {
                c++;
            }
        }
    }
    if( c>=k )
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

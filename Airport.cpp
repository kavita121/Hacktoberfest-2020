//218 B Airport

#include<bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int> min;
    multiset<int, greater<int>> max;
    int n, m, i, j, a;
    cin>>n>>m;
    for( i=0; i<m; i++ )
    {
        cin>>a;
        min.insert(a);
        max.insert(a);
    }
    //for finding the max cost
    i = 0;
    int max_cost = 0, min_cost = 0, val;
    while( i<n )
    {
        auto itr = max.begin();
        val = *itr;
        max_cost += val;
        max.erase(max.lower_bound(val));
        val--;
        if(val > 0)
            max.insert(val);
        i++;
    }
    
    //for finding the min cost
    i = 0;
    while( i<n )
    {
        auto itr = min.begin();
        val = *itr;
        min_cost += val;
        min.erase(min.lower_bound(val));
        val--;
        if(val > 0)
            min.insert(val);
        i++;
    }
    cout<<max_cost<<" "<<min_cost;
    return 0;
}

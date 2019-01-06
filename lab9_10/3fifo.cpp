#include<bits/stdc++.h>
using namespace std;
#define pf printf
#define sf scanf
#define z long long int 

z solve(queue<z> q, z val)
{
    while(!q.empty())
    {
        z pp = q.front();
        if(pp==val) return 1;
        q.pop();
    }
    return 0;
}

int main()
{
    
    
    
    z i,capa,n,pgf=0;
    pf("enter no of page frames\n");
    sf("%lld",&capa);
    pf("enter no of pages\n");
    sf("%lld",&n);
    z pages[n];
    queue<z> q;

    
    for(i=0;i<n;i++) sf("%lld",&pages[i]);
    
    for(i=0;i<n;i++)
    {
        if(!solve(q,pages[i])) // not found
        {
            pgf++;
            if(q.size()<capa)
            {
                q.push(pages[i]);
            }
            else if(q.size()==capa)
            {
                q.pop();
                q.push(pages[i]);
            }
        }
        
    }
    pf("number of page faults: %lld\n",pgf);
    
}

#include<bits/stdc++.h>
using namespace std;
#define pf printf
#define sf scanf
#define z long long int

z solve(z pages[],z n ,z capacity)
{
	set<z> s;
	map<z,z> ma;
	z i;
	z pgf=0;
	for(i=0;i<n;i++)
	{
			if(s.size()<capacity)
			{
				if(s.find(pages[i])==s.end())
				{
					s.insert(pages[i]);
					pgf++;
				}
					ma[pages[i]]=i;
			}
			else
			{
			
					set<z> :: iterator it ;
				if(s.find(pages[i])==s.end())
				{
					z val,lru=INT_MAX;
					for(it = s.begin();it!=s.end();it++)
					{
						if(ma[*it]<lru)
						{
							lru=ma[*it];
							val=*it;
						}	
					}
					
					s.erase(val);
					s.insert(pages[i]);
					pgf++;
					
				}
				
				ma[pages[i]]=i;
			}
			
		
			
			
			
					
	}
	
	return pgf;
	

}

int main()
{
	z capacity,n,i;
	pf("enter page frames\n");
	sf("%lld",&capacity);
	pf("enter no of pages \n");
	sf("%lld",&n);
	z pages[n];
	pf("enter elements for refer string\n");
	for(i=0;i<n;i++) sf("%lld",&pages[i]);
	
	pf("total page faults: %lld\n",solve(pages,n,capacity));
	
	

}

#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define z long long int 
struct obj
{
	z id,at,bt,ct,tat,wt;

}list[100];
int cmp(const void *a , const void *b)
{
	z p1 = ((struct obj *)a)->at;
	z p2 = ((struct obj *)b)->at;
	if(p1>p2) return true; else return false;
}

int main()
{
	z n,i;
	pf("enter no of processes\n");
	sf("%lld",&n);
	pf("enter arrival time for processes\n");
	for(i=0;i<n;i++)
	{
		sf("%lld",&list[i].at);
		list[i].id=i+1;
	}
	pf("enter burst time for processes\n");
	for(i=0;i<n;i++)
		sf("%lld",&list[i].bt);
	qsort(list,n,sizeof(list[0]),cmp);
	list[0].ct = list[0].at+list[0].bt;
	list[0].tat= list[0].ct-list[0].at;
	list[0].wt= list[0].tat-list[0].bt;

	for(i=1;i<n;i++)
	{
		list[i].ct = list[i-1].ct+list[i].bt;
		list[i].tat= list[i].ct-list[i].at;
		list[i].wt= list[i].tat-list[i].bt;
	}

	for(i=0;i<n;i++)
	{
		pf("%lld %lld %lld %lld %lld %lld\n",list[i].id , list[i].at , list[i].bt , list[i].ct , list[i].tat , list[i].wt);
	}





}

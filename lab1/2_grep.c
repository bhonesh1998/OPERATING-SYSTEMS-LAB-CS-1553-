#include<stdio.h>
#include<string.h>
#define pf printf
#define sf scanf

int main()
{
	char fn[100],temp[100],pat[100];
	pf("enter filename : \n");
	sf(" %s",fn);
	FILE *fp;
	fp=fopen(fn,"r");
	pf("enter pattern to be searched : ");
	sf(" %s",pat);
	while(!feof(fp))	
	{
		fgets(temp,100,fp);
		if(strstr(temp,pat))
		{
			pf("%s",temp);
		}
		bzero(temp,100);
		//temp[0] = '\0'; //  clear buffer 
	}	
		fclose(fp);
}
	

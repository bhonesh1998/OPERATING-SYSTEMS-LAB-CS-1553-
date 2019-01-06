#include<stdio.h>
#include<stdlib.h>	
#define pf printf
#define sf scanf

	
int main()
{	FILE *fp;
	pf("1. create a file \n 2. read a file \n 3. write to a file \n");
	int op;
	sf("%d",&op);
	char fname[100];
	switch(op)
	{
		case 1: 
			pf("enter file name\n");
			sf("%s",fname);
			fp=fopen(fname,"w");break;
		case 2:
			pf("enter file name\n");
			sf("%s",fname);
			fp=fopen(fname,"r");
			while(!feof(fp))
			{
				fgets(fname,100,fp);
				pf("%s",fname);
			}
		break;
			
		case 3:
			pf("enter file name\n");
			sf("%s",fname);
			fp=fopen(fname,"w");
			pf("enter contents to file\n");
			sf("%s",fname);
			fprintf(fp,"%s",fname);
			break;
					

	}	
}

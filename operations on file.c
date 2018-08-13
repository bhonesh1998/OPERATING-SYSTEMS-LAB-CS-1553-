#include<stdio.h>
#include<string.h>
#define pf printf
#define sf scanf
int main(){
	FILE *fp;
	int op=1;
	while(op){
	pf("1. Create a file\n2. Read contents of a file\n3. Write to a file\n4. Link and unlink a file\n5. Copy file\n6. Read contents     of a file in a reverse order\nUsing the system calls: open( ), close( ), read( ), write( ), lseek( ),link( ), unlink( ).\n");
   sf("%d",&op);
   char fname[1000];
 	switch(op){
 	case 1:
 	     pf("Enter the file name:\n");
 	     sf("%s",fname);
	     fp=fopen(fname,"w");
	     break;
	case 2:
	       pf("Enter the name of the file\n");
	       sf("%s",fname);
	       pf("The Contents of file are:\n");
	       fp=fopen(fname,"r");
	       while(!feof(fp)){
	          fgets(fname,1000,fp);
	          pf("%s",fname);
	       }
	       break;
   case 3:
         pf("Enter the file name to write to:\n");
         sf("%s",fname);
         fp=fopen(fname,"w");
         pf("Enter the Contents to Write :\n");
         sf("%s",fname);
         fprintf(fp,"%s",fname);
         break;      
	}
	}
 	return 0;
}

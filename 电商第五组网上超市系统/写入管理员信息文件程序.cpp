#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void menu();
void Customer();
void Manager();
void Account();

struct managers
{
	char id[11];  
    char password[11];
	char name[20];  
	char number[12];
	char  mall[20];  
    char email[20];
   
};
int main()
{
	 managers d[3]={ {"a000001","10000","hm老板","13839986666","盒马鲜生","hema@163.com "} ,{"a000002","20000","wm老板","13536668888","物美超市","wumei@163.com "},{"a000003","30000","sh老板","13836688866","首航超市"," shouhang@163.com "}}; 
	
	FILE*fppp;
	if((fppp=fopen("managers.txt","w"))==NULL)
	{
		printf("gg");
		exit(0);
	}
	fwrite(d, sizeof(struct managers),3, fppp);
	fclose(fppp);
	return 0;
}

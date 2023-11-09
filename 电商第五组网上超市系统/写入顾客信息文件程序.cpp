#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void menu();
void Customer();
void Manager();
void Account();

struct users
{
	char id[11]; //璐﹀彿 
    char password[11]; //瀵嗙爜 
    char name[10];//濮撳悕涓哄瓧绗︿覆 
    char sex; //鎬у埆涓哄崟涓瓧绗?
    char number[12];
    char email[20];
    char address[30];
    float money;
};
int main()
{
	users a[5]={ {"a000001","10000","李明",'m',"13900011000","liming@163.com","幸福小区",10} ,{"a000002","20000","赵兵",'m',"13900022000","zhaobing@163.com","快乐家园",50},{"a000003","30000","王红",'f',"13900033000","wanghong@163.com","幸福小区",100},{"a000004","40000","马娟",'f',"13900044000","majuan@163.com","快乐家园",200}, {"a000005","50000","杨帆",'m',"13900055000","yangfan@163.com","明珠小区",300}}; 
	
	FILE*fppp;
	if((fppp=fopen("users.txt","w"))==NULL)
	{
		printf("gg");
		exit(0);
	}
	fwrite(a, sizeof(struct users),5, fppp);
	fclose(fppp);
	return 0;
}

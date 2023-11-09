#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Goods
{
	char name[5];
	char number[10];
	char shop[10];
	float sell_price;
	float buy_price;
	int sell_number;
	int left_number;
	
}goods[30];
void search();
int main()
{
	FILE*fp;
	int i=0;
	if((fp=fopen("C:\\Users\\86159\\Desktop\\goods.txt","r"))==NULL)
	{
		printf("gg");
		exit(0);
	}
	
	while(fscanf(fp,"%s %s %s %f %f %d %d",&goods[i].name,&goods[i].number,&goods[i].shop,&goods[i].sell_price,&goods[i].buy_price,&goods[i].sell_number,&goods[i].left_number)!=EOF)
	{
		++i;
	}
	
	for(int j=0;j<i;++j)
	{
		printf("%s %s %s %f %f %d %d\n",goods[j].name,goods[j].number,goods[j].shop,goods[j].sell_price,goods[j].buy_price,goods[j].sell_number,goods[j].left_number);
	}
	fclose(fp);
	search();
	return 0;
	
}
void search()
{
	int yes_or_no=0;
	char search_goods[5];
	printf("请输入查询商品名\n");
	scanf("%s",search_goods);
	for(int i=0;i<30;++i)
	{
		if(strcmp(search_goods,goods[i].number)==0)
		{
		    printf("%s %s %s %f\n",goods[i].name,goods[i].number,goods[i].shop,goods[i].sell_price);
		    yes_or_no=1;
		}
		else
		{
			if(yes_or_no==0&&i==29)
			{
				printf("无该结果\n");
			}
		}
	}
	
}
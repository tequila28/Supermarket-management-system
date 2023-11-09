#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
struct users
{
	char id[11]; //账号 
    char password[11]; //密码 
    char name[10];//姓名为字符串 
    char sex; //性别为单个字符
    char number[12];
    char email[20];
    char address[30];
    float money;
};

struct Goods
{
	int serial_number;
	char name[15];
	char number[10];
	char shop[20];
	float sell_price;
	float buy_price;
	int sell_number;
	int left_number;
	
}goods[35];

struct managers
{
	char id[11];  
    char password[11];    
    char email[20];
    int  mall;
};


int user_number,manager_number,goods_number;
int left_enough=1;
char time_now[15];
users a,b[5];
managers c,d[3];
Goods buy_goods[10];

void menu();
void Customer();
void Account_customer();
void change_information();


void Manager();

void Account_manager();



void read_text();
void search();
void sort();
void salesvolume();
void sellingprice();
void buy();
void time();
void make_order();
void history_manager_order();
void history_customer_order();






int main()
{
	menu();
}

void menu()
{
	printf("欢迎来到网上超市系统，请先选择你的身份！\n");
	printf("1.顾客\n");
	printf("2.超市管理人员\n");
	int choice1;
	scanf("%d",&choice1);
	switch (choice1)
	{
		case 1:
            Account_customer();
            
            break;
        case 2:
            Account_manager();
            break;
        default:
        	return;
	}
       
  
}

void Customer()
{
	    
	    int choice;	    
	    printf("\n");
		printf("\t\t************************************\n");
		printf("\t\t\t欢迎进入网上超市系统，请选择您所需要的服务\n");
		printf("\t\t************************************\n");
		printf("\t\t\t1.商品查询\n");
		printf("\t\t\t2.热门推荐\n");
		printf("\t\t\t3.我的历史订单\n");
		printf("\t\t\t4.修改个人信息\n");
		printf("\t\t\t5.退出系统\n");
		printf("\n\n请选择你想要进行的操作(1~5)：");
		scanf("%d",&choice);			
	
	    read_text();
	    
		switch(choice)
		{
		case 1:
			search();
			break;
		case 2:
			sort();
			buy();
			break;
		case 3:
			history_customer_order();
			break;
		case 4:
			change_information();
			break;
		
		default:
			printf("输入序号错误，请重新输入\n");
			break;
		
		}
	
}

void Manager()
{
	int choice;
	int flag=1;
	do
	{
		printf("\n");
		printf("\t\t************************************\n");
		printf("\t\t\t欢迎进入管理员系统，请选择您所需要的服务\n");
		printf("\t\t************************************\n");
		printf("\t\t\t1.查看用户订单\n");
		printf("\t\t\t2.统计信息\n");
		printf("\t\t\t3.商品查询\n");
		printf("\t\t\t4.添加商品\n");
		printf("\t\t\t5.修改管理员信息\n");
        printf("\t\t\t6.返回\n");
		printf("\n\n请选择你想要进行的操作(1~5)：");
		
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			history_manager_order();
			break;
		case 2:
		
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		
		case 5:
			
			break;
			
		case 6:
			
			break;
			
		default:
			printf("\n输入序号错误，请重新输入：\n");
			break;
			
		}
		if(flag==0)
		{
			break;
		}
	}while(flag);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}



void Account_customer()
{
	printf("欢迎来到账户登录系统，请先登录！\n");
   
    int n=0,p;
    FILE *fp;
    if((fp = fopen("users.txt","r"))==NULL)
    {
    	printf("gg");
		exit(0);
	}
    fread(b, sizeof(struct users), 5, fp); //读入一个结构体字符块 写入b
    printf("请输入账号\n");
      
    
    
    for(int i=0;i<5;++i)
    {
    	scanf("%s",&a.id); 
    	if(strlen(a.id)>=6 &&strlen(a.id)<=10)
    	{
    		for(int j=0;j<strlen(a.id);++j)
    		{
    			if(('0'<=a.id[j]&&a.id[j]<='9')||('a'<=a.id[j]&&a.id[j]<='z')||('A'<=a.id[j]&&a.id[j]<='Z'))
    			{
    				p=j;
    				continue;   				
				}
				else
				{
					printf("输入了非法字符，请重新输入！\n");
					i=0;
					break;
				}
		    }
    		
			
    	}
		else
		{
			printf("账号长度在6-10位，请重新输入！\n");
			i=0;
		}
		if(p==strlen(a.id)-1)
		{
			break;
		}
		
    }
    
    for(int i=0;i<5;++i)
    {
    		if(!strcmp(a.id, b[i].id))        //如果有此用户名
              {
        	      user_number=i;
                  break;       
              }
                else
              {
        	      if(i==4)
        	    {
        		  printf("此用户名不存在，请重新输入！\n");       
                  fclose(fp); 
                  return; 
			    }
            
              }

	}
    
    printf("请输入密码\n");
    
        do{   
           scanf("%s",&a.password); 
           if (strcmp(a.password, b[user_number].password)==0)            /*如果密码匹配*/
               
           {  
                fclose(fp);
                printf("登录成功,欢迎使用!");     
			    n=0;   
				Customer();   
                break;
            }
           else  
           {    printf("密码不正确!请重新输入密码\n");
                n+=1;
                if(n==3)
                {
                	printf("密码已连续错误三次，系统退出\n");
                	return;
				}
            }
        }while(strcmp(a.password, b[user_number].password));
       
}



void Account_manager()
{
	printf("欢迎来到账户登录系统，请先登录！\n");
   
    int n=0,p;
    FILE *fp;
    if((fp = fopen("managers.txt","r"))==NULL)
    {
    	printf("gg");
		exit(0);
	}
    fread(d, sizeof(struct users), 3, fp); //读入一个结构体字符块 写入b
    printf("请输入账号\n");
      
    
    
    for(int i=0;i<3;++i)
    {
    	scanf("%s",&c.id); 
    	if(strlen(c.id)>=6 &&strlen(c.id)<=10)
    	{
    		for(int j=0;j<strlen(c.id);++j)
    		{
    			if(('0'<=c.id[j]&&c.id[j]<='9')||('a'<=c.id[j]&&c.id[j]<='z')||('W'<=c.id[j]&&c.id[j]<='Z'))
    			{
    				p=j;
    				continue;   				
				}
				else
				{
					printf("输入了非法字符，请重新输入！\n");
					i=0;
					break;
				}
		    }
    		
			
    	}
		else
		{
			printf("账号长度在6-10位，请重新输入！\n");
			i=0;
		}
		if(p==strlen(c.id)-1)
		{
			break;
		}
		
    }
    
    for(int i=0;i<3;++i)
    {
    		if(!strcmp(c.id, d[i].id))        //如果有此用户名
              {
        	      manager_number=i;
                  break;       
              }
                else
              {
        	      if(i==2)
        	    {
        		  printf("此用户名不存在，请重新输入！\n");       
                  fclose(fp); 
                  return; 
			    }
            
              }

	}
    
    printf("请输入密码\n");
    
        do{   
           scanf("%s",&c.password); 
           if (strcmp(c.password, d[manager_number].password)==0)            /*如果密码匹配*/
               
           {  
                fclose(fp);
                printf("登录成功,欢迎使用!");     
			    n=0;   
				Manager();   
                break;
            }
           else  
           {    printf("密码不正确!请重新输入密码\n");
                n+=1;
                if(n==2)
                {
                	printf("密码已连续错误三次，系统退出\n");
                	return;
				}
            }
        }while(strcmp(c.password, d[manager_number].password));
       
}
	



void search()
{
	int yes_or_no=0;
	char search_goods[20];
	printf("请输入查询商品名或超市名\n");
	scanf("%s",search_goods);
	for(int j=0;j<goods_number;++j)
	{
		if(strcmp(search_goods,goods[j].name)==0||strcmp(search_goods,goods[j].shop)==0)
		{
		    printf("%d %s %s %s %f\n",goods[j].serial_number,goods[j].name,goods[j].number,goods[j].shop,goods[j].sell_price);
		    yes_or_no=1; 
		}
		else
		{
			if(yes_or_no==0&&j==29)
			{
				printf("无该结果\n");
			}
		}
	}
	
}

void sort()
{
	int sort_choice; 
	printf("请选择排序的方式\n");
	printf("1.按销量排序进行推荐\n");
	printf("2.按售价排序进行推荐\n");
	scanf("%d",&sort_choice);
	switch(sort_choice)	
	{
		case 1:
			salesvolume();
			break;
		case 2:
			sellingprice();
		default:
			break;
	}
}

void change_information()
{
	int change_choice;
	printf("请选择你想更改的信息\n");	
	printf("1.修改密码\n");
	printf("2.修改姓名\n");
	printf("3.修改性别\n");
	printf("4.修改电话\n");
	printf("5.修改邮箱\n");
	printf("6.修改地址\n");
	scanf("%d",&change_choice);
	switch(change_choice)
	{
		case 1:
			printf("原始密码为:%s\n",b[user_number].password);
			printf("请输入新密码：");
			scanf("%s",b[user_number].password);
			break;
		case 2:
			printf("原始姓名为:%s\n",b[user_number].name);
			printf("请输入新名字：");
			scanf("%s",b[user_number].name);
			break;
		case 3:
			printf("原始性别为:%c",b[user_number].sex);
			printf("请输入新性别：");
			scanf("%c",&b[user_number].sex);
			break;
		case 4:
			printf("原始电话为:%s\n",b[user_number].email);
			printf("请输入新电话：");
			scanf("%s",b[user_number].email);
			break;
		case 5:
			printf("原始邮箱为:%s\n",b[user_number].password);
			printf("请输入新邮箱：");
			scanf("%s",b[user_number].password);
			break;
		case 6:
			printf("原始地址为:%s\n",b[user_number].address);
			printf("请输入新地址：");
			scanf("%s",b[user_number].address);
			break;
	}
	FILE *fp;
    if((fp = fopen("users.txt","w"))==NULL)
    {
    	printf("gg");
		exit(0);
	}
	fwrite(b, sizeof(struct users),3, fp);
	fclose(fp);
	
	
    
	
}



void salesvolume()
{
	Goods middle;
	for(int j=0;j<goods_number-1;++j)
	{
		for(int n=j+1;n<goods_number;++n)
		{
			if(goods[j].sell_number<goods[n].sell_number)
			{
				middle=goods[j];
				goods[j]=goods[n];
				goods[n]=middle;
			}
		}
	}
	printf("序号  商品名  商品编码  商品超市  售价   销售量   库存\n");
	for(int j=0;j<goods_number;++j)
	{
		printf("%d    %s   %s   %s   %0.2f     %d     %d\n",goods[j].serial_number,goods[j].name,goods[j].number,goods[j].shop,goods[j].sell_price,goods[j].sell_number,goods[j].left_number);
	}

	
	
}


void sellingprice()
{
	Goods middle;
	for(int j=0;j<goods_number-1;++j)
	{
		for(int n=j+1;n<goods_number;++n)
		{
			if(goods[j].sell_price<goods[n].sell_price)
			{
				middle=goods[j];
				goods[j]=goods[n];
				goods[n]=middle;
			}
		}
	}
	printf("序号  商品名  商品编码  商品超市  售价   销售量   库存\n");
	for(int j=0;j<goods_number;++j)
	{
		printf("%d    %s   %s   %s   %0.2f     %d     %d\n",goods[j].serial_number,goods[j].name,goods[j].number,goods[j].shop,goods[j].sell_price,goods[j].sell_number,goods[j].left_number);
	}
}

void read_text()
{
	    FILE*fp;
	    goods_number=0;
	    if((fp = fopen("goods.txt","r"))==NULL)
	   {
		   printf("gg");
		   exit(0);
	   }
	
	    while(fscanf(fp,"%d %s %s %s %f %f %d %d",&goods[goods_number].serial_number,goods[goods_number].name,goods[goods_number].number,goods[goods_number].shop,&goods[goods_number].sell_price,&goods[goods_number].buy_price,&goods[goods_number].sell_number,&goods[goods_number].left_number)!=EOF)
	   {
		    ++goods_number;
	   }
		   
	   fclose(fp);
	   
}



void buy()
{
	int choose_number,choice;
	printf("请选择添加购物车商品的序号（一次只能添加一种商品）\n");
	scanf("%d",&choose_number);
	
	for(int i=0;i<goods_number;++i)
	{
		if(goods[i].serial_number==choose_number)
		{
			for(int j=0;j<10;++j)
			{
				if(buy_goods[j].serial_number==0)
				{
					buy_goods[j]=goods[i];
					break;
				}
			}
		}
		
	}
	
	printf("扣1生成订单\n");
	printf("扣2继续添加\n");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		printf("序号  商品名  商品编码  商品超市  售价   销售量   库存\n");
		for(int j=0;j<10;++j)
	 {
					
		 if(buy_goods[j].serial_number!=0)
		 {
			printf("%d    %s   %s   %s   %0.2f     %d     %d\n",buy_goods[j].serial_number,buy_goods[j].name,buy_goods[j].number,buy_goods[j].shop,buy_goods[j].sell_price,buy_goods[j].sell_number,buy_goods[j].left_number);
	     }
	 }
	 
	 
		printf("扣1进行购买\n");
	    printf("扣2取消订单\n");
		int order;
		scanf("%d",&order);
		
		if(order==1)
		{
			float total_money=0;
			for(int j=0;j<10;++j)
	      {
					
		       if(buy_goods[j].serial_number!=0)
		     {
			 
			   total_money+=buy_goods[j].sell_price;
		     }
		    
			
		  }
	   
	     printf("订单总价为");
		 printf("%0.2f\n",total_money);
		 
		 if(b[user_number].money<total_money)
		 {
		 	printf("余额为%f",b[user_number].money);
		 	printf("余额不足购买失败，请充值！\n");
		 }
		 
		 else 
		 {
		 	for(int i=0;i<10;++i)
		 	{
		 		for(int j=0;j<goods_number;++j)
		 		{
		 			if(buy_goods[i].serial_number==goods[j].serial_number)
		 			{
		 				goods[j].left_number-=1;
		 				goods[j].sell_number+=1;
		 				
		 			}
		 			
		 		}
			}
			
			for(int j=0;j<goods_number;++j)
			{
				if(goods[j].left_number<0)
				{
					printf("订单中有商品库存不足请重新购买\n");
					left_enough=0;
					read_text();
				}
			}
				if(left_enough==1)
				{
					b[user_number].money-=total_money;
		 	        printf("购买成功，余额为%0.2f\n",b[user_number].money);
		 	        time();
		  	        make_order();
		 	        FILE *fp;
                    if((fp = fopen("users.txt","w"))==NULL)
               {
    	            printf("gg");
		            exit(0);
      	       }
	                fwrite(b, sizeof(struct users),5, fp);
	                fclose(fp);
	                
	               FILE *p;
                    if((p = fopen("goods.txt","w"))==NULL)
               {
    	            printf("gg");
		            exit(0);
      	       }
	                for(int i=0;i<goods_number;++i)
	                {
	                	fprintf(p,"%d %s %s %s %f %f %d %d\n",goods[i].serial_number,goods[i].name,goods[i].shop,goods[i].number,goods[i].sell_price,goods[i].buy_price,goods[i].sell_number,goods[i].left_number);
					}
	                fclose(p); 
	            
	         
	         
	         
	         
	         
	         
	         
	         
	         
	         
	          for(int i=0;i<10;++i)
	         {
	         	
	         	if(strcmp(buy_goods[i].shop,"物美超市")==0)
	         	{
	         		FILE*wumei;
	         		if((wumei = fopen("物美超市.txt","a"))==NULL)
                  {
    	               printf("gg");
		               exit(0);
      	          }
	                 fprintf(wumei,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
	                 fclose(wumei);
	         		
	         		
	         		
				}
	         	
	         	if(strcmp(buy_goods[i].shop,"首航超市")==0)
	         	{
	         		FILE*shouhang;
	         		if((shouhang= fopen("首航超市.txt","a"))==NULL)
                  {
    	               printf("gg");
		               exit(0);
      	          }
	                 fprintf(shouhang,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
	                 fclose(shouhang);
	         		
	         		
	         		
				}
				
				
	         	
	         	if(strcmp(buy_goods[i].shop,"盒马鲜生")==0)
	         	{
	         		FILE*hema;
	         		if((hema= fopen("盒马鲜生.txt","a"))==NULL)
                  {
    	               printf("gg");
		               exit(0);
      	          }
	                 fprintf(hema,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
	                 fclose(hema);
	         		
	 		
				}
	      	
	         	
			 }
					
					
									
					
				}
		}
		 	
		 	
		 	
		 	
		}
		 
		 
		 
		 
		 
		 	
			 
			 
	
		 
		 
	   
	    
	    
	    if(order==2)
	    {
	    	printf("订单已取消\n");
	    	memset(buy_goods,0,sizeof(buy_goods));
	    	
		}
		
		printf("请问是否继续购买（1.继续买 or 2.不买了）\n");
		int if_buy;
		scanf("%d",&if_buy);
		
		if(if_buy==1)
		{
			memset(buy_goods,0,sizeof(buy_goods));
			buy();
		}
		if(if_buy==2)
		{
			printf("谢谢惠顾，欢迎下次再来！\n");
			return;
		}
	}
		
		
	    
	
	
	if(choice==2)
	{
		buy();
	}
	
	
}

	
void time()
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);
    printf ( "购买时间为：%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
}

void make_order()
{
	if(strcmp(a.id,"000001")==0)
	{
		FILE*user_one;
		if( (user_one= fopen("用户1.txt","a"))==NULL)
          {
    	        printf("gg");
		        exit(0);
      	  }
      	  for(int i=0;i<10;++i)
      	  {
      	  	if(buy_goods[i].serial_number!=0)
      	  	{
			  fprintf(user_one,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
		    }
		 
		  }
		   time_t t;
           struct tm * lt;
           time (&t);
           lt = localtime (&t);
           fprintf ( user_one,"购买时间为：%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
		   fclose(user_one);
		
	}
	
	if(strcmp(a.id,"000002")==0)
	{
		FILE*user_two;
		if( (user_two= fopen("用户2.txt","a"))==NULL)
          {
    	        printf("gg");
		        exit(0);
      	  }
      	  for(int i=0;i<10;++i)
      	  {
      	  	if(buy_goods[i].serial_number!=0)
      	  	{
			  fprintf(user_two,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
		    }
		 
		  }
		   time_t t;
           struct tm * lt;
           time (&t);
           lt = localtime (&t);
           fprintf ( user_two,"购买时间为：%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
		   fclose(user_two);
		
	}
	
	if(strcmp(a.id,"000003")==0)
	{
		FILE*user_three;
		if( (user_three= fopen("用户3.txt","a"))==NULL)
          {
    	        printf("gg");
		        exit(0);
      	  }
      	  for(int i=0;i<10;++i)
      	  {
      	  	if(buy_goods[i].serial_number!=0)
      	  	{
			  fprintf(user_three,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
		    }
		 
		  }
		   time_t t;
           struct tm * lt;
           time (&t);
           lt = localtime (&t);
           fprintf ( user_three,"购买时间为：%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
		   fclose(user_three);
		
	}
	
	if(strcmp(a.id,"000004")==0)
	{
		FILE*user_four;
		if( (user_four= fopen("用户4.txt","a"))==NULL)
          {
    	        printf("gg");
		        exit(0);
      	  }
      	  for(int i=0;i<10;++i)
      	  {
      	  	if(buy_goods[i].serial_number!=0)
      	  	{
			  fprintf(user_four,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
		    }
		 
		  }
		   time_t t;
           struct tm * lt;
           time (&t);
           lt = localtime (&t);
           fprintf ( user_four,"购买时间为：%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
		   fclose(user_four);
		
	}
	
	if(strcmp(a.id,"000005")==0)
	{
		FILE*user_five;
		if( (user_five= fopen("用户5.txt","a"))==NULL)
          {
    	        printf("gg");
		        exit(0);
      	  }
      	  for(int i=0;i<10;++i)
      	  {
      	  	if(buy_goods[i].serial_number!=0)
      	  	{
			  fprintf(user_five,"%d %s %s %s %f %f %d %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
		    }
		 
		  }
		   time_t t;
           struct tm * lt;
           time (&t);
           lt = localtime (&t);
           fprintf ( user_five,"购买时间为：%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
		   fclose(user_five);
		
	}
	
}

void history_customer_order()
{
	if(strcmp(a.id,"000001")==0)
	{
		FILE*user_one;
		int ch;
		if ((user_one = fopen("用户1.txt","r")) == NULL)
		{
			printf("gg\n");
		}
            
        else 
		{
           while((ch=fgetc(user_one))!=EOF)
           {
           	putchar(ch); 
		   }
           
           fclose(user_one);
        }

   }
   if(strcmp(a.id,"000002")==0)
	{
		FILE*user_second;
		int ch;
		if ((user_second = fopen("用户2.txt","r")) == NULL)
		{
			printf("gg\n");
		}
            
        else 
		{
           while((ch=fgetc(user_second))!=EOF)
           {
           	putchar(ch); 
		   }
           
           fclose(user_second);
        }

   }
   if(strcmp(a.id,"000003")==0)
	{
		FILE*user_three;
		int ch;
		if ((user_three = fopen("用户3.txt","r")) == NULL)
		{
			printf("gg\n");
		}
            
        else 
		{
           while((ch=fgetc(user_three))!=EOF)
           {
           	putchar(ch); 
		   }
           
           fclose(user_three);
        }

   }
   if(strcmp(a.id,"000004")==0)
	{
		FILE*user_four;
		int ch;
		if ((user_four = fopen("用户4.txt","r")) == NULL)
		{
			printf("gg\n");
		}
            
        else 
		{
           while((ch=fgetc(user_four))!=EOF)
           {
           	putchar(ch); 
		   }
           
           fclose(user_four);
        }

   }
   if(strcmp(a.id,"000005")==0)
	{
		FILE*user_five;
		int ch;
		if ((user_five= fopen("用户5.txt","r")) == NULL)
		{
			printf("gg\n");
		}
            
        else 
		{
           while((ch=fgetc(user_five))!=EOF)
           {
           	putchar(ch); 
		   }
           
           fclose(user_five);
        }

   }
   
   
   
   
   
   
   
}

void history_manager_order()
{
	
}


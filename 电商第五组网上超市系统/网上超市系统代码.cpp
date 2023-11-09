#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
struct users                                    //用户结构体
{
	char id[11];  
    char password[11]; 
    char name[10];
    char sex; 
    char number[12];
    char email[20];
    char address[30];
    float money;
};

struct Goods                                    //商品结构体
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

struct managers                                  //管理员结构体
{
	char id[11];  
    char password[11];
	char name[20];  
	char number[12];
	char  mall[20];  
    char email[20];
   
};


int user_number,manager_number,goods_number=0;   //用户、管理员、商品序号，为了定位其在各自所属结构体中的位置
int left_enough=1;                               //判断库存是否充足的整型变量
float total_money;                               //三家超市各自的营业额和利润
float hm_sell_money=0,hm_profit=0;
float wm_sell_money=0,wm_profit=0;
float sh_sell_money=0,sh_profit=0;
char eemail[20];
char iphone[12];
users a,b[5];                                     //a是接收当前登录顾客的结构体，b是用于接收所有顾客信息的结构体
managers c,d[3];                                  //c是接收当前登录管理员的结构体，d是用于接收所有管理员信息的结构体
Goods buy_goods[10];                              //用于存放添加的商品，相当于购物车
void Menu();                                      //选择身份菜单函数
void Account_customer();                          //顾客登录函数
void Customer();                                  //顾客主界面函数
void Change_information_customer();               //顾客修改信息函数
void Change_information_manager();                //管理员修改信息函数
void Manager();                                    //管理员主界面函数
void Account_manager();                            //管理员登录函数
void Read_text();                                  //读取商品文件函数
void Search();                                     //顾客搜索查询函数
void Sort();                                       //排序主界面函数
void Salesvolume();                                //销量排序函数
void Sellingprice();                               //售价排序函数
void Buy();                                        //购买函数
void Time();                                       //显示当前时间函数
void Write_seperate_order();                       //写用户历史订单函数
void History_manager_order();                      //管理员查看该超市历史订单函数
void History_customer_order();                     //顾客查看自己历史订单函数
void Add();                                        //添加商品函数
void Statistics();                                 //统计信息函数
void Manager_search();                             //管理员查询函数
void Manager_profit();                             //利润排序函数
void Manager_salesvolume();                        //销量排序函数
void Business_volume();                            //营业额排序函数
void Make_seperate_order();                        //按超市自动拆分订单函数
void Write_shop_order();                           //写超市历史订单函数
void Purchase_status();                            //进货情况函数
void Phone_number();                               //电话纠错机制函数
void Order_volume();                               //计算所有订单营业额及利润函数
void Email();                                      //邮箱纠错函数



int main()
{
	Menu();
	system("pause");
	return 0;
}

void Menu()                                                                                              //选择身份主菜单
{
	printf("*****欢迎来到网上超市系统，请先选择你的身份！（选择所需序号即可）*****\n");
	printf("*****1.顾客*************\n");
	printf("*****2.超市管理人员*****\n");
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
        	printf("输入错误,请重新输入\n");
        	Menu();
            break;
	}
       
  
}

void Customer()                                                               //顾客界面主菜单
{
	int flag=1;
	do
	{                                                                         //五个功能可供选择
	    int choice;	    
		printf("******************************************\n");
		printf("欢迎进入网上超市系统，请选择您所需要的服务\n");
		printf("******************************************\n");
		printf("1.商品查询\n");
		printf("2.热门推荐\n");
		printf("3.我的历史订单\n");
		printf("4.修改个人信息\n");
		printf("5.退出系统\n");
		printf("请选择你想要进行的操作(选择序号1~5)：");
		scanf("%d",&choice);			
	
	    Read_text();
	    
		switch(choice)
		{
		case 1:
			Search();			
			break;
		case 2:
			Sort();
			break;
		case 3:
			History_customer_order();
			break;
		case 4:
			Change_information_customer();
			break;
		case 5:
			printf("谢谢惠顾，欢迎下次再来！\n");
			flag=0;
			return;
		
		default:
			printf("输入序号错误，请重新输入\n");
			Customer();
			break;
		
																}
	}while(flag);
	
}

void Manager()                                                    //管理员界面主菜单
{
	int choice;
	int flag=1;
	do                                                                //六个功能可供选择
	{
		printf("\n");
		printf("**********************************************\n");
        printf("欢迎进入%s管理员系统，请选择您所需要的服务\n",d[manager_number].mall);
	    printf("**********************************************\n");
		printf("1.查看用户订单\n");
		printf("2.统计信息\n");
		printf("3.商品查询\n");
		printf("4.添加商品\n");
		printf("5.修改管理员信息\n");
        printf("6.退出系统 \n");
		printf("请选择您想要进行的操作(1~5)：");
		
		scanf("%d",&choice);
	
		switch(choice)
		{
		case 1:
			History_manager_order();
			break;
		case 2:
			Statistics();			
			break;
		case 3:
			Manager_search();		
			break;
		case 4:
			Add();			
			break;
		
		case 5:
			Change_information_manager(); 			
			break;
			
		case 6:
			flag=0;
			break;
			
		default:
			printf("\n输入序号错误，请重新输入：\n");
			Manager();
			break;
			
		}	
    }while(flag==1);
	
}



void Account_customer()
{
	printf("@欢迎来到顾客账户登录系统，请先登录！（若选择错误，按0可返回）@\n");
    int n=0,p;
    FILE *fp;
    if((fp = fopen("users.txt","r"))==NULL)
	{
    	printf("文件打开失败>_<\n");
		exit(0);
	}
    fread(b, sizeof(struct users), 5, fp); //读入一个结构体字符块 写入b
    printf("请输入用户账号~~~\n");
        
    for(int i=0;i<5;++i)
    {
    	scanf("%s",&a.id); 
    	if(strcmp(a.id,"0")==0)                  //实现输入0返回的功能
    	{
    		Menu();
		}
    	if(strlen(a.id)>=6 &&strlen(a.id)<=10)                    //检查字符串长度是否在6-10之间 
    	{
    		for(int j=0;j<strlen(a.id);++j)
    		{
    			if(('0'<=a.id[j]&&a.id[j]<='9')||('a'<=a.id[j]&&a.id[j]<='z')||('A'<=a.id[j]&&a.id[j]<='Z'))      //字符长度符合要求，进入for循环，检查每个字符的类型是否符合要求 
    			{
    				p=j;                                                    //p用于记当前检查的字符位数 
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
		
		if(p==strlen(a.id)-1)                            //最后一个字符的类型也符合要求 
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
        		printf("此用户名不存在，请重新输入！\n");        //输入字符与文件中的最后一个信息不匹配 
                fclose(fp); 
                Account_customer();
           }
            
        }

	}
    
    printf("请输入密码~~~\n");
    
        do
		{   
           scanf("%s",&a.password); 
           if (strcmp(a.password, b[user_number].password)==0)            //如果密码匹配      
           {  
                fclose(fp);
                printf("登录成功,欢迎使用!\n");     
			    n=0;                                                                   //n+1为输入密码的次数 
				Customer();                                                               //输入正确则跳转至注册主界面函数 
                break;
            }
           else  
           {    printf("密码不正确,请重新输入密码!（还有%d次机会）\n",2-n);
                n+=1;
                if(n==3)
                {
                	printf("密码已连续错误三次，系统退出!\n");
                	return;
				}
            }
        }while(strcmp(a.password, b[user_number].password));                                //若输入的密码与文件中对应的密码不匹配 ，继续循环 
}



void Account_manager()
{
	printf("@欢迎来到管理员账户登录系统，请先登录！（若选择错误，按0可返回）@\n");  
    int n=0,p;
    FILE *fp;
    if((fp = fopen("managers.txt","r"))==NULL)
    {
    	printf("文件打开失败>_<\n");
		exit(0);
	}
    fread(d, sizeof(struct users), 3, fp);                             //读入一个结构体字符块 写入b
    printf("请输入管理员账号~~~\n");
     
    for(int i=0;i<3;++i)                                                    //检查字符串长度是否在6-10之间 
    {
    	scanf("%s",&c.id); 
    	if(strcmp(c.id,"0")==0)
    	{
    		Menu();                                                               //实现输入0返回的功能
		}
    	if(strlen(c.id)>=6 &&strlen(c.id)<=10)
    	{
    		for(int j=0;j<strlen(c.id);++j)
    		{
    			if(('0'<=c.id[j]&&c.id[j]<='9')||('a'<=c.id[j]&&c.id[j]<='z')||('A'<=c.id[j]&&c.id[j]<='Z'))                    //字符长度符合要求，进入for循环，检查每个字符的类型是否符合要求
    			{
    				p=j;                                                                  //p用于记当前检查的字符位数 
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
		if(p==strlen(c.id)-1)                                                   //最后一个字符的类型也符合要求 
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
        		printf("此用户名不存在，请重新输入！\n");                  //输入字符与文件中的最后一个信息不匹配 
                fclose(fp); 
                Account_manager();
			}          
        }
	}
    
    printf("请输入密码~~~\n");
    
    do
	{   
        scanf("%s",&c.password); 
        if (strcmp(c.password, d[manager_number].password)==0)            /*如果密码匹配*/           
        {  
            fclose(fp);
            printf("登录成功,欢迎使用!");     
			n=0;   
			Manager();                                                                    //输入正确则跳转至注册主界面函数 
            break;
        }
        else  
        {   
			printf("密码不正确，请重新输入密码！（还有%d次机会）\n",2-n);                     //n+1为输入密码的次数 
            n+=1;
            if(n==2)
            {
                printf("密码已连续错误三次，系统退出！\n");                                      
                return;
			}
        }
    }while(strcmp(c.password, d[manager_number].password));                               //若输入的密码与文件中对应的密码不匹配 ，继续循环 
       
}
	



void Search()//用户搜索函数
{
	int yes_or_no=0;             //定义一个整形，初始值为0，用于判断是否查询到商品
	char search_goods[20];                 //定义一个数组，用于暂存用户输入的商品名或超市名
	printf("\n请输入查询商品名或超市名:");    //输入商品名或超市名
	scanf("%s",search_goods);
	printf("序号  商品名  商品超市  商品编码  售价   销售量   库存\n");               //打印搜索结果对应项目
	for(int j=0;j<goods_number;++j)                        //遍历结构体中每一个商品
	{
		if(strcmp(search_goods,goods[j].name)==0||strcmp(search_goods,goods[j].shop)==0)          //用strcmp函数进行比较
		{
			
		    printf("%d    %s    %s    %s  %.2f    %d       %d\n",goods[j].serial_number,goods[j].name,goods[j].shop,goods[j].number,goods[j].sell_price,goods[j].sell_number,goods[j].left_number);
		    yes_or_no=1;                   //查询到结果，则给整形赋值为1
		}
		else
		{
			if(yes_or_no==0&&j==29)
			{
				printf("很抱歉，查询无该结果！\n");			       //j==29时，整个数组被遍历完，若未查询到结果，则打印"无该结果"
			}
		}
	}
	int choice;                                                             //定义一个整形，用于用户选择下一步操作
	printf("请选择操作（1.加入购物车 2.继续查询 3.返回主界面）\n");
	scanf("%d",&choice);                          //让用户选择下一步操作
	switch(choice)
	{
		case 1:                                                       //选1，加入购物车
			if(yes_or_no==0)
			{
				printf("很抱歉，查询无该结果，无法加入购物车，已自动返回主界面！\n");
				return;
			}
			Buy();
			break;
		case 2:             //选2，继续查询
			Search();
			break;
		case 3:                 //选3，返回用户主界面
			return;
		default:
			return;		
		
	}	
}

void Sort()                //热门推荐界面
{
	int sort_choice;                  //定义一个选择数 
	int choice;
	printf("\n请选择查看商品排序的方式（输入序号即可）\n");
	printf("1.按销量排序进行推荐\n");
	printf("2.按售价排序进行推荐\n");
	scanf("%d",&sort_choice);                    //输入一个选择数
	switch(sort_choice)	
	{
		case 1:                                               //输入1，实现按销量排序
			Salesvolume();
			break;
		case 2:                                         //输入2，实现按售价排序
			Sellingprice();
			break;
		default:                                             //输入错误，则重新选择排序方式
			printf("输入错误，请重新输入！\n");
			Sort();
			break;
	}
	printf("请选择操作（1.添加商品到购物车中 2.返回主界面）\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		Buy();
	}
	if(choice==2)
	{
		return;
	}
}

void Change_information_customer()                                 //修改顾客信息 
{
	int change_choice;                                 //定义顾客的选项 
	printf("\n请选择您想更改的个人信息\n");	
	printf("1.修改密码\n");
	printf("2.修改姓名\n");
	printf("3.修改电话\n");
	printf("4.修改邮箱\n");
	printf("5.修改地址\n");
	printf("6.充值\n");
	printf("7.返回主界面\n");                    //打印顾客修改信息的界面 
	scanf("%d",&change_choice);
	switch(change_choice)
	{
		case 1:
			printf("原始密码为:%s\n",b[user_number].password);              //打印顾客修改信息的界面 
			printf("请输入新密码：");
			scanf("%s",b[user_number].password);                     //读入新密码 
			printf("修改成功~~~\n");
			break;
		case 2:
			printf("原始姓名为:%s\n",b[user_number].name);
			printf("请输入新名字：");
			scanf("%s",b[user_number].name);
			printf("修改成功~~~\n");
			break;		
		case 3:
			printf("原始电话为:%s\n",b[user_number].number);
			printf("请输入新电话：");		
			Phone_number();
			strcpy(b[user_number].number,iphone);
			printf("修改成功~~~\n");
			break;
		case 4:
			printf("原始邮箱为:%s\n",b[user_number].email);
			printf("请输入新邮箱：");			
			Email();
			strcpy(b[user_number].email,eemail);
			break;
		case 5:
			printf("原始地址为:%s\n",b[user_number].address);
			printf("请输入新地址：");
			scanf("%s",b[user_number].address);
			printf("修改成功~~~\n");
			break;
		case 6:
			printf("原始余额为:%.2f\n",b[user_number].money);
			printf("请输入充值后的余额：");
			scanf("%f",&b[user_number].money);
			printf("充值成功~~~\n");
			break;
		case 7:
			return;
		default:
			printf("输入错误，请重新输入！\n");
			Change_information_customer();
			break;
	}
	FILE *fp;
    if((fp = fopen("users.txt","w"))==NULL)                            //打开文件 
    {
    	printf("文件打开失败>_<\n");
		exit(0);
	}
	fwrite(b, sizeof(struct users),5, fp);                                //文件写入函数 
	fclose(fp);                                                             //关闭文件 
		
}



void Salesvolume()                                                     //按销量进行排序函数
{
	Goods middle;                                                      //定义一个Goods类型的变量
	for(int j=0;j<goods_number-1;++j)                      //从第一位比较到倒数第二位
	{
		for(int n=j+1;n<goods_number;++n)                              //从第二位比较到倒数第一位
		{
			if(goods[j].sell_number<goods[n].sell_number)                  //前一位若小于后一位，交换位置
			{ 
				middle=goods[j];
				goods[j]=goods[n];
				goods[n]=middle;
			}
		}
	}
	printf("序号  商品名  商品超市  商品编码  售价   销售量   库存\n");             //打印排序表表头
	for(int j=0;j<goods_number;++j)
	{
		printf("%d    %s   %s   %s   %0.2f     %d     %d\n",goods[j].serial_number,goods[j].name,goods[j].shop,goods[j].number,goods[j].sell_price,goods[j].sell_number,goods[j].left_number);
	}

	
	
}


void Sellingprice()                                                      //按售价进行排序函数
{
	Goods middle;                                    //定义一个Goods类型的变量
	for(int j=0;j<goods_number-1;++j)                           //从第一位比较到倒数第二位
	{
		for(int n=j+1;n<goods_number;++n)                            //从第二位比较到倒数第一位
		{
			if(goods[j].sell_price<goods[n].sell_price)                    //前一位若小于后一位，交换位置
			{
				middle=goods[j];
				goods[j]=goods[n];
				goods[n]=middle;
			}
		}
	}
	printf("序号  商品名  商品超市  商品编码  售价   销售量   库存\n");                    //打印排序表表头
	for(int j=0;j<goods_number;++j)
	{
		printf("%d    %s   %s   %s   %0.2f     %d     %d\n",goods[j].serial_number,goods[j].name,goods[j].shop,goods[j].number,goods[j].sell_price,goods[j].sell_number,goods[j].left_number);
	}
}

void Read_text()                                                        //读取商品文件函数
{
	    FILE*fp;
	    goods_number=0;
	    if((fp = fopen("goods.txt","r"))==NULL)
	   {
		   printf("文件打开失败>_<\n");
		   exit(0);
	   }                                                            //不断读入商品的属性并赋值到相应的结构体中
	
	    while(fscanf(fp,"%d %s %s %s %f %f %d %d",&goods[goods_number].serial_number,goods[goods_number].name,goods[goods_number].shop,goods[goods_number].number,&goods[goods_number].sell_price,&goods[goods_number].buy_price,&goods[goods_number].sell_number,&goods[goods_number].left_number)!=EOF)
	   {
			++goods_number;
	   }
		   
	   fclose(fp);
	   
}



void Buy()                                                                    //添加购物车购买商品函数
{
	int choose_number,choice;
	printf("\n请选择添加购物车商品的序号（一次只能添加一种商品的一个）\n");           //输入序号添加商品
	scanf("%d",&choose_number);
	if(choose_number<=0||choose_number>goods_number)
	{
		printf("输入序号不存在，请重新输入!\n");
		Buy();
	}	
	for(int i=0;i<goods_number;++i)                                    //遍历商品文件查找所选的商品
	{
		if(goods[i].serial_number==choose_number)
		{
			for(int j=0;j<10;++j)
			{
				if(buy_goods[j].serial_number==0)
				{
					buy_goods[j]=goods[i];                                //查找到商品就将其添加到购物车中
					break;
				}
			}
		}
		
	}
	
	printf("输入1生成订单\n");                                                 //两个选项可供选择
	printf("输入2继续添加\n");
	scanf("%d",&choice);
	
	if(choice==1)
{
		printf("序号  商品名  商品超市  商品编码  售价   销售量   库存\n");             //生成订单
		Make_seperate_order();                                                          //按超市自动拆分订单
	    printf("订单总价为%0.2f\n",total_money);
	    printf("订单编号为：%s",b[user_number].id);
	    time_t t;
    	struct tm * lt;                                                               //输出订单总价和编号
    	time (&t);
    	lt = localtime (&t);                         
    	printf ( "%d:%d:%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
	    printf("输入1进行购买\n");
	    printf("输入2取消订单\n");                                              //两个选项可供选择
		int order;
		scanf("%d",&order);
		
		if(order==1)
	{
			
		 
		if(b[user_number].money<total_money)                                     //余额不足购买失败
		{
		 	printf("您的当前余额为%.2f元",b[user_number].money);
		 	printf("余额不足购买失败，请充值！>_<\n");
		}
		 
		else 
	{
		 	for(int i=0;i<10;++i)
		 	{
		 		for(int j=0;j<goods_number;++j)                                  //遍历购物车，查看是否有商品库存不足
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
				if(goods[j].left_number<0)                                      //库存不足购买失败
				{
					printf("订单中有商品库存不足，请重新购买！>_<\n");
					left_enough=0;
					Read_text();
		 		}
	 		}
	 		
			if(left_enough==1)
	 	{
				b[user_number].money-=total_money;
		 		printf("购买成功，您的当前余额为%0.2f元\n",b[user_number].money);          //购买成功余额自动扣除
		 		Write_seperate_order();                                                    //写入用户历史订单文件中
		 		Write_shop_order();                                                        //写入超市历史订单文件中
		 		Time();
		 		
		 		FILE *fp;
            	if((fp = fopen("users.txt","w"))==NULL)
    			{
    	    		printf("文件打开失败>_<\n");
		    		exit(0);
    			}
	        	fwrite(b, sizeof(struct users),5, fp);                                     //修改顾客中该用户余额
	        	fclose(fp);
	                
	       	 	FILE *p;
            	if((p = fopen("goods.txt","w"))==NULL)
        		{
    	    		printf("文件打开失败>_<\n");
		    		exit(0);
      			}
	        	for(int i=0;i<goods_number;++i)
	        {
	        	fprintf(p,"%d %s %s %s %.2f %.2f %d %d\n",goods[i].serial_number,goods[i].name,goods[i].shop,goods[i].number,goods[i].sell_price,goods[i].buy_price,goods[i].sell_number,goods[i].left_number);
			}
	            fclose(p); 	                                                               //修改商品文件中该商品的销量和库存
	         
	    		for(int i=0;i<10;++i)
			{
	         	
	     		if(strcmp(buy_goods[i].shop,"物美超市")==0)                                //将该超市的订单的总价和利润写入该文件
	    		{
	        		FILE*wumei;
	        		if((wumei = fopen("wm老板","a"))==NULL)
         			{
    	        		printf("文件打开失败>_<\n");
		        		exit(0);
      				}
	            	fprintf(wumei,"%.2f %.2f ",wm_sell_money,wm_profit);
	            	fclose(wumei);
	            	break;	         		
				}
			}
	         	
	    		for(int i=0;i<10;++i)	
			{
		 
		 		if(strcmp(buy_goods[i].shop,"首航超市")==0)                                //将该超市的订单的总价和利润写入该文件
				{
	        		FILE*shouhang;
	        		if((shouhang= fopen("sh老板","a"))==NULL)
        			{
    	        		printf("文件打开失败>_<\n");
		        		exit(0);
      	 			}
	        		fprintf(shouhang," %.2f %.2f ",sh_sell_money,sh_profit);
	        		fclose(shouhang);
	        		break;
	         		      		
				}				
   			}
	         
				for(int i=0;i<10;++i)	
	 		{
		 		if(strcmp(buy_goods[i].shop,"盒马鲜生")==0)                                //将该超市的订单的总价和利润写入该文件
	    		{
	        		FILE*hema;
	        		if((hema= fopen("hm老板","a"))==NULL)
            		{
    	        		printf("文件打开失败>_<\n");
		        		exit(0);
      	    		}
	            	fprintf(hema,"%.2f %.2f  ",hm_sell_money,hm_profit);
	            	fclose(hema);
	            	break;
	         				
				}      	         	
	 		}									
					
		}
	}
		 	
	}
		 
		 	 	
			 
		if(order==2)
	    {
	    	printf("订单已成功取消！\n");
	    	
		}
		
		printf("请问是否继续购买（1.继续买  2.不买了）\n");                          //可选择两个选项
		int if_buy;
		scanf("%d",&if_buy);	
		if(if_buy==1)
		{
			memset(buy_goods,0,sizeof(buy_goods));                                   //清空购物车
			Buy();
		}
		if(if_buy==2)
		{
			memset(buy_goods,0,sizeof(buy_goods));
			printf("谢谢惠顾，欢迎下次再来！^_^\n");
			return;
		}
}
		
		
	    
	
	
	if(choice==2)
	{
		Buy();                                                                     //继续购买
	}
	
	
}

	
void Time()                    //显示当前时间的函数 
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);
    printf ( "当前时间为：%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   
}



void History_customer_order()                 //顾客历史订单 
{
	FILE*u;
	int ch;
	if ((u= fopen(a.id,"r")) == NULL)                    //以只读方式打开打开对应id的文件 
    {
	    printf("文件打开失败>_<\n\n");
    }
        
        else 
    {
        while((ch=fgetc(u))!=EOF)
      	{
        	putchar(ch);                                 //打印订单内容 
      	}
           
        	fclose(u);                      //关闭文件 
    }
    

}

void History_manager_order()                                 //管理员对应超市的历史订单 
{
        FILE*m;
	    int ch;
	    if ((m= fopen(d[manager_number].mall,"r")) == NULL)            //管理员对应超市的历史订单 
      	{
	      printf("文件打开失败>_<\n\n");
      	}
        
        else 
    	{
    	  	printf("序号  商品名  商品超市  商品编码  售价   销售量   库存\n");
          	while((ch=fgetc(m))!=EOF)
      		{
          		putchar(ch);                                //打印内容 
      		}         
        	fclose(m);                                   //关闭文件 
 		}
     		Order_volume();                                 //计算总营业额和总利润的函数 
     		return;
}

void Add()                                                                     //商品增加
{
	int flag;
	Read_text();
	printf("\n请添加新的的商品信息:\n");
    goods[goods_number+1].serial_number=goods_number+1;                               //新增商品的序号为原商品序号+1
    strcpy(goods[goods_number+1].shop,d[manager_number].mall);                          //将该管理员的所属超市复制到该商品的所属超市
 do
{
	flag=1;
 	printf("请输入新商品的名称:");
    scanf("%s", goods[goods_number+1].name);
    for(int i=0; i<goods_number;++i)
   {
        if (strcmp(goods[i].name, goods[goods_number+1].name) == 0)                                //将每一个商品的名称和新增商品的名称比较 若有相同名称
        {
    		if(strcmp(goods[i].shop, goods[goods_number+1].shop) == 0)                   //将新增商品的超市和管理员超市相比较 若相同 则该商店已有相同名字商品
			{ 
		    	printf("该名称已存在，请重新输入！\n");  
            	break;
        	}   
        }
        else if(i==goods_number-1)                                                 //无相同名称 退出循环
    	{
        	flag=0;
		}
   }
}while(flag==1);
 
 	do
 	{
 		flag=1;
    	printf("请输入新的商品的编号:\n");
    	scanf("%s", goods[goods_number+1].number);
    	for(int i= 0; i<goods_number;++i)
 		{
        	if (strcmp(goods[i].number, goods[goods_number+1].number)==0)           //将每一个商品的编号和新增商品的编号比较 若有相同名称
     		{
				printf("该ID已存在，请重新输入！\n");
        		break;
     		}
     		else if(i==goods_number-1)                                        //无相同名称 退出循环
    		{
        	flag=0;
			}	
     
 		}
	}while(flag==1);

    printf("请输入零售价格: ");                                   //输入零售价格
	do
    {
    	scanf("%f",&goods[goods_number+1].sell_price);
    	if(goods[goods_number+1].sell_price<=0)
		{
			printf("零售价格必须为正数，请重新输入！\n");
		}  	
	}while(goods[goods_number+1].sell_price<=0);
	printf("添加成功！\n");
	printf("请输入进货价格： ");                                     //输入进价
	do
    {
    	scanf("%f",&goods[goods_number+1].buy_price);
    	if(goods[goods_number+1].buy_price<=0)
		{
			printf("进货价格必须为正数，请重新输入！\n");
		}  	
	}while(goods[goods_number+1].buy_price<=0);
	printf("添加成功！\n");
	goods[goods_number+1].sell_number=0;
    printf("销量已默认为0\n");
    printf("请输入库存：");                                               //输入库存
    do
    {
    	scanf("%d",&goods[goods_number+1].left_number);
    	if(goods[goods_number+1].left_number<=0)
		{
			printf("库存必须为正数，请重新输入！\n");
		}  	
	}while(goods[goods_number+1].left_number<=0);
	printf("请确定是否发布该商品（1.是 2.否）\n");                                       //选择是否发布
	int choicee;
	scanf("%d",&choicee);
	if(choicee==1)
	{	
		printf("商品已经成功发布！\n");
		FILE *p;
    	if((p = fopen("goods.txt","a"))==NULL)
    	{
    		printf("文件打开失败>_<\n");
			exit(0);
    	}                                                                     //向商品文件中写入新添加的商品
	       
		fprintf(p,"%d %s %s %s %.2f %.2f %d %d\n",goods[goods_number+1].serial_number,goods[goods_number+1].name,goods[goods_number+1].shop,goods[goods_number+1].number,goods[goods_number+1].sell_price,goods[goods_number+1].buy_price,goods[goods_number+1].sell_number,goods[goods_number+1].left_number);
		fclose(p);
	}
	if(choicee==2)
	{
		printf("该商品的发布已取消\n");
		memset(goods,0,sizeof(goods));
	}
	printf("请问是否继续添加商品（1.是 2.不是）\n");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		Add();
	}
	else
	{
		return;
	}
	            
}

void Change_information_manager()                       //修改管理员信息 
{
	int change_choice;                                   //定义管理员的选项 
	printf("\n请选择您想更改的信息：\n");	
	printf("1.修改密码\n");
	printf("2.修改姓名\n");
	printf("3.修改电话\n");
	printf("4.修改邮箱\n");
	printf("5.返回主界面\n");                         //打印界面 
	
	
	scanf("%d",&change_choice);            //读入选项 
	switch(change_choice)                                                 //选项对应 
	{
		case 1:
			printf("原始密码为:%s\n",d[manager_number].password);                 //打印旧密码 
			printf("请输入新密码：");
			scanf("%s",d[manager_number].password);                 //读入新密码
			printf("修改成功！\n");
			break;
		case 2:
			printf("原始姓名为:%s\n",d[manager_number].name);
			printf("请输入新名字：");
			scanf("%s",d[manager_number].name);
			printf("修改成功！\n");
			break;		
		case 3:
			printf("原始电话为:%s\n",d[manager_number].number);
			printf("请输入新电话：");
			Phone_number();
			strcpy(d[manager_number].number,iphone);
			printf("修改成功！\n");
			break;
		case 4:			
			printf("原始邮箱为:%s\n",d[manager_number].email);
			printf("请输入新邮箱：");
			Email();
			strcpy(d[manager_number].email,eemail);
			break;
		case 5:
			return;
		default:
			printf("输入错误，请重新输入！\n");
			Change_information_manager();
			break;
		
	}
	FILE *fp;
    if((fp = fopen("managers.txt","w"))==NULL)                          //打开管理员文件 
    {
    	printf("文件打开失败>_<\n");
		exit(0);
	}
	fwrite(d, sizeof(struct managers),3, fp);                      //按结构体格式写入文件
	fclose(fp);                                                      //关闭文件 
	return;
	
	            
}


void Manager_search()                                  //管理员搜索函数
{
	Read_text();                                         //读取文件
	char search_choice[20];                                   //定义一个数组，用于暂存管理员输入的商品名或商品编号
	int which=-1,change_choice;                                  //定义int which=-1用于未查到商品却想要修改信息的情况；定义int change_choice用于管理员选择修改操作
	printf("\n请搜索商品名或商品编号：\n");
	scanf("%s",search_choice);                                        //输入搜索内容
	printf("序号  商品名  商品超市  商品编码  售价  进价 销售量   库存\n");              //打印搜索项目
	for(int i=0;i<goods_number;++i)
  	{
		if(strcmp(search_choice,goods[i].name)==0||strcmp(search_choice,goods[i].number)==0)           //将输入内容与结构体内容比较
		{
			if(strcmp(d[manager_number].mall,goods[i].shop)==0)                                //如果搜索商品是管理员所在超市商品，则打印查询结果
		  	{
				printf("%d    %s   %s   %s   %.2f   %.2f   %d     %d\n",goods[i].serial_number,goods[i].name,goods[i].shop,goods[i].number,goods[i].sell_price,goods[i].buy_price,goods[i].sell_number,goods[i].left_number);
	        	which=i;
	        	break;
	      	}
	    }
	    	else if(i==goods_number-1)                         //若遍历数组完毕未找到结果，则打印"查无该结果"
	    {
	    	printf("查无该结果\n");	    
		}
	}
	int choice;                                                          //定义一个整形，用于用户选择功能
	printf("请选择操作（1.继续查询 2.修改信息 3.返回主界面）\n");
	scanf("%d",&choice);                                                   //用户输入数字进行选择
	switch(choice)
	{
		case 1:                                                           //选1，继续查询
		    Manager_search();
		    break;
		case 2: 	
			if(which==-1)                                                          //用于未查到商品却想要修改信息的情况
			{
				printf("没有查询到商品，无法修改！\n");
				return;
			}   
			int  change_choice;             
	        printf("请选择您要修改的商品信息：\n");                                             //选择要完成的操作   
	        printf("1.修改售价\n");
	        printf("2.修改库存\n");	  	        
	        scanf("%d",&change_choice);	       
	        if(change_choice==1)
		   	{
		        printf("原始售价为:%.2f\n",goods[which].sell_price);
			    printf("请输入新售价：");                                                   //修改售价
			    do
    			{
    				scanf("%f",&goods[which].sell_price);
    				if(goods[which].sell_price<=0)
					{
						printf("售价必须为正数，请重新输入！\n");
					}  	
				}while(goods[which].sell_price<=0);
			    printf("修改成功\n");
			 
		   	}
			 	
		    else if(change_choice==2)
		   	{	   	
			    printf("原始库存为:%d\n",goods[which].left_number);
			    printf("请输入新库存：");                                             //修改库存
			    do
    			{
    				scanf("%d",&goods[which].left_number);
    				if(goods[which].left_number<0)
					{
						printf("库存不能为负数，请重新输入！\n");
					}  	
				}while(goods[which].left_number<=0);
			    printf("修改成功\n");
				}
			else
			{
				printf("输入错误，已自动返回主界面！\n");
			}		
		case 3:
			return;
			break;
		default:
			return;
		
	}

	        
	
	FILE *ppp;                                                    //打开"goods"文件
    if((ppp = fopen("goods.txt","w"))==NULL)
    {
    	printf("文件打开失败>_<\n");                                  //打开失败
		exit(0);
    }
	    for(int i=0;i<goods_number;++i)                              //遍历整个结构体，将修改后的内容写入结构体 
	{
	    fprintf(ppp,"%d %s %s %s %.2f %.2f %d %d\n",goods[i].serial_number,goods[i].name,goods[i].shop,goods[i].number,goods[i].sell_price,goods[i].buy_price,goods[i].sell_number,goods[i].left_number);
	}
		fclose(ppp); 
	            
}





void Statistics()                                                    //统计信息函数
{

	int sort_choice,flag=1; 
  	do
  	{
		printf("\n请选择您想查看的信息\n");                          //可选择五个功能
		printf("1.商品按营业额排序\n");
		printf("2.商品按销量排序\n");
		printf("3.商品按利润排序\n");
		printf("4.进货情况\n");
		printf("5.返回主界面\n");
		scanf("%d",&sort_choice);
		switch(sort_choice)	
		{
			case 1:
				Business_volume();
				break;
			case 2:
				Manager_salesvolume();
	        	break;	
	    	case 3:
	    		Manager_profit();
				break;
	    	case 4:
	    		Purchase_status();
				break;
			case 5:
				flag=0;
				break;	
			default:
				printf("输入序号错误，请重新输入！\n");
				Statistics();
				break;	
		}
  	}while(flag==1);

}

void Manager_salesvolume()                                             //管理员按销量排序函数
{
	Read_text();
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
	printf("序号  商品名  商品超市  商品编码  售价   进价  利润  销售量   库存\n");      //销量由高到低输出商品
	for(int j=0;j<goods_number;++j)
	{
		if(strcmp(d[manager_number].mall,goods[j].shop)==0)
		printf("%d    %s   %s   %s   %0.2f  %0.2f  %0.2f   %d       %d\n",goods[j].serial_number,goods[j].name,goods[j].shop,goods[j].number,goods[j].sell_price,goods[j].buy_price,(goods[j].sell_price-goods[j].buy_price),goods[j].sell_number,goods[j].left_number);
	}
	return;
}

void Manager_profit()                           						//商品利润排序
{
	Read_text();                                   						//读取文件
	Goods middle;                                       				//定义一个Goods类型的变量
	for(int j=0;j<goods_number-1;++j)                   				//从第一位比较到倒数第二位
	{
		for(int n=j+1;n<goods_number;++n)                   			//从第二位比较到倒数第一位
		{
			if((goods[j].sell_price-goods[j].buy_price)<(goods[n].sell_price-goods[n].buy_price))                 //前一位若小于后一位，交换位置
			{
				middle=goods[j];
				goods[j]=goods[n];
				goods[n]=middle;
			} 
		}
	}
	printf("序号  商品名  商品超市  商品编码  售价   进价  利润  销售量   库存\n");
	for(int j=0;j<goods_number;++j)
	{
		if(strcmp(d[manager_number].mall,goods[j].shop)==0)
		printf("%d    %s   %s   %s   %0.2f  %0.2f  %0.2f     %d       %d\n",goods[j].serial_number,goods[j].name,goods[j].shop,goods[j].number,goods[j].sell_price,goods[j].buy_price,(goods[j].sell_price-goods[j].buy_price),goods[j].sell_number,goods[j].left_number);
	}
	return;
	
	
}

void Order_volume()                                                      //计算该超市总订单营业额及利润函数
{
	
	    float volume_middle,profit_middle;
	    float volume_total=0,profit_total=0;
		FILE *p;
        if((p = fopen(d[manager_number].name,"r"))==NULL)
        {
    	    printf("文件打开失败>_<\n");
		    exit(0);
      	}
	       
	    while(fscanf(p,"%f %f",&volume_middle,&profit_middle)!=EOF)        //不断读入每一单的总价和利润
	    {
	        volume_total+=volume_middle;
	        profit_total+=profit_middle;                                   //计算总营业额和利润
		}
		printf("总营业额为%.2f ，总利润为%.2f\n",volume_total,profit_total);	
		fclose(p); 
	
}



void Make_seperate_order()                                //按超市拆分订单函数
{
	
    float hm=0,wm=0,sh=0;
	for(int i=0;i<10;++i)                                //迭代购物车数组，分别按不同的超市输出商品
  	{
      	if(strcmp(buy_goods[i].shop,"盒马鲜生")==0)                 
      	{			
			printf("%d   %s   %s     %s   %.2f   %d     %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			hm+=buy_goods[i].sell_price;			
		}
  	}
	    if(hm!=0)
     	{
	     	printf("盒马鲜生商品总价为%0.2f\n",hm);
	     	Time();
     	} 
 
    for(int i=0;i<10;++i)                                //迭代购物车数组，分别按不同的超市输出商品
  	{
      	if(strcmp(buy_goods[i].shop,"物美超市")==0)
      	{			
			printf("%d   %s   %s     %s   %.2f   %d      %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].sell_number,buy_goods[i].left_number);
		    wm+=buy_goods[i].sell_price;
		}
  	}
	    if(wm!=0)
   		{
	    	printf("物美超市商品总价为%0.2f\n",wm);
	    	Time();
   		} 
   
    for(int i=0;i<10;++i)                                 //迭代购物车数组，分别按不同的超市输出商品
 	{
      	if(strcmp(buy_goods[i].shop,"首航超市")==0)
      	{			
			printf("%d   %s    %s    %s   %.2f    %d     %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			sh+=buy_goods[i].sell_price;
		}
	}
	    if(sh!=0)
    	{
	       	printf("首航超市商品总价为%0.2f\n",sh);
	       	Time();
	      
      	} 
      
      
      	total_money=0;
		for(int j=0;j<10;++j)
		{					
			if(buy_goods[j].serial_number!=0)
	 		{		 
				total_money+=buy_goods[j].sell_price;            //计算订单总价
	 		}	    			
		}
}

void Write_seperate_order()                                 //写顾客历史订单文件函数
{
	FILE *u;
    if((u = fopen(a.id,"a"))==NULL)
    {
    	printf("文件打开失败>_<\n");
		exit(0);
    }  
	  	float hm=0,wm=0,sh=0;
	  	for(int i=0;i<10;++i)                                      //迭代购物车数组，分别按不同的超市将商品写入顾客历史订单
  	{
      	if(strcmp(buy_goods[i].shop,"盒马鲜生")==0)
      	{		
			fprintf(u,"%d    %s   %s   %s    %.2f    %d    %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			hm+=buy_goods[i].sell_price;			
		}
  	}
	if(hm!=0)
 	{
	 
	  	fprintf(u,"盒马鲜生商品总价为%0.2f\n",hm);
	  	time_t t;
      	struct tm * lt;
      	time (&t);
      	lt = localtime (&t);
      	fprintf ( u,"购买时间为：%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
 	} 
 
    	for(int i=0;i<10;++i)                                       //迭代购物车数组，分别按不同的超市将商品写入顾客历史订单
  	{
      	if(strcmp(buy_goods[i].shop,"物美超市")==0)
      	{		
			fprintf(u,"%d    %s   %s   %s    %.2f    %d    %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			wm+=buy_goods[i].sell_price;
		}
  	}
	   	if(wm!=0)
   		{	 
	  		fprintf(u,"物美超市商品总价为%0.2f\n",wm);
	  		time_t t;
      		struct tm * lt;
      		time (&t);
      		lt = localtime (&t);
	  		fprintf ( u,"购买时间为：%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
   		} 
   
    for(int i=0;i<10;++i)                                          //迭代购物车数组，分别按不同的超市将商品写入顾客历史订单
 	{
      	if(strcmp(buy_goods[i].shop,"首航超市")==0)
      	{	
			fprintf(u,"%d    %s   %s   %s    %.2f     %d    %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			sh+=buy_goods[i].sell_price;
		}
  	}
	    if(sh!=0)
     	{	      
	       	fprintf(u,"首航超市商品总价为%0.2f\n",sh); 
	       	time_t t;
           	struct tm * lt;
           	time (&t);
           	lt = localtime (&t);
	       	fprintf ( u,"购买时间为：%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
      	} 
      		total_money=0;
			for(int j=0;j<10;++j)
		{				
			if(buy_goods[j].serial_number!=0)
	 		{		 
				total_money+=buy_goods[j].sell_price;
	 		}			
		}
		fprintf(u,"订单编号为：%s",b[user_number].id);                   //将该订单的编号写入历史订单文件
	    time_t t;
    	struct tm * lt;
    	time (&t);
    	lt = localtime (&t);                                                 
    	fprintf ( u,"%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		fprintf(u,"订单总价为%0.2f\n",total_money);                      //将该订单的总价写入历史订单文件
		fprintf(u,"您的余额为%.2f\n",b[user_number].money);              //将顾客余额写入历史订单文件
		fclose(u);
	
}

void Write_shop_order()                                               //写超市历史订单文件函数
{

	FILE *h;
    if((h= fopen("盒马鲜生","a"))==NULL)
    {
    	printf("文件打开失败>_<\n");
		exit(0);
    }  
  
    FILE *w;
    if((w= fopen("物美超市","a"))==NULL)
    {
    	printf("文件打开失败>_<\n");
		exit(0);
    }  
    FILE *s;
    if((s= fopen("首航超市","a"))==NULL)
    {
    	printf("文件打开失败>_<\n");
		exit(0);
    }  
       
	  for(int i=0;i<10;++i)                                      //遍历购物车数组，将所属该超市的小订单写入该超市历史订单文件
  	{
      	if(strcmp(buy_goods[i].shop,"盒马鲜生")==0)
      	{	
			fprintf(h,"%d   %s  %s  %s   %.2f  %.2f   %d   %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			hm_sell_money+=buy_goods[i].sell_price;
			hm_profit+=buy_goods[i].sell_price-buy_goods[i].buy_price;
		}
  	}
	    if(hm_sell_money!=0)
     	{
	     	fprintf(h,"盒马鲜生商品总价为%0.2f\n",hm_sell_money); 
	     	time_t t;
         	struct tm * lt;
         	time (&t);
         	lt = localtime (&t);                                         //将订单总价、顾客编号、购买时间、订单编号写入该文件
         	fprintf ( h,"用户编号为%s,购买时间为：%d：%d：%d %d:%d:%d\n",a.id,lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
         	fprintf(h,"订单编号为：%s",b[user_number].id);
	   		fprintf ( h,"%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
     	} 
 
      for(int i=0;i<10;++i)                                      //遍历购物车数组，将所属该超市的小订单写入该超市历史订单文件
  	{
      	if(strcmp(buy_goods[i].shop,"物美超市")==0)
      	{	
			fprintf(w,"%d   %s  %s  %s   %.2f  %.2f   %d   %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			wm_sell_money+=buy_goods[i].sell_price;
			wm_profit+=buy_goods[i].sell_price-buy_goods[i].buy_price;
		}
  	}
	    if(wm_sell_money!=0)
       {
	       	fprintf(w,"物美超市商品总价为%0.2f\n",wm_sell_money);
	       	time_t t;
           	struct tm * lt;
           	time (&t);
           	lt = localtime (&t);                                        //将订单总价、顾客编号、购买时间、订单编号写入该文件
	       	fprintf ( w,"用户编号为%s,购买时间为：%d：%d：%d %d:%d:%d\n",a.id,lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);    
	       	fprintf(w,"订单编号为：%s",b[user_number].id);
	   		fprintf ( w,"%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
      	} 
   
    	for(int i=0;i<10;++i)                                        //遍历购物车数组，将所属该超市的小订单写入该超市历史订单文件
 	{
      	if(strcmp(buy_goods[i].shop,"首航超市")==0)
      	{
			fprintf(s,"%d   %s  %s  %s   %.2f  %.2f   %d   %d\n",buy_goods[i].serial_number,buy_goods[i].name,buy_goods[i].shop,buy_goods[i].number,buy_goods[i].sell_price,buy_goods[i].buy_price,buy_goods[i].sell_number,buy_goods[i].left_number);
			sh_sell_money+=buy_goods[i].sell_price;
			sh_profit+=buy_goods[i].sell_price-buy_goods[i].buy_price;
		}
  	}
	    if(sh_sell_money!=0)
     	{   
	       	fprintf(s,"首航超市商品总价为%0.2f\n",sh_sell_money);
	       	time_t t;
           	struct tm * lt;
           	time (&t);
           	lt = localtime (&t);                                        //将订单总价、顾客编号、购买时间、订单编号写入该文件
	       	fprintf ( s,"用户编号为%s,购买时间为：%d：%d：%d %d:%d:%d\n",a.id,lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	       	fprintf(s,"订单编号为：%s",b[user_number].id);
	   		fprintf ( s,"%d:%d:%d:%d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
      	} 
         
	fclose(h);
	fclose(w);
	fclose(s);
		
}



void Purchase_status()                                    //商品状态函数
{
 	Read_text();
  	float rate;
  	int yes_no=0;
  	for (int j=0;j<goods_number;++j)
   {
     	if(strcmp(goods[j].shop,d[manager_number].mall)==0)
     	{
      		float m=goods[j].sell_number;                                 
        	rate=m/(goods[j].left_number+goods[j].sell_number);        //计算销量/（销量+库存）
       		if(rate<=0.1)
      		{
          		printf("%s有滞销情况\n",goods[j].name);                //判断商品出售情况
          		yes_no=1;
      		}
       		else if(rate>=0.9)
      		{
       			printf("%s需要进货\n",goods[j].name);
				   yes_no=1;    
       		}			
    	}
    	if(j==goods_number-1&&yes_no==0)
    	{
    		printf("没有需要进货或滞销的商品\n");
		}
    	
 	}
   return;



}


void Phone_number()                                            //检查电话格式 
{
	scanf("%s",iphone);
	while(strlen(iphone)!=11)                                      //计算字符串长度的函数 
 	{
		printf("输入电话长度不是11位，请重新输入！\n");
		Phone_number();                                         //输入错误 重新输入 返回函数开始 重新检查 
 	}
	for(int i=0;i<11;++i)
  	{
		if(iphone[i]>='0'&&iphone[i]<='9')                         //电话只能是0-9的数字 
		{
			continue;
		}
		else
		{
			printf("输入电话格式错误，请重新输入！\n");
			Phone_number();                                         //输入错误 重新输入 返回函数开始 重新检查
		}
  	}
  	return;
}

void Business_volume()                                              //总营业额排序
{
	Read_text();                                      //读取文件
	Goods middle;                                 //定义一个Goods类型的变量
	for(int j=0;j<goods_number-1;++j)                             //从第一位比较到倒数第二位
	{
		for(int n=j+1;n<goods_number;++n)                               //从第一位比较到倒数第二位
		{
			if((goods[j].sell_price*goods[j].sell_number)<(goods[n].sell_price*goods[n].sell_number))          //前一位若小于后一位，交换位置
			{
				middle=goods[j];
				goods[j]=goods[n];
				goods[n]=middle;
			} 
		}
	}
	printf("序号  商品名  商品超市  商品编码  售价   进价  利润  销售量   库存   该商品营业额\n");
	for(int j=0;j<goods_number;++j)
	{
		if(strcmp(d[manager_number].mall,goods[j].shop)==0)
		printf("%d    %s   %s   %s   %0.2f  %0.2f  %0.2f     %d       %d    %.2f\n",goods[j].serial_number,goods[j].name,goods[j].shop,goods[j].number,goods[j].sell_price,goods[j].buy_price,(goods[j].sell_price-goods[j].buy_price),goods[j].sell_number,goods[j].left_number,goods[j].sell_price*goods[j].sell_number);
	}
	return;
		
}

void Email()                                 //检查邮箱格式 
{
	scanf("%s",eemail);
	int n=strlen(eemail);                       //n为字符串长度 
	int which=-1;
	for(int i=0;i<n;++i)                           //循环访问字符串数组 
	{
		if(eemail[i]=='@'&&i<n-5)                            //读到
		{
			which=i;
			for(int j=which+2;j<n;++j)                 //从@后两位开始循环读
			{
				if(eemail[j]=='.'&&j!=n-1)                 //有.且不是最后一位 
				{
					printf("修改成功！\n");
					return;
				}
				else
				{
					if(j==n-1)                                           //.是最后一位 
					{
						printf("邮箱格式不正确，请重新输入！\n");                //输入错误 重新输入 返回函数开始 重新检查
						Email();
					}
						
				}
				
			}
		}
		if(i==n-1&&which==-1)                                               //@是最后一位或者没有@ 
		{
			printf("邮箱格式不正确，请重新输入！\n");
			Email();                                                          //输入错误 重新输入 返回函数开始 重新检查
		}
	}
}

#include<stdio.h>
#include<string.h>
#include<math.h>
//SZTU202100801044 
void caidan(int n)//菜单函数，便于输出菜单 
{
	if(n==0)printf("信息已录入，成功初始化，输入功能前的数字以继续\n1添加一个学生信息\n2添加多个学生信息\n3根据学号删除某个学生的信息\n4根据学号查找某个学生的信息\n5生成根据学号顺序排列学生信息的表格\n6生成根据分数由高到低顺序排列学生信息的表格\n7返回最高分学生信息\n8返回最低分学生信息\n9返回所有学生期末成绩平均分\n10返回某个学生成绩是否为质数\n11返回某两个学生成绩是否互质\n12返回各个GPA等级的人数\n...\n0退出\n");//首次使用调用 
	else if(n==1)printf("操作已完成，输入功能前的数字以继续\n1添加一个学生信息\n2添加多个学生信息\n3根据学号删除某个学生的信息\n4根据学号查找某个学生的信息\n5生成根据学号顺序排列学生信息的表格\n6生成根据分数由高到低顺序排列学生信息的表格\n7返回最高分学生信息\n8返回最低分学生信息\n9返回所有学生期末成绩平均分\n10返回某个学生成绩是否为质数\n11返回某两个学生成绩是否互质\n12返回各个GPA等级的人数\n...\n0退出\n");//非首次使用调用
}
void chuli();//声明chuli函数，用于每次对学生信息进行增删操作后补全重修信息、gpa信息、班级排名 
void add(char name[100],long long id,int score);//声明add函数 
void adds(int n,char names[100][100],long long ids[100],int scores[100]);//声明adds函数 
void deletea(long long id);//声明deletea函数 
void search(long long id);//声明search函数 
void sort_by_id();//声明sort_by_id函数
void sort_by_score();//声明sort_by_score函数 
void max();//声明max函数 
void min();//声明min函数 
void ave();//声明ave函数 
void prime(long long id);//声明prime函数
void coprime(long long id,long long id2);//声明coprime函数 
void analysis();//声明analysis函数 
struct student//建立结构 student
	{
		char xingming[100];//学生姓名 
		long long xuehao;//学号
		int c;//c语言成绩 
		long long chongxiu;//重修信息，如果为学号则为不需要重修，1为需要重修 
		char gpa[2];//学生gpa信息 
		int paiming;//学生班级排名 
	};
	struct student sztu[100];//建立结构数组 
	struct student *p; //建立结构指针 
int main()
{
	int x,y,z,i,j,n,tem1[100],tem2[200];
	char tem3[100],tem4[100];//定义一些临时中间变量
	int score;//用户输入的学生分数
	long long id,id2;//学生的学号，长整型 
	char na[100],me[100];//用户输入的学生姓、名 
	char name[100];//将用户输入的姓、名合成为一个字符串 
	char names[100][100];//用于用户批量添加学生信息时存入学生姓名 
	long long ids[100];//用于用户批量添加学生信息时存入学生学号
	int cs[100];//用于用户批量添加学生信息时存入学生c语言成绩 
	for(i=0;i<100;i++)
	{
		sztu[i].xuehao=0;//为学生学号赋初值0，便于以后的判定及删除操作 
		sztu[i].c=0;//为学生成绩赋初值0，便于以后的判定
		sztu[i].chongxiu=0;//为学生重修信息赋初值0
	}
	printf("欢迎使用，请按照（学生姓名、学号、成绩）的方式输入若干组初始学生信息，输入CTRL+Z以结束\n");
	for(i=0;i>(-1);i++)//进行一个不会自主结束的循环，用于录入初始的一些学生信息 
	{
			if(scanf("%s %s %lld %d",na,me,&sztu[i].xuehao,&sztu[i].c)!=EOF)//分别存入学生的个人信息 
			{
				 strcat(na," ");
				 strcat(na,me);//合成为一个字符串
				 strcpy(sztu[i].xingming,na);//存入学生信息的姓名中 
			}
			else
			{
				break;//由于不知道输入的学生信息数量，当输入CTRL+Z时（EOF）跳出循环
			}
	}
	chuli();//调用chuli函数，补全学生信息中的重修信息、gpa信息、班级排名，下同，每次增删学生信息后调用 
	caidan(0);//调用菜单函数 
	for(i=0;i>(-1);i++)//不自动结束的循环，重复获取用户输入的数字 
	{
		printf("请输入你要进行的操作序号：");
		scanf("%d",&x);//获取用户输入的数字 
		if(x==0)
		{
			printf("期待您的下次使用!\n"); 
			break;//用户输入0退出，程序结束 
		}
		switch(x)//根据输入的数字选择对应的功能 
		{
			case 1:
			printf("请输入姓名、学号、C语言成绩：");
			scanf("%s %s %lld %d",na,me,&id,&score);
			strcat(na," ");
			strcat(na,me);
			strcpy(name,na);//将学生姓、名合成为一个字符串 
			add(name,id,score);//调用add函数，添加单个学生信息 
			chuli();//调用chuli函数，补全或修改学生信息中的重修信息、gpa信息、班级排名
			caidan(1);//输出菜单 
			break;
			
			case 2:
			printf("请在第一排输入要批量添加的学生信息数量\n第二排依次输入学生的姓名\n第三排依次输入学生的学号\n第四排依次输出学生的c语言成绩\n");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s %s",na,me);
				strcat(na," ");
				strcat(na,me);
				strcpy(name,na);//将学生姓、名合成为一个字符串 
				strcpy(names[i],name);//存入names二维字符数组 
			}
			for(i=0;i<n;i++)
			{
				scanf("%lld",&ids[i]);//将学生学号信息存入ids长数组中 
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&cs[i]);//将学生c语言成绩信息存入cs数组中 
			}
			adds(n,names,ids,cs); //调用adds函数 
			chuli(); //调用chuli函数，补全或修改学生信息中的重修信息、gpa信息、班级排名
			caidan(1);//输出菜单 
			break;
			
			case 3:
			printf("请输入学生学号：");
			scanf("%lld",&id);
			deletea(id);//调用deletea函数 
			chuli();//调用chuli函数，补全或修改学生信息中的重修信息、gpa信息、班级排名
			caidan(1);//输出菜单
			break;
			
			case 4:
			printf("请输入学生学号：");
			scanf("%lld",&id);
			search(id);//调用search函数 
			caidan(1);//输出菜单
			break;
			
			case 5:
			sort_by_id();//调用sort_by_id函数 
			caidan(1);//输出菜单
			break;
			
			case 6:
			sort_by_score();//调用sort_by_score函数 
			caidan(1);//输出菜单
			break;
			
			case 7:
			max();//调用max函数 
			caidan(1);//输出菜单
			break;
			
			case 8:
			min();//调用min函数 
			caidan(1);//输出菜单
			break;
			
			case 9:
			ave();//调用ave函数 
			caidan(1);//输出菜单
			break;
			
			case 10:
			printf("请输入学生学号：");
			scanf("%lld",&id);
			prime(id);//调用prime函数 
			caidan(1);//输出菜单
			break; 
			
			case 11:
			printf("请输入学生学号1、学生学号2：");
			scanf("%lld %lld",&id,&id2);
			coprime(id,id2);//调用coprime函数 
			caidan(1);//输出菜单
			break;
			
			case 12:
			analysis();//调用analysis函数 
			caidan(1);//输出菜单
			break;
			
			default:
			printf("非法输入！请重新输入！\n");
			break;
		}
	}
}
void chuli()//chuli函数，用于每次对学生信息进行增删操作后补全重修信息、gpa信息、班级排名
{
	p=&sztu[0];//重置p的位置 
	int i,j,pm,tem;
	int a[100];//临时储存成绩信息，便于排序 
	for(i=0;i<100;i++,p++)
	{
		if(p->c>=93&&p->xuehao!=0)
		{
			strcpy(p->gpa,"A+");//为学生信息的gpa赋值 ，下同 
			p->chongxiu=p->xuehao;//为学生信息的重修信息赋值，下同 
		}
		else if(p->c<93&&p->c>=85&&p->xuehao!=0)
		{
			strcpy(p->gpa,"A");
			p->chongxiu=p->xuehao;
		}
		else if(p->c<85&&p->c>=80&&p->xuehao!=0)
		{
			strcpy(p->gpa,"B+");
			p->chongxiu=p->xuehao;
		}
		else if(p->c<80&&p->c>=75&&p->xuehao!=0)
		{
			strcpy(p->gpa,"B");
			p->chongxiu=p->xuehao;
		}
		else if(p->c<75&&p->c>=70&&p->xuehao!=0)
		{
			strcpy(p->gpa,"C+");
			p->chongxiu=p->xuehao;
		}
		else if(p->c<70&&p->c>=65&&p->xuehao!=0)
		{
			strcpy(p->gpa,"C");
			p->chongxiu=p->xuehao;
		}
		else if(p->c<65&&p->c>=60&&p->xuehao!=0)
		{
			strcpy(p->gpa,"D");
			p->chongxiu=p->xuehao;
		}
		else if(p->c<60&&p->xuehao!=0)
		{
			strcpy(p->gpa,"F");
			p->chongxiu=1;//如果需要重修则赋值为1 
		}
	}
	p=&sztu[0];//重置p的位置 
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==0)//学号为0则跳过 
		{
			a[i]=0;//跳过后赋值为0
			continue;
		}
		a[i]=p->c;//将成绩信息存入a[i]中，便于排序 
	}
	for(i=0;i<100;i++)
	{
		for(j=i;j<100;j++)//逐个比较，最终将其从大到小排列 
		{
			if(a[i]<a[j])
			{
				tem=a[i];
				a[i]=a[j];
				a[j]=tem;//利用中间变量交换a[i]和a[j]的值 
			}
		}
	}	
	p=&sztu[0];//重置p的位置 
	pm=1;//排名数
	for(i=0;i<100;i++)
	{
		if(a[i]==a[i-1]&&i>0)//考虑到并列排名，跳过对相同成绩的判定 
		{
			continue;
		}
		for(j=0;j<100;j++,p++)
		{
			if(p->c==a[i]&&p->xuehao!=0)
			{
				p->paiming=pm;//为学生的班级排名信息赋值 
			}	
		}
		p=&sztu[0];//重置p的位置 
		pm++;//排名+1 
	}
}
void add(char name[100],long long id,int score) //功能1函数，添加单个学生信息 
{
	p=&sztu[0];//重置p的位置 
	int i,j;
	for(i=0;i<100;i++,p++)//寻找空位进行赋值 
	{
		if (p->xuehao==0)//找到空位后进行赋值操作 
		{
			strcpy(p->xingming,name);
			p->xuehao=id;
			p->c=score; //为姓名、学号、c语言成绩赋值 
			break;
		}
	}
}
void adds(int n,char names[100][100],long long ids[100],int scores[100])//功能2函数，添加多个学生信息 
{
	p=&sztu[0];//重置p的位置 
	int i,j,count;
	count=0;//赋初值为0，用于计数已经添加了几个学生的信息 
	for(i=0;i<100;i++,p++)//寻找空位进行赋值 
	{
		if (p->xuehao==0)//找到空位后进行赋值操作 
		{
			strcpy(p->xingming,names[count]);
			p->xuehao=ids[count];
			p->c=scores[count]; //为姓名、学号、c语言成绩赋值 
			count++;//计数已经添加了几个学生的信息 
		}
		if (count==n) //添加完后退出 
		{
			break; 
		}
	}
}
void deletea(long long id)//功能3函数，删除单个学生信息 
{
	p=&sztu[0];//重置p的位置 
	int i,j;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//按照学号搜索信息 
		{
			p->xuehao=0;//匹配到后将学号的值改为0，视为删除
			break; 
		}
	}
}
void search(long long id)//功能4函数，寻找学生信息并打印出来 
{
	p=&sztu[0];//重置p的位置 
	int i,j;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//按照学号搜索信息 
		{
			printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//输出符合的学生信息 
			break;
		}
	}
} 
void sort_by_id()//功能5函数，把学生信息按学号从大到小输出 
{
	p=&sztu[0];//重置p的位置 
	int i,j;
	long long a[100];//定义长数组a[]用于储存学号信息并排序 
	long long tem;//定义临时长变量 
	for(i=0;i<100;i++,p++)
	{
		a[i]=p->xuehao;//将学生学号信息储存到数组a[]中 
	}

	for(i=0;i<100;i++)
	{
		for(j=i;j<100;j++)//逐个比较，最终将其从大到小排列 
		{
			if(a[i]<a[j])
			{
				tem=a[i];
				a[i]=a[j];
				a[j]=tem;//利用中间变量交换a[i]和a[j]的值 	
			}
		}
	}
	p=&sztu[0];//重置p的位置 
	for(i=0;i<100;i++)
	{
		if(a[i]==0)//学号从大到小的顺序，如果a[i]==0，则说明后面没有学号信息了 
		{
			break;
		}
		for(j=0;j<100;j++,p++)
		{
			if(p->xuehao==a[i]&&p->xuehao!=0)//在学号不等于0的情况下逐个进行匹配，如果符合则输出 
			{
				printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//输出符合的学生信息 
				p=&sztu[0];//重置p的位置 
				break;
			}
		}
	}
}
void sort_by_score() //功能6函数，将学生信息按排名从小到大输出 
{
	p=&sztu[0];//重置p的位置 
	int i,j;
	for(i=1;i<=100;i++)
	{
		for(j=0;j<100;j++,p++)
		{
			if(p->paiming==i&&p->xuehao!=0)//在学号不等于0(为0则视为空或被删除）的情况下逐个进行匹配，如果符合则输出
			{
				printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//输出符合的学生信息 
			}
		}
		p=&sztu[0];//重置p的位置 
	}
}
void max() //功能7函数，输出最高分的学生信息 
{
	p=&sztu[0];//重置p的位置  
	int i,j,max;
	max=0;
	for(i=0;i<100;i++,p++)
	{
		if(max<p->c&&p->xuehao!=0)
		{
			max=p->c;//得到最高分 
		}
	}
	p=&sztu[0];//重置p的位置 
	for(i=0;i<100;i++,p++)
	{
		if(p->c==max&&p->xuehao!=0)
		{
			printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//输出符合的学生信息 
		}
	}
}
void min()//功能8函数，输出最低分学生信息 
{
	p=&sztu[0];//重置p的位置 
	int i,j,min;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao!=0)//若该位置不为空或已删除 
		{
			min=p->c;//为min赋一个有效的分数值 
		}
	}
	p=&sztu[0];//重置p的位置 
	for(i=0;i<100;i++,p++)
	{
		if(min>p->c&&p->xuehao!=0)
		{
			min=p->c;//得到最低分 
		}
	}
	p=&sztu[0];//重置p的位置 
	for(i=0;i<100;i++,p++)
	{
		if(p->c==min&&p->xuehao!=0)
		{
			printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//输出符合的学生信息 
		}
	}
}
void ave()//功能9函数，输出学生期末平均分数
{
	p=&sztu[0];
	int i,j,sum,renshu;
	double ave;
	sum=0;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==0)
		{
			continue;
		}
		sum=p->c+sum;
		renshu++;
	}
	printf("学生期末成绩平均分为：%.6f\n",sum*1.0/renshu);
}
void prime(long long id)//功能10函数 ,判断学生的成绩是否为素数 
{
	p=&sztu[0];//重置p的位置 
	int i,j,flag;
	flag=0;//判断成绩是否为素数 
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//找到输入的学号对应的位置 
		{
			break;
		}
	}
	if(p->c==0||p->c==1)
	{
		printf("该生的成绩不是素数"); //0和1不为素数 
	}
	else if(p->c==2||p->c==3)
	{
		printf("该生的成绩是素数"); //2和3为素数 
	}
	else
	{
		for(j=2;j<p->c;j++)
		{
			if(p->c%j==0)//如果成绩能被比他小的数整除，则其为素数 
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("该生的成绩是素数\n");
		}
		else
		{
			printf("该生的成绩不是素数\n");
		}
	}
}
void coprime(long long id,long long id2)//功能11函数，判断两个学生的成绩是否互质 
{
	p=&sztu[0];//重置p的位置 
	int i,j,gb,m,n,tem;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//找到输入的学号对应的位置 
		{
			break;
		}
	}
	m=p->c;//第一个学生对应的成绩 
	p=&sztu[0];//重置p的位置 
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id2)//找到输入的学号对应的位置 
		{
			break;
		}
	}
	n=p->c; //第二个学生对应的成绩 
	if(m<n)//使m>=n 
	{
		tem=m;
		m=n;
		n=tem;//借助tem互换m和n的值 
	}
	while (n != 0)
	{
        tem = m % n;
        m = n;
        n = tem;//欧几里得求最大公约数 
    } 
    if(m==1)
    {
    	printf("两学生的成绩互质\n"); //如果两数的最大公约数为1，则两数互质 
	}
	else
	{
		printf("两学生的成绩不互质\n");//反之，则不互质 
	}
}
void analysis()//功能12函数，分析整体情况，输出各个gpa等级的人数 
{
	p=&sztu[0];//重置p的位置 
	int i,j,a1,a,b1,b,c1,c,d,f;
	a1=0;
	a=0;
	b1=0;
	b=0;
	c1=0;
	c=0;
	d=0;
	f=0;//赋初值为0，用于计数 
	for(i=0;i<100;i++,p++)
	{
		if(strcmp(p->gpa,"A+")==0&&p->xuehao!=0)//如果gpa等级为A+，且学号位置不为0，代表a+人数的a1+1，下同 
		{
			a1++;
		}
		else if(strcmp(p->gpa,"A")==0&&p->xuehao!=0)
		{
			a++;
		}
		else if(strcmp(p->gpa,"B+")==0&&p->xuehao!=0)
		{
			b1++;
		}
		else if(strcmp(p->gpa,"B")==0&&p->xuehao!=0)
		{
			b++;
		}
		else if(strcmp(p->gpa,"C+")==0&&p->xuehao!=0)
		{
			c1++;
		}
		else if(strcmp(p->gpa,"C")==0&&p->xuehao!=0)
		{
			c++;
		}
		else if(strcmp(p->gpa,"D")==0&&p->xuehao!=0)
		{
			d++;
		}
		else if(strcmp(p->gpa,"F")==0&&p->xuehao!=0)
		{
			f++;
		}
	}
	printf("A+的人数为：%d\n",a1); 
	printf("A的人数为： %d\n",a); 
	printf("B+的人数为：%d\n",b1);
	printf("B的人数为： %d\n",b);  
	printf("C+的人数为：%d\n",c1); 
	printf("C的人数为： %d\n",c); 
	printf("D的人数为： %d\n",d);
	printf("F的人数为： %d\n",f);  //分别输出各个等级的人数 
}

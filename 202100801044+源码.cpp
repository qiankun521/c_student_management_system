#include<stdio.h>
#include<string.h>
#include<math.h>
//SZTU202100801044 
void caidan(int n)//�˵���������������˵� 
{
	if(n==0)printf("��Ϣ��¼�룬�ɹ���ʼ�������빦��ǰ�������Լ���\n1���һ��ѧ����Ϣ\n2��Ӷ��ѧ����Ϣ\n3����ѧ��ɾ��ĳ��ѧ������Ϣ\n4����ѧ�Ų���ĳ��ѧ������Ϣ\n5���ɸ���ѧ��˳������ѧ����Ϣ�ı��\n6���ɸ��ݷ����ɸߵ���˳������ѧ����Ϣ�ı��\n7������߷�ѧ����Ϣ\n8������ͷ�ѧ����Ϣ\n9��������ѧ����ĩ�ɼ�ƽ����\n10����ĳ��ѧ���ɼ��Ƿ�Ϊ����\n11����ĳ����ѧ���ɼ��Ƿ���\n12���ظ���GPA�ȼ�������\n...\n0�˳�\n");//�״�ʹ�õ��� 
	else if(n==1)printf("��������ɣ����빦��ǰ�������Լ���\n1���һ��ѧ����Ϣ\n2��Ӷ��ѧ����Ϣ\n3����ѧ��ɾ��ĳ��ѧ������Ϣ\n4����ѧ�Ų���ĳ��ѧ������Ϣ\n5���ɸ���ѧ��˳������ѧ����Ϣ�ı��\n6���ɸ��ݷ����ɸߵ���˳������ѧ����Ϣ�ı��\n7������߷�ѧ����Ϣ\n8������ͷ�ѧ����Ϣ\n9��������ѧ����ĩ�ɼ�ƽ����\n10����ĳ��ѧ���ɼ��Ƿ�Ϊ����\n11����ĳ����ѧ���ɼ��Ƿ���\n12���ظ���GPA�ȼ�������\n...\n0�˳�\n");//���״�ʹ�õ���
}
void chuli();//����chuli����������ÿ�ζ�ѧ����Ϣ������ɾ������ȫ������Ϣ��gpa��Ϣ���༶���� 
void add(char name[100],long long id,int score);//����add���� 
void adds(int n,char names[100][100],long long ids[100],int scores[100]);//����adds���� 
void deletea(long long id);//����deletea���� 
void search(long long id);//����search���� 
void sort_by_id();//����sort_by_id����
void sort_by_score();//����sort_by_score���� 
void max();//����max���� 
void min();//����min���� 
void ave();//����ave���� 
void prime(long long id);//����prime����
void coprime(long long id,long long id2);//����coprime���� 
void analysis();//����analysis���� 
struct student//�����ṹ student
	{
		char xingming[100];//ѧ������ 
		long long xuehao;//ѧ��
		int c;//c���Գɼ� 
		long long chongxiu;//������Ϣ�����Ϊѧ����Ϊ����Ҫ���ޣ�1Ϊ��Ҫ���� 
		char gpa[2];//ѧ��gpa��Ϣ 
		int paiming;//ѧ���༶���� 
	};
	struct student sztu[100];//�����ṹ���� 
	struct student *p; //�����ṹָ�� 
int main()
{
	int x,y,z,i,j,n,tem1[100],tem2[200];
	char tem3[100],tem4[100];//����һЩ��ʱ�м����
	int score;//�û������ѧ������
	long long id,id2;//ѧ����ѧ�ţ������� 
	char na[100],me[100];//�û������ѧ���ա��� 
	char name[100];//���û�������ա����ϳ�Ϊһ���ַ��� 
	char names[100][100];//�����û��������ѧ����Ϣʱ����ѧ������ 
	long long ids[100];//�����û��������ѧ����Ϣʱ����ѧ��ѧ��
	int cs[100];//�����û��������ѧ����Ϣʱ����ѧ��c���Գɼ� 
	for(i=0;i<100;i++)
	{
		sztu[i].xuehao=0;//Ϊѧ��ѧ�Ÿ���ֵ0�������Ժ���ж���ɾ������ 
		sztu[i].c=0;//Ϊѧ���ɼ�����ֵ0�������Ժ���ж�
		sztu[i].chongxiu=0;//Ϊѧ��������Ϣ����ֵ0
	}
	printf("��ӭʹ�ã��밴�գ�ѧ��������ѧ�š��ɼ����ķ�ʽ�����������ʼѧ����Ϣ������CTRL+Z�Խ���\n");
	for(i=0;i>(-1);i++)//����һ����������������ѭ��������¼���ʼ��һЩѧ����Ϣ 
	{
			if(scanf("%s %s %lld %d",na,me,&sztu[i].xuehao,&sztu[i].c)!=EOF)//�ֱ����ѧ���ĸ�����Ϣ 
			{
				 strcat(na," ");
				 strcat(na,me);//�ϳ�Ϊһ���ַ���
				 strcpy(sztu[i].xingming,na);//����ѧ����Ϣ�������� 
			}
			else
			{
				break;//���ڲ�֪�������ѧ����Ϣ������������CTRL+Zʱ��EOF������ѭ��
			}
	}
	chuli();//����chuli��������ȫѧ����Ϣ�е�������Ϣ��gpa��Ϣ���༶��������ͬ��ÿ����ɾѧ����Ϣ����� 
	caidan(0);//���ò˵����� 
	for(i=0;i>(-1);i++)//���Զ�������ѭ�����ظ���ȡ�û���������� 
	{
		printf("��������Ҫ���еĲ�����ţ�");
		scanf("%d",&x);//��ȡ�û���������� 
		if(x==0)
		{
			printf("�ڴ������´�ʹ��!\n"); 
			break;//�û�����0�˳���������� 
		}
		switch(x)//�������������ѡ���Ӧ�Ĺ��� 
		{
			case 1:
			printf("������������ѧ�š�C���Գɼ���");
			scanf("%s %s %lld %d",na,me,&id,&score);
			strcat(na," ");
			strcat(na,me);
			strcpy(name,na);//��ѧ���ա����ϳ�Ϊһ���ַ��� 
			add(name,id,score);//����add��������ӵ���ѧ����Ϣ 
			chuli();//����chuli��������ȫ���޸�ѧ����Ϣ�е�������Ϣ��gpa��Ϣ���༶����
			caidan(1);//����˵� 
			break;
			
			case 2:
			printf("���ڵ�һ������Ҫ������ӵ�ѧ����Ϣ����\n�ڶ�����������ѧ��������\n��������������ѧ����ѧ��\n�������������ѧ����c���Գɼ�\n");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s %s",na,me);
				strcat(na," ");
				strcat(na,me);
				strcpy(name,na);//��ѧ���ա����ϳ�Ϊһ���ַ��� 
				strcpy(names[i],name);//����names��ά�ַ����� 
			}
			for(i=0;i<n;i++)
			{
				scanf("%lld",&ids[i]);//��ѧ��ѧ����Ϣ����ids�������� 
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&cs[i]);//��ѧ��c���Գɼ���Ϣ����cs������ 
			}
			adds(n,names,ids,cs); //����adds���� 
			chuli(); //����chuli��������ȫ���޸�ѧ����Ϣ�е�������Ϣ��gpa��Ϣ���༶����
			caidan(1);//����˵� 
			break;
			
			case 3:
			printf("������ѧ��ѧ�ţ�");
			scanf("%lld",&id);
			deletea(id);//����deletea���� 
			chuli();//����chuli��������ȫ���޸�ѧ����Ϣ�е�������Ϣ��gpa��Ϣ���༶����
			caidan(1);//����˵�
			break;
			
			case 4:
			printf("������ѧ��ѧ�ţ�");
			scanf("%lld",&id);
			search(id);//����search���� 
			caidan(1);//����˵�
			break;
			
			case 5:
			sort_by_id();//����sort_by_id���� 
			caidan(1);//����˵�
			break;
			
			case 6:
			sort_by_score();//����sort_by_score���� 
			caidan(1);//����˵�
			break;
			
			case 7:
			max();//����max���� 
			caidan(1);//����˵�
			break;
			
			case 8:
			min();//����min���� 
			caidan(1);//����˵�
			break;
			
			case 9:
			ave();//����ave���� 
			caidan(1);//����˵�
			break;
			
			case 10:
			printf("������ѧ��ѧ�ţ�");
			scanf("%lld",&id);
			prime(id);//����prime���� 
			caidan(1);//����˵�
			break; 
			
			case 11:
			printf("������ѧ��ѧ��1��ѧ��ѧ��2��");
			scanf("%lld %lld",&id,&id2);
			coprime(id,id2);//����coprime���� 
			caidan(1);//����˵�
			break;
			
			case 12:
			analysis();//����analysis���� 
			caidan(1);//����˵�
			break;
			
			default:
			printf("�Ƿ����룡���������룡\n");
			break;
		}
	}
}
void chuli()//chuli����������ÿ�ζ�ѧ����Ϣ������ɾ������ȫ������Ϣ��gpa��Ϣ���༶����
{
	p=&sztu[0];//����p��λ�� 
	int i,j,pm,tem;
	int a[100];//��ʱ����ɼ���Ϣ���������� 
	for(i=0;i<100;i++,p++)
	{
		if(p->c>=93&&p->xuehao!=0)
		{
			strcpy(p->gpa,"A+");//Ϊѧ����Ϣ��gpa��ֵ ����ͬ 
			p->chongxiu=p->xuehao;//Ϊѧ����Ϣ��������Ϣ��ֵ����ͬ 
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
			p->chongxiu=1;//�����Ҫ������ֵΪ1 
		}
	}
	p=&sztu[0];//����p��λ�� 
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==0)//ѧ��Ϊ0������ 
		{
			a[i]=0;//������ֵΪ0
			continue;
		}
		a[i]=p->c;//���ɼ���Ϣ����a[i]�У��������� 
	}
	for(i=0;i<100;i++)
	{
		for(j=i;j<100;j++)//����Ƚϣ����ս���Ӵ�С���� 
		{
			if(a[i]<a[j])
			{
				tem=a[i];
				a[i]=a[j];
				a[j]=tem;//�����м��������a[i]��a[j]��ֵ 
			}
		}
	}	
	p=&sztu[0];//����p��λ�� 
	pm=1;//������
	for(i=0;i<100;i++)
	{
		if(a[i]==a[i-1]&&i>0)//���ǵ�������������������ͬ�ɼ����ж� 
		{
			continue;
		}
		for(j=0;j<100;j++,p++)
		{
			if(p->c==a[i]&&p->xuehao!=0)
			{
				p->paiming=pm;//Ϊѧ���İ༶������Ϣ��ֵ 
			}	
		}
		p=&sztu[0];//����p��λ�� 
		pm++;//����+1 
	}
}
void add(char name[100],long long id,int score) //����1��������ӵ���ѧ����Ϣ 
{
	p=&sztu[0];//����p��λ�� 
	int i,j;
	for(i=0;i<100;i++,p++)//Ѱ�ҿ�λ���и�ֵ 
	{
		if (p->xuehao==0)//�ҵ���λ����и�ֵ���� 
		{
			strcpy(p->xingming,name);
			p->xuehao=id;
			p->c=score; //Ϊ������ѧ�š�c���Գɼ���ֵ 
			break;
		}
	}
}
void adds(int n,char names[100][100],long long ids[100],int scores[100])//����2��������Ӷ��ѧ����Ϣ 
{
	p=&sztu[0];//����p��λ�� 
	int i,j,count;
	count=0;//����ֵΪ0�����ڼ����Ѿ�����˼���ѧ������Ϣ 
	for(i=0;i<100;i++,p++)//Ѱ�ҿ�λ���и�ֵ 
	{
		if (p->xuehao==0)//�ҵ���λ����и�ֵ���� 
		{
			strcpy(p->xingming,names[count]);
			p->xuehao=ids[count];
			p->c=scores[count]; //Ϊ������ѧ�š�c���Գɼ���ֵ 
			count++;//�����Ѿ�����˼���ѧ������Ϣ 
		}
		if (count==n) //�������˳� 
		{
			break; 
		}
	}
}
void deletea(long long id)//����3������ɾ������ѧ����Ϣ 
{
	p=&sztu[0];//����p��λ�� 
	int i,j;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//����ѧ��������Ϣ 
		{
			p->xuehao=0;//ƥ�䵽��ѧ�ŵ�ֵ��Ϊ0����Ϊɾ��
			break; 
		}
	}
}
void search(long long id)//����4������Ѱ��ѧ����Ϣ����ӡ���� 
{
	p=&sztu[0];//����p��λ�� 
	int i,j;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//����ѧ��������Ϣ 
		{
			printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//������ϵ�ѧ����Ϣ 
			break;
		}
	}
} 
void sort_by_id()//����5��������ѧ����Ϣ��ѧ�ŴӴ�С��� 
{
	p=&sztu[0];//����p��λ�� 
	int i,j;
	long long a[100];//���峤����a[]���ڴ���ѧ����Ϣ������ 
	long long tem;//������ʱ������ 
	for(i=0;i<100;i++,p++)
	{
		a[i]=p->xuehao;//��ѧ��ѧ����Ϣ���浽����a[]�� 
	}

	for(i=0;i<100;i++)
	{
		for(j=i;j<100;j++)//����Ƚϣ����ս���Ӵ�С���� 
		{
			if(a[i]<a[j])
			{
				tem=a[i];
				a[i]=a[j];
				a[j]=tem;//�����м��������a[i]��a[j]��ֵ 	
			}
		}
	}
	p=&sztu[0];//����p��λ�� 
	for(i=0;i<100;i++)
	{
		if(a[i]==0)//ѧ�ŴӴ�С��˳�����a[i]==0����˵������û��ѧ����Ϣ�� 
		{
			break;
		}
		for(j=0;j<100;j++,p++)
		{
			if(p->xuehao==a[i]&&p->xuehao!=0)//��ѧ�Ų�����0��������������ƥ�䣬������������ 
			{
				printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//������ϵ�ѧ����Ϣ 
				p=&sztu[0];//����p��λ�� 
				break;
			}
		}
	}
}
void sort_by_score() //����6��������ѧ����Ϣ��������С������� 
{
	p=&sztu[0];//����p��λ�� 
	int i,j;
	for(i=1;i<=100;i++)
	{
		for(j=0;j<100;j++,p++)
		{
			if(p->paiming==i&&p->xuehao!=0)//��ѧ�Ų�����0(Ϊ0����Ϊ�ջ�ɾ������������������ƥ�䣬������������
			{
				printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//������ϵ�ѧ����Ϣ 
			}
		}
		p=&sztu[0];//����p��λ�� 
	}
}
void max() //����7�����������߷ֵ�ѧ����Ϣ 
{
	p=&sztu[0];//����p��λ��  
	int i,j,max;
	max=0;
	for(i=0;i<100;i++,p++)
	{
		if(max<p->c&&p->xuehao!=0)
		{
			max=p->c;//�õ���߷� 
		}
	}
	p=&sztu[0];//����p��λ�� 
	for(i=0;i<100;i++,p++)
	{
		if(p->c==max&&p->xuehao!=0)
		{
			printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//������ϵ�ѧ����Ϣ 
		}
	}
}
void min()//����8�����������ͷ�ѧ����Ϣ 
{
	p=&sztu[0];//����p��λ�� 
	int i,j,min;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao!=0)//����λ�ò�Ϊ�ջ���ɾ�� 
		{
			min=p->c;//Ϊmin��һ����Ч�ķ���ֵ 
		}
	}
	p=&sztu[0];//����p��λ�� 
	for(i=0;i<100;i++,p++)
	{
		if(min>p->c&&p->xuehao!=0)
		{
			min=p->c;//�õ���ͷ� 
		}
	}
	p=&sztu[0];//����p��λ�� 
	for(i=0;i<100;i++,p++)
	{
		if(p->c==min&&p->xuehao!=0)
		{
			printf("%-14s %-14lld %-5d %-14lld %-5s %-5d\n",p->xingming,p->xuehao,p->c,p->chongxiu,p->gpa,p->paiming);//������ϵ�ѧ����Ϣ 
		}
	}
}
void ave()//����9���������ѧ����ĩƽ������
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
	printf("ѧ����ĩ�ɼ�ƽ����Ϊ��%.6f\n",sum*1.0/renshu);
}
void prime(long long id)//����10���� ,�ж�ѧ���ĳɼ��Ƿ�Ϊ���� 
{
	p=&sztu[0];//����p��λ�� 
	int i,j,flag;
	flag=0;//�жϳɼ��Ƿ�Ϊ���� 
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//�ҵ������ѧ�Ŷ�Ӧ��λ�� 
		{
			break;
		}
	}
	if(p->c==0||p->c==1)
	{
		printf("�����ĳɼ���������"); //0��1��Ϊ���� 
	}
	else if(p->c==2||p->c==3)
	{
		printf("�����ĳɼ�������"); //2��3Ϊ���� 
	}
	else
	{
		for(j=2;j<p->c;j++)
		{
			if(p->c%j==0)//����ɼ��ܱ�����С��������������Ϊ���� 
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("�����ĳɼ�������\n");
		}
		else
		{
			printf("�����ĳɼ���������\n");
		}
	}
}
void coprime(long long id,long long id2)//����11�������ж�����ѧ���ĳɼ��Ƿ��� 
{
	p=&sztu[0];//����p��λ�� 
	int i,j,gb,m,n,tem;
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id)//�ҵ������ѧ�Ŷ�Ӧ��λ�� 
		{
			break;
		}
	}
	m=p->c;//��һ��ѧ����Ӧ�ĳɼ� 
	p=&sztu[0];//����p��λ�� 
	for(i=0;i<100;i++,p++)
	{
		if(p->xuehao==id2)//�ҵ������ѧ�Ŷ�Ӧ��λ�� 
		{
			break;
		}
	}
	n=p->c; //�ڶ���ѧ����Ӧ�ĳɼ� 
	if(m<n)//ʹm>=n 
	{
		tem=m;
		m=n;
		n=tem;//����tem����m��n��ֵ 
	}
	while (n != 0)
	{
        tem = m % n;
        m = n;
        n = tem;//ŷ����������Լ�� 
    } 
    if(m==1)
    {
    	printf("��ѧ���ĳɼ�����\n"); //������������Լ��Ϊ1������������ 
	}
	else
	{
		printf("��ѧ���ĳɼ�������\n");//��֮���򲻻��� 
	}
}
void analysis()//����12��������������������������gpa�ȼ������� 
{
	p=&sztu[0];//����p��λ�� 
	int i,j,a1,a,b1,b,c1,c,d,f;
	a1=0;
	a=0;
	b1=0;
	b=0;
	c1=0;
	c=0;
	d=0;
	f=0;//����ֵΪ0�����ڼ��� 
	for(i=0;i<100;i++,p++)
	{
		if(strcmp(p->gpa,"A+")==0&&p->xuehao!=0)//���gpa�ȼ�ΪA+����ѧ��λ�ò�Ϊ0������a+������a1+1����ͬ 
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
	printf("A+������Ϊ��%d\n",a1); 
	printf("A������Ϊ�� %d\n",a); 
	printf("B+������Ϊ��%d\n",b1);
	printf("B������Ϊ�� %d\n",b);  
	printf("C+������Ϊ��%d\n",c1); 
	printf("C������Ϊ�� %d\n",c); 
	printf("D������Ϊ�� %d\n",d);
	printf("F������Ϊ�� %d\n",f);  //�ֱ���������ȼ������� 
}

#include<bits/stdc++.h>
using namespace std;

//1.ð������
//����˼�룺��Ҫ�����һ�����У��Ե�ǰ��δ�ź���ķ�Χ�ڵ�ȫ������
//���϶��¶����ڵ����������ν��бȽϣ��ýϴ�������³�����С������ð��
//����ÿ�������ڵ����ȽϺ������ǵ�����������Ҫ���෴ʱ���ͽ����ǻ�����
void Bubble_sort(int a[],int n)//ð������ ��a[]�����������飬n�����������鳤�� 
{
	for(int i=0;i<n-1;i++)
	{
		int flag=1;
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int team=a[j];
				a[j]=a[j+1];
				a[j+1]=team;
				flag=0;
			}
		}
		if(flag==1)
		break;
	}
}


//2.��ѡ������
//����˼�룺��һ�ˣ��ӵ�һ����¼��ʼ��������n-1����¼���бȽϣ��ҵ�������С�ļ�¼�͵�һ����¼���н�����
//�ڶ��ˣ��ӵڶ�����¼��ʼ��������n-2����¼���бȽϣ��ҵ�������С�ļ�¼�͵�2����¼���н�����
//��
//��i�ˣ��ӵ�i����¼��ʼ��������n-i����¼���бȽϣ��ҵ�������С�ļ�¼�͵�i����¼���н�����
//�Դ����ƣ�����n-1�˱Ƚϣ���n-1����¼�ŵ�λ��ʣ��һ������¼ֱ���������
void Select_sort(int a[],int n)//��ѡ������    a[]�����������飬n�����������鳤�� 
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int team=a[i];
				a[i]=a[j];
				a[j]=team;
			}
		}
	}
} 

//3.ֱ�Ӳ�������
//����˼�룺��һ����¼���뵽������õ�������У��Ӷ��õ�һ���µģ���¼����1�������
//���Ƚ����еĵ�һ����¼������һ������������У�Ȼ��ӵڶ�����¼������в��룬ֱ��������������Ϊֹ��
void Straight_Insertion_sort(int a[],int n)//ֱ�Ӳ�������	a[]�����������飬n�����������鳤��  
{
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		continue;
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				int team=a[i];
				for(int k=i-1;k>=j;k--)
				a[k+1]=a[k];
				a[j]=team;
				break;
			}
		}
	}
}


//4.ϣ������
//����˼�룺�Ƚ�����������Ԫ�����зָ�����������У������ĳ������������Ԫ����ɵģ��ֱ����ֱ�Ӳ�������
//Ȼ���������������ٽ������򣬴����������е�Ԫ�ػ������������㹻С��ʱ��
//�ٶ�ȫ��Ԫ�ؽ���һ��ֱ�Ӳ���������Ϊֱ�Ӳ���������Ԫ�ػ������������£�Ч�ʺܸߣ���
void Shell_sort(int a[],int n)//ϣ������	a[]�����������飬n�����������鳤�� 
{
	int i=5;
	while(i>=1)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=j+i;k<n;k+=i)
			{
				for(int m=j;m<k;m+=i)
				{
					if(a[k]<a[m])
					{
						int team=a[k];
						for(int n=k-i;n>=m;n-=i)
						a[n+i]=a[n];
						a[m]=team;
						break;
					}
				}
			}
		}
		i-=2;
	}
} 


//5.������
//����˼�룺�Ƚ���ʼ���齨��һ������ѣ��˶�Ϊ��ʼ����������
//�ٽ�����Ԫ�غ������������һ����¼�������ɴ˵õ��µ�����������������������<=��ֵ��
//���ڽ������µĸ�����Υ�������ʣ��ʽ���ǰ����������Ϊ�ѡ�
//Ȼ���ٴν���������Ԫ�غ͸���������һ����¼�������ɴ˵õ��µ�����������������
//���������ϵ��ֵ<=��ֵ��ͬ��Ҫ�������Ϊ�ѣ�
//��
//ֱ��������ֻ��һ��Ԫ��Ϊֹ��
void swap(int a[],int min,int max)//�����ѺͿ�������ʱʹ�õĺ�������������֮���ֵ���� 	a[]�����������飬min�����±��С�ģ�max���������±�ϴ�� 
{
	int team=a[max];
	a[max]=a[min];
	a[min]=team;
}

void build_sort(int a[],int start,int i)//������ 	a[]�����������飬start�ն˽ڵ㣬i��ʾ���ж��ٸ����ֻ��ڶ��� 
{
	if(start*2+1>i-1)
	return ;
	int num,m=a[start];
	if(start*2+2<i)
	{
		if(a[start*2+1]<a[start*2+2])
		num=start*2+2;
		else
		num=start*2+1;
	}
	else
	num=start*2+1;
	if(a[start]<a[num])
	swap(a,start,num);
	if(m!=a[start]&&(start-1)/2>=0&&a[start]>a[(start-1)/2])
	build_sort(a,(start-1)/2,i);
	else
	{
		if(start*2+1<i)
		build_sort(a,start*2+1,i);
		if(start*2+2<i)
		build_sort(a,start*2+2,i);
	}
}
void Heap_sort(int a[],int n)//������	a[]�����������飬n�����������鳤�� 
{
	for(int i=0;i<n-1;i++)
	{
		build_sort(a,0,n-i);
		int team=a[0];
		a[0]=a[n-i-1];
		a[n-i-1]=team;
	}
} 

//6.�������� 
//
//����˼�룺ѡ��һ����׼Ԫ�أ����Ȼ�׼Ԫ��С��Ԫ�ط�����ǰ�棬�Ȼ�׼Ԫ�ش��Ԫ�ط�������棬
//Ȼ���ڽ�С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼Ԫ�ص������а�ԭ���ķ�������ֱ��������������;
void Quick_sort(int a[],int low,int high)//��������ݹ�		a[]�����������飬low��������С�±꣬high����������±�	
{
	if(low<high)
	{
		int pivotkey=a[(low+high)/2],i=low,j=high;
		while(i<=j)
		{
			while(a[i]<pivotkey)
			i++;
			while(a[j]>pivotkey)
			j--;
			if(i<=j)
			{
				swap(a,i,j);
				i++;
				j--;
			}
			
		}
		Quick_sort(a,low,j);
		Quick_sort(a,i,high);
	}
}


//7.��������
//����˼�룺ͨ�������и���Ԫ�ص�ֵ���������N��Ԫ�ؽ��������˵ġ����䡱�롰�ռ�����ʵ������
//���䣺���ǽ�L[i]�е�Ԫ��ȡ��������ȷ�����λ�ϵ����֣����ݸ����ַ��䵽��֮�����ͬ��Ͱ��
//�ռ��������������е�Ԫ�ض����䵽��Ӧ��Ͱ�У��ٰ���˳�����ν�Ͱ�е�Ԫ���ռ��γ��µ�һ����������L[ ]
//�����γɵ�����L[]�ظ�ִ�з�����ռ�Ԫ���е�ʮλ����λ��ֱ��������������е����λ�������������
//�������£�
typedef struct LNode//��������ʱʹ�õĽṹ�� 
{
	int data;
	struct LNode* next;
	int length;
}LNode;
int Radix_sort1(int a[],int n,int s)
//��������	a[]�����������飬n��ʾ����Ĵ�С,s��ʾҪ����s+1λ 
{
	LNode e[10];
	for(int i=0;i<10;i++)
	{
		e[i].length=0;
		e[i].next=NULL;
	}
	for(int i=0;i<n;i++)
	{
		int k=a[i]/s%10;
		LNode* p=&e[k];
		while(p->next)
		p=p->next;
		LNode* m=new LNode;
		m->next=NULL;
		m->data=a[i];
		p->next=m;
		e[k].length++;
	}
	int i=0;
	for(int j=0;j<10;j++)
	{
		LNode* p=&e[j];
		while(p->next)
		{
			p=p->next;
			a[i]=p->data;
			i++;
		}
	}
	if(e[0].length==n)
	return 1;
	for(int i=0;i<10;i++)
	{
		if(e[i].length==0)
		continue;
		while(e[i].length)
		{
			LNode* p=&e[i];
			LNode* x=p->next;
			while(x->next)
			{
				p=p->next;
				x=x->next;
			}
			p->next=NULL;
			delete x;
			x=NULL;
			e[i].length--;
		}
	}
	return 0; 
}
void Radix_sort(int a[],int n,int num=0)
//��������(main������ʹ�����)	 a[]�����������飬n��ʾ����Ĵ�С��numĬ��Ϊ1��main�в���Ҫ��num�� 
{	
	int s=1;
	for(int i=0;i<num;i++)
	s*=10;
	if(Radix_sort1(a,n,s)==1)
	return ;
	else
	return Radix_sort(a,n,num+1);
}

//8.�鲢���� 
//����˼�룺���Ƚ���ʼ���е�n����¼������n������������У�ÿ�������еĳ���Ϊ1��Ȼ�������鲢���õ�n/2������Ϊ2�����������У��ڴ˻����ϣ��ٶԳ���Ϊ2�����������н��������鲢���õ����ɸ�����Ϊ4�����������У��Դ����ƣ�ֱ���õ�һ������Ϊn����������Ϊֹ��
//�������£�
void Merge_sort1(int a[],int L,int M,int R)//�鲢����
{
	int left_size=M-L;
	int right_size=R-M+1;
	int left[left_size];
	int right[right_size];
	for(int i=L;i<M;i++)
	{
		left[i-L]=a[i];
	}
	for(int i=M;i<=R;i++)
	{
		right[i-M]=a[i];
	}
	int i=0,j=0;
	for(int k=L;k<=R;k++)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		if(i==left_size)
		{
			k++;
			while(k<=R)
			{
				a[k]=right[j];
				j++;
				k++;
			}
		}
		if(j==right_size)
		{
			k++;
			while(k<=R)
			{
				a[k]=left[i];
				i++;
				k++;
			}
		}
	}
} 

void Merge_sort(int a[],int n,int sum=2)
//�鲢����main������ʹ�������
//a[]�����������飬n��ʾ����Ĵ�С��sum��ʾһ�����������ж��ٸ�Ԫ�أ�Ĭ��ֵΪ2�� 
{
	if(sum/2>=n)
	return ;
	for(int i=0;i<n;i+=sum)
	{
		if(i+sum<=n)
		Merge_sort1(a,i,i+sum/2,i+sum-1);
		else if(i+sum/2<n&&i+sum>=n)
		Merge_sort1(a,i,i+sum/2,n-1);
	}
	return Merge_sort(a,n,2*sum);
}


int main()
{
	int n=9;
//	cin>>n;
//	int *m0=new int[n];
	int *m=new int[n];
//	for (int i=0;i<n;i++) cin>>m0[i];
	int m0[n]={43,65,21,9,32,54,98,33,90};
	
	cout<<"ð������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Bubble_sort(m,n);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;

	cout<<"ѡ������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Select_sort(m,n);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;

	cout<<"ֱ�Ӳ�������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Straight_Insertion_sort(m,n);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"ϣ������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Shell_sort(m,n);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Heap_sort(m,n);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"��������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Quick_sort(m,0,n-1);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"��������"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Radix_sort(m,n,0);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;
	
	cout<<"�鲢����"<<endl; 
	for (int i=0;i<n;i++) m[i]=m0[i];
	Merge_sort(m,n,2);
	for (int i=0;i<n;i++) cout<<m[i]<<" ";
	cout<<endl<<endl;
	
	return 0;
}


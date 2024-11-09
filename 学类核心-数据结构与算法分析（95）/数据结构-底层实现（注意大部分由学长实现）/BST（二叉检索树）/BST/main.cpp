#include "BST.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
void creat(BST& tree,int n,vector<int> &A);
void print(int f);
int height(BSTNode *root);
void PrintNodeByLevel(BSTNode *root,int n);   
int main()
{
	int i,n,nC,val,flag,temp;
	BST tree;
	vector<int> A;
	cout<<"�������BST���Ļ�������������ʾ"<<endl;
	cout<<"����Ԫ�ص�����n���Իس�����:"<<endl;
	cin>>n;
	if(n<=0) {
		cout<<"���벻�Ϸ�"<<endl; exit(0); 
	}
	cout<<"����n��Ԫ�أ��м��Կո����"<<endl;
	for(i=0;i<n;i++){
		cin>>val;
		A.push_back(val);
	}
	creat(tree,n,A);//����BST
	nC=tree.nodecount();
	cout<<"��α������BST����"<<endl;
	PrintNodeByLevel(tree.getRoot(),nC);	
	cout<<"������Ҫ�����ֵ"<<endl;
	cin>>val;
	tree.insert(val);
	nC=tree.nodecount();
	cout<<"�������£�"<<endl;
	PrintNodeByLevel(tree.getRoot(),nC);
    cout<<"������Ҫɾ����ֵ"<<endl;
	cin>>val;
	temp=tree.remove(val);
	if(temp==1){
	    nC=tree.nodecount();
	    cout<<"�������£�"<<endl;
	    PrintNodeByLevel(tree.getRoot(),nC);
    }
    else cout<<"����ʧ�ܣ�"<<endl;
	cout<<"������Ҫ���ҵ�ֵ��ctrl+Z��������"<<endl; 
	while(cin>>val){
		flag=tree.find(val);//���Һ��� 
		print(flag);//������� 
		count=0;//ÿ�β�����Ͻ�count��ԭ 
	}
	return 0;
}
void creat(BST& tree,int n,vector<int> &A){
	int i;
	for(i=0;i<n;i++){
		tree.insert(A[i]);
	}
} 
void print(int f){
	if(f)
		cout<<"���ҳɹ�  "<<count<<endl;
	else
		cout<<"���Ҳ��ɹ�  "<<count<<endl; 
}
int height(BSTNode *root){//�����ĸ߶� 
    int lh,rh,h;
    if(root==NULL) return -1;
    lh=height(root->left());
    rh=height(root->right());
    h=lh>rh?lh:rh;
    return (h+1);
}
void PrintNodeByLevel(BSTNode *root,int nC){  
    int parentSize=1, childSize=0;  
    int ncount=0,level=0,i=0,j=0,k=0;
    int *A=new int[1000000];//�½�����
    BSTNode *temp;
	BSTNode *temp1=new BSTNode(-1,NULL,NULL);//��-1�Ľڵ��ʾ�սڵ� 
    queue<BSTNode *> q;
	q.push(root);
    do  //���ö��н��в�α��� 
    {
        temp=q.front(); 
        if(temp->getData()!=-1)
            ncount++;//��¼���������Ч�ڵ���� 
		A[i++]=temp->getData();//���ڵ���Ϣ���������� 
        q.pop();
        if(temp->left()!=NULL){   //���tempָ����ָ�ĸ��ڵ������ 
            q.push(temp->left());  
            childSize ++;  
        }
		else q.push(temp1);	
        if(temp->right()!=NULL){  //���tempָ����ָ�ĸ��ڵ���Һ��� 
            q.push(temp->right());  
            childSize ++;  
        }
		else q.push(temp1);
        parentSize--; 
        if(parentSize==0) 
        {  
            parentSize=childSize;  
            childSize=0;  
        }  
    }while (ncount!=nC);
    level=height(root)+1;
	for(i=0,j=0;i<level;i++)  //��ε�����ڵ� 
	{
		k=0;
		while(k<pow(2,i))
		{
			if(A[j]==-1)
			  cout<<"* ";     //'*'�ű�ʾ�սڵ�
			else if(A[j]==0) ;//A[j]δ�洢�ڵ�ֵʱֵΪ0������� 
			else cout<<A[j]<<" ";
			k++;
			j++;
		}
		cout<<endl;
	} 
	delete [] A;//�ͷ�����ռ� 
} 

	
	

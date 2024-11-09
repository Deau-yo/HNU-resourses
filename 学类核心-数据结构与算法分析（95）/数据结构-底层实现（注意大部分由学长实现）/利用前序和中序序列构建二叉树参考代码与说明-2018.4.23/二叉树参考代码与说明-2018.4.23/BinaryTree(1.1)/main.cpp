#include"BinTree.h"
template<typename E>
void printNode(BinNode<E>*tmp)//��ӡ����ֵ�ĺ���
{
	cout << tmp->getValue() << " ";
}

//update2018.4.23
//���������ݹ齨�� 
template<typename E> 
//pre:������� preStart�������еĵ�һ��Ԫ���±꣬preEnd��Ϊ���һ��Ԫ���±�
//in:ͬ�� 
BinNode<E>* creatBinaryTree(string pre[], int preStart,int preEnd,string in[],int inStart,int inEnd)
{
//�߽���� 
	if(preStart>preEnd || inStart > inEnd)
	{
		return NULL;
	}
	BinNode<E>*node=new BinNode<E>(pre[preStart]);
	for(int i=inStart;i<=inEnd;i++)
	{
		if(in[i]==pre[preStart])//�����������ҵ����ڵ㣬�ٴ��������л����������� 
		{
			node->setLeft(creatBinaryTree<E>(pre,preStart+1,preStart+i-inStart,in,inStart,i-1));
			node->setRight(creatBinaryTree<E>(pre,preStart+i-inStart+1,preEnd,in,i+1,inEnd));
			break; 
		}
	}
	return node;
} 

void creatBinaryTree(BinTree<string>*BT)//�����������ĺ���������������Ĺ������������������������������������м��һЩ������
{
	cout << "���ڽ��빹������������......" << endl;
	int n=0;
	cout<<"������������ж��ٸ��ڵ㣬������սڵ�"<<endl;
	cin>>n;
	string *pre=new string[n];
	string *in=new string[n];
	cout<<"����������������У��ո����"<<endl;
	for(int i=0;i<n;i++)
	cin>>pre[i];
	cout<<"����������������У��ո����"<<endl;
	for(int i=0;i<n;i++)
	cin>>in[i];
	BT->setRoot(creatBinaryTree<string>(pre,0,n-1,in,0,n-1));
}
int main()
{
	//������Ķ�������һ��ģ���࣬����ı�Ϊ������ͣ���������صĵط��ڡ�<>�����޸���ز���,������Ĭ��Ϊ������ձ��Ե�string
	BinTree<string>*BT = new BinTree<string>;
	creatBinaryTree(BT);
	//������Ѿ���������һ�ö�����
	//�����Ƕ������Ļ�������������չʾ
	cout << "there are some functions here" << endl;
	cout << "0:�ж��Ƿ�Ϊ������";
	if (BT->BinTreeEmpty() == true)
		cout << "��" << endl;
	else
		cout << "��" << endl;
	cout << "1:ǰ�����:";
	BT->preOrder(printNode);
	cout << endl;
	cout << "2:�������:";
	BT->inOrder(printNode);
	cout << endl;
	cout << "3:�������:";
	BT->postOrder(printNode);
	cout << endl;
	cout << "4:��α���:";
	BT->LevelOrderTranverse(printNode);
	cout << endl;
	cout << "5:��¼�������:";
	cout << BT->BinTreeDepth() << endl;
	cout << "6:��¼���ĸ߶�:";
	cout << BT->BinTreeHeight() << endl;
	cout << "7:ͳ�ƽ��:";
	cout << BT->BinTreeNodes() << endl;
	cout << "8:ͳ��Ҷ�ӽ��:";
	cout << BT->BinTreeLeafs() << endl;
	cout << "9:�ڶ������в���ĳ��ֵ�Ƿ���ڣ�Ĭ�ϲ��ҡ�C��:";
	if (BT->find("C") == true)
		cout << "����" << endl;
	else
		cout << "������" << endl;
	cout << "10:�Ƿ����:";
	BT->clear();
	cout << "�����" << endl;
	cout << "5:��¼�������:";
	cout << BT->BinTreeDepth() << endl;
	cout << "6:��¼���ĸ߶�:";
	cout << BT->BinTreeHeight() << endl;
	cout << "7:ͳ�ƽ��:";
	cout << BT->BinTreeNodes() << endl;
	cout << "8:ͳ��Ҷ�ӽ��:";
	cout << BT->BinTreeLeafs() << endl;
	system("pause");
}

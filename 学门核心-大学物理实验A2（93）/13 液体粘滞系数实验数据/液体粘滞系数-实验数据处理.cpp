#include<bits/stdc++.h>
using namespace std;
int main()
{
	//Һ��ճ��ϵ��ʵ�����ݴ������ 
	//by wolf 9.30
	//rou���ܶȣ�yita���Ǹ����ţ�Re�ļ��㷽ʽ�μ��鱾�������ַ���ʵ�鵥��Ӧ 
	double rou=7.8*1000;
	double rou0=0.95*1000;
	double d=1.00125/1000;
	double g=9.8;
	double D=2/100;
	double v0=13.71/1000;//���������v0����Ϊ���Լ������������ 
	double yita=(rou-rou0)*g*d*d/(v0*18);
	double yita1=(rou-rou0)*g*d*d/(v0*18.0*(1.0+2.4*((d*10000)/(D*10000))));
	//�����bug��ϣ���д����ܵ�һ�� 
	double Re=v0*d*rou0/yita;
	cout<<"yita="<<yita<<endl;
	cout<<"Re="<<Re<<endl;
	cout<<"yita1="<<yita1<<endl;//yita1����c++��������λ���������޷����㣬��Ҫ���� 
  return 0;
}


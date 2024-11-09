#include <iostream>  
#include <cstring>  
#define N 101
using namespace std;  
int n,m;
int u,v;
int g[N][N];
int vis[N],appear[N];
int ans[N],num[N];
int length;
int x;

void dfs(int last,int i)//last��ʾ�ϴη��ʵĵ� 
{  
    vis[i]=1;//���Ϊ�Ѿ����ʹ�  
    appear[i]=1;//���Ϊ����һ��ͼ�г��ֹ�  
    ans[length++]=i;//��¼��  
    for(int j=1;j<=num[i];j++)  
    {  
        if(g[i][j]==x&&g[i][j]!=last)//�ص���㹹�ɹ��ܶٻ�  
        {   
            ans[++length]=g[i][j];//�洢��  
            for(int i=1;i<=length-1;i++) //�ҵ���һ���������ans
                cout<<ans[i]<<' ';  
            cout<<ans[length]<<endl;
            length--;//����-1
            break;
        }  
        if(!vis[g[i][j]])//������i�����������δ���ʵĵ㡣  
            dfs(i,g[i][j]); 
    }  
    length--;  
    vis[i]=0;//����
}  

int main(){  
    memset(vis,0,sizeof(vis));  
    memset(appear,0,sizeof(appear));  
    cin>>n>>m; //������������
    for(int i=1;i<=m;i++){   
        cin>>u>>v; //��������
        g[u][++num[v]]=v;//��¼u-v�ı�
        g[v][++num[v]]=u;//��¼v-u�ı�
    }  
    for(x=1;x<=n;x++) //ö��ÿһ���㣬������Ϊ��������Է���
    {  
        if(!appear[x])//�����x����֮ǰ���������ʹ���ͼ��  
        {  
            length=0;//��¼�𰸵ĳ���  
            dfs(0,x);  
        }  
    }  
    return 0;  
} 

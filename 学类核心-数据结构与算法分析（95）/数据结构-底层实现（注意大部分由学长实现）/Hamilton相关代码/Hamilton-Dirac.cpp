#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 1001
#define E 1e-6
#define LL long long
using namespace std;
bool G[N][N];
bool vis[N];
int ans[N];
void Reverse(int arv[N],int s,int t){//������anv���±�s��t�Ĳ��ֵ�˳����
    int temp;
    while(s<t){
        swap(arv[s],arv[t]);
        s++;
        t--;
    }
}
void Hamilton(int n){
    int t;
    int s=1;//��ʼ��ȡsΪ1�ŵ�
    for(int i=1;i<=n;i++)
        if(G[s][i]){
            t=i;//ȡ�����ڽ���s�ĵ�Ϊt
            break;
        }
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    vis[t]=true;
    ans[0]=s;
    ans[1]=t;
    int ansi=2;
    while(true){
        //��t������չ
        while(true){
            int i;
            for(i=1;i<=n;i++){
                if(G[t][i] && !vis[i]){
                    ans[ansi++]=i;
                    vis[i]=true;
                    t=i;
                    break;
                }
            }
            if(i>n)
                break;
        }
        //����ǰ�õ������е���
        Reverse(ans,0,ansi-1);
        //s��t����
        swap(s,t);
        while(true){//��t������չ,�൱����ԭ���������ϴ�s������չ
            int i;
            for(i=1;i<=n;i++){
                if(G[t][i] && !vis[i]){
                    ans[ansi++]=i;
                    vis[i]=true;
                    t=i;
                    break;
                }
            }
            if(i>n)
                break;
        }
        //���s��t������,���е���
        if(!G[s][t]){
            //ȡ�����е�һ��i,ʹ��ans[i]��t����,����ans[i+1]��s����
            int i;
            for(i=1;i<ansi-2;i++)
                if(G[ans[i]][t]&&G[s][ans[i+1]])
                    break;
            i++;
            t=ans[i];
            Reverse(ans,i,ansi-1);//����ans[i+1]�������ֵ�ans[]����
        }//��ʱs��t���� 
        //�����ǰ���а���n��Ԫ��,�㷨����
        if(ansi==n)
            return;
        //��ǰ������Ԫ�صĸ���С��n,Ѱ�ҵ�ans[i],ʹ��ans[i]��ans[]���һ��������
        int i,j;
        for(j=1;j<=n;j++){
            if(vis[j])
                continue;
            for(i=1;i<ansi-2;i++)
                if(G[ans[i]][j])
                    break;
            if(G[ans[i]][j])
                break;
        }
        s=ans[i-1];
        t=j;//�����ҵ��ĵ�j����t
        Reverse(ans,0,i-1);//��ans[]��s��ans[i-1]�Ĳ��ֵ���
        Reverse(ans,i,ansi-1);//��ans[]��ans[i]��t�Ĳ��ֵ���
        ans[ansi++]=j;//����j���뵽ans[]β��
        vis[j]=true;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    n*=2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j){
                G[i][j]=false;
                G[j][i]=false;
            }
            else{
                G[i][j]=true;
                G[j][i]=true;
            }
        }
    }
    int ansi=0;
    memset(ans, 0, sizeof(ans));
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[y][x]=false;
        G[x][y]=false;
    }
    Hamilton(n);
    for(int i=0;i<n;i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}

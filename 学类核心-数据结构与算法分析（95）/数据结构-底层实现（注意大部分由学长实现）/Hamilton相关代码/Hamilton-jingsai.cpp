#include<bits/stdc++.h>
using namespace std;

int ans[105];
int mapm[105][105];

void Insert(int arv[], int &len, int index, int key){
    if(index>len)
        index=len;
    len++;
    for(int i=len-1; i>=0; i--){
        if(i!=index && i)
            arv[i]=arv[i-1];
        else{
            arv[i]=key;
            return;
        }
    }
}

void Hamilton(int n){
    int ansi = 1;
    ans[ansi++] = 1;
    for(int i=2; i<=n; i++){//��һ�����,ֱ�Ӱѵ�ǰ����ӵ�����ĩβ
        if(mapm[i][ans[ansi-1]]==1)
            ans[ansi++]=i;
        else{
            int flag=0;
            //��ǰ���дӺ���ǰ�ҵ���һ�����������ĵ�j,ʹ�ô���<Vj,Vi>��<Vi,Vj+1>.
            for(int j=ansi-2; j>0; j--){
                if(mapm[i][ans[j]]==1){//�ҵ���Ѹõ���뵽���еĵ�j+1����ǰ.
                    flag=1;
                    Insert(ans,ansi,j+1,i);
                    break;
                }
            }
            if(!flag)//����˵�����е㶼�ڽ��Ե�i,��Ѹõ�ֱ�Ӳ��뵽�����׶�.
                Insert(ans,ansi,1,i);
        }
    }
}

int main(){
    int n,m;
    scanf("%d", &n);
    m=n*(n-1)/2;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u<v)
            mapm[v][u]=1;
    }
    Hamilton(n);
    for(int i=1;i<=n;i++)
        printf(i==1? "%d":" %d",ans[i]);
    printf("\n");
    return 0;
}

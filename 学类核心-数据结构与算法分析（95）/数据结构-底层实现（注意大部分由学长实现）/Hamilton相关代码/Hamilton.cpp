#include<bits/stdc++.h>
using namespace std;

void Hamilton(int ans[maxN + 7], bool map[maxN + 7][maxN + 7], int n){
    Init();
    bool visit[maxN + 7] = {false};
    for(i = 1; i <= n; i++) if(map[s][i]) break;
    t = i;//ȡ�����ڽ���s�ĵ�Ϊt
    visit[s] = visit[t] = true;
    ans[0] = s;
    ans[1] = t;
    while(true){
        while(true){//��t������չ
            for(i = 1; i <= n; i++){
                if(map[t][i] && !visit[i]){
                    ans[ansi++] = i;
                    visit[i] = true;
                    t = i;
                    break;
                }
            }
            if(i > n) break;
        }
        //����ǰ�õ������е���,s��t����,��t������չ,�൱����ԭ���������ϴ�s������չ
        Hreverse(ansi, ans, i, w)
        temp = s;
        s = t;
        t = temp;
        while(true){//���µ�t����������չ,�൱����ԭ���������ϴ�s������չ
            for(i = 1; i <= n; i++){
                if(map[t][i] && !visit[i]){
                    ans[ansi++] = i;
                    visit[i] = true;
                    t = i;
                    break;
                }
            }
            if(i > n) break;    
        }
        if(!map[s][t]){//���s��t������,���е���
            for(i = 1; i < ansi - 2; i++)//ȡ�����е�һ��i,ʹ��ans[i]��t����,����ans[i+1]��s����
                if(map[ans[i]][t] && map[s][ans[i + 1]])break;
            w = ansi - 1;
            i++;
            t = ans[i];
            reverse(ans, i, w);//����ans[i +��]�������ֵ�ans[]����
        }//��ʱs��t����
        if(ansi == n) return;//�����ǰ���а���n��Ԫ��,�㷨����
        for(j = 1; j <= n; j++){//��ǰ������Ԫ�صĸ���С��n,Ѱ�ҵ�ans[i],ʹ��ans[i]��ans[]���һ��������
            if(visit[j]) continue;
            for(i = 1; i < ansi - 2; i++)if(map[ans[i]][j])break;
                if(map[ans[i]][j]) break;
        }
        s = ans[i - 1];
        t = j;//�����ҵ��ĵ�j����t
        reverse(ans, 0, i - 1);//��ans[]��s��ans[i-1]�Ĳ��ֵ���
        reverse(ans, i, ansi - 1);//��ans[]��ans[i]��t�Ĳ��ֵ���
        ans[ansi++] = j;//����j���뵽ans[]β��
        visit[j] = true;
    }


int main()
{

  return 0;
}


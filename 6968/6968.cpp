/*
AC�Զ���������
ǰ��֪ʶ��kmp���ֵ���
���Ƚ�����ģ�崮�ŵ��ֵ����У���ô�Ϳ��԰�ƥ�䴮�ŵ��ֵ����Ͻ���ƥ�䡣
���ú�kmp���Ƶķ�����ֻҪ���ֵ������ҵ�ÿ�����ʧ��ָ�뼴�ɡ�
���Ƕ���һ������˵��������ĸ��ڵ��ʧ��ָ����ָ�Ľڵ���ӽڵ����к��������ͬ�ĵ㣬��ô�Ϳ���ֱ��ָ��������ˡ�
��ô���û���أ�
��kmp���Ƶ�˼·��next[i]���Ծ�ȥ��next[next[i]]
���Ƕ���ÿ������˵���������ӽڵ��еĿսڵ�ָ������ڵ��ʧ��㡣
��ôֱ��������Ĳ����Ϳ����ҵ��ˡ�

Ȼ���Ǵ����ȥ�ҡ�
���ǽ��ֵ�����Ȩֵ���ϣ����ڵ�ǰƥ�䵽��һ���㣬��������ӽڵ����ƥ��ͼ���������Ȩֵ��
�����ܻ��кܶ�ȨֵΪ0�ĵ㣬��ʱ���˷ѣ�TLE
�����Ż���
����·��ѹ������lastֱ��ָ����һ����Ȩֵ�ĵ�Ϳ����ˡ�
*/
#include<bits/stdc++.h>
using namespace std; 
const int N=1E6+5;
char st[N];
int ans,s[N],tr[N][30],nex[N],tot,last[N];
void add(){//�ֵ���
	int now=0,len=strlen(st+1);
	for(int i=1;i<=len;i++){
		int x=st[i]-'a';
		if(!tr[now][x])tr[now][x]=++tot;
		now=tr[now][x];
	}
	s[now]++;//ÿ���ڵ��Ȩֵ
}
void get(){//��next����
	queue<int> q;//����bfsȥ��next����
	q.push(0);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int t=nex[x];
		for(int i=0;i<26;i++){
			int y=tr[x][i];//��ǰ����ӽڵ�
			if(!y){tr[x][i]=tr[t][i];continue;}//�������ڵ��ǿսڵ㣬��ָ������ʧ��ڵ�
			q.push(y);
			nex[y]=x?tr[t][i]:0;//�Ҹ��׽ڵ��ʧ��ڵ���ӽڵ�
			last[y]=s[nex[y]]?nex[y]:last[nex[y]];//ָ����һ��ֵ��Ϊ0�ĵط�
		}
	}
}
void ask(){//��ѯ��
	int now=0,len=strlen(st+1);
	for(int i=1;i<=len;i++){
		int x=st[i]-'a';
		now=tr[now][x];//������ǰƥ��
		if(s[now]){//�����ǰ��ƥ��ͼ��ϴ�
			ans+=s[now];
			s[now]=0;
		}
		int y=now;
		while(last[y]){//���ӽڵ��ʧ���
			y=last[y];
			if(s[y]){
				ans+=s[y];
				s[y]=0;
			}
		}
	}
}
void clear(){//���
	tot=0;
	ans=0;
	memset(tr,0,sizeof(tr));
	memset(s,0,sizeof(s));
	memset(last,0,sizeof(last));
	memset(nex,0,sizeof(nex));
}
int _,n;
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",st+1);
			add();
		}
		get();
		scanf("%s",st+1);
		ask();
		printf("%d\n",ans);
	}
}

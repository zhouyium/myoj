/*
AC自动机板子题
前置知识：kmp，字典树
首先将所有模板串放到字典树中，那么就可以把匹配串放到字典树上进行匹配。
利用和kmp类似的方法，只要在字典树上找到每个点的失配指针即可。
考虑对于一个点来说，如果它的父节点的失配指针所指的节点的子节点中有和这个点相同的点，那么就可以直接指向这个点了。
那么如果没有呢？
用kmp类似的思路，next[i]不对就去找next[next[i]]
考虑对于每个点来说，将它的子节点中的空节点指向这个节点的失配点。
那么直接用上面的操作就可以找到了。

然后考虑答案如何去找。
我们将字典树的权值加上，对于当前匹配到的一个点，如果它的子节点可以匹配就加上这个点的权值。
但可能会有很多权值为0的点，会时间浪费，TLE
考虑优化。
采用路径压缩，用last直接指向上一个有权值的点就可以了。
*/
#include<bits/stdc++.h>
using namespace std; 
const int N=1E6+5;
char st[N];
int ans,s[N],tr[N][30],nex[N],tot,last[N];
void add(){//字典树
	int now=0,len=strlen(st+1);
	for(int i=1;i<=len;i++){
		int x=st[i]-'a';
		if(!tr[now][x])tr[now][x]=++tot;
		now=tr[now][x];
	}
	s[now]++;//每个节点的权值
}
void get(){//找next数组
	queue<int> q;//采用bfs去找next数组
	q.push(0);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int t=nex[x];
		for(int i=0;i<26;i++){
			int y=tr[x][i];//当前点的子节点
			if(!y){tr[x][i]=tr[t][i];continue;}//如果这个节点是空节点，就指向它的失配节点
			q.push(y);
			nex[y]=x?tr[t][i]:0;//找父亲节点的失配节点的子节点
			last[y]=s[nex[y]]?nex[y]:last[nex[y]];//指向上一个值不为0的地方
		}
	}
}
void ask(){//查询答案
	int now=0,len=strlen(st+1);
	for(int i=1;i<=len;i++){
		int x=st[i]-'a';
		now=tr[now][x];//继续向前匹配
		if(s[now]){//如果当前点匹配就加上答案
			ans+=s[now];
			s[now]=0;
		}
		int y=now;
		while(last[y]){//找子节点的失配点
			y=last[y];
			if(s[y]){
				ans+=s[y];
				s[y]=0;
			}
		}
	}
}
void clear(){//清空
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

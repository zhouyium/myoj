#include <iostream>
#include <cstdio>
#include <cstring>
#include <string> 
//#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const int MAXN=10;
string a[MAXN];
bool vis[MAXN];
int n,K;
int ans;

//����1: pos �к�
//����2: num ��ǰ���������� 
void dfs(int pos, int num) {
	//����
	if (num>=K) {
		ans++;
		return;
	}
	if (pos>n) {
		return;
	}
	for (int i=0; i<n; i++) {
		if (vis[i]==false && a[pos][i]=='#') {
			vis[i]=true;
			dfs(pos+1, num+1);
			vis[i]=false;
		}
	}
	dfs(pos+1, num);//���п���û��# 
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin>>n>>K) {
		if (-1==n&&-1==K) {
			break;
		}
		
		ans=0;
		memset(vis, 0, sizeof(vis));
		for (int i=1; i<=n; i++) {
			cin>>a[i];
		}
		dfs(1, 0);
		cout<<ans<<"\n";
	}

	return 0;
}


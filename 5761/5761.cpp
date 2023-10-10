//http://47.110.135.197/problem.php?id=5761
//https://www.luogu.com.cn/problem/P1886
//https://www.acwing.com/problem/content/156/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+10;
int a[MAXN];
int que[MAXN];
int head=1;
int tail=0;

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	//������Сֵ 
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		//���ֵ�����
		while (head<=tail && a[que[tail]]>=a[i]) {
			tail--;
		}
		que[++tail]=i;
		//���ִ�С
		while (head<=tail && i-m+1>que[head]) {
			head++;
		}
		//ȷ�����ڴ�СΪm 
		if (i>=m) {
			cout<<a[que[head]]<<" ";
		}
	}
	cout<<"\n";
	//���ֵ 
	head=1;
	tail=0;
	for (int i=1; i<=n; i++) {
		//���ֵ�����
		while (head<=tail && a[que[tail]]<=a[i]) {
			tail--;
		}
		que[++tail]=i;
		//���ִ�С
		while (head<=tail && i-m+1>que[head]) {
			head++;
		}
		//ȷ�����ڴ�СΪm 
		if (i>=m) {
			cout<<a[que[head]]<<" ";
		}
	}
	cout<<"\n";

	return 0;
}


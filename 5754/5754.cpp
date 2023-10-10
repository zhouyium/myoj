//http://47.110.135.197/problem.php?id=5754
//https://www.luogu.com.cn/problem/P1440
//��m�����ڵ���Сֵ
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e6+10;
int a[MAXN];
deque<int> que;//�����±� 

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
	cout<<"0\n";
	for (int i=1; i<n; i++) {
		cin>>a[i];
		//ά�������� 
		while (que.size()>0&&a[que.back()]>a[i]) {
			que.pop_back();
		}
		que.push_back(i);
		//ά����С 
		while (i-m>=que.front()) {
			que.pop_front();
		}
		cout<<a[que.front()]<<"\n";
	}

	return 0;
}


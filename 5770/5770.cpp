//https://www.acwing.com/problem/content/869/
//http://47.110.135.197/problem.php?id=5770
//分解质因数

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("07.out", "w", stdout);
	int n;
	cin>>n;
	while (n--) {
		int x;
		cin>>x;
		
		for (int i=2; i*i<=x; i++) {
			if (x%i==0) {
				int cnt=0;
				while (x%i==0) {
					cnt++;
					x/=i;
				}
				cout<<i<<" "<<cnt<<"\n";
			}
		}
		if (x>1) {
			cout<<x<<" 1\n";
		}
		cout<<"\n";
	}

	return 0;
}


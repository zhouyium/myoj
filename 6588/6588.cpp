//6588: ˮ������
//http://47.110.135.197/problem.php?id=6588
//���辭����a�ι���x��y�ι���y�����õ� z
//ax+by=gcd(a,b) 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E6+10;
int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL x,y,z;
	cin>>x>>y>>z;
	
	if (x+y<z) {
		cout<<"no\n";
		return 0;
	}
	LL d=__gcd(x,y);
	if (z%d) {
		cout<<"no\n";
	} else {
		cout<<"yes\n";
	}

	return 0;
}


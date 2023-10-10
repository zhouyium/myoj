//http://47.110.135.197/problem.php?id=5690
//5690: µ¥´ÊÌæ»»

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int cnt[110];
int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("8.in", "r", stdin);
	//freopen("8.out", "w", stdout);
	string s;
	cin>>s;
	
	int wz=-1;
	while ((wz=s.find("black", wz+1))>=0) {
		s.replace(wz, 5, "block");
	}
	
	cout<<s<<"\n";

	return 0;
}


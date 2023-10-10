//6678: 被 3 整除的子序列
//http://47.110.135.197/problem.php?id=6678

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MO=1e9+7;
const int N=1e3+10;
//f[i][j]指的是，以s[i]结尾的对3取余后值为j的集合
LL f[N][3];

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	string s;
	cin>>s;
	LL n=s.size();
	//初始化 
	for (LL i=0; i<n; i++) {
		f[i][(s[i]-'0')%3] = 1;
	}
	for (LL i=0; i<n; i++)  {
		for (LL j=0; j<3; j++) {
			for (LL k=i+1; k<n; k++) {
				f[k][(j+s[k]-'0')%3] = (f[k][(j+s[k]-'0')%3]+f[i][j])%MO;
			}
		}
	}
	
	LL ans=0;
	for (LL i=0; i<n; i++) {
		ans=(ans+f[i][0])%MO;
	}
	cout<<ans<<"\n";

	return 0;
}


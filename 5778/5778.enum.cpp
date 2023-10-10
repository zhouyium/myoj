//http://acm.hdu.edu.cn/showproblem.php?pid=6744
//http://47.110.135.197/problem.php?id=5778
//GPA

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double check(int x) {
	double t=0;
	if (95<=x&&x<=100) {
		t+=4.3;
	} else if (90<=x&&x<=94) {
		t+=4.0;
	} else if (85<=x&&x<=89) {
		t+=3.7;
	} else if (80<=x&&x<=84) {
		t+=3.3;
	} else if (75<=x&&x<=79) {
		t+=3.0;
	} else if (70<=x&&x<=74) {
		t+=2.7;
	} else if (67<=x&&x<=69) {
		t+=2.3;
	} else if (65<=x&&x<=66) {
		t+=2.0;
	} else if (62<=x&&x<=64) {
		t+=1.7;
	} else if (60<=x&&x<=61) {
		t+=1.0;
	}
	return t;
}

int main() {
#if 0
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T;
	cin>>T;
	while (T--) {
		int n;
		cin>>n;
		
		double ans=0;
		for (int i=0; i<=100; i++) {
			for (int j=0; j<=100; j++) {
				for (int k=0; k<=100; k++) {
					int t=n-i-j-k;
					if (t<0) {
						break;
					}
					ans=max(ans, check(i)+check(j)+check(k)+check(t));
				}
			}
		}
		cout<<fixed<<setprecision(1)<<ans<<"\n";
	}

	return 0;
}

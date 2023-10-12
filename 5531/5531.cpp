#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

//最长递减子序列的长度
const int N=1E3+10;
LL a[N];
LL f[N][2];
//f[i][0] 最长下降子序列
//f[i][1] 最长上升子序列

void solve() {
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	
	memset(f, 0, sizeof f);
	LL res1=-9e18;//
	LL res2=-9e18;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<i;j++){
			if(a[i]<=a[j]){
				f[i][0]=max(f[i][0], f[j][0]+1);
				res1=max(res1, f[i][0]);
			}else{
				f[i][1]=max(f[i][1], f[j][1]+1);
				res2=max(res2, f[i][1]);
			}
		}
	}
	
	cout<<res1+1<<"\n"<<res2+1<<"\n";
}

int main() {
#if 0
	//这里是提交代码
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("01.in", "r", stdin);
	//freopen("01.out", "w", stdout);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	for(int i=0;i<10;i++){
		char in[16];
		sprintf(in, "%02d.in", i);
		char out[16];
		sprintf(out, "%02d.out", i);
		
		freopen(in, "r", stdin);
		freopen(out, "w", stdout);
		
		LL T=1;
		//cin>>T;
		while(T--) {
			//cout<<i<<"\n";
			solve();
		}
		
		fclose(stdin);
		fclose(stdout);
	}
#endif
	
	return 0;
}

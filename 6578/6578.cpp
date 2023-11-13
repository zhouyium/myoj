//6578: ALDS1_2_A : 冒泡排序
//http://47.110.135.197/problem.php?id=6578

#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-10;
const LL MO=1e9+7;

const int N=5e5+10;
LL a[N];
LL n;
LL cnt;

void bubble_sort() {
	for (LL i=1; i<n; i++) {//i表示执行了几轮 
		for (LL j=1; j<n; j++) {//j表示次数 
			if (a[j]>a[j+1]) {
				//逆序就交换
				swap(a[j],a[j+1]);
				cnt++;
			}
		}
	}
}

void solve() {
	cnt=0;
	cin>>n;
	for(LL i=1; i<=n; i++){
		cin>>a[i];
	}	
	
	bubble_sort();
	
	for(LL i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n"<<cnt<<"\n";	
}

int main() {
#if 1
	//提交到OJ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL T=1;
	//cin>>T;
	while(T--) {
		//cout<<i<<"\n";
		solve();
	}
#else
	int n=10;
	for(int i=0;i<n;i++){
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

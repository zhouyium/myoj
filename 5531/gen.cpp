//5531: DP15 拦截导弹
//http://47.110.135.197/problem.php?id=5531
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;

int random(int l, int r) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

int main(int argc, char *argv[]) {
	int seed = time(NULL);
	if (argc>1) {
		//有参数
		seed = atoi(argv[1]);
	}
	srand(seed);
	
	freopen("09.in", "w", stdout);
	
	LL T=1;
	//cout<<T<<"\n";
	while (T--) {
		//生成n,x,y
		LL n = random(1e3,1e3);
		cout<<n<<"\n";
		
		for (LL i=1; i<=n; i++) {
			for(LL j=1;j<=n;j++){
				LL a = random(1,1e3);
				cout<<a<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}

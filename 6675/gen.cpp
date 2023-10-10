//6675: DP8 乘积为正数的最长连续子数组
//http://47.110.135.197/problem.php?id=6675
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
    
    freopen("10.in", "w", stdout);
    
    LL T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL n = random(1e5,1e5);
	    cout<<n<<"\n";
	    
	    for (LL i=1; i<=n; i++) {
	    	LL a = random(0,1e4)+5e8;
			cout<<a<<" ";
		}
		cout<<"\n";
	}

    return 0;
}

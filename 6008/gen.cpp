//6008: Row GCD
//http://47.110.135.197/problem.php?id=6008
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;
LL a[N];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("03.in", "w", stdout);
    
    //生成n,x,y
    LL maxx = 2e5;//1000位
    LL minx = 2e5;
    LL n = rand()%(maxx-minx+1)+minx;
	maxx=2e5;
	minx=2e5;
    LL m = rand()%(maxx-minx+1)+minx;
    cout<<n<<" "<<m<<"\n";
    
	maxx=1e11;
	minx=1e10;
    for (LL i=1; i<=n; i++) {
    	LL x = rand()%(maxx-minx+1)+minx;
		cout<<x<<" ";
	}
	cout<<"\n";

	maxx=1e11;
	minx=1e10;
	for (LL i=1; i<=m; i++) {
		LL x = rand()%(maxx-minx+1)+minx;
		cout<<x<<" ";
	}
	cout<<"\n";

    return 0;
}

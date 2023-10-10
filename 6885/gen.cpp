//6885: 吃粽子
//http://47.110.135.197/problem.php?id=6885
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
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 2e5;//1000位
	    LL minx = 2e5;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    
	    for (LL i=1; i<=n; i++) {
			maxx=2e5;
			minx=1e5+9e4;
	    	LL x = rand()%(maxx-minx+1)+minx;
	    	cout<<x<<" ";
		}
		cout<<"\n";
	}

    return 0;
}

//6571: 天平与砝码（二）
//http://47.110.135.197/problem.php?id=6571
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
    
    freopen("12.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 100;
	    LL minx = 100;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    
	    LL sum=0;
	    for (LL i=1; i<n; i++) {
			maxx=1e3;
			minx=6e2;
	    	LL x = rand()%(maxx-minx+1)+minx;
	    	sum+=x;
			cout<<x<<" ";
		}
		cout<<1e5-sum<<"\n";
	}

    return 0;
}

//6636: 前缀最值差
//http://47.110.135.197/problem.php?id=6636

#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e2+10;
bool a[N];

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
	    LL maxx = 1e6;
	    LL minx = 1e6;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    
		maxx=1e9;
		minx=5e8;
		for (LL i=1; i<=n; i++) {
    		LL x = rand()%(maxx-minx+1)+minx;
			cout<<x<<" ";
		}
		cout<<"\n";

		maxx=n;
		minx=n;
	    LL q = rand()%(maxx-minx+1)+minx;
	    cout<<q<<"\n";
		maxx=n;
		minx=1;
	    for (LL i=1; i<=n; i++) {
    		LL x = rand()%(maxx-minx+1)+minx;
			cout<<x<<" ";
		}
		cout<<"\n";
	}

    return 0;
}

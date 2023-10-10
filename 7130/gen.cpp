//7310: Pizza Delivery
//http://47.110.135.197/problem.php?id=7310

#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;
bool a[N];

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("08.in", "w", stdout);
    
    LL T;
    T=500;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 500;
	    LL minx = 500;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";

		//hi	    
	    maxx=500;
	    minx=300;
	    for (LL i=1; i<=n; i++) {
	    	LL x = rand()%(maxx-minx+1)+minx;
	    	cout<<x<<' ';
		}
	    cout<<"\n";

		//ki
	    maxx=500;
	    minx=1;
	    for (LL i=1; i<=n; i++) {
	    	LL x = rand()%(maxx-minx+1)+minx;
	    	cout<<x<<' ';
		}
	    cout<<"\n";
	}

    return 0;
}

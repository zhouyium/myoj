//6011: Nezzar and Board
//http://47.110.135.197/problem.php?id=6011
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
    
    freopen("00.in", "w", stdout);
    
    LL T;
    T=10;
    cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 15;//1000位
	    LL minx = 10;
	    LL n = rand()%(maxx-minx+1)+minx;
		maxx=2e4;
		minx=1e4;
	    LL m = rand()%(maxx-minx+1)+minx;
	    cout<<n<<" "<<m<<"\n";
	    
		maxx=1e18;
		minx=1e3;
	    for (LL i=1; i<=n; i++) {
	    	LL x = rand()%(maxx-minx+1)+minx;
			cout<<x<<" ";
		}
		cout<<"\n";    	
	}

    return 0;
}

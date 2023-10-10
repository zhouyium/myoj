//6630: 加边的无向图
//http://47.110.135.197/problem.php?id=6630
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+10;
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
	    LL maxx = 2;
	    LL minx = 0;
	    
	    for (LL i=1; i<=6; i++) {
	    	LL a1 = rand()%(maxx-minx+1)+minx;
	    	LL b1 = rand()%(maxx-minx+1)+minx;
	    	LL c1 = rand()%(maxx-minx+1)+minx;
	    	LL a2 = rand()%(maxx-minx+1)+minx;
	    	LL b2 = rand()%(maxx-minx+1)+minx;
	    	LL c2 = rand()%(maxx-minx+1)+minx;
			cout<<a1<<b1<<c1<<" "<<a2<<b2<<c2<<"\n";
		}
	}

    return 0;
}

//6678: 被 3 整除的子序列
//http://47.110.135.197/problem.php?id=6678

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
    
    //freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 40;
	    LL minx = 30;
	    LL n = rand()%(maxx-minx+1)+minx;
	    
	    maxx=9;
	    minx=0;
	    for (LL i=1; i<=n; i++) {
	    	LL x = rand()%(maxx-minx+1)+minx;
	    	cout<<x;
		}
	    cout<<"\n";
	}

    return 0;
}

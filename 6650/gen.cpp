//6682: 倒垃圾
//http://47.110.135.197/problem.php?id=6682

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
	    LL maxx = 1e5;
	    LL minx = 1e5;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    
		LL prev=-10000;
		for (LL i=1; i<=n; i++) {
			maxx=1e4;
			minx=0;
    		LL x = rand()%(maxx-minx+1)+minx;
    		cout<<prev<<" ";
    		prev+=x;
		}
		cout<<"\n";
	}

    return 0;
}

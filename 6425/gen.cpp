//6425: 盾神与砝码称重
//http://47.110.135.197/problem.php?id=6425

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
    
    //freopen("01.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 24;
	    LL minx = 24;
	    LL n = rand()%(maxx-minx+1)+minx;
	    maxx = 10;
	    minx = 10;
	    LL m = rand()%(maxx-minx+1)+minx;
	    cout<<n<<" "<<m<<"\n";
	    
		maxx=4096;
		minx=1;
		for (LL i=1; i<=n; i++) {
    		LL x = rand()%(maxx-minx+1)+minx;
			cout<<x<<" ";
		}
		cout<<"\n";

		maxx=5012;
		minx=1;
	    for (LL i=1; i<=n; i++) {
    		LL x = rand()%(maxx-minx+1)+minx;
			cout<<x<<" ";
		}
		cout<<"\n";
	}

    return 0;
}

//5332: 矩阵减法
//http://47.110.135.197/problem.php?id=5332
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
    
    freopen("07.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 100;//1000位
	    LL minx = 100;
	    LL n = rand()%(maxx-minx+1)+minx;
		maxx=100;
		minx=100;
	    LL m = rand()%(maxx-minx+1)+minx;
	    cout<<n<<" "<<m<<"\n";
	    
		maxx=1000;
		minx=1;
	    for (LL i=1; i<=n; i++) {
	    	for (LL j=1; j<=m; j++) {
		    	LL x = rand()%(maxx-minx+1)+minx;
				cout<<x<<" ";
			}
			cout<<"\n";    	
		}
		maxx=1000;
		minx=1;
	    for (LL i=1; i<=n; i++) {
	    	for (LL j=1; j<=m; j++) {
		    	LL x = rand()%(maxx-minx+1)+minx;
				cout<<x<<" ";
			}
			cout<<"\n";    	
		}
	}

    return 0;
}

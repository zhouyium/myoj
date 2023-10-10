//4685: Priority_Queue基本使用：利用Priority_Queue排序 II
//http://47.110.135.197/problem.php?id=4685
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
    
    freopen("06.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 1e5;
	    LL minx = 1e5;
	    LL n = rand()%(maxx-minx+1)+minx;
	    cout<<n<<"\n";
	    
		maxx=1e6;
		minx=1e3;
	    for (LL i=1; i<=n; i++) {
	    	LL a = rand()%(maxx-minx+1)+minx;
			cout<<a<<" ";
		}
		cout<<"\n"; 
	}

    return 0;
}

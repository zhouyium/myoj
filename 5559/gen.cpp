//http://47.110.135.197/problem.php?id=5559
//5559: 采药 II
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("02.in", "w", stdout);
    
    //生成n,m
    LL maxx = 1e3;//1000位
    LL minx = 1e3;
    LL n = rand()%(maxx-minx+1)+minx;
	maxx=6e3;
	minx=5e3;
	LL m = rand()%(maxx-minx+1)+minx;
	cout<<m<<" "<<n<<"\n";
    for (int i=1; i<=n; i++) {
    	LL w,v;
    	
		maxx=3e2;
		minx=1e1;
    	w=rand()%(maxx-minx+1)+minx;
    	v=rand()%(maxx-minx+1)+minx;
    	cout<<w<<" "<<v<<"\n";
	}

    return 0;
}

//8350: 欧拉函数
//http://47.110.135.197/problem.php?id=8350
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("07.in", "w", stdout);
    
    LL maxx = 5e2;
    LL minx = 5e2;
    LL T = 1;
	//cout<<n<<"\n";
	
	for (LL i=1; i<=T; i++)	{
		//数字 N
		minx=100;
		maxx=100;
		LL n = rand()%(maxx-minx+1)+minx;
		cout<<n<<"\n";
		
		//n个数据
		for (LL j=1; j<=n; j++) {
			minx=1.99e9;
			maxx=2e9;
			LL w = rand()%(maxx-minx+1)+minx;
			cout<<w<<"\n";
		}
	}
	
    return 0;
}

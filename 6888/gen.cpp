//6888: ����˯���
//http://47.110.135.197/problem.php?id=6888
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+10;
LL a[N];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //�в���
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //����n,x,y
	    LL maxx = 2e5;//1000λ
	    LL minx = 2e5;
	    LL n = rand()%(maxx-minx+1)+minx;
	    maxx = 2e5;//1000λ
	    minx = 2e5;
	    LL q = rand()%(maxx-minx+1)+minx;	    
	    cout<<n<<" "<<q<<"\n";
	    
	    //n������ 
	    for (LL i=1; i<=n; i++) {
			maxx=1000;
			minx=1;
	    	LL x = rand()%(maxx-minx+1)+minx;
	    	if (x<=30000) {
	    		cout<<'z';
			} else {
				cout<<'Z';
			}
		}
		cout<<"\n";
	}

    return 0;
}

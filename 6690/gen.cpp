//6690: 航海探险
//http://47.110.135.197/problem.php?id=6690

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
    
    freopen("09.in", "w", stdout);
    
    LL T;
    T=1;
    //cout<<T<<"\n";
    while (T--) {
	    //生成n,x,y
	    LL maxx = 1e4;
	    LL minx = 1e4;
	    LL n = rand()%(maxx-minx+1)+minx;
	    maxx = 1e5;
	    minx = 1e5;
	    LL m = rand()%(maxx-minx+1)+minx;
	    
	    cout<<n<<" "<<m<<"\n";
	    
	    for (LL i=1; i<=m; i++) {
	    	//类型 
	    	maxx=10;
	    	minx=1;
	    	LL type=rand()%(maxx-minx+1)+minx;
	    	if (type<5) {
	    		//ask
	    		cout<<"? ";
				//a b
				maxx=n;
				minx=1;
				LL a=rand()%(maxx-minx+1)+minx;
				LL b=rand()%(maxx-minx+1)+minx;
				cout<<a<<' '<<b<<'\n';
			} else {
		    	//方向 
			    maxx=20;
			    minx=1;
		    	LL d = rand()%(maxx-minx+1)+minx;
		    	if (d<=8) {
		    		cout<<"N ";
				} else if (d<=10) {
					cout<<"S ";
				} else if (d<=13) {
					cout<<"W ";
				} else {
					cout<<"E ";
				}
				
				//a b
				maxx=n;
				minx=1;
				LL a=rand()%(maxx-minx+1)+minx;
				LL b=rand()%(maxx-minx+1)+minx;
				cout<<a<<' '<<b<<' ';
				
				//dist
				maxx=1e6;
				minx=1;
				LL dist=rand()%(maxx-minx+1)+minx;
				cout<<dist<<"\n";				
			}
		}
	}

    return 0;
}

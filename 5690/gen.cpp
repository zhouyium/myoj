#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500+10;
ll a[MAXN][MAXN];
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //ÓÐ²ÎÊý
        seed = atoi(argv[1]);
    }
    srand(seed);
    
    freopen("8.in", "w", stdout);
    int n=5;
    while (n<=198000) {
    	cout<<"black";
    	n+=5;
	}
	cout<<"\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN=1e3+10;
LL f[MAXN][MAXN];//f[i][j]±íÊ¾×Ö·û´®a[i]ºÍ×Ö·û´®b[j]

int main() {
#if 0
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif

    string a,b;
    while (cin>>a>>b) {
	    LL n=a.size();
	    LL m=b.size();
	    memset(f, 0, sizeof(f));
	    for (LL i=0; i<n; i++) {
	        for (LL j=0; j<m; j++) {
	            if (a[i]==b[j]) {
	                f[i+1][j+1]=f[i][j]+1;
	            } else {
	                f[i+1][j+1]=max(f[i][j+1], f[i+1][j]);
	            }
	        }
	    }
	
	    cout<<f[n][m]<<"\n";
	}


    return 0;
}

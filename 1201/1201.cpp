//1201: ¡ì1 5 ¾ØÕó×ªÖÃ
//http://47.110.135.197/problem.php?id=1201
#include <iostream>
using namespace std;
const int MAXN=1e2+4;
int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main() {
	freopen("06.in", "r", stdin);
	freopen("06.out", "w", stdout);
	
    int n,m;
    cin>>n>>m;
    //read a
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];
        }
    }
    //generate b
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            b[i][j]=a[j][i];
        }
    }

    //output
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

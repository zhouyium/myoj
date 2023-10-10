//1200: §1 5 矩阵乘法
//http://47.110.135.197/problem.php?id=1200
#include <iostream>
using namespace std;
using LL=long long;

const int MAXN = 1e2+2;//行
const int MAXM = 1e2+2;//列
LL a[MAXM][MAXN];
LL b[MAXM][MAXN];
LL c[MAXM][MAXN];

int main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
    LL n,m,k;
    cin>>n>>m>>k;

    //读入矩阵A
    for (LL i=1; i<=n; i++) {//行
        for (LL j=1; j<=m; j++) {//列
            cin>>a[i][j];
        }
    }
    //读入矩阵B
    for (LL i=1; i<=m; i++) {//行
        for (LL j=1; j<=k; j++) {//列
            cin>>b[i][j];
        }
    }

    //求矩阵C
    for (LL i=1; i<=n; i++) {//行
        for (LL j=1; j<=k; j++) {//列
            for (int d=1; d<=m; d++) {
                c[i][j]+=a[i][d]*b[d][j];
            }
        }
    }

    //输出数据
    for (LL i=1; i<=n; i++) {
        for (LL j=1; j<=k; j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

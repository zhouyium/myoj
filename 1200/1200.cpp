//1200: ��1 5 ����˷�
//http://47.110.135.197/problem.php?id=1200
#include <iostream>
using namespace std;
using LL=long long;

const int MAXN = 1e2+2;//��
const int MAXM = 1e2+2;//��
LL a[MAXM][MAXN];
LL b[MAXM][MAXN];
LL c[MAXM][MAXN];

int main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
    LL n,m,k;
    cin>>n>>m>>k;

    //�������A
    for (LL i=1; i<=n; i++) {//��
        for (LL j=1; j<=m; j++) {//��
            cin>>a[i][j];
        }
    }
    //�������B
    for (LL i=1; i<=m; i++) {//��
        for (LL j=1; j<=k; j++) {//��
            cin>>b[i][j];
        }
    }

    //�����C
    for (LL i=1; i<=n; i++) {//��
        for (LL j=1; j<=k; j++) {//��
            for (int d=1; d<=m; d++) {
                c[i][j]+=a[i][d]*b[d][j];
            }
        }
    }

    //�������
    for (LL i=1; i<=n; i++) {
        for (LL j=1; j<=k; j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

//http://47.110.135.197/problem.php?id=5345
//奖牌颁发

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _SCORE {
    int cj;//分数
    int idx;//序号
    int jp;//奖牌
} SCORE;

const int MAXN=2e6+4;
SCORE xs[MAXN];

bool cmpcj(const SCORE &x, const SCORE &y) {
    return x.cj>y.cj;
}

bool cmpsy(const SCORE &x, const SCORE &y) {
    return x.idx<y.idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("9.in", "r", stdin);
    //freopen("9.out", "w", stdout);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>xs[i].cj;
        xs[i].idx=i;
        xs[i].jp=2;//初始都给铜牌
    }

    //按照成绩排序
    sort(xs+1, xs+1+n, cmpcj);

    int g=n*0.2;//金牌人数
    int s=n*0.3;//银牌人数
    int b=n*0.5;//铜牌人数

    //分配奖牌
    int g_s = xs[g].cj;//金牌分数
    int s_s;//银牌分数
    int g_r = 0;//实际金牌人数
    for (int i=1; i<=n; i++) {
        if (xs[i].cj>=g_s) {
            xs[i].jp=0;//给金牌
            g_r++;
            if (g>0) {
                g--;
            } else {
                if (s>0) {
                    s--;
                } else {
                    b--;
                }
            }
        } else {
            //确认银牌分数
            if (s>0) {
                s_s = xs[g_r+s].cj;
            }
            if (s>0 && xs[i].cj>=s_s) {
                xs[i].jp=1;//给铜牌
            }
        }
    }

    sort(xs+1, xs+1+n, cmpsy);

    for (int i=1; i<=n; i++) {
        cout<<xs[i].jp<<" ";
    }
    cout<<"\n";

    return 0;
}
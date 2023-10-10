//5345的随机数据产生
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("9.in", "w", stdout);

    srand((int)time(0));

    int n;
    n=2000000;
    cout<<n<<"\n";

    int g=n*0.275;//金牌人数
    int s=n*0.36;//银牌人数
    int b=n-g-s;//铜牌人数
    if (b<0) {
        b=0;
    }

    //金牌
    int maxx=600;
    int minx=500;
    int type;//奖牌类型
    int x;//分数
    while (g>0 || s>0 || b>0) {
        //产生奖牌类型
        int type=rand()%3;
        bool flag=false;
        if (0==type) {
            //金牌
            maxx=600;
            minx=500;
            if (g>0) {
                g--;
                flag=true;
            }
        } else if (1==type) {
            //银牌
            maxx=499;
            minx=300;
            if (s>0) {
                s--;
                flag=true;
            }
        } else {
            //铜牌
            maxx=299;
            minx=0;
            if (b>0) {
                b--;
                flag=true;
            }
        }

        //产生一个分数
        if (true==flag) {
            x=rand()%(maxx-minx+1)+minx;
            cout<<x<<" ";
        }
    }
    cout<<"\n";

    return 0;
}
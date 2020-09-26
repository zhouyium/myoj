//5335的随机数据产生
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("10.in", "w", stdout);

    srand((int)time(0));

    int maxx=1e9;//数据最大值
    int minx=1e9;//数据最小值

    //生成数据 n
    int n;
    n=rand()%(maxx-minx+1)+minx;
    cout<<n<<"\n";

    //生成 26 个字母个数
    maxx=1e9;
    minx=1e9;
    for (int i=0; i<26; i++) {
        int x=rand()%(maxx-minx+1)+minx;
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}
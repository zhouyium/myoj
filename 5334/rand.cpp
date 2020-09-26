//5334的随机数据产生
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("11.in", "w", stdout);

    srand((int)time(0));

    int n;
    n=2e5;
    cout<<n<<"\n";

    int maxx=1;
    int minx=0;
    for (int i=1; i<=n; i++) {
        int x=rand()%(maxx-minx+1)+minx;
        cout<<x;
    }
    cout<<"\n";

    return 0;
}
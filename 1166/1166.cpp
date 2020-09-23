//http://47.110.135.197/problem.php?id=1166
//计算多项式的值
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x;
    int n;
    cin>>x>>n;

    double ans=1;
    for (int i=1; i<=n; i++) {
        double t=pow(x, i);
        ans+=t;
    }

    cout<<fixed<<setprecision(2)<<ans<<"\n";

    return 0;
}
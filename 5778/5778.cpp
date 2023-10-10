//http://acm.hdu.edu.cn/showproblem.php?pid=6744
//http://47.110.135.197/problem.php?id=5778
//GPA

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double ans;

double ch(int x){
    if (x >= 95) return(4.3);
    if (x >= 90) return(4.0);
    if (x >= 85) return(3.7);
    if (x >= 80) return(3.3);
    if (x >= 75) return(3.0);
    if (x >= 70) return(2.7);
    if (x >= 67) return(2.3);
    if (x >= 65) return(2.0);
    if (x >= 62) return(1.7);
    if (x >= 60) return(1.0);
    return 0;
}

//枚举所有可能性 
void solve(int x,int pos,double mark){
    if (pos==4){
        mark += ch(x);
        ans = max(ans, mark);
        return;
    }
    if (x >= 95) solve(x-95,pos+1,mark+4.3);
    if (x >= 90) solve(x-90,pos+1,mark+4.0);
    if (x >= 85) solve(x-85,pos+1,mark+3.7);
    if (x >= 80) solve(x-80,pos+1,mark+3.3);
    if (x >= 75) solve(x-75,pos+1,mark+3.0);
    if (x >= 70) solve(x-70,pos+1,mark+2.7);
    if (x >= 67) solve(x-67,pos+1,mark+2.3);
    if (x >= 65) solve(x-65,pos+1,mark+2.0);
    if (x >= 62) solve(x-62,pos+1,mark+1.7);
    if (x >= 60) solve(x-60,pos+1,mark+1.0);
    solve(x,pos+1,mark);
}


int main() {
#if 1
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    freopen("09.in", "r", stdin);
    freopen("09.out", "w", stdout);
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        
        ans=0;
        solve(n, 1, 0);
        cout<<fixed<<setprecision(1)<<ans<<"\n";
    }

    return 0;
}

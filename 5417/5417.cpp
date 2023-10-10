#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    //freopen("function.in","r",stdin);
    //freopen("function.out","w",stdout);
    int n;
    cin>>n;
    int l=1,r=max(n,10);//注意r的取值范围
    while (l<r){//二分
        int mid=l+r>>1;
        if (1.0*mid*log(mid)>=1.0*(n-1)*log(10)){//上公式
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}

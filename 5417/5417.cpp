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
    int l=1,r=max(n,10);//ע��r��ȡֵ��Χ
    while (l<r){//����
        int mid=l+r>>1;
        if (1.0*mid*log(mid)>=1.0*(n-1)*log(10)){//�Ϲ�ʽ
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}

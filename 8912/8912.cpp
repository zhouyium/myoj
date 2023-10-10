/*
对于每一个数ai，设Li,Ri分别为ai 左边和右边第一个大于i的数的下标，则对于任意的
L∈(Li,i]和]r∈[i,R i),
a_i=max_{j=i}^r (a_j)
故以ai为最大值的序列总数为(i?L_i)(R_i-i)，则最大值的和为a_i(i?L_i)(R_i-i)，原问题的答案就是
∑_{i=1}^{n} a_i(i-L_i)(R_i-i)
所以只要求出每个数对应的L_i,R_i 即可。

用一个单调递减栈维护，设栈顶元素下标为j，
即将入栈的元素下标为i，由于单调递减，当
i>j时，i就是j右边第一个大于j的值，即
Rj=i，j出栈。
直到j>i时，j就是i左边第一个大于i的值，即
Li=j.
*/
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll a[N],n,L[N],R[N],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("14.in","r",stdin);
    freopen("14.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<ll> st;
    for(int i=1;i<=n;i++){
        R[i]=n+1;
        while(!st.empty()&&a[i]>=a[st.top()]){
            ll &t=st.top();
            R[t]=i;
            ans+=a[t]*(R[t]-t)*(t-L[t]);
            st.pop();
        }
        L[i]=st.empty()?0:st.top();
        st.push(i);
    }
    while(!st.empty()){
        ll &t=st.top();
        ans+=a[t]*(R[t]-t)*(t-L[t]);
        st.pop();
    }
    cout<<ans;
    return 0;
}

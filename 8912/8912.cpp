/*
����ÿһ����ai����Li,Ri�ֱ�Ϊai ��ߺ��ұߵ�һ������i�������±꣬����������
L��(Li,i]��]r��[i,R i),
a_i=max_{j=i}^r (a_j)
����aiΪ���ֵ����������Ϊ(i?L_i)(R_i-i)�������ֵ�ĺ�Ϊa_i(i?L_i)(R_i-i)��ԭ����Ĵ𰸾���
��_{i=1}^{n} a_i(i-L_i)(R_i-i)
����ֻҪ���ÿ������Ӧ��L_i,R_i ���ɡ�

��һ�������ݼ�ջά������ջ��Ԫ���±�Ϊj��
������ջ��Ԫ���±�Ϊi�����ڵ����ݼ�����
i>jʱ��i����j�ұߵ�һ������j��ֵ����
Rj=i��j��ջ��
ֱ��j>iʱ��j����i��ߵ�һ������i��ֵ����
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

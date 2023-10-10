#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MO=1e9+7;

const int N=1E6+10;

template< typename T, typename Compare = greater< T > >
vector< T > knapsack_01(const vector< int > &w, const vector< T > &v, const int &W, const T &NG, const Compare &comp = Compare()) {
  const int N = (int) w.size();
  vector< T > dp(W + 1, NG);
  dp[0] = T();
  for(int i = 0; i < N; i++) {
    for(int j = W; j >= w[i]; j--) {
      if(dp[j - w[i]] != NG) {
        if(comp(dp[j - w[i]] + v[i], dp[j])) {
          dp[j] = dp[j - w[i]] + v[i];
        }
      }
    }
  }
  return dp;
}

template< typename T >
T knapsack_01_2(const vector< T > &w, const vector< int > &v, const T &W) {
  const int N = (int) w.size();
  const int sum = accumulate(begin(v), end(v), 0);
  vector< T > dp(sum + 1, W + 1);
  dp[0] = T();
  for(int i = 0; i < N; i++) {
    for(int j = sum; j >= v[i]; j--) {
      dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  int ret = 0;
  for(int i = 0; i <= sum; i++) {
    if(dp[i] <= W) ret = i;
  }
  return ret;
}

template< typename T, typename Compare = greater< T > >
vector< T > knapsack(const vector< int > &w, const vector< T > &v, const int &W, const T &NG, const Compare &comp = Compare()) {
  const int N = (int) w.size();
  vector< T > dp(W + 1, NG);
  dp[0] = T();
  for(int i = 0; i < N; i++) {
    for(int j = w[i]; j <= W; j++) {
      if(dp[j - w[i]] != NG) {
        if(comp(dp[j - w[i]] + v[i], dp[j])) {
          dp[j] = dp[j - w[i]] + v[i];
        }
      }
    }
  }
  return dp;
}

template< typename T >
size_t longest_increasing_subsequence(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(begin(lis), end(lis), p);
    else it = upper_bound(begin(lis), end(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}

template< typename T, typename Compare = greater< T > >
vector< T > knapsack_limitations(const vector< int > &w, const vector< int > &m, const vector< T > &v,
                                 const int &W, const T &NG, const Compare &comp = Compare()) {
  const int N = (int) w.size();
  vector< T > dp(W + 1, NG), deqv(W + 1);
  dp[0] = T();
  vector< int > deq(W + 1);
  for(int i = 0; i < N; i++) {
    if(w[i] == 0) {
      for(int j = 0; j <= W; j++) {
        if(dp[j] != NG && comp(dp[j] + v[i] * m[i], dp[j])) {
          dp[j] = dp[j] + v[i] * m[i];
        }
      }
    } else {
      for(int a = 0; a < w[i]; a++) {
        int s = 0, t = 0;
        for(int j = 0; w[i] * j + a <= W; j++) {
          if(dp[w[i] * j + a] != NG) {
            auto val = dp[w[i] * j + a] - j * v[i];
            while(s < t && comp(val, deqv[t - 1])) --t;
            deq[t] = j;
            deqv[t++] = val;
          }
          if(s < t) {
            dp[j * w[i] + a] = deqv[s] + j * v[i];
            if(deq[s] == j - m[i]) ++s;
          }
        }
      }
    }
  }
  return dp;
}

template< typename T >
T knapsack_limitations(const vector< T > &w, const vector< T > &m, const vector< int > &v,
                       const T &W) {
  const int N = (int) w.size();
  auto v_max = *max_element(begin(v), end(v));
  if(v_max == 0) return 0;
  vector< int > ma(N);
  vector< T > mb(N);
  for(int i = 0; i < N; i++) {
    ma[i] = min< T >(m[i], v_max - 1);
    mb[i] = m[i] - ma[i];
  }
  T sum = 0;
  for(int i = 0; i < N; i++) sum += ma[i] * v[i];
  auto dp = knapsack_limitations(v, ma, w, sum, T(-1), less<T>());
  vector< int > ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
    return v[a] * w[b] > v[b] * w[a];
  });
  T ret = T();
  for(int i = 0; i < dp.size(); i++) {
    if(dp[i] > W || dp[i] == -1) continue;
    T rest = W - dp[i], cost = i;
    for(auto &p : ord) {
      auto get = min(mb[p], rest / w[p]);
      if(get <= 0) continue;
      cost += get * v[p];
      rest -= get * w[p];
    }
    ret = max(ret, cost);
  }
  return ret;
}

void solve() {
  int N;
  long long W;
  cin >> N >> W;
  vector< int > v(N);
  vector< long long > w(N), m(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i] >> w[i] >> m[i];
  }
  cout << knapsack_limitations(w, m, v, W) << endl;
}

int main() {
#if 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	LL T=1;
	//cin>>T;
	for (LL i=1; i<=T; i++) {
		//cout<<i<<"\n";
		solve();
	}

	return 0;
}



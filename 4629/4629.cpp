#include <bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<string, vector<string>> mp;
	vector<string> us;
	string user, website;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		cin >> user >> website;
		if(mp.count(user) == 0)
			us.push_back(user);
		mp[user].push_back(website);
	}
	for(string u : us)
	{
		cout << u << ' ';
		for(string w : mp[u])
			cout << w << ' ';
		cout << endl;
	}
	return 0;
}

//4685: Priority_Queue基本使用：利用Priority_Queue排序 II
//http://47.110.135.197/problem.php?id=4685
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <cstdio>

int main () {
	freopen("07.in", "r", stdin);
	freopen("07.out", "w", stdout);
	std::priority_queue<int, std::vector<int>, std::less<int> >q;
	//std::priority_queue<int>q;
	int n;
	std::cin >> n;
	
	int i;
	int shu;
	for (i=0; i<n; i++) {
		std::cin >> shu;
		q.push(shu);
	}
	
	while (!q.empty()) {
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << '\n';
	
	//fclose(stdin);
	//fclose(stdout);

	return 0;
}

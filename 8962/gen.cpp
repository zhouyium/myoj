//8962: 连续字符
//http://47.110.135.197/problem.php?id=8962

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

string str="abcdefghijklmnopqrstuvwxyz";

const int N=1e5+10;
//二叉树
vector<LL> adj[N];//图的邻接表
LL fa[N];
/*
  tree[i]表示节点编号为i的父亲是谁
  tree[i]=-1表示父亲是自己，类似并查集
 */

void init(LL n){
	for(LL i=0;i<=n;i++){
		adj[i].clear();
		fa[i]=-1;
	}
}

LL ran(LL l=1,LL r=1e3) {
	if (l>r) {
		swap(l,r);
	}
	return rand()%(r-l+1)+l;
}

// Prints edges of tree
// represented by give Prufer code
void printTreeEdges(vector<int> prufer, int m){
	int vertices = m + 2;
	vector<int> vertex_set(vertices);
	
	// Initialize the array of vertices
	for (int i = 0; i < vertices; i++){
		vertex_set[i] = 0;
	}
	
	// Number of occurrences of vertex in code
	for (int i = 0; i < vertices - 2; i++){
		vertex_set[prufer[i] - 1] += 1;
	}
	
	//cout<<("\nThe edge set E(G) is:\n");
	
	int j = 0;
	// Find the smallest label not present in
	// prufer[].
	for (int i = 0; i < vertices - 2; i++){
		for (j = 0; j < vertices; j++){
			// If j+1 is not present in prufer set
			if (vertex_set[j] == 0){
				// Remove from Prufer set and print
				// pair.
				vertex_set[j] = -1;
				//cout<<"(" << (j + 1) << ", " << prufer[i] << ") ";
				
				adj[j+1].push_back(prufer[i]);
				adj[prufer[i]].push_back(j+1);
				
				vertex_set[prufer[i] - 1]--;
				break;
			}
		}
	}
	
	LL u,v;
	j = 0;
	// For the last element
	for (int i = 0; i < vertices; i++){
		if (vertex_set[i] == 0 && j == 0){
			//cout << "(" << (i + 1) << ", ";
			u = i + 1;
			j++;
		}else if (vertex_set[i] == 0 && j == 1){
			//cout << (i + 1) << ")\n";
			v = i + 1;
		}
	}
	adj[u].push_back(v);
	adj[v].push_back(u);	
}

// Function to Generate Random Tree
void generateRandomTree(int n){
	int length = n - 2;
	vector<int> arr(length);
	
	// Loop to Generate Random Array
	for (int i = 0; i < length; i++){
		arr[i] = ran(0, length + 1) + 1;
	}
	printTreeEdges(arr, length);
}

void dfs(LL u, LL fath){
	fa[u]=fath;
	for(const auto &v : adj[u]){
		if(v==fath){
			continue;
		}
		dfs(v, u);
	}
}

int main(int argc, char *argv[]) {
	int seed = time(NULL);
	if (argc>1) {
		//有参数
		seed = atoi(argv[1]);
	}
	srand(seed);
	
	freopen("09.in", "w", stdout);
	
	LL T = 1;
	//cout<<T<<"\n";
	
	while (T--)	{
		//n
		LL n = ran(1e5,1e5);
		//LL m = ran(1,n);
		cout<<n<<"\n";

		//输出字符串
		char t='A';
		for(LL i=1;i<=n;i++){
			if(80000<=i && i<=80026){
				cout<<t;
				t++;
			}else{
				LL x = ran(0,25);
				char t=str[x]-32;
				cout<<t;				
			}
		}
		cout<<"\n";
	}
	
	return 0;
}

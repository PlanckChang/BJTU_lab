// 2023-05-10
// zhangzhiwei 20271259 for Computer Networking lab 5 link state routing algorithm 
// dijkstra
// cpp 14

#include <iostream>
#include <climits>
using namespace std;
#define MAXN 2023

struct edge{
	int v, w, next;
};

int idx = 0, head[MAXN], visit[MAXN];
edge e[MAXN*2];

int add(int u, int v, int w){
	e[++idx].v = v;
	e[idx].w   = w;
	e[idx].next = head[u];
	head[u] = idx;
}

int main(){
	int n, m, x, y, z, last, now, idx2;
	cin >> n >> m;
	long long dis[n+1], path[n+1], parent[n+1];
	for(int i=1; i<=m;++i){
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}

	for(int i=1; i<=n; ++i){
		dis[i] = INT_MAX;
	}

	for(int i=head[6]; i; i=e[i].next){
		dis[e[i].v] = e[i].w;
	}
	visit[6] = 1;
	path[1] = 6;
	idx2 = 1;
    dis[6] = 0;  // 6 i.e the u first point
    parent[6] = 0;
    int prior = 6;
	for(int i=1; i<=n-1; ++i){
		last = INT_MAX;
		for(int j=1; j<=n; ++j){
			if(!visit[j] && last > dis[j]){
				last = dis[j];
				now = j;
			}
		}

		if(last == INT_MAX) {
			cout << "this networking is not a connected net" << endl;
			return 0;
		}
		path[++idx2] = now;
		visit[now] = 1;
        parent[now] = prior;
        prior = now;

//		cout << now << "\n";

		for(int j=head[now]; j; j=e[j].next){
			int v = e[j].v;
			if(!visit[v] && dis[v] > dis[now] + e[j].w){
				dis[v] = dis[now] + e[j].w;
			}
		}
	}
	
	string output;
	for(int i=1; i<=n; ++i){
        char a = -path[i] + 'a' + 26;
		output.append(1, a);
	}
	for(int i=0; i<n; ++i){
		cout << "step " << i << ": " << output[i] << " dis: " << dis[path[i+1]] <<  "\n";
	}

	cout << output << endl;
	return 0;
}
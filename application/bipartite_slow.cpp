#include<stdio.h>
#include<bitset>
#include<string.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<assert.h>
#include<utility>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<=(e);i++)

#define REP(i,n)	for(int i=0;i<(n);i++)

#define mp	make_pair
#define pb push_back

#define DEBUG(x) cout<<" "<<#x<<"  "<<(x)<<"\n";


/************************************Bipartite Matching Begins********************/

int lnodes,rnodes,edges;
vector<int> to,next,Left,Right,fin,visited;

void addedge(int u,int v)
{
	to.pb(v),next.pb(fin[u]),fin[u]=edges,edges++;
}

void init(int l,int r)
{
	edges = 0;
	lnodes = l;
	rnodes = r;
	to.clear();next.clear();
	visited = vector<int>(l+2,-1);
	fin = vector<int>(l+2,-1);
	Left = vector<int>(l+2,-1);
	Right = vector<int>(r+2,-1);
}

bool dfs(int u)
{
	int v;
	if(visited[u] == 1)	return false;
	visited[u] = 1;
	//Search for a direct path.
	for(int j = fin[u];j!=-1;j=next[j]){
		v = to[j];
		if(Right[v] == -1){
			Right[v] = u;
			Left[u] = v;
			return true;
		}
	}
	//Search for an augmenting path
	for(int j=fin[u];j!=-1;j=next[j]){
		v = to[j];
		if(dfs(Right[v])){
			Right[v] = u;
			Left[u] = v;
			return true;
		}
	}
	return false;
}

int match()
{
	int ans = 0;
	//1 Based Indexing for Left and Right , if you wish for 0 base indexing do i=0...
	for(int i=1;i<=lnodes;i++){
		fill(visited.begin(),visited.end(),0);
		//visited = vector<int> (lnodes+2,0);
		if(dfs(i))	ans++;
	}
	return ans;
}

void solve()
{
	int N,M,P,a,b;
	scanf("%d%d%d",&N,&M,&P);
	init(N,M);
	while(P--){
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}	
	printf("%d\n",match());
}

int main()
{
	int T;
	T=1;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}

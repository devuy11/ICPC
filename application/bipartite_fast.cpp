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


/********************************************Fast bipartite matching****************/

#define INF 1e9+10
#define NIL 0
int edges,lnodes,rnodes;
vector<int> to,next,Left,Right,fin,dist;

void addedge(int u,int v)
{
	to.pb(v) , next.pb(fin[u]) , fin[u] = edges , edges++;
}

void init(int l,int r)
{
	lnodes = l;
	rnodes = r;
	edges = 0;
	to.clear(),next.clear();
	fin = vector<int>(lnodes+2,-1);
	Left = vector<int> (lnodes+2,NIL);
	Right = vector<int> (rnodes+2,NIL);
	dist = vector<int> (lnodes + 2, 0);
}

bool bfs()
{
	int u,v,u1;
	queue<int> Q;
	for(int i=1;i<=lnodes;i++){
		if(Left[i] == NIL ){
			dist[i] = 0;
			Q.push(i);
		}
		else	dist[i] = INF;
	}
	dist[NIL] = INF;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(int j=fin[u];j!=-1;j=next[j]){
			v = to[j];
			u1 = Right[v];
			if ( dist[u1] == INF ){
				dist[u1] = dist[u] + 1;
				Q.push(u1);
			}
			if(u1 == NIL){
				return true;
			}
			//if(dist[NIL] != INF)	return true;
		}
	}
	return false;
	//return dist[NIL]!=INF;
}

bool dfs(int u)
{
	int v,u1;
	if(u!=NIL){
		for(int i = fin[u] ;i!=-1;i=next[i]){
			v = to[i];
			u1 = Right[v];
			if ( dist[u1] == dist[u] + 1){
				if(dfs(u1)){	
					Right[v] = u;
					Left[u] = v;
					return true;
				}
			}
		}
		return false;
	}
	else	return true;
}

int HopCroft()
{
	int ans = 0;
	while(bfs()){
		for(int i=1;i<=lnodes;i++){
			if(Left[i] == NIL )	if(dfs(i))	ans++;
		}
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
	printf("%d\n",HopCroft());
}

int main()
{
	int T=1;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}

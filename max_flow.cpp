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


/*****************************************MAX FLOW TEMPLATE****************************/
#define INF 1e9+10

int nodes,edges,src,snk;
vector<int> to,fin,next,cop,dist;
vector<ll> cap,flow;

void init(int n,int sc,int sk)	//give me src and snk
{
	edges = 0;
	nodes = n;
	src = sc;
	snk = sk;
	to.clear();
	cap.clear();
	flow.clear();
	next.clear();
	fin = vector<int>(n+2,-1);
	dist = vector<int>(n+2,-1);
}

void addedge(int u,int v,int c)
{
	to.pb(v) , next.pb(fin[u]) , fin[u] = edges , cap.pb(c) , flow.pb(0) , edges++;
	//to.pb(u) , next.pb(fin[v]) , fin[v] = edges , cap.pb(0) , flow.pb(0) , edges++;	//for directed graphs!
	to.pb(u) , next.pb(fin[v]) , fin[v] = edges , cap.pb(c) , flow.pb(0) , edges++;	//for undirected graphs!
}

bool bfs()
{
	fill(dist.begin(),dist.end(),-1);	
	
	queue<int> Q;
	Q.push(src);
	dist[src] = 0;
	int u,v;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(int i=fin[u];i!=-1;i=next[i]){	
			v = to[i];
			if(flow[i]< cap[i] && dist[v] == -1){
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
	return dist[snk] != -1;
}

ll dfs(int u,ll fl)
{
	ll val,v;
	if(u==snk)	return fl;
	for(int &e = cop[u];e!=-1;e=next[e]){
		v = to[e];
		if ( flow[e] < cap[e] && dist[v] == dist[u] + 1){
			val = dfs(v,min(fl,cap[e]-flow[e]));
			if(val >0){
				flow[e] += val;
				flow[e^1] -= val;
				return val;
			}
		}
	}
	return 0;
}

ll Network()
{
	ll ans = 0,x;
	while(bfs()){
		cop = fin;
		while(1){
			x = dfs(src,INF);
			if(x==0)	break;
			else	ans+=x;
		}
	}
	return ans;
}

/***************************Max Flow Ends******************************/

//Solution to FAST FLOW
void solve()
{
	int N,M,a,b,c;
	scanf("%d%d",&N,&M);
	init(N,1,N);
	for(int i=1;i<=M;i++){	
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	printf("%lld\n",Network());
}

int main()
{
	int T=1;
	//cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}

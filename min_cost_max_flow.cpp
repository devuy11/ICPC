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

/***********************************MAX FLOW MIN COST TEMPLATE**************************/

#define INF 1e9+10

int nodes,edges,src,snk;
vector<int> to,from,cap,cost,pre,dist;

void addedge(int u,int v,int c,int w)
{
	to.pb(v),from.pb(u) ;cap.pb(c);cost.pb(w);edges++;
	to.pb(u),from.pb(v) ;cap.pb(0);cost.pb(-w);edges++;
}

void init(int n,int sc,int sk)	//give me nodes , source and sink asap before you do anything.
{
	edges = 0;
	src = sc ;
	snk = sk ;
	nodes = n;
	dist = vector<int>(n+3);
	pre = vector<int>(n+3);
	to.clear();from.clear();cap.clear();cost.clear();
}

bool bellmann()
{
	int u,v;
	fill(dist.begin(),dist.end(),INF);
	fill(pre.begin(),pre.end(),-1);
	dist[src] =0;
	bool check = true;
	while(check){
		check = false;
		for(int i=0;i<edges;i++){	
			if (cap[i]){
				u = from[i];
				v = to[i];
				if ( dist[u] != INF && dist[v] > dist[u] + cost[i] ){	
					dist[v] = dist[u] + cost[i];
					check = true;
					pre[v] = i;
				}
			}
		}
	}
	return dist[snk] != INF;
}

int max_flow_min_cost()
{
	int ans = 0;
	while(bellmann()){
		for(int i=pre[snk];i!=-1;i=pre[from[i]]){
			cap[i] -= 1;
			cap[i^1] += 1;
			ans += cost[i] ;
		}
	}
	return ans;
}

/********************************************************************************************/


void solve()
{
	//First Find Total Number of nodes
	//Next find source and snk
	//call init
	//Add Edges using addedge between the 2 components.
	//Add edges from source to left half
	//Add edges from right half to sink
	//call max_flow_min_cost
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}

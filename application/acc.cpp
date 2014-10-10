#include<stdio.h>
#include<algorithm>
using namespace std;
#define Nodes 5000
#define Edges 60000
typedef long long int ll;
const ll INF = (ll) 1000000000 * (ll) 1000000000 ;
int nodes,edges,to[Edges],fin[Nodes],next[Edges],src,snk,cop[Nodes],Q[Nodes],dist[Nodes],cap[Edges];
ll flow[Edges];
void addedge(int u,int v,int c)
{
	to[edges]=v;
	next[edges]=fin[u];
	fin[u]=edges;
	cap[edges]=c;
	flow[edges]=0;
	edges++;
}
bool bfs()
{
	for(int i=0;i<nodes;i++)	dist[i]=-1;
	int st=0,end=1,u,v;
	Q[0]=src;
	dist[src]=0;
	while(st<end){
		u=Q[st];
		st++;
		for(int i=fin[u];i!=-1;i=next[i]){	
			v=to[i];
			if(flow[i]<cap[i] && dist[v]==-1){
				dist[v]=dist[u]+1;
				Q[end]=v;
				end++;
			}
		}
	}
	return dist[snk]!=-1;
}
ll dfs(int u,ll fl)
{
	ll val;int v;
	if(u==snk)		return fl;
	for(int &e = cop[u];e!=-1;e=next[e]){
		v=to[e];
		if(flow[e]<cap[e] && dist[v]==dist[u]+1){
			val=dfs(v,min(fl,cap[e]-flow[e]));
			if(val>0){
				flow[e]+=val;
				flow[e^1]-=val;
				return val;
			}
		}
	}
	return 0;
}
ll Network()			//Returns the maximum flow from src to snk
{
	ll ans=0,x;
	while(bfs()){
		for(int i=0;i<nodes;i++)	cop[i]=fin[i];
		while(true){
			x=dfs(src,INF);
			if(x==0)	break;
			else	ans+=x;
		}
	}
	return ans;
}
int main()
{	
	int n,c,a,b,m;
	char x ,y;
	scanf("%d%d",&n,&m);
	src=0;snk=n-1;
	nodes=n;
	for(int i=0;i<nodes;i++)	fin[i]=-1;
	while(m--){
		scanf(" %d %d %d",&a,&b,&c);
		a--;b--;
		addedge(a,b,c);
		addedge(b,a,c);
	}
	printf("%lld\n",Network());
	return 0;
}


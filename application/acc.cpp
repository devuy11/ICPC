#include<stdio.h>
#include<string.h>
#define Nodes 	50001	//N	+ NIL_Node
#define Edges	150000
#define RNodes	50001	//M
#define NIL 0
#define INF 1000000000
//  0  :: N  ::   M
int nodes,edges,N,M,to[Edges],next[Edges],fin[Nodes],Left[Nodes],Right[RNodes],dist[Nodes],Q[Nodes];
void addedges(int u,int v)
{
	to[edges]=v;
	next[edges]=fin[u];
	fin[u]=edges;
	edges++;
}
bool bfs()
{
	int s=0,e=0,u,v,u1;
	for(int i=1;i<=N;i++){
		if(Left[i]==NIL){
			dist[i]=0;
			Q[e]=i;
			e++;
		}
		else	dist[i]=INF;
	}
	dist[NIL]=INF;
	
	while(s<e){
		u=Q[s];
		s++;
		for(int j=fin[u];j!=-1;j=next[j]){	
			v=to[j];
			u1=Right[v];
			if(dist[u1]==INF){			//Traversing a Matched Edges and a unmatched Edges
				dist[u1]=dist[u]+1;
				Q[e]=u1;
				e++;
			}
			if(dist[NIL]!=INF)			//Free Vertex in M has been encountered
				return true;
		}
	}
	return dist[NIL]!=INF;
}
bool dfs(int u)
{
	int v,u1;
	if(u!=NIL){
		for(int j=fin[u];j!=-1;j=next[j]){
			v=to[j];
			u1=Right[v];
			if(dist[u1]==dist[u]+1){
				if(dfs(u1)){
					Right[v]=u;
					Left[u]=v;
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
	int ans=0;
	for(int i=1;i<=N;i++)	Left[i]=NIL;
	for(int j=1;j<=M;j++)	Right[j]=NIL;
	while(bfs()){
		//printf("Helo\n");
		for(int i=1;i<=N;i++){
			if(Left[i]==NIL){
				if(dfs(i))	ans++;
			}
		}
	}
	return ans;
}
int main()
{
	int P,x,y;
	scanf("%d%d%d",&N,&M,&P);
	edges=0;
	for(int i=1;i<=N;i++)	fin[i]=-1;		//N nodes
	while(P--){
		scanf("%d%d",&x,&y);
		addedges(x,y);
	}
	printf("%d\n",HopCroft());
	return 0;
}


#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int p[300005], sz[300005], mx, id, d[300005];
vector<int> e[300005];
bool vis[300005];

int f(int x)
{
	if(p[x]==x) return x;
	else return p[x]=f(p[x]);
}

void dfs(int cur, int prv, int dep)
{
	if(dep>mx) { mx=dep; id=cur; }
	for(int i=0;i<(int)e[cur].size();i++)
	{
		int nxt=e[cur][i];
		if(nxt!=prv) dfs(nxt,cur,dep+1);
	}
}

int main()
{
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for(int i=0;i<=n;i++) { p[i]=i; sz[i]=1; }
	for(int i=0;i<m;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		e[a].push_back(b); e[b].push_back(a);
		int u=f(a), v=f(b);
		if(sz[u]>sz[v]) swap(u,v);
		sz[v]+=sz[u]; p[u]=v;
	}
	for(int i=1;i<=n;i++)
	{
		int x=f(i);
		if(vis[x]) continue;
		vis[x]=true;
		mx=-1; dfs(i,-1,0);
	    mx=-1; dfs(id,-1,0);
		d[x]=mx;
	}
	
	while(q--)
	{
		int st; scanf("%d", &st);
		if(st==1)
		{
			int x; scanf("%d", &x);
			printf("%d\n", d[f(x)]);
		}
		else 
		{
			int x, y; scanf("%d%d", &x, &y);
			int u=f(x), v=f(y);
			if(u==v) continue;
			if(sz[u]>sz[v]) swap(u,v);
			sz[v]+=sz[u]; p[u]=v;
			d[v]=max(d[v],1+((d[u]+1)/2)+((d[v]+1)/2));
			d[v]=max(d[v],d[u]);
		}
	}
	return 0;
}


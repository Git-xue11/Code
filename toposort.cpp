/// HDU - 1285 
#pragma GCC optimize(2)
#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define ll long long 
#define ull unsigned long long
const int mxn = 2e3+7;
const int mod = 1e9+7;
template <class T>
void rd(T &x){
	T f = 1 ; char ch = getchar() ; x = 0 ;
	while(!isdigit(ch)) { if(ch=='-') f = -1 ; ch = getchar(); }
	while(isdigit(ch)) { x = (x<<1) + (x<<3) + (ch^48) ; ch = getchar() ; }
	x *= f ;
}
int n,m,t,ans,cnt;
int head[mxn] , in[mxn] , to[mxn] , nx[mxn] ;
void add(int u,int v) { to[cnt] = v , nx[cnt] = head[u] , head[u] = cnt++; in[v]++; }
void topo()
{
	priority_queue<int ,vector<int> , greater<int> >q ;
	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	int k = 0 ;
	while(!q.empty()){
		int u = q.top() ; q.pop() ; k++;
		if(k==n) {
			printf("%d\n",u); break;
		}
		printf("%d ",u);
		for(int i=head[u];~i;i=nx[i]){
			int v = to[i] ; in[v]--;
			if(!in[v]) q.push(v);
		}
	}
}
void solve()
{
	while(~scanf("%d %d",&n,&m)){
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		cnt = 0 ;
		for(int i=1,u,v;i<=m;i++){
			rd(u) , rd(v) , add(u,v);
		}
		topo();
	}
}
int main()
{
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0); solve();
	return 0;
}
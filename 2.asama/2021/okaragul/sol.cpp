#include <bits/stdc++.h>
#include<debug.h>
using namespace std;

#define all(aa) aa.begin(), aa.end()

string s, t;
int N, M;
vector<vector<int>> dp;

int f(int i, int j){
	if(i>=N || j>=M) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
   return dp[i][j]=max({f(i+1, j+1)+(s[i] == s[j]), f(i+1, j), f(i, j+1)});
}

int calc(string ss, string tt){
	ss+='%'; tt+='%';
	s=ss; t=tt; N=s.size(); M=t.size();
	dp.assign(N+1, vector<int>(M+1, -1));

	f(0, 0);
	debug(dp);
	int i=0, j=0, ans=0, l1=-1, l2=-1;
	while(i != N || j != M){
	  debug(i, j);
		if(i + 1 <= N && j + 1 <= M && s[i]==t[j] && dp[i][j]==dp[i+1][j+1]+1){
			ans+=max(i-l1-1, j-l2-1); 
			l1=i++; l2=j++;
		}
		else{
			if(j + 1 <= M && dp[i][j+1]==dp[i][j]) j++;
			else i++;
		}
	}
	return ans;
}

vector<int> root;

int findRoot(int n){
	return root[n]=(n==root[n] ? n:findRoot(root[n]));
}

int main(){ 
  cout << calc("a", "b");
  /*
	int n, m;
	cin>>n>>m;

	vector<pair<int, int>> tmp;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		tmp.push_back({a, b});
	}
	root.resize(n);
	iota(all(root), 0);
	vector<string> val(n);
	for(auto &e:val) cin>>e;

	vector<tuple<int, int, int>> edges;
	for(auto e:tmp){
		edges.push_back({calc(val[e.first-1], val[e.second-1]), e.first-1, e.second-1});
	}
	sort(all(edges));

	int cnt=0, ans=0, cur=0;
	while(cnt!=n-1){
		int x=get<0>(edges[cur]);
		int a=get<1>(edges[cur]);
		int b=get<2>(edges[cur]);
		if(findRoot(a)!=findRoot(b)){
			ans+=x;
			cnt++;
			root[findRoot(a)]=findRoot(b);
		}
		cur++;
	}
	cout<<ans<<endl;
	*/
}
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


//undirected graph add edge function
void addEdge(vector<int> adj[],int u, int y){
	adj[u].push_back(y);
	adj[y].push_back(u);
}

vector<int> neighbours(int x,vector<int> adj[]){
	vector<int> sol;
	for(int y:adj[x]){
		sol.push_back(y);
	}
	return sol;
}

vector<int> cores(vector<int> adj[],int v){
	
	vector<int> solution;
	//array with degree of every vertex
	int degree[v+1];
	
	//calculating degree of every vertex and also calculating maximum degree
	int md=0;
	for(int i=1;i<=v;i++){
		int m=0;
		m=adj[i].size();
		degree[i]=m;
		if(m>md){
			md=m;
		}
	}

	//now to sort according to the degree of each vertex in O(m) time
	int bin[v+1];
	for(int i=0;i<=md;i++){
		bin[i]=0;
	}
	for(int i=1;i<=v;++i){
		bin[degree[i]]++;
	}
	
	int start=1;
	for(int i=0;i<=md;i++){
		int num=bin[i];
		bin[i]=start;
		start+=num;
	}
	
	int pos[v+1];
	int vert[v+1];
	for(int i=1;i<=v;++i){
		pos[i]=bin[degree[i]];
		vert[pos[i]]=i;
		bin[degree[i]]++;
	}
	
	for(int i=md;i>0;--i){
		bin[i]=bin[i-1];
	}
	bin[0]=1;
	
	//algorithm
	int n,w,pu,du,pw;
	for(int i=1;i<=v;i++){
		n=vert[i];
		vector<int> neigh=neighbours(n,adj);
		for(int u:neigh){
			if(degree[u]>degree[n]){
				du=degree[u];
				pu=pos[u];
				pw=bin[du];
				w=vert[pw];
				if(u!=w){
					pos[u]=pw;
					vert[pu]=w;
					pos[w]=pu;
					vert[pw]=u;
				}
				bin[du]++;
				degree[u]--;
			}
		}
	}
	for (int i=0;i<=v;i++){
		solution.push_back(degree[i]);
	}
	return solution;
}

int main(){
	freopen( "input.txt", "r" , stdin);
	freopen( "output.txt", "w" , stdout);
	
	//edges
	int v;
	cin >> v;
	
	//nodes
	int n=204473;
	
	vector<int> adj[n+1];
	vector<int> arr(n+1);
	for(int i=0;i<=n;i++){
		arr[i]=0;
	}
	int count = 1;
	for(int i=0;i<v;i++){
		int x,y;
		cin >> x >> y;
		if(arr[x]==0){
			x=count;
			arr[x]=count;
			count++;
		}
		if(arr[y]==0){
			y=count;
			arr[y]=count;
			count++;
		}
		addEdge(adj,x,y);
	}
	
	vector<int> ver=cores(adj,n);
	for(int i=0;i<=n;i++){
		if(ver[i]==0)
			continue;
		cout << i << " - "<< ver[i]<< endl;
	}
	return 0;
}


//terminal - x-terminal-emulator -e "/bin/sh %c"

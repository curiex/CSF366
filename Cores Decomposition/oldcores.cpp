
#include <bits/stdc++.h>
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
	for (int i=1;i<=v;i++){
		solution.push_back(degree[i]);
	}
	return solution;
}

int main(){
	//vertices in graph
	int v=17;
	//graph declartaion
	vector<int> adj[v+1];
	
	//graph1
	//addEdge(adj,1,2);
	//addEdge(adj,1,3);
	//addEdge(adj,3,2);
	//addEdge(adj,3,4);
	//addEdge(adj,4,5);
	//addEdge(adj,5,6);
	//addEdge(adj,6,4);
	//graph2
	addEdge(adj,1,2);
	addEdge(adj,2,5);
	addEdge(adj,3,4);
	addEdge(adj,3,5);
	addEdge(adj,3,8);
	addEdge(adj,5,7);
	addEdge(adj,5,8);
	addEdge(adj,6,7);
	addEdge(adj,7,8);
	addEdge(adj,8,9);
	addEdge(adj,6,10);
	addEdge(adj,6,11);
	addEdge(adj,7,11);
	addEdge(adj,7,10);
	addEdge(adj,10,11);
	addEdge(adj,11,12);
	addEdge(adj,12,13);
	addEdge(adj,8,13);
	addEdge(adj,9,14);
	addEdge(adj,13,14);
	addEdge(adj,12,15);
	addEdge(adj,13,15);
	addEdge(adj,16,15);
	addEdge(adj,15,17);
	addEdge(adj,9,13);
	addEdge(adj,8,14);
	
	vector<int> ver=cores(adj,v);
	for(int i:ver)
		cout << i << " ";
	return 0;
}


//terminal - x-terminal-emulator -e "/bin/sh %c"

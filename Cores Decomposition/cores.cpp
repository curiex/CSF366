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

//calculates no of nodes in the graph
int size(vector<int> adj[]){

}

//degree of each vertex
int dov(vector<int> adj[],int degree[],int v){
	int max=adj[1].size();
	for(int i=1;i<=v;++i){
		degree[i]=adj[i].size();
		if(degree[i]>max){
			max=degree[i];
		}
	}
	return max;
}

int * cores(vector<int> adj[],int v){
	//int v = size(adj);
	
	//array with degree of every vertex
	int degree[v+1];
	
	//calculating degree of every vertex and also calculating maximum degree
	int md=dov(adj,degree,md);
	
	//now to sort according to the degree of each vertex in O(m) time
	int bin[v+1];
	for(int i=0;i<=v;i++){
		bin[i]=0;
	}
	for(int i=0;i<=v;++i){
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
		vert[pos[v]]=i;
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
			if(degree[u]>degree[v]){
				du=degree[u];
				pu=pos[u];
				pw=bin[du];
				w=vert[pw];
				if(u!=v){
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
	return degree;
}

int main(){
	//giving manual input for the vertices 
	//if a graph is provided this would not be required
	//size of the graph would then be calculated by size() function
	int v=6;
	//graph declartaion
	vector<int> adj[v+1];
	//testing graph
	//graph1
	addEdge(adj,1,2);
	addEdge(adj,3,2);
	addEdge(adj,3,4);
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,6,4);
	
	int* p;
	p=cores(adj,v);
	
	for(int i=1;i<=v;i++){
		cout << p[i] << " ";
	}
	
	return 0;
}

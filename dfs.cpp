#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void dfs_utils(int node, bool visited[], vector<int> &result);

public:
	//contructor
	Graph(int V);
	void add_edge(int u, int v);
	void dfs(int node);
	void print(void);
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph::add_edge(int u, int v){
	adj[u].push_back(v);
}

void Graph::dfs_utils(int node, bool visited[], vector<int> &result){
	if(!visited[node]){
		visited[node]=true;
		result.push_back(node);
		list<int>::iterator i;
		for(i=adj[node].begin();i!=adj[node].end();++i){
			dfs_utils(*i, visited, result);
		}
	}
}

void Graph::dfs(int node){
	bool *visited=new bool[V];
	vector<int> result;
	for(int i=0;i<V;++i){
		visited[i]=false;
	}
	dfs_utils(node, visited, result);
	cout<<"Depth first search from node:"<<node<<endl;
	for(int i=0;i<result.size();++i){
		cout<<result[i]<<" ";
	}cout<<endl;
}

void Graph::print(void){
	list<int>::iterator it;
	for(int i=0;i<V;++i){
		cout<<i<<":";
		for(it=adj[i].begin();it!=adj[i].end();++it){
			cout<<"->"<<*it;
		}cout<<endl;
	}cout<<endl;
}

int main(){
	//example #1
	Graph g(8);
	g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 4);
    g.add_edge(4, 7);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    g.add_edge(6, 7);
    g.add_edge(4, 5);

 
	//example #2
/*	Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
*/
    //g.print();
    g.dfs(0);

	return 0;
}
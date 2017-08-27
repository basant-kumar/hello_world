#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void bfs_utils(int start_node, bool visited[]);
public:
	Graph(int v);
	void add_edge(int u, int v);
	void bfs(int start_node);
	void print(void);
};

Graph::Graph(int V){
	this->V=V;
	adj= new list<int>[V];
}

void Graph::add_edge(int u, int v){
	adj[u].push_back(v);
}

void Graph::bfs_utils(int start_node, bool visited[]){
	queue<int> temp;
	temp.push(start_node);

	while(!temp.empty()){
		int node=temp.front();
		temp.pop();
		if(!visited[node]){
			visited[node]=true;
			cout<<node<<" ";
			
			list<int>::iterator it;
			for(it=adj[node].begin();it!=adj[node].end();++it){
					temp.push(*it);
			}
		}
	}cout<<endl;
}

void Graph::bfs(int start_node){
	bool *visited=new bool[V];
	for(int i=0;i<V;++i){
		visited[i]=false;
	}
	bfs_utils(start_node, visited);
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

    g.print();
    g.bfs(0);

/* 	Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.print();
    g.bfs(0);
*/

	return 0;
}
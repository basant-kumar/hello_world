#include<iostream>
#include<queue>
#include<utility>
#include<map>

#define pb push_back
#define ff first
#define ss second
#define mpa make_pair
using namespace std;
typedef long long LL;

using namespace std;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool valid(int x, int y, int N, int M) {
    if(x <= 0 || y <= 0 || x > N || y > M)
            return false;
    return true;
}
int bfs(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    
	int N = p3.ff;
    int M = p3.ss;
    queue<pair<pair<int, int>, int> > Que;
    map<pair<int, int>, bool> Vis;
        
    Que.push(mpa(p1, 0));

    while(!Que.empty()) {
    
	    pair<pair<int, int>, int> temp = Que.front();
	    Que.pop();

        if(temp.ff.ff == p2.ff && temp.ff.ss == p2.ss)
                return temp.ss;
        int x = temp.ff.ff;
        int y = temp.ff.ss;
        int dis = temp.ss + 1;


        if(Vis.count(mpa(x, y))){
            continue;
        }
        Vis[mpa(x, y)] = true;

        for(int i = 0; i < 8; ++i) {
           
		    int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(valid(x1, y1, N, M))
            Que.push(mpa(mpa(x1, y1), dis));
        }

    }

    return -1;
}


int min_step_to_reach(pair<int, int> &source, pair<int, int> &dest, pair<int, int> &size){
	int ans=bfs(source, dest, size);
	return ans;
}


int main(){
	int N=6,M=6;
	pair<int, int> source, dest, size;
	source=make_pair(4, 5);
	dest=make_pair(1, 1);
	size=make_pair(N,M);

	cout<<min_step_to_reach(source, dest, size)<<endl;

	return 0;
}
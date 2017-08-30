#include<iostream>
#include<vector>

using namespace std;

struct point{
	double x,y;
	point(){};
	point(double x, double y): x(x), y(y){};
};

int LEFT=-1, RIGHT=1, ON_THE_LINE=0;

double get_cross_product(point p1, point p2){
	//cout<<p1.x<<" "<<p1.y<<endl;
	//cout<<p2.x<<" "<<p2.y<<endl;
	return p1.x*p2.y - p1.y*p2.x;
}

point subtract(point p1, point p2){
	point res;
	res.x=p1.x - p2.x;
	res.y=p1.y - p2.y;
	return res;
}

int get_direction(point a, point b, point p){
	//cout<<a.x<<" "<<a.y<<endl;
	//cout<<b.x<<" "<<b.y<<endl;
	//cout<<p.x<<" "<<p.y<<endl;

	b=subtract(b,a);//cout<<b.x<<" "<<b.y<<endl;
	p=subtract(p,a);//cout<<p.x<<" "<<p.y<<endl;
	double cross_product=get_cross_product(b,p);

	if(cross_product > 0){
		return LEFT;
	}
	else if(cross_product < 0){
		return RIGHT;
	}
	else{
		return ON_THE_LINE;
	}
}


int main(){
	
	int res=get_direction(point(-30,10), point(29,-15), point(15,28));
	
	if(res==-1){
		cout<<"point is on the left of the line segment"<<endl;
	}
	else if(res==1){
		cout<<"point is on the right of the line segment"<<endl;
	}
	else{
		cout<<"point is on the line segment"<<endl;
	}

	return 0;
}
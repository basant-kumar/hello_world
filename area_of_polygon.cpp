#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct point{
	double x,y;
	point(){};
	point(double x, double y): x(x), y(y){};
};

double cross_product(point a, point b){
	return a.x*b.y - a.y*b.x;
}

double area_of_polygon(vector<point> &points, int n){
	double sum=0.0;
	for(int i=0;i<n;++i){
		sum+=cross_product(points[i], points[(i+1)%n]);
	}
	return abs(sum);
}

int main(){

	vector<point> points{point(1,2),point(3.3,4),point(2,6),point(-1,-2)}; //supported by c++11

	/*for(int i=0;i<n;++i){
		double x,y;
		cin>>x>>y;
		points.push_back(point(x,y));
	}*/
	cout<<"area of polygon is: ";
	cout<<area_of_polygon(points, points.size())<<endl;

	return 0;
}
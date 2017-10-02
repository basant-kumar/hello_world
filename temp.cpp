#include<iostream>
using namespace std;

class A
{
int x;
public:
A(int i) { x = i; }

void print() { cout<<"basant"<<endl; }
};


int main()
{
	A a;
	a.print();
	return 0;
}

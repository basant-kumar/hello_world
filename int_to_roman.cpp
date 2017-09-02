#include<iostream>
#include<string>

using namespace std;

string int_to_roman(int n){
	string M[]={"","M","MM","MMM"}; // 1000,2000,3000
	string C[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}; //100...900
	string X[]={"","X","XX","XXX","XL","LX","LXX","LXXX","XC"}; //10...90
	string I[]={"","I","II","III","IV","V","VI","VII","VIII","IX"}; //1...9
	return M[n/1000] + C[(n%1000)/100] + X[(n%100)/10] + I[(n%10)];
}


int main(){
	int n=15;
	cout<<int_to_roman(n)<<endl;

}
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;

void cross_off(vector<bool> &flags,int &prime){
	/*cross off remaining mutliples of prime. we can start with prime*prime, because if we have a k*prime,
		where k < prime, this value would've already been crossed off in a prior iteration.
	*/

	for(int i=prime*prime;i<flags.size();i+=prime){
		flags[i]=false;
	}

}

int get_next_prime(vector<bool> &flags,int &prime){
	int next=prime+1;
	while(next<flags.size() && !flags[next]){
		next++;
	}
	return next;
}

void sieve_of_eratosthenes(int & max){
	vector<bool> flags(max,true);
	
	flags[0]=false; flags[1]=false;
	int prime=2;
	while(prime<=sqrt(max)){

		cross_off(flags,prime);
		prime=get_next_prime(flags,prime);
	}
	for(int i=2;i<flags.size();++i){
		if(flags[i]==1){
			cout<<i<<" ";
		}
	}cout<<endl;
}


int main(){

	int n;
	cout<<"Enter the value of max number"<<endl;
	cin>>n;
	sieve_of_eratosthenes(n);


	return 0;
}
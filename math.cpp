#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

class Math{
	
	void find_digits_in_decimal(int n, vector<int> &res); 
	void decimal_to_binary(int n, vector<int> &res); 
	void print_digits(vector<int> &res); //Complexity O(n)
	void print_all_factors_of_number(int n, vector<int> &res);
	void print_all_prime_factors_of_number(int n, vector< pair<int, int> > &res);
	void print_power_of_number(vector< pair<int, int> > &res);


public:
	Math();
	~Math();
	void find_digits_in_decimal(int n); //Complexity O(# of digits)
	void decimal_to_binary(int n); //Complexity O(# of digits)
	bool is_prime(int n); //Complexity O(sqrt(n))
	void print_all_prime_number(int n); //Complexity O(n*log(log(n)))
	void print_all_factors_of_number(int n); //Complexity O(sqrt(n))
	void print_all_prime_factors_of_number(int n); //Complexity O(sqrt(n))
	int euclid_gcd(int a, int b); //Complexity O(log(b))
	int euclid_gcd_recursive(int a, int b); //Complexity O(log(b)) + Space O(log(b))

};

Math::Math(){
	cout<<endl<<"This class contains basic math programs which requires in programming."<<endl<<endl;
}

Math::~Math(){
	cout<<endl<<"Hi I am destroying every assigned or allocated memory from stack and heap."<<endl<<endl;
}

void Math::find_digits_in_decimal(int n, vector<int> &res){

	if(n==0){
		res.push_back(n);
		//return res;
	}
	while(n>0){
		int rem=n%10;
		res.push_back(rem);
		n=n/10;
	}
	reverse(res.begin(),res.end());
	//return res;
}

void Math::find_digits_in_decimal(int n){
	vector<int> res;
	find_digits_in_decimal(n, res);
	print_digits(res);
}

void Math::decimal_to_binary(int n, vector<int> &res){
	if(n==0){
		res.push_back(n);
	}
	while(n>0){
		int rem=n%2;
		res.push_back(rem);
		n=n/2;
	}
	reverse(res.begin(), res.end());
}

void Math::decimal_to_binary(int n){
	vector<int> res;
	decimal_to_binary(n, res);
	print_digits(res);
}

void Math::print_digits(vector<int> &res){
	cout<<"Number is: ";
	for(int i=0;i<res.size();++i){
		cout<<res[i];
	}cout<<endl;
	for(int i=0;i<res.size();++i){
		cout<<i+1<<" digit: "<<res[i]<<endl;
	}
}

bool Math::is_prime(int n){
	if(n<2){
		return false;
	}
	for(int i=2;i<=sqrt(n);++i){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void Math::print_all_prime_number(int n){

	//sieve of eratosthenes algorithm
	vector<int> arr(n+1,1);
	arr[0]=0;
	arr[1]=0;
	for(int i=2;i<=sqrt(n);++i){
		if(arr[i]==1){
			for(int j=2;i*j<n;++j){
				arr[i*j]=0;
			}
		}
	}

	for(int i=2;i<n;++i){
		if(arr[i]==1){
			cout<<i<<" ";
		}
	}cout<<endl;
}

void Math::print_all_factors_of_number(int n, vector<int> &res){

	
	if(n<2){
		res.push_back(n);
		return;
	}
	res.push_back(1);
	for(int i=2;i<=sqrt(n);++i){
		if(n%i==0){
			res.push_back(i);
		}
	}
	for(int i=res.size()-1;i>=0;--i){
		if(n/res[i] > sqrt(n)){
			res.push_back(n/res[i]);
		}
	}
}

void Math::print_all_factors_of_number(int n){
	vector<int> res;
	print_all_factors_of_number(n, res);
	for(int i=0;i<res.size();++i){
		cout<<res[i]<<" ";
	}cout<<endl;
}

void Math::print_all_prime_factors_of_number(int n, vector< pair<int, int> > &res){
	for(int i=2;i<=sqrt(n);++i){
		if(n%i==0){
			int count=0;
			while(n%i==0){
				n=n/i;
				count++;
			}
			res.push_back(make_pair(i,count));
		}
	}
	if(n!=1){
		res.push_back(make_pair(n,1));
	}
}


void Math::print_all_prime_factors_of_number(int n){
	vector< pair<int, int> > res;
	print_all_prime_factors_of_number(n, res);
	print_power_of_number(res);
}

void Math::print_power_of_number(vector< pair<int, int> > &res){
	cout<<"******************************************"<<endl;
	for(int i=0;i<res.size();++i){
		cout<<" "<<res[i].second;
		cout<<" ";
	}cout<<endl;
	for(int i=0;i<res.size();++i){
		cout<<res[i].first<<", ";
	}cout<<endl;
	cout<<"******************************************"<<endl;
}

int Math::euclid_gcd(int a, int b){
	while(b!=0){
		int rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}

int Math::euclid_gcd_recursive(int a, int b){
	return b==0 ? a : euclid_gcd_recursive(b,a%b);
}

int main(){

	Math m;
	//m.find_digits_in_decimal(125);
	//m.decimal_to_binary(125);
	//cout<<"Is 12 prime :"<<m.is_prime(12)<<endl;
	//m.print_all_prime_number(25);
	//m.print_all_factors_of_number(36);
	m.print_all_prime_factors_of_number(36);
	cout<<"gcd(400,124):"<<m.euclid_gcd(400, 124)<<endl;
	cout<<"gcd(400,124):"<<m.euclid_gcd_recursive(400, 124)<<" using recursion"<<endl;

	return 0;
}
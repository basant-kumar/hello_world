#include<iostream>
#include<vector>

using namespace std;

const int MAX_VAL=1000001;

void update_bit(int i, int add, vector<int> &bit){
	
	while(i>0 && i<bit.size()){
		bit[i]+=add;
		i+= i & (-i);
	}
}

int get_sum(int i, vector<int> &bit){
	int sum=0;
	while(i>0){
		sum+=bit[i];
		i-= i &(-i);
	}
	return sum;
}

int find_kth_smallest_element(int k, vector<int> &bit){
	int l=0;
	int h=bit.size();
	while(l<h){
		int mid=(l+h)/2;
		if(k<=get_sum(mid, bit)){
			h=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}


void insert_element(int x, vector<int> &bit){
	update_bit(x, 1, bit);
}

void delete_element(int x, vector<int> &bit){
	update_bit(x, -1, bit);
}

int find_rank(int x, vector<int> &bit){
	return get_sum(x, bit);
}

int main(){
	vector<int> BIT(MAX_VAL);
	insert_element(20, BIT);
	insert_element(50, BIT);
	insert_element(30, BIT);
	insert_element(40, BIT);

	cout << "2nd Smallest element is "
     << find_kth_smallest_element(2, BIT) << endl;
 
    cout << "Rank of 40 is "
         << find_rank(40, BIT) << endl;
 
    delete_element(40, BIT);
 
    cout << "Rank of 50 is "
         << find_rank(50, BIT) << endl;

	return 0;
}
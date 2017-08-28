#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int no_of_rooms_needed(vector<int> &arrival, vector<int> &departure){
	int size=arrival.size();
	int a_idx=0,d_idx=0;
	sort(arrival.begin(),arrival.end());
	sort(departure.begin(), departure.end());
	int max_so_far=0, curr=0;
	while(a_idx<size){
		if(arrival[a_idx]<departure[d_idx]){
			a_idx++;
			curr++; //someone needs a room
			max_so_far=max(curr,max_so_far);
		}
		else{
			d_idx++;
			curr--; //someone vacates a room
		}
	}
	return max_so_far;
}


bool booking_possible(vector<int> &arrival, vector<int> &departure, int rooms_available){
	return rooms_available >= no_of_rooms_needed(arrival, departure);
}

int main(){

	vector<int> arrival={1,3,5};
	vector<int> departure={2,6,8};
	int rooms_available=1;

	if(booking_possible(arrival, departure, rooms_available)){
		cout<<"hotel booking is possible"<<endl;
	}
	else{
		cout<<"hotel booking not possible"<<endl;
	}

	return 0;
}
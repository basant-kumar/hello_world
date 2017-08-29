#include<iostream>

using namespace std;

void print_pascal_with_extra_space(int n){
	int arr[n][n]; 

	// Iterate through every line and print integer(s) in it
	for(int line = 0; line < n; line++){
		// Every line has number of integers equal to line number
		for(int i = 0; i <= line; i++){
			// First and last values in every row are 1
			if(line == i || i == 0){
				arr[line][i] = 1;
			}
			else{
				// Other values are sum of values just above and left of above
				arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
			} 
			cout<<arr[line][i]<<" ";
		}cout<<endl;
	}
	
}

void print_pascal(int n){
	for(int line=1;line<=n;++line){
		int c=1;
		for(int i=1;i<=line;++i){
			cout<<c<<" ";
			c=c * (line-i) / i;
		}cout<<endl;
	}
}

int main(){

	int n=7;
	//print_pascal_with_extra_space(n);
	print_pascal(n);

	return 0;
}
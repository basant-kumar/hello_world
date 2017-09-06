#include<iostream>

using namespace std;

class Heap{
	
public:

	int size=0;
	int capacity=10;
	int *items = new int[capacity];


	Heap(){
		cout<<"Heap: Hey, I am heap. what you got?"<<endl;
	}
	~Heap(){
		cout<<"Heap: Ouch !!, What happened ?!, Where are you going ?."<<endl;
	}

	int get_left_child_index(int parent_index){ return 2*parent_index + 1; }
	int get_right_child_index(int parent_index){ return 2*parent_index + 2; }
	int get_parent_index(int child_index){ return (child_index-1)/2; }

	bool has_left_child(int index){ return get_left_child_index(index) < size; }
	bool has_right_child(int index){ return get_right_child_index(index) < size; }
	bool has_parent(int index){ return get_parent_index(index) >= 0 ;}

	int left_child(int index){ return items[get_left_child_index(index)]; }
	int right_child(int index){ return items[get_right_child_index(index)]; }
	int parent(int index){ return items[get_parent_index(index)]; }

	void swap(int idx1, int idx2){
		int temp=items[idx1];
		items[idx1]=items[idx2];
		items[idx2]=temp;
	}

	void ensure_extra_capacity(){
		if(size==capacity){
			int *temp = new int[2*capacity];
			//copy(begin(items), end(items), begin(temp));
			for(int i=0;i<size;++i){
				temp[i]=items[i];
			}
			delete[] items;
			items=temp;
			capacity=2*capacity;
		}
	}

	
};

class MinHeap: public Heap{
public:
	MinHeap(){ cout<<"MinHeap: Hi, My name is MinHeap and I am in your service."<<endl<<endl; }
	~MinHeap(){ cout<<endl<<"MinHeap: Hey, It was good to work with you. :)"<<endl; }
	
	int top(){
		if(size==0){
			cout<<"MinHeap: Panic: MinHeap Empty !!"<<endl<<endl;
			exit(0);
		}
		return items[0];
	}

	int pop(){
		if(size==0){
			cout<<"MinHeap: Panic: MinHeap Empty !!"<<endl<<endl;
			exit(0);
		}
		int item=items[0];
		items[0]=items[size-1];
		size--;
		heapify_down();
		return item;
	}

	int push(int item){
		ensure_extra_capacity();
		items[size]=item;
		size++;
		heapify_up();
	}

	void heapify_up(){
		int index=size-1;
		while(has_parent(index) && items[get_parent_index(index)] > items[index]){
			swap(get_parent_index(index), index);
			index=get_parent_index(index);
		}
	}

	void heapify_down(){
		int index=0;
		while(has_left_child(index)){
			int smaller_child_index=get_left_child_index(index);
			if(has_right_child(index) && items[get_right_child_index(index)] < items[smaller_child_index]){
				smaller_child_index=get_right_child_index(index);
			}

			if(items[index] < items[smaller_child_index]){
				break;
			}
			else{
				swap(index, smaller_child_index);
			}
			index=smaller_child_index;
		}
	}

};


int main(){

	MinHeap m;
	m.push(10);
	m.push(15);
	m.push(20);
	m.push(17);
	m.push(25);
	cout<<m.top()<<endl;
}


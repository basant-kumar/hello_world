#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

struct node *root=NULL;

struct node *new_node(int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node *insert(struct node *node, int data){
	if(node==NULL){
		//root = new_node(data);
		return new_node(data);
	}

	if(data < node->data){
		node->left=insert(node->left, data);
	}
	else{
		node->right=insert(node->right, data);
	}
	return node;
}

void in_order(struct node *root){
	if(root!=NULL){
		in_order(root->left);
		cout<<root->data<<" ";
		in_order(root->right);	
	}
}

void pre_order(struct node *root){
	if(root!=NULL){
		cout<<root->data<<" ";
		pre_order(root->left);
		pre_order(root->right);	
	}
}

void post_order(struct node *root){
	if(root!=NULL){
		post_order(root->left);
		post_order(root->right);
		cout<<root->data<<" ";	
	}
}

struct node* minimal_bst_utils(vector<int> &arr, int start, int end){
	if(end<start){
		return NULL;
	}
	struct node *node; 
	int mid=(start+end)/2;
	//cout<<arr[mid]<<endl;
	node=new_node(arr[mid]);	
	node->left=minimal_bst_utils(arr,start,mid-1);
	node->right=minimal_bst_utils(arr,mid+1,end);
	return node;
}

void minimal_bst(vector<int> &arr){
	int size=arr.size();
	root=minimal_bst_utils(arr, 0, size-1);
}


int main(){

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	minimal_bst(arr);


/*
	struct node *root=NULL;
	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
*/
    in_order(root);cout<<endl;
    pre_order(root);cout<<endl;
    post_order(root);cout<<endl;

	return 0;
}
#include<iostream>
#include<cstdlib>
#include<queue>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

class BST{
	node *root;
	void destroy_tree(node *leaf);
	void insert(int data, node* leaf);
	node *search(int data, node* leaf);
	void display(node *root, int level);
	void in_order(node *root);
	void pre_order(node *root);
	void post_order(node *root);
	void print_level_order(node *root);;
	bool is_balanced(node *root);
	int check_height(node *root);
	int get_height(node *root);
	bool is_tree_BST(node *root, int min, int max);

public:
	BST();
	~BST();
	void insert(int data);
	node *search(int data);
	void destroy_tree();
	void display();
	void in_order();
	void pre_order();
	void post_order();
	void print_level_order();
	bool is_balanced();
	int get_height();
	bool is_tree_BST();
	

};

BST::BST(){
	cout<<"BST created"<<endl;
	root=NULL;
}

BST::~BST(){
	cout<<"BST destroyed"<<endl;
	destroy_tree();
}

void BST::destroy_tree(node *leaf){
	if(leaf!=NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BST::destroy_tree(){
	destroy_tree(root);
}

void BST::insert(int data,struct node *leaf){
	if(data < leaf->data){
		if(leaf->left !=NULL){
			insert(data, leaf->left);
		}
		else{
			leaf->left=new node;
			leaf->left->data=data;
			leaf->left->left=NULL;
			leaf->left->right=NULL;
		}
	}
	else if(data >= leaf->data){
		if(leaf->right !=NULL){
			insert(data, leaf->right);
		}
		else{
			leaf->right=new node;
			leaf->right->data=data;
			leaf->right->left=NULL;
			leaf->right->right=NULL;
		}
	}
}

void BST::insert(int data){
	if(root!=NULL){
		insert(data, root);
	}
	else{
		root= new node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
}

node *BST::search(int data, node *leaf){
	if(leaf!=NULL){
		if(data==leaf->data){
			return leaf;
		}
		if(data < leaf->data){
			search(data, leaf->left);
		}
		else{
			search(data, leaf->right);
		}
	}
	else return NULL;
}

node *BST::search(int data){
	return search(data, root);
}


void BST::display(node *node, int level){
	
	if(node!=NULL){
		display(node->right, level+1);
		cout<<endl;
		if(node==root){
			cout<<"Root->:  ";
		}
		else{
			for(int i=0;i<level;++i){
				cout<<"       ";
			}				
		}
		cout<<node->data;
		display(node->left, level+1);
	}
}

void BST::display(){
	display(root,1);
	cout<<endl;
}

void BST::in_order(node *node){
	if(node!=NULL){
		in_order(node->left);
		cout<<node->data<<" ";
		in_order(node->right);
	}
}

void BST::in_order(){
	in_order(root);
	cout<<endl;
}

void BST::pre_order(node *node){
	if(node!=NULL){
		cout<<node->data<<" ";
		pre_order(node->left);
		pre_order(node->right);
	}
}

void BST::pre_order(){
	pre_order(root);
	cout<<endl;
}

void BST::post_order(node *node){
	if(node!=NULL){
		post_order(node->left);
		post_order(node->right);
		cout<<node->data<<" ";
	}
}

void BST::post_order(){
	post_order(root);
	cout<<endl;
}

void BST::print_level_order(node *root){
	if(root==NULL) return;

	queue<node*> q;
	q.push(root);

	while(1){
		int node_count=q.size();
		if(node_count==0){
			break;
		}
		while(node_count>0){
			node *temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
			node_count--;
		}
		cout<<endl;
	}
}

void BST::print_level_order(){
	print_level_order(root);
}

int BST::check_height(node *node){
	if(node==NULL){
		return 0;
	}

	int left_height = check_height(node->left);
	if(left_height==INT_MIN){
		return INT_MIN;
	}
	int right_height = check_height(node->right);
	if(right_height==INT_MIN){
		return INT_MIN;
	}
	int height_diff= left_height - right_height;
	if(height_diff>1){
		return INT_MIN;
	}
	else{
		return max(left_height, right_height) + 1;
	}
}

bool BST::is_balanced(){
	return is_balanced(root);
}

bool BST::is_balanced(node *node){
	return check_height(node) != INT_MIN;
}

int BST::get_height(){
	return get_height(root);
}

int BST::get_height(node *node){
	if(node==NULL){
		return 0;
	}
	return max( get_height(node->left), get_height(node->right) ) + 1;
}

bool BST::is_tree_BST(){
	return is_tree_BST(root, INT_MIN, INT_MAX);
}

bool BST::is_tree_BST(node *node, int min, int max){
	if(node==NULL){
		return true;
	}
	if(min!=INT_MIN && node->data <= min || max!=INT_MAX && node->data > max){
		return false;
	}
	if(!is_tree_BST(node->left, min, node->data) || !is_tree_BST(node->right, node->data, max)){
		return false;
	}
	return true;
}

int main(){

	BST bst;
	bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.display();
    bst.in_order();
    bst.pre_order();
    bst.post_order();
    node* res=bst.search(40);
    cout<<"Found the node with value: "<<res->data<<endl;
    bst.print_level_order();
    cout<<"Is Balanced: "<<bst.is_balanced()<<endl;
    cout<<"Height of BST is: "<<bst.get_height()<<endl;
    cout<<"Is Tree BST: "<<bst.is_tree_BST()<<endl;

	return 0;
}


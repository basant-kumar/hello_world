#include<iostream>
#include<unordered_map>

using namespace std;

struct Trie{
	bool is_leaf;
	unordered_map<char, Trie*> map;
};

Trie* get_node(void){
	Trie *p=new Trie;
	p->is_leaf=false;
	return p;
}

void insert(Trie* &root, char *key){
	if(root==NULL){
		root=get_node();
	}
	Trie *curr=root;

	while(*key){
		if(curr->map.find(*key)==curr->map.end()){
			curr->map[*key]=get_node();
		}
		curr=curr->map[*key];
		key++;
	}
	curr->is_leaf=true;
}

bool have_children(Trie *node){

	for(auto it: node->map){
		if(it.second!=NULL){
			return true;
		}
	}
	return false;
}

bool deletion(Trie* &root, char *key){
	//return if trie is empty
	if(root==NULL){
		return false;
	}

	if(*key){
		//recurse for the node curresponding to next character in
		//string and if it return true, delete current node if it is not leaf
		if(root!=NULL && root->map.find(*key)!=root->map.end() && 
			deletion(root->map[*key], key+1) && root->is_leaf==false){

			if(!have_children(root)){
				delete root;
				root=NULL;
				return true;
			}
			else{
				return false;
			}
		}
	}
	// if we have reached the end of the string
	if(*key=='\0' && root->is_leaf){
		//if current node is leaf and don't  have any children
		if(!have_children(root)){
			delete root; //delete current node
			root=NULL;
			return true; //delete non leaf parent node
		}
		//if current node is leaf and have children
		else{
			//mark current node as non-leaf (don't delete it)
			root->is_leaf=false;
			return false; //don't delete its parent node
		}
	}

	return false;
}

bool search(Trie *root, char *key){
	if(root==NULL){
		return false; // return false if trie is empty
	}

	Trie *curr=root;
	while(*key){
		curr=curr->map[*key];
		if(curr==NULL){
			return false;
		}
		key++;
	}
	return curr->is_leaf;
}

int main(){

	Trie *root=NULL;
	insert(root, "hello");
	search(root, "hello") ? cout<<"hello:yes"<<endl : cout<<"hello:no"<<endl;
	insert(root, "helloworld");
	search(root, "helloworld") ? cout<<"helloworld:yes"<<endl : cout<<"helloworld:no"<<endl;
	search(root, "hellowrld") ? cout<<"hellowrld:yes"<<endl : cout<<"hellowrld:no"<<endl;
	insert(root, "hell");
	search(root, "hell") ? cout<<"hell:yes"<<endl : cout<<"hell:no"<<endl;
	insert(root, "h");
	search(root, "h") ? cout<<"h:yes"<<endl : cout<<"h:no"<<endl;
	
	deletion(root,"hello");
	search(root, "hello") ? cout<<"hello:yes"<<endl : cout<<"hello:no"<<endl;
	search(root, "helloworld") ? cout<<"helloworld:yes"<<endl : cout<<"helloworld:no"<<endl;
	search(root, "hell") ? cout<<"hell:yes"<<endl : cout<<"hell:no"<<endl;
	
	deletion(root,"h");
	search(root, "h") ? cout<<"h:yes"<<endl : cout<<"h:no"<<endl;
	search(root, "helloworld") ? cout<<"helloworld:yes"<<endl : cout<<"helloworld:no"<<endl;
	search(root, "hell") ? cout<<"hell:yes"<<endl : cout<<"hell:no"<<endl;

	deletion(root,"helloworld");
	search(root, "helloworld") ? cout<<"helloworld:yes"<<endl : cout<<"helloworld:no"<<endl;
	search(root, "hell") ? cout<<"hell:yes"<<endl : cout<<"hell:no"<<endl;

	deletion(root,"hell");
	search(root, "hell") ? cout<<"hell:yes"<<endl : cout<<"hell:no"<<endl;

	if(root==NULL){
		cout<<"trie is empty"<<endl;
	}

	search(root, "hello") ? cout<<"hello:yes"<<endl : cout<<"hello:no"<<endl;



	return 0;
}
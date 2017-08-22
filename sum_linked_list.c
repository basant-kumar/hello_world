#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1=NULL;
struct node *head2=NULL;

void create_linked_list(int n){
	struct node *p=(struct node*)malloc(sizeof(struct node));
	int i;
	head2=p;
	for(i=0;i<n-1;++i){
		printf("Enter the %d node data\n",i+1);
		scanf("%d",&p->data);
		p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
	}
	printf("Enter the %d node data\n",i+1);
	scanf("%d",&p->data);
	p->next=NULL;
}

void display(struct node *head){
	struct node *p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}printf("\n");
}


int main(){
	int m,n;
	printf("Enter the size of first linked list\n");
	scanf("%d",&m);
	create_linked_list(m);

	head1=head2;

	printf("Enter the size of second linked list\n");
	scanf("%d",&n);
	create_linked_list(n);
	display(head1);
	display(head2);


	return 0;
}
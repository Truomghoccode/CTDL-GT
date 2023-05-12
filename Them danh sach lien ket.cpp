#include<stdio.h> 
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
}node;

int main(){
	int n ; printf("nhap gioi han cho danh sach: ") ;scanf("%d",&n);
	
	node *head , *newnode;
	head = NULL;
	newnode =(node*)malloc(sizeof(node));
	head = newnode;
	printf("Nhap gia tri cho danh sach:\n");
	scanf("%d",&newnode->data);
	//printf("%d",newnode->data);
	
	for(int i = 1 ; i < n; i++){
		newnode -> next = (node*)malloc(sizeof(node));
		newnode = newnode->next;
		scanf("%d",&newnode->data);
	}
	newnode->next = NULL;
	
	
	int k ;printf("Vi tri muon chen: ");scanf("%d",&k);
	node*cur = head;
	node *new_node = (node*)malloc(sizeof(node));
	printf("Nhap gia tri muon chen: ");scanf("%d",&new_node->data);
	
	if(k == n+1){
		for(int i = 1 ; i < k-1 ; i++) cur = cur->next;
		new_node->next = cur->next;
		cur->next = new_node;
	}
	else if(k == 1){
		new_node ->next = head;
		head = new_node;
	}
	else if(k > 1 && k < n+1){
		for(int i = 1 ; i < k - 1 ; i++) cur = cur-> next;
		new_node -> next = cur->next;
		cur -> next= new_node;
	}
	
	printf("Danh sach sau khi chen: ");
	cur = head;
	for(int i = 0 ; i <=n ; i++){
		printf("%d ",cur->data);
		cur = cur->next;
	}
}

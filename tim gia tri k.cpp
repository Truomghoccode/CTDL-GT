#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
}node;

int main() {
	int n ; printf("Nhap gioi han cho danh sach: "); scanf("%d",&n);
	
	node* head = NULL, *newnode;
	newnode =(node *) malloc(sizeof(node));
	head = newnode;
	scanf("%d",&newnode->data);
	
	for(int i = 1 ; i < n-1 ; i++ ){
		newnode -> next =(node *)malloc(sizeof(node));
		newnode = newnode->next;
		scanf("%d",&newnode->data);
	}
	newnode -> next =(node *)malloc(sizeof(node));
	newnode =newnode->next;
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	
	node *tim = NULL;
	newnode =(node *) malloc(sizeof(node));
	tim = newnode;
	printf("Nhap gia tri can tim:");scanf("%d",&newnode->data);
	node *cur = head;
	
	if(tim -> data == cur -> data){
	printf("Gia tri can tim o head");
	}
	else if(tim -> data != cur -> data){
		int dem = 0;
		for(int i = 0 ; i < n; i++){
		if(tim ->data == cur ->data){
			printf("Da tim duoc gia tri can tim");
			dem++;
			}
			cur = cur->next;
		}
		 if(dem == 0)printf("Khong tim thay gia tri can tim");
	}
}
	
	

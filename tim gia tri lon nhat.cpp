#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node* next;
} node;

int main(){
	//nhap gioi han cho danh sach lien ket
	int n ; printf("Nhap gioi han danh sach: "); scanf("%d",&n);
	
	// tao head bang null
	node* head = NULL, *newnode; 
	
	//tao node moi
	
	//cap phat bo nho
	newnode =(node *) malloc(sizeof(node));
	
	//nhap gia tri cho head
	head = newnode;
	scanf("%d",&newnode->data);
	
	//tao for de nhap cac node con lai
	for(int i = 1 ; i < n-1 ; i++){
		//cap phat bo nho cho node tiep theo
		newnode -> next=(node *)malloc(sizeof(node));
		newnode = newnode ->next;
		
		//nhap phan tu cho node moi
		scanf("%d",&newnode->data);
	}
	// nhap phan tu cho node cuoi
	newnode -> next=(node *)malloc(sizeof(node));
	newnode = newnode ->next;
	scanf("%d",&newnode->data);
	
	//tao node NULL cuoi;
	newnode ->next = NULL;
	
	//tao node MAX  d
	node *cur = head;
	node *max = head;
	
	//so sanh lan luot cac phan tu trong danh sach 
	for(int i = 2 ; i <= n ; i++){
	//chi toi cur tiep theo
	cur = cur->next;
	//dat dieu kien neu tim ra gia tri lon hon max
	if(cur->data > max->data) max->data = cur->data;
	}
	printf(" gia tri lon nhat trong danh sach la: %d ",max->data);
	return 0;
}

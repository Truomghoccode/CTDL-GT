#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
} node;
int main(){
	
	//nhap gioi han cho danh sach lien ket
	int n ; printf("Nhap gioi han danh sach: "); scanf("%d",&n);
	
	// tao head bang null
	node* head = NULL;
	node *newnode; 
	
	//cap phat bo nho
	newnode =(node *) malloc(sizeof(node));
	
	//nhap gia tri cho head
	head = newnode;
	scanf("%d",&newnode->data);
	
	//tao for de nhap cac node con lai
	for(int i = 1 ; i <= n-1 ; i++){
		//cap phat bo nho cho node tiep theo
		newnode -> next=(node *)malloc(sizeof(node));
		newnode = newnode ->next;
		
		//nhap phan tu cho node moi
		scanf("%d",&newnode->data);
	}
	
	//tao node NULL cuoi;
	newnode ->next = NULL;
	
	//tao node cur de nhan gia tri dau
	node *cur = head;
	// in node cur dau
	printf("gia tri dau cua danh sach la: %d\n",cur->data);
	
	//in lan luot cac cur con lai
	for(int i = 2 ; i <= n ; i++){
	cur = cur->next;
	printf("gia tri thu %d cua danh sach la: %d\n",i,cur->data);
	}
	
}

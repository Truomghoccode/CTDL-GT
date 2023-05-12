#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

int main(){
	int n ;
	printf("Nhap so luong phan tu cho danh sach lien ket:");
	scanf("%d",&n);
	node *head , *newnode;
	newnode =(node*)malloc(sizeof(node));
	head =newnode;
    printf("Nap phan tu cho danh sach lien ket:\n");
	scanf("%d",&newnode->data);
    for(int i = 1 ; i < n ; i++){
        newnode->next=(node*)malloc(sizeof(node));
        newnode = newnode->next;
        scanf("%d",&newnode->data);
    }
    newnode->next = NULL;
    node *tmp = head;
   int k ; printf("1: xoa dau\n2: xoa cuoi\n3: bo qua\n4 : lua chon vi tri muon xoa\n");scanf("%d",&k);
    
   if(k == 1){
    head = head ->next; // chuyen vi tri node head sang node head ke tiep
    free(tmp);
   }
   else if(k == 2){
    while(tmp->next->next != NULL){
        tmp = tmp -> next; //chuyen node den node cuoi - 1
    }
    node *xoa = tmp ->next; // luu dia chi node cuoi
    tmp -> next = NULL; // chi dia chi node cuoi sang null
    free(xoa); // xoa node
   }
   else if(k == 4){
    int a ; printf("vi tri muon xoa la:");scanf("%d",&k);
    for(int i = 1 ; i < k -1 ; i++){
        tmp = tmp -> next; // chuyen node den truoc node muon xoa
        }
        node *xoa = tmp ->next; // luu dia chi node muon xoa 
        tmp -> next = tmp -> next -> next; // noi node truoc vi tri xoa va sau vi tri xoa
        free(xoa); // xoa node
    }
   node *cur = head;
   for(int i = 0 ; i < n ; i++){
    printf("%d ",cur->data);
    cur = cur->next;
}
}
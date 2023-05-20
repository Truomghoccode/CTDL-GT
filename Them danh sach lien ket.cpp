#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *newnode(int x){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void in(node *head, int n){
    node *cur = head;
    for(int i = 0 ; i < n ; i++){
        printf("%d ",cur->data);
        cur = cur ->next;
    }   
}

void them(node **head , int n , int k){
    node *cur = *head ;
    node *nnode =(node*)malloc(sizeof(node));
    printf("Nhap gia tri muon chen: ");scanf("%d",&nnode->data);
    if(k == 1){
        nnode->next = cur;
        *head = nnode;
    }
    else if(k == n+1){
        for(int i = 0 ; i < n-1 ; i++){
            cur = cur->next;
        }
        cur->next = nnode;
        cur->next->next = NULL;
    }
    else if(k > 1 && k <= n){
        for(int i = 1 ; i < k-1 ; i++){
            cur = cur ->next;
        }
        nnode->next = cur->next ;
        cur->next = nnode;
    }
}

int main(){
    int x;
    node *head = NULL,*new_node,*last_node;
    int n ; printf("Nhap so luong phan tu trong cay: ");scanf("%d",&n);
    printf("Nap phan tu cho dslk: \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&x);
        new_node = newnode(x);
         // kiem tra node dau 
        if(head == NULL){ //head = NULL
            head = new_node;// nap gia tri cho head 
            last_node = new_node;// cap nhat gia tri cho con tro
        }
        else{ // head da co gia tri
            last_node->next = new_node;// cap nhat gia tri node tiep theo
            last_node = new_node;
        }

    }
    int k ; printf("nhap vi tri muon them phan tu: ");scanf("%d",&k);
    them(&head,n,k);
    printf("Danh sach phan tu: \n");
    in(head,n);
}

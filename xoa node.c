#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *newnode(int x){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void in(node *head){
    node *cur = head;
    while(cur != NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    }
}

void xoa(node **head , int k){
    node *cur = *head;
    if(k == 0){
        *head = cur->next;
        free(cur);
    }
    else{
        for(int i = 0 ; i < k-1 ; i++){
            cur = cur->next;
        }
        node *xoa = cur->next;
        cur->next = cur->next->next;
        free(xoa);
    }
}

int main(){
    int x ;
    int n ; scanf("%d",&n);
    node *head = NULL , *last_node , *new_node;
    for(int i = 0; i < n ; i++){
        scanf("%d",&x);
        new_node = newnode(x);
        if(head == NULL){
            head = new_node;
            last_node = new_node;
        }
        else{
            last_node->next = new_node;
            last_node = new_node;
        }
    }
    int k;scanf("%d",&k);
    xoa(&head,k);
    in(head);
}

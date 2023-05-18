#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *trai;
    struct tree *phai;
}tree;

tree *createnode(int data){ //khoi tao cay
    tree *newnode;
    newnode = (tree*)malloc(sizeof(tree)); //cap phat bo nho cho cay
    newnode -> data = data;
    newnode -> trai = NULL;
    newnode -> phai = NULL;
    return newnode;
}

tree *insert(tree *goc, int data){
    if(goc == NULL)
        goc = createnode(data);
    else if(data < goc->data)
        goc->trai = insert(goc->trai, data);
    else
        goc->phai = insert(goc->phai, data);
    return goc;
}

void NLR(tree *goc)
{
    if (goc != NULL)
    {
        printf("%d ", goc->data);
        NLR(goc->trai);
        NLR(goc->phai);
    }
}

int main(){
    int n ;scanf("%d",&n);
    tree *goc = NULL , *newnode;
    int data , x;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&data);
        goc = insert(goc, data);
    }
    NLR(goc);
}
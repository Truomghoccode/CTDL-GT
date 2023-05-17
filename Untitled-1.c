#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef struct cuahang{
    char ten[100];
    char ma[100];
    int gia;
    int slg;
}ch;

void nhap(ch *a){
    printf("Nhap ten hang: ");
    fgets(a->ten, 100, stdin);
    a->ten[strcspn(a->ten, "\n")] = 0;
    printf("Nhap ma hang: ");
    fgets(a->ma, 100, stdin);
    a->ma[strcspn(a->ma, "\n")] = 0;
    printf("Nhap gia hang: ");
    scanf("%d",&a->gia);
    printf("Nhap so luong hang: ");
    scanf("%d",&a->slg);
    getchar();
}

void sapxep(ch *a, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(a[i].ma,a[j].ma) > 0){
                ch temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void indanhsach(ch *a, int n){
    printf("Danh sach cac mat hang co tong gia tri ban > 500000:\n");
    for(int i=0;i<n;i++){
        if(a[i].gia*a[i].slg > 500000){
			printf("+-----+-----------+------------------+------------+-----------------+\n");
			printf("| STT |	 Ma hang  |   Ten hang hoa   |  Gia hang  |  So luong hang  |\n");
			printf("+-----+-----------+------------------+------------+-----------------+\n");
			printf("| %d | %s | %s | %d | %d |\n",i+1,a[i].ma,a[i].ten,a[i].gia,a[i].slg);
			printf("+-----+-----------+------------------+------------+-----------------+\n");
			}
        }
    }

int main(){
    ch a[1000];
    int i = 0;
    while(1){
        nhap(&a[i]);
        if(strcmp(a[i].ten,"***") == 0) break;// neu nhap *** thi se dung lai viec nhap
        i++;
    }
    sapxep(a,i);
    indanhsach(a,i);
}
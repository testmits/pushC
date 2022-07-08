#include <stdio.h>
#include <conio.h>
 
int tinhTong(int mang[], int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        if( mang[i]%3 == 0){
            tong = tong + mang[i];
        }
    }
    return tong;
}
 
main(){
    int a[100], n, tg;
 
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    printf("\nNhap day so");

    for(int i = 0; i < n; i++){
        printf("\nSo thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
 
    tg = tinhTong(a, n);
 
    printf("\nTong cac so chia het cho 3 la %d", tg);
    getch();
}

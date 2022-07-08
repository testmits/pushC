#include "stdio.h"
void bai1();
void bai2();
void bai3();
void bai4();

int main() {
	int so;
	printf("1: Chuong trinh tinh trung binh tong cac so chia het cho 3 trong mang:\n");
	printf("2: Chuong trinh tim max, min trong mang:\n");
	printf("3: Chuong trinh sap xep mang theo thu tu giam dan:\n");
	printf("4: Chuong trinh tinh binh phuong cac phan tu trong mang hai chieu:\n");
	printf("Moi chon truong trinh(1-->4):\n");
	scanf("%d",&so);
	
	switch(so) {
		case 1:
			bai1();
			break;
		case 2:
			bai2();
			break;
		case 3:
			bai3();
			break;
		case 4:
			bai4();
			break;
		default:
			printf("\Ban da chon sai chuong trinh");
			break;
	}
}
void bai1() {
	int n,i;
	int a[100];
	printf("Nhap vao so gia tri cua mang:");
	scanf("%d",&n);
	printf("\nNhap vao gia tri cua mang:");
	for(i=0; i<n; i++) {
		printf("\nGia tri thu %d :",i);
		scanf("%d",&a[i]);
	}
	printf("\ngia tri cua mang la:");
	for(i=0; i<n; i++) {
		printf(" %5d",a[i]);
	}
	int tong=0, dem =0;
	float tb;
	for(i=0; i<n; i++)
		if(a[i]%3==0) {
			tong=tong+a[i];
			dem++;
		}
	tb = (float)tong/(float)dem;
	printf("\nTrung binh tong cac so chia het cho 3 trong mang la:%g",tb);

}
void bai2() {
	int n,i;
	int a[100];
	printf("\nMoi nhap so gia tri ");
	scanf("%d",&n);
	printf("\nMoi nhap gia tri cua mang:");
	for(i=0; i<n; i++) {
		printf("\n So thu %d:",i);
		scanf("%d",&a[i]);
	}
	printf("\nGia tri cua mang:");
	for(i=0; i<n; i++) {
		printf(" %5d",a[i]);
	}
	int max=0, min=a[0];
	for(i=0; i<n; i++)
		if(max<a[i])
			max =  a[i];
	for(i=0; i<n; i++)
		if(min>a[i])
			min =  a[i];
	printf("\n max cua mang la: %d", max);
	printf("\n min cua mang la: %d", min);
}
void bai3() {
	int n,i;
	int a[100];
	printf("\nMoi nhap so gia tri ");
	scanf("%d",&n);
	printf("\nMoi nhap gia tri cua mang:");
	for(i=0; i<n; i++) {
		printf("\n So thu %d:",i);
		scanf("%d",&a[i]);
	}
	printf("\nGia tri cua mang:");
	for(i=0; i<n; i++) {
		printf(" %5d",a[i]);
	}
	int tg;
	for(i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i]>a[j]) {
				tg  = a[i];
				a[i]= a[j];
				a[j]= tg;
			}
		}
	}
	printf("\nMang da sap xep lai:");
	for(int i =0; i<n; i++) {
		printf("%5d",a[i]);
	}
}
void bai4() {
	int n,i,m,j;

	printf("\nMoi nhap so hang: ");
	scanf("%d",&n);
	printf("\nMoi nhap so cot:");
	scanf("%d",&m);
	int	a[n][m];
	for(i=0; i<n; i++) {
		for( j=0; j<m; j++) {
			printf("\nXin moi nhap vao gia tri thu a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0; i<n; i++) {
		for( j=0; j<m; j++) {
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	int mangBinhPhuong;
	for(i=0; i<n; i++) {
		for( j=0; j<m; j++) {
			mangBinhPhuong = (a[i][j])*(a[i][j]);
		}
		printf("\nMa tran binh phuong cua mang:%d",mangBinhPhuong);
	}
}

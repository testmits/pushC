#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct mayTinh {
	char tenMT[20];
	char hangMT[20];
	float giaTien;
};
void nhapds( mayTinh *mt, int n);
void xuatds(mayTinh *mt, int n);
void doTruot(int diem);
void dsLopCNTT(int n);

int main() {
	int chon;
	printf("\n01. Thong tin may tinh");
	printf("\n02. Xet do truot");
	printf("\n03. Thong tin lop CNTT");
	printf("\n00. Thoat");
	printf("\nMOI CHON CHUONG TRINH (1-->4)");
	scanf("%d",&chon);
	switch(chon) {
		case 1: {
			int n;
			mayTinh *mt;
			printf("\nNhap vao so luong may tinh:");
			scanf("%d",&n);
			mt = (mayTinh*)calloc(n,sizeof(mayTinh));
			nhapds(mt,n);
			xuatds(mt,n);
			break;
		}
		case 2: {
			int diem;
			printf("Moi nhap vao diem:");
			scanf("%d",&diem);
			doTruot(diem);
			break;
		}
		case 3: {
			int n;
			printf("Moi nhap so lop:");
			scanf("%d",&n);
			dsLopCNTT(n);
			break;
		}
			default:
			printf("Hen gap lai!");
	}
}
void nhapds( mayTinh *mt, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("\nMay tinh thu %d:",i);
		printf("\nNhap vao ten may tinh:");
		fflush(stdin);
		gets(mt[i].tenMT);
		printf("\nNhap vao hang may tinh");
		gets(mt[i].hangMT);
		printf("\nNhap vao gia tien:");
		scanf("%f",&mt[i].giaTien);
	}
}
void xuatds(mayTinh *mt, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("\nDANH SACH MAY TINH");
		printf("STT:%d/n TEN MAY TINH:%s\n HANG MAY TINH:%s\n GIA TIEN:%.0f",i,mt[i].tenMT,mt[i].hangMT,mt[i].giaTien);
	}
}
void doTruot(int diem) {
	if(diem >=5) {
		printf("\nDo");
	} else {
		printf("\nTruot");
	}
}
void dsLopCNTT(int n) {
	
	int i;
	int siso[100];
	
	for( i = 0; i < n; i++) {
		printf("\nLop thu %d: ", i);
		printf("\nNhap vao si so lop: ");
		scanf("%d", &siso[i]);
	}
	
	printf("\nThong tin: ");
	for(i = 0; i<n; i++) {
		printf("\nlop%d:", i);
		printf("\nSi so:%d", siso[i]);
	}
	
	printf("\nNhung lop co va khong si so tren 40");
	for( i = 0; i < n; i++) {
		if(siso[i] > 40) {
			printf("\nLop %d co si so tren 40!", i);
		} else {
			printf("\nLop %d khong co si so tren 40!", i);
		}
	}
	
	int min = siso[0];
	for(int i = 1 ; i < n; i++) {
		if(min > siso[i]) {
			min = siso[i];
		}
	}
	// Xin chao ban
	// Rat vui khi duoc gap ban nha
	// Lam lai phat nua nhaa
	printf("\nLop co si so nho nhat la: %d", min);
}

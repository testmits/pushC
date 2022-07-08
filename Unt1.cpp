#include "stdio.h"
struct sinhVien {
	char mssv[10];
	char tenSv[20];
	char lopSV[10];
	float diemTB;
	int hocBong;
};

int main() {
	int n,i,j;
	printf("Moi nhap vao so sinh vien:");
	scanf("%d",&n);
	printf("\nMoi nhap danh sach sinh vien:");
	struct sinhVien sv[n];
	for(i=0; i<n; i++) {
		printf("\nSinh vien thu %d:",i);
		printf("\nNhap vao ma so sinh vien:");
		scanf("%s",&sv[i].mssv);
		printf("\nNhap vao ten sinh vien:");
		fflush(stdin);
		gets(sv[i].tenSv);
		printf("\nNhap vao lop cua sinh vien:");
		gets(sv[i].lopSV);
		printf("\nNhap vao diem trung binh:");
		scanf("%f",&sv[i].diemTB);
		printf("\nHoc bong cua sinh vien:");
		if(sv[i].diemTB>=9) {
			sv[i].hocBong=2000000;
			printf("2.000.000 VND");
		} else if(sv[i].diemTB>=8) {
			sv[i].hocBong=1000000;
			printf("1.000.000 VND");
		} else {
			printf("Khong co!");
		}
	}
	for(i=0; i<n; i++) {
		printf("\nDANH SACH SINH VIEN:");
		printf("\nMSVS:%s\nTEN SV:%s\nLOP:%s\nDIEM TB:%.1f\nHOC BONG:%d ",sv[i].mssv,sv[i].tenSv, sv[i].lopSV, sv[i].diemTB, sv[i].hocBong);
	}
	//sinh vien co diem trung binh cao nhat
	float max= sv[0].diemTB;
	int k = 0;
	for(i=0; i<n; i++) {
		if(max < sv[i].diemTB) {
			max = sv[i].diemTB ;
			k = i;
		}
	}
	printf("\nSinh vien co diem trung binh cao nhat:");
	printf("\nMSVS:%s\nTEN SV:%s\nLOP:%s\nDIEM TB:%.1f\nHOC BONG:%d ",sv[k].mssv,sv[k].tenSv, sv[k].lopSV, sv[k].diemTB,sv[k].hocBong);


	//tinh hoc bong
	int hocbong=0;
	for(i=0; i<n; i++) {
		hocbong= hocbong + sv[i].hocBong;
	}
	printf("\nTong hoc bong cua danh sach la:%d VND",hocbong);
}

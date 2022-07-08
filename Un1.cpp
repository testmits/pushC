#include "stdio.h"
struct sinhVien {
	char mssv[50];
	char tenSV[50];
	char nganhHoc[50];
	float diemTb;
};
int main() {
	int n,i;
	printf("Nhap vao so luong sinh vien:");
	scanf("%d",&n);
	struct sinhVien SV[n];
	printf("\nMoi nhap thong tin sinh vien:");
	for(i=0; i<n; i++) {
		printf("\nSinh vien %d:",i);
		printf("\nMoi nhap MSSV:");
		scanf("%s",&SV[i].mssv);
		printf("\nMoi nhap ten sinh vien:");
		fflush(stdin);
		gets(SV[i].tenSV);
		printf("\nMoi nhap nganh hoc cua sinh vien:");
		gets(SV[i].nganhHoc);
		printf("\nMoi nhap diem TB cua sinh vien:");
		scanf("%f",&SV[i].diemTb);
	}
	printf("\DANH SACH SINH VIEN:\n");
	for(i=0; i<n; i++) {
		printf("STT:%d\n Ma SV:%s\n Ten SV:%s\n Nganh hoc:%s\n Diem TB:%.2f\n",i,SV[i].mssv,SV[i].tenSV,SV[i].nganhHoc,SV[i].diemTb);
	}
	printf("\n SAP XEP LAI SINH VIEN THEO DIEM:");

	for(i = 0; i< n - 1; i++) {
		for(int j = i+1; j < n; j++) {
			if(SV[i].diemTb > SV[j].diemTb) {
				struct sinhVien temp;
			 	temp.diemTb = SV[i].diemTb;
				SV[i].diemTb = SV[j].diemTb;
				SV[j].diemTb = temp.diemTb;

			}
		}
	}
	for(i=0; i<n; i++) {
		printf("STT:%d\n Ma SV:%s\n Ten SV:%s\n Nganh hoc:%s\n Diem TB:%.2f\n",i,SV[i].mssv,SV[i].tenSV,SV[i].nganhHoc,SV[i].diemTb);
	}
}


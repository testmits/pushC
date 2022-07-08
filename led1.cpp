#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct danhSach {
	char loaiMay[10];
	char tenMayTinh[20];
	char noiSX[10];
	int soLuong;
	int donGia;
	int thanhTien;
};
void nhapDS(danhSach *ds,int n) {
	int i,giaTri;
	for(i=0; i<n; i++) {
		printf("\nSan pham may tinh %d:",i);
		fflush(stdin);
		printf("\nMoi nhap loai may:");
		gets(ds[i].loaiMay);
		printf("\nMoi nhap ten may tinh:");
		gets(ds[i].tenMayTinh);
		printf("\nMoi nhap noi san xuat:");
		gets(ds[i].noiSX);
		printf("\nMoi nhap so luong:");
		scanf("%d",&ds[i].soLuong);
		printf("\nMoi nhap don gia:");
		scanf("%d",&ds[i].donGia);
		giaTri= ds[i].donGia*ds[i].soLuong;
	}
}
void xuatDs(danhSach *ds,int n) {
	int i,giaTri;
	for(i=0; i<n; i++) {
		printf("\nSan pham may tinh thu %d",i);
		printf("\nLoai may tinh:%s",ds[i].loaiMay);
		printf("\nTen may tinh:%s",ds[i].tenMayTinh);
		printf("\nNoi san xuat: %s",ds[i].noiSX);
		printf("\nSo luong:%d",ds[i].soLuong);
		printf("\nDon gia:%d",ds[i].donGia);
		giaTri= ds[i].donGia*ds[i].soLuong;
		printf("\nThanh tien:%d",giaTri);
	}
}
void mayXuatSuMy(danhSach *ds,int n) {
	int i;
	char tim[40] ="" ;
	// cach thay doi de tim may co xuat su ma nguoi dung nhap tu ban phim
//	printf("\nNhap vao noi xuat xu can tim:");
//	fflush(stdin);
//	gets(tim);
	int a=0;
	for(i=0; i<n; i++)
		if(strcmp(ds[i].noiSX,tim)==0) {
			printf("\nDa tim thay ket qua:");
			a++;
			printf("\nLoai may tinh:%s\n Ten may tinh:%s\n Noi san xuat:%s\n So luong:%d\n Don gia:%d",ds[i].loaiMay, ds[i].tenMayTinh, ds[i].noiSX,ds[i].soLuong,ds[i].donGia);
		}
	if(a==0) {
		printf("\nKhong co may nao nhu tren");
	}
}
int tinhTongGiaTriDS(danhSach *ds,int n) {
	int i;
	int	tong;
	for(i=0; i<n; i++) {
	ds[i].thanhTien = ds[i].donGia * ds[i].soLuong;
		tong = tong + ds[i].thanhTien;
	}
	return tong;
}
int main() {
	int n;
	danhSach *ds;
	printf("Nhap vao so luong san pham cua danh sach:");
	scanf("%d",&n);
	ds=(danhSach*)calloc(n,sizeof(danhSach));
	nhapDS(ds,n);
	printf("\nDANH SACH SAN PHAM:\n");
	xuatDs(ds,n);
	printf("\nCac may tinh co xuat xu tu America");
	mayXuatSuMy(ds,n);
	printf("\nTong tien danh sach la:%d",tinhTongGiaTriDS(ds,n));
 
}

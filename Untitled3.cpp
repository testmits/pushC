#include<stdio.h>
#include<conio.h>

int checkYear(int year) {
	int flag = 0;
	
	if (year % 400 == 0) {
		flag = 1;
	}
	
	if (year % 4 == 0 && year % 100 != 0) {
		flag = 1;
	}
	
	return flag;
}

int main() {
	while (true) {
	int year;
	
	printf("Nhap year: ");
	scanf("%d", &year);
	
	if (checkYear(year) == 1) {
		printf("Nhuan!\n");
	} else {
		printf("Khong nhuan!\n");
	}
}

	
	getch();
	return 0;
}

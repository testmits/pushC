#include<stdio.h>

int main(){
	int a, b, c;
	printf("Nhap vao a, b, c: ");
	scanf("%d%d%d", &a, &b, &c);
	int check = timMax(a, b, c);
	printf("Max la: ", check);
}

int timMax(int a, int b, int c) {
	int max = a;
	if(max < b) {
		max = b;
	}
	if(max < c) {
		max = c;
	}
	
	return max;
}

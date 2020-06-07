#include <stdio.h>
#include <conio.h>
using namespace std;

int main(int argc, char *argv[]){
	char k;
	do {
		printf("Nhan esc de ket thuc\n");
		k = getch();
		printf("\n Ban vua nhap phim %c\n", k);
	}while(k != 27);
}

#include <stdio.h>


int main() {

	int n;
	
	int a = 1;
	int b = 0;
	int c = 0;




	printf("입력: ");
	scanf_s("%d", &n);

	if (n == 0) { printf("\n 0"); }
	if (n == 1) { printf("\n 1"); }

	for (int i = 0; i < n-1; i++) {

		c = a + b;
		b = a;
		a = c;

		printf("\n %d", c);
	}



	return 0;
}

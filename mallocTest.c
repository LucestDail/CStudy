#include<stdio.h>
#include<malloc.h>

void main(void) {
	char *string;

	string = (char *)malloc(1000);
	if (string == NULL) {
		printf("Insufficient memory available\n");
	}
	else {
		printf("Allocated 1000 bytes\n");
		free(string);
		printf("Memory freed\n");
	}

}

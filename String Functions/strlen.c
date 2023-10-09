#include <stdio.h>

int strlen(char *string){
	int length = 0;
	for(; string[length] != '\0'; ++length);
	return length;
}

int main(int argc, char** argv){
	printf("%d\n", strlen(argv[1]));
}

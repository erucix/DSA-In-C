#include <stdio.h>

void strncpy(char *destination, char *source, size_t index){
	for(int i = 0; (*source != '\0') && i < index; i++){
		*destination = *source;
		destination++;
		source++;
	}
}

int main(){
	char *a = "Awesome test";
	char b[20];

	strncpy(b,a,7);

	printf("%s\n", b);
}

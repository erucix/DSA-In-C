#include <stdio.h>

void strcp(char *destination, char*source) {
	while(*source != '\0'){
		*destination = *source;
		source++;
		destination++;
	}
}

int main(){
	char a[]="Jello";
	char b[20];

	strcp(b,a);

	printf("%s", b);
}

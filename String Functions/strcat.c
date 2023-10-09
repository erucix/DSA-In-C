#include <stdio.h>

void strcat(char *first, char *second){
	while(*first != '\0')
		first++;

	while(*second != '\0'){
		*first = *second;
		first++;
		second++;	
	}
}

int main(){
	char *a = "brat!";
	char b[20] = "Stupid ";

	strcat(b,a);

	printf("%s\n", b);
}

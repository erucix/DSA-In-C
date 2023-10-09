#include <stdio.h>

void strncat(char *first, char *second, size_t index){
	while(*first != '\0')
		first++;

	for(int i=0; *second != '\0' && i < index; i++){
		*first = *second;
		first++;
		second++;
	}
}

int main(){
	char *a = "Brat!";
	char b[20] = "Hello ";

	strncat(b,a,3);

	printf("%s\n",b);
}

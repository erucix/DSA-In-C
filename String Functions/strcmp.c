#include <stdio.h>

int strcmp(char *first, char *second){
	while(*first && *second){
		if(*first > *second){
			return 1;
		} else if (*first < *second){
			return -1;
		}
		first++;
		second++;
	}

	return 0;
}

int main(){
	char *a = "Hey";
	char *b = "Man";

	printf("%d", strcmp(a,b));
}

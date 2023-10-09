#include <stdio.h>

int strcmp(char *first, char *second, size_t index){
	for (int i = 0; *first && *second && i < index; i++){
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
	char *a = "HHHcd";
	char *b = "HHHjkds";

	printf("%d", strcmp(a,b, 3));
}

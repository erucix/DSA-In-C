#include <stdio.h>

char *strchr(char *string, char pattern){\
	char *lastPointer = NULL;
	while(*string) {
		if(*string == pattern) {
			lastPointer = string;
		}
		string++;
	}
	return lastPointer;
}

int main(){
	char a[20] = "Wot da hell is dis";
	char p = 'z';

	printf("%p\n", strchr(a,p));
}

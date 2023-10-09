#include <stdio.h>

char *strrev(char *string){
	int length = 0;

	while(string[length]) length++;

	int start = 0, end = length-1;

	while(start < end){
		char temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}

	return string;
}

int main(){
	char a[5] = "HELLO";
	printf("%s\n", strrev(a));
}

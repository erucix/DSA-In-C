#include <stdio.h>

char *strupr(char *string){
	for(int i =0; string[i]; i++){
		if(string[i] >= 97 && string[i] <= 122 ) {
			string[i] = string[i] - 32;
		}
	}

	return string;
}

int main(){
	char a[8] = "BoB MAan";
	printf("%s\n", strupr(a));
}

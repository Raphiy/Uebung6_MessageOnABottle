/*
 * main.c
 *
 *  Created on: 12.01.2020
 *      Author: Froemberg Raphael
 */

#include <stdio.h>

int main(){
	FILE *doc;
	doc = fopen("weihnachten.txt", "rb");
	if(doc == NULL){
		printf("Unzulässiger Text");
	}
	int binchar[8] = {0};
	int output = 0;
	int input;
	int n = 0;

	while(1){
		input = fgetc(doc);
		if (!(input == 49 || input == 48 || input ==32 || input ==10 || input ==13 || input ==EOF)){
			break;
		}

		if (!(input == 32 || input == 10 || input ==13 || input == EOF)){
			binchar[n] = input -48;
			n++;
		}

		if (n == 8){
			n = 128;
			for (int i = 0; i < 8; i++){
				output += binchar[i] * n;
				n = n/2;
			}
			printf("%c", output);
			output = 0;
			n = 0;
		}
		if (input == EOF){
			if(n!=0){
				printf("\nEs sind noch folgende Zeichen übrig:");
				for (int x = 0; x <= n; x++){
					printf("%d", binchar[x]);
				}
			}
			break;
		}
	}
}

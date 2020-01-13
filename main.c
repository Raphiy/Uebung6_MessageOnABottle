/*
 * main.c
 *
 *  Created on: 12.01.2020
 *      Author: Froemberg Raphael
 */

#include <stdio.h>
#include <ctype.h>

int main() {
	//File Weihnachten.txt öffnen und mit rb (read, binary)
	FILE *doc;
	doc = fopen("weihnachten.txt", "rb");
	//Überprüfen ob das geöffnete Document leer ist
	if (doc == NULL) {
		printf("Unzulässiger Text");
	}
	//Variablen
	int binchar[8] = { 0 };
	int output = 0;
	int input;
	int n = 0;

	//Schleife mit Abbruchbedingung in der Schleife
	while (1) {
		//Buchstabe in input schreiben
		input = fgetc(doc);
		//überprüfen ob eingelesener Buchstabe ein gültiges Zeichen ist
		if (input == 49 || input == 48 || isspace(input) || input == EOF) {
			//Überprüfen ob eingegebenes Zecihen 1 oder 0 ist
			if (input == 49 || input == 48) {
				//1 oder 0 in nächste Stelle von binchar schreiben
				binchar[n] = input - 48;
				n++;
			}
		} else {
			//Wenn Zeichen ungültig -> Abbruch
			printf("\nProgrammabbruch: Ungültiges Zeichen.");
			break;
		}

		//Wenn Zeichenkete von 8 Zeichen erreicht
		if (n == 8) {
			//Umwandeln der 8-stelligen Binärzahl in Dezimal
			n = 128;
			for (int i = 0; i < 8; i++) {
				output += binchar[i] * n;
				n = n / 2;
			}
			//Umgewandelte Dezimalzahl ausgeben -> Buchstabe weil ASCII
			printf("%c", output);
			//Output und Zeichenkette zurücksetzen
			output = 0;
			n = 0;
		}
		//Wenn EOF (End Of File)
		if (input == EOF) {
			if (n != 0) {
				//Und Zeichenkette nicht zurückgesetzt auf 0, dann Werte in binchar ausgeben (Können nicht umgewandelt werden)
				printf("\nEs sind noch folgende Zeichen übrig:");
				for (int x = 0; x <= n; x++) {
					printf("%d", binchar[x]);
				}
			}
			break;
		}
	}
}

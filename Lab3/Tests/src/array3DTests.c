#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "array3DTests.h"


void setArray(int*** array3d, int x, int y, int z, FILE* fileI, FILE* fileO) {
	int xIn, yIn, zIn;
	for (zIn = 0; zIn < z; zIn++) {
		for (xIn = 0; xIn < x; xIn++) {
			for (yIn = 0; yIn < y; yIn++) {
				fprintf(fileO, "Enter value in {%d, %d, %d} ", xIn + 1, yIn + 1, zIn + 1);
				int temp, correctInput;
				do {
					correctInput = fscanf(fileI, "%d", &temp);
					if (!correctInput || !((temp != 1 && temp == 0) || (temp == 1 && temp != 0))) {
						fprintf(fileO, "Incorrect Input. Try again: ");
						while (getc(fileI) != '\n');
					}
				} while (!correctInput || !((temp != 1 && temp == 0) || (temp == 1 && temp != 0)));
				array3d[xIn][yIn][zIn] = temp;
			}
		}
	}
}

void projection(int*** array3d, int x, int y, int z, FILE* file) {
	fprintf(file, "XOY:\n");


	int xIn, yIn, zIn;
	int flag = 0;
	for (xIn = 0; xIn < x; xIn++) {
		for (yIn = 0; yIn < y; yIn++) {
			for (zIn = 0; zIn < z; zIn++) {
				if (array3d[xIn][yIn][zIn] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag) fprintf(file, "1 ");
			else fprintf(file, "0 ");
			flag = 0;
		}
		fprintf(file, "\n");
	}

	fprintf(file, "\nXOZ\n");
	for (zIn = z - 1; zIn >= 0; zIn--) {
		for (xIn = x - 1; xIn >= 0; xIn--) {
			for (yIn = 0; yIn < y; yIn++) {
				if (array3d[xIn][yIn][zIn] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag) fprintf(file, "1 ");
			else fprintf(file, "0 ");
			flag = 0;
		}
		fprintf(file, "\n");
	}

	fprintf(file, "\nYOZ\n");
	for (zIn = z - 1; zIn >= 0; zIn--) {
		for (yIn = 0; yIn < y; yIn++) {
			for (xIn = 0; xIn < x; xIn++) {
				if (array3d[xIn][yIn][zIn] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag) fprintf(file, "1 ");
			else fprintf(file, "0 ");
			flag = 0;
		}
		fprintf(file, "\n");
	}
}
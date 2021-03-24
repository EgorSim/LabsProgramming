#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "array3D.h"


void setArray(int*** array3d, int x, int y, int z) {
	int xIn, yIn, zIn;
	for (zIn = 0; zIn < z; zIn++) {
		for (xIn = 0; xIn < x; xIn++) {
			for (yIn = 0; yIn < y; yIn++) {
				printf("Enter value in {%d, %d, %d} ", xIn + 1, yIn + 1, zIn + 1);
				int temp, correctInput;
				do {
					correctInput = scanf("%d", &temp);
					if (!correctInput || !((temp != 1 && temp == 0) || (temp == 1 && temp != 0))) {
						printf("Incorrect Input. Try again: ");
						while (getc(stdin) != '\n');
					}
				} while (!correctInput || !((temp != 1 && temp == 0) || (temp == 1 && temp != 0)));
				array3d[xIn][yIn][zIn] = temp;
			}
		}
	}
}

void projection(int*** array3d, int x, int y, int z) {
	printf("XOY:\n");


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
			if (flag) printf("1 ");
			else printf("0 ");
			flag = 0;
		}
		printf("\n");
	}

	printf("\nXOZ\n");
	for (zIn = z - 1; zIn >= 0; zIn--) {
		for (xIn = x - 1; xIn >= 0; xIn--) {
			for (yIn = 0; yIn < y; yIn++) {
				if (array3d[xIn][yIn][zIn] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag) printf("1 ");
			else printf("0 ");
			flag = 0;
		}
		printf("\n");
	}

	printf("\nYOZ\n");
	for (zIn = z - 1; zIn >= 0; zIn--) {
		for (yIn = 0; yIn < y; yIn++) {
			for (xIn = 0; xIn < x; xIn++) {
				if (array3d[xIn][yIn][zIn] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag) printf("1 ");
			else printf("0 ");
			flag = 0;
		}
		printf("\n");
	}
}
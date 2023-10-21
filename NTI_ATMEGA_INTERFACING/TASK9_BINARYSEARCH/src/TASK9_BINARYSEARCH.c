/*
 ============================================================================
 Name        : TASK9_BINARYSEARCH.c
 Author      : HOSSAM MAHMOUD
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int input;
	int low = 0, middle, limit;
	printf("Enter your array: \n");
	int inputArray[10] = {4, 5, 7, 8, 12, 15, 18, 22, 25, 27};

	int length = sizeof(inputArray) / sizeof(inputArray[0]);

	limit = length;
	middle = (low + limit) / 2;
	int found;

	int reqValue = 15;

	int i = 0;
	while(i < length)
	{
		if(middle == reqValue) {
			found = i;
			break;
		}
		else if(reqValue > middle) {
			low = middle;
			middle = (limit - middle) / 2;
			continue;
		}
		else if(reqValue < middle) {
			limit = middle;
			middle = (middle - low) / 2;
			continue;
		}
		i++;
	}

	return found;
}
















//	for(int i = 0; i < sizeof(inputArray) ; i++) {
//		scanf("%d", &input);
//		inputArray[i] = input;
//	}
//
//	int min = inputArray[0];
//	for(int i = 1; i < sizeof(inputArray) ; i++) {
//		if(inputArray[i] > min) {
//			min = inputArray[i];
//
//		}
//	}

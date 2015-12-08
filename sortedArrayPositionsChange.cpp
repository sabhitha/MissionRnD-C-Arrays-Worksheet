/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (!Arr)
		return NULL;
	int temp;
	int x = 0;
	int y = 0;
	int flag = 0;
	if (len <=1)
		return NULL;
	for (int i = 1; i < len; i++){
		if (Arr[i - 1] == Arr[i])
			return NULL;
	}
	int i, j;
	if (Arr[0] > Arr[1]){
		x = 0;
		if (Arr[0] < Arr[2])
			y = 1;
	}
	if (Arr[len - 1] < Arr[len - 2]){
		y = len - 1;
		if (Arr[len - 3] < Arr[len - 2] && Arr[len - 3] < Arr[len - 1])
			x = len - 2;
	}
	else{
		for (i = 0; i < len - 1; i++){
			if (Arr[i] >Arr[i + 1]){
				x = i;
				break;
			}
		}
		for (j = 1; j < len - 1; j++){
			if (Arr[j - 1] > Arr[j] && Arr[j] <Arr[j + 1]){
				y = j;
			}
		}
	}
	temp = Arr[x];
	Arr[x] = Arr[y];
	Arr[y] = temp;
	return NULL;
}
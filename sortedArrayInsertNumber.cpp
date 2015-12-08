/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len <= 0 || !Arr)
		return NULL;
	int idx = 0;
	int i = 0;
	int low = 0;
	int high = len - 1;
	while (1){
		
		int mid = (low + high) / 2;
		if (num < Arr[low]){
			idx = low;
			break;
		}
		if (num > Arr[high]){
			idx = high;
			break;
		}
		if (Arr[mid] < num && Arr[mid] > num){
			idx = mid + 1;
			break;
		}
		else if (Arr[mid] < num){
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	for (int i = high; i >= idx; i--){
		Arr[i + 1] = Arr[i];
	}
	Arr[idx] = num;
	return Arr;
}
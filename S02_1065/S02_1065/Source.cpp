#include "stdio.h"
#include "malloc.h"
void main()
{
	int*** matrix = NULL;
	FILE* pFile = fopen("Data.txt", "r");
	int noCols = 0, noRows = 0, index = 0;
	if (pFile)
	{
		fscanf(pFile, "%d %d", &noRows, &noCols);
		matrix = (int***)malloc(sizeof(int**)*noCols);
		for (register int rowIndex = 0; rowIndex < noRows; rowIndex++)
		{
			matrix[rowIndex] = (int**)malloc(sizeof(int*)*noCols);
		}
		while (!feof(pFile))
		{
			//1.read the current element from the file
			int value = 0;
			fscanf(pFile, "%d", &value);
			//2.calculate the indices (i,j)
			int i = index / noCols;
			int j = index % noCols;
			//3.allocate space for the matrix[i][j] element
			matrix[i][j] = (int*)malloc(sizeof(int));
			//4.store the element 
			*matrix[i][j] = value;
			index++;
		}
	}
	for (int i = 0; i < noRows; i++)
	{
		printf("\n");
		for (int j = 0; j < noCols; j++)
		{
			printf("%5d", *matrix[i][j]);
		}
	}
}
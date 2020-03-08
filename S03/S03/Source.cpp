#include "stdio.h"
#include "malloc.h"
#include "string.h"
struct Student
{
	char* name;
	int year;
};
struct List
{
	Student* info;
	List* next;
};

void printArray(Student*, int);
List* createNodeList(Student*);
void insertNodeList(List**, List*);

void main()
{
	FILE* pFile = fopen("Data.txt","r");
	Student* data = NULL;
	if (pFile)
	{
		int dim = 0, index = 0;
		fscanf(pFile, "%d", &dim);
		data = (Student*)malloc(sizeof(Student)*dim);
		while (!feof(pFile))
		{
			//1.read the name
			char buffer[100]; int year = 0;
			fscanf(pFile, "%s", buffer);
			//2.read the year
			fscanf(pFile, "%d", &year);
			//3.store the student's data in the array on the index position
			data[index].name = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
			strcpy(data[index].name, buffer);
			data[index].year = year;

			index++;
		}
		fclose(pFile);

		printArray(data, dim);

		List* head = NULL;

		for (int i = 0; i < dim; i++)
		{
			List* node = createNodeList(&data[i]);
			insertNodeList(&head, node);
		}
		while (head)
		{
			printf("Value: %s, year: %X \n", head->info->name,
				head->info);
			head = head->next;
		}

	}
}

List* createNodeList(Student* student)
{
	List* newNode = (List*)malloc(sizeof(List*));
	newNode->next = NULL;
	newNode->info = student;
	return newNode;
}
void insertNodeList(List** head, List* node)
{
	//insertion at the begining of the list
	node->next = *head;
	*head = node;
}


void printArray(Student* array, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		printf("Student: %s, year=%d \n", array[i].name, array[i].year);
	}
}
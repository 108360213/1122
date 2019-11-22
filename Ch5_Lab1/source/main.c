#include<stdio.h>
#include<stdlib.h>
#define STUDENTS 3
#define EXAMS 4

void minimum(int grades[][EXAMS], int pupils, int tests);
void maximum(int grades[][EXAMS], int pupils, int tests);
void average(int grades[][EXAMS], int pupils, int tests);
void printarray(int grades[][EXAMS], int pupils, int tests);
void printmenu(void);

int main()
{
	void(*processgrades[4])(int[][EXAMS], int, int) = { printarray,minimum,maximum,average };
	int choice = 0;
	int studentgrades[STUDENTS][EXAMS] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };

	while (choice!=4)
	{
		do
		{
			printmenu();
			scanf_s("%d",&choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processgrades[choice])(studentgrades, STUDENTS, EXAMS);
		}
		else
		{
			printf("Program Ended. \n");
		}
	}
	system("pause");
	return 0;
}
void minimum(int grades[][EXAMS], int pupils, int tests)
{
	int i, j, lowgrade = 100;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] < lowgrade)
				lowgrade = grades[i][j];
		}
	}
	printf("\n\tThe highest grade is %d\n", lowgrade);
}
void maximum(int grades[][EXAMS], int pupils, int tests)
{
	int i, j, highgrade = 0;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] > highgrade)
				highgrade = grades[i][j];
		}
	}
	printf("\n\tThe highest grade is %d\n", highgrade);
}
void average(int grades[][EXAMS], int pupils, int tests)
{
	int i, j, total;
	printf("\n");
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			total += grades[i][j];
		}
		printf("\tThe average grade for student %d is %.1f\n",i+1,(double)total/tests);
	}
}
void printarray(int grades[][EXAMS], int pupils, int tests)
{
	int i, j;
	printf("\n\t                 [0]  [1]  [2]  [3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j <= tests - 1; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}
void printmenu(void)
{
	printf("\nEnter a choice:\n\t 0 Print the array of grades\n\t 1 Find the minimum grade\n\t 2 Find the maximum grade\n\t 3 Point the average on all tests for each student\n\t 4 End program\n\t?");
}
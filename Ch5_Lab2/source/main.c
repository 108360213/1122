#include<stdio.h>
#include<stdlib.h>
#define ISSUES 5
#define RATINGS 10

void recordrespinse(int i, int response);
void highestratings();
void lowestratings();
float averageratings(int issue);
void displayresults();

int responses[ISSUES][RATINGS];
const char *topics[ISSUES] = { "Global Warming","Economy","War","Health Care","Education" };

int main(void)
{
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale ffrom 1-10\n 1 = least important,10 = most important\n");
		for (i = 0; i < ISSUES; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("?");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordrespinse(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
		scanf_s("%d", &response);
	} while (response != 1);
	displayresults();
	system("pause");
	return 0;
}
void recordrespinse(int issues, int rating)
{
	responses[issues][rating - 1]++;
}
void highestratings(void)
{
	int highrating = 0, hightopic = 0;
	int i, j;
	for (i = 0; i < ISSUES; i++)
	{
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++)
		{
			topicrating += responses[i][j] * (j + i);
		}
		if (highrating < topicrating)
		{
			highrating = topicrating;
			hightopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[hightopic]);
	printf(" with a total rating of %d\n", highrating);
}
void lowestratings(void)
{
	int lowrating = 0;
	int lowtopic = 0;
	int i, j;
	for (i = 0; i < ISSUES; i++)
	{
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++)
			topicrating += responses[i][j] * (j + 1);
		if (i == 0)
			lowrating = topicrating;
		if (lowrating > topicrating)
		{
			lowrating = topicrating;
			lowrating = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowtopic]);
	printf(" with a total rating of %d\n", lowrating);
}
float averageratings(int issue)
{
	float total = 0;
	int counter = 0, j;
	for (j = 0; j < RATINGS; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
	}
	return total / counter;
}
void displayresults()
{
	int i, j;
	printf("%20s", "Topic");
	for (i = 1; i <= RATINGS; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average Rating\n");
	for (i = 0; i < ISSUES; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < RATINGS; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f\n", averageratings(i));
	}
	highestratings();
	lowestratings();
}

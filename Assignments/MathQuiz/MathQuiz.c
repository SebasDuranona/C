#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initialize(void);

int get_answer(int secret)
{
	int answer;

	printf("Please enter your answer: ");
	scanf("%d", &answer);

	if (answer == secret)
	{
		printf("You got it right!\n");
		return 1;
	}


	if (answer < secret)
	{
		printf("Your answer is too small, please try again.\n");
	}
	else /* if (answer > secret) */
	{
		printf("Your answer is too large, please try again.\n");
	}

	return 0;
}

int main(void)
{
	int upper_bound = 0;
	int secret;
	int is_answer_correct;

	initialize();

	do
	{
		printf("Please enter a positive integer number: ");
		scanf("%d", &upper_bound);
	}
	while (upper_bound <= 0);

	secret = (rand() % upper_bound) + 1;

	do {
		is_answer_correct = get_answer(secret);
	}
	while (!is_answer_correct);

	return 0;
}

void initialize(void)
{
	srand(time(NULL));
}


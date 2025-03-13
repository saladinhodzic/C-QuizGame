// Building the C Quiz Game
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX_QUESTIONS = 5;

typedef struct Question
{
    char question[20];
    char options[4][20];
    int correct_option;
}QUESTION;

// function declared to display the question
void displayQuestion(QUESTION question);
// function declared to check the user guess
int checkAnswer(QUESTION question,int guess);

int main(void)
{
    printf("Welcome to the computer science quiz!\n");
}

void displayQuestion(QUESTION question)
{
    printf("%s",question.question);
    for(int i=0;i<4;i++)
    {
        printf("%d. %s",i+1,question.options[i]);
    }
}

int checkAnswer(QUESTION question,int guess)
{
    if (question.correct_option == guess)
    {
        return 1;
    }
    return 0;
}
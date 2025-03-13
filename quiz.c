// Building the C Quiz Game
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUESTIONS 5

typedef struct Question
{
    char question[300];
    char options[4][60];
    int correct_option;
}QUESTION;

// function declared to display the question
void displayQuestion(QUESTION question);
// function declared to check the user guess
int checkAnswer(QUESTION question,int guess);

int main(void)
{
    // random number generator
    srand(time(NULL));
    printf("Welcome to the computer knowledge quiz!\n");

    QUESTION original_questions[MAX_QUESTIONS] = {
        {"A sort of malware computer program that keeps replicating itself and can easily get diffused into other computers through internet is known as ...",
            {"Virus","Worms","Trojans","Spyware"},
        2},
        {"The Fourth Generation Computer used ...",
            {"Transistors","Integrated Circuit","Vacuum tube","Microprocessor"},
        4},
        {"Who among the following has designed the Ruby programing language?",
            {"Larry Wall","Gudio van Rossum","Joe Armstrong","Yukihiro Matsumoto"},
        4},
        {"A person who sends irrelevant or unsolicited messages by using Internet, usually to large numbers of users, for the purposes of advertising, spreading malware, phishing, etc. is known as ...",
            {"Programmer","Hacker","Scammer","Hobbyist"},
        3},
        {"In reference to computer system, program has the similar meaning as of ...",
            {"Software","Information","Data","Security system"},
        1}
    };
    QUESTION questions[MAX_QUESTIONS];
    memcpy(questions,original_questions,sizeof(original_questions));
    int num_questions = MAX_QUESTIONS;
    // keeping track of score
    int score = 0;
    for(int i=0;i<MAX_QUESTIONS;i++)
    {
        int random_index = rand() % num_questions;
        QUESTION current_question = questions[random_index];
        printf("Your score:%d/5\n",score);
        displayQuestion(current_question);
        int guess;
        printf("Enter the your guess (1-4): ");
        scanf("%d",&guess);
        if(guess >=1 && guess<=4)
        {
            if (guess == current_question.correct_option)
            {
                printf("Correct Answer!\n");
                score++;
            }else
            {
                printf("You got the wrong answer!\nCorrect answer was %s!\n",current_question.options[current_question.correct_option-1]);
            }
        }else
        {
            printf("Please enter number in range from 1 to 4!\n");
        }
        questions[random_index] = questions[num_questions-1];
        num_questions--;
    }
    printf("Congratulations on finishing the quiz!\nYour score is %d/5.",score);
}

void displayQuestion(QUESTION question)
{
    printf("%s\n",question.question);
    for(int i=0;i<4;i++)
    {
        printf("%d. %s\n",i+1,question.options[i]);
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
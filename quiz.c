// Building the C Quiz Game
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX_QUESTIONS = 5;

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
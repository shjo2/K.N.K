#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_STUDENTS 5
#define NUM_QUIZZES 5

int main() {
    int grades[NUM_STUDENTS][NUM_QUIZZES];
    int total_scores[NUM_STUDENTS] = { 0 };
    double average_score[NUM_STUDENTS] = { 0 };
    double quiz_averages[NUM_STUDENTS] = { 0 };
    int quiz_max_score[NUM_QUIZZES] = { 0 };
    int quiz_min_score[NUM_QUIZZES] = { 0 };

    for (int i = 0; i < NUM_QUIZZES; i++) {
        quiz_min_score[i] = 101;
        quiz_max_score[i] = -1;
        quiz_averages[i] = 0;
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter 5 quiz grades for student %d: ", i + 1);
        for (int j = 0; j < NUM_QUIZZES; j++) {
            scanf("%d", &grades[i][j]);
            total_scores[i] += grades[i][j];
            quiz_averages[j] += grades[i][j];

            if (quiz_max_score[j] < grades[i][j])
                quiz_max_score[j] = grades[i][j];

            if (quiz_min_score[j] > grades[i][j])
                quiz_min_score[j] = grades[i][j];

        }
        average_score[i] = total_scores[i] / NUM_QUIZZES;
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        quiz_averages[i] = quiz_averages[i] / NUM_STUDENTS;
    }

    printf("\nStudent Totals:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %d %.2f\n", i + 1, total_scores[i], average_score[i]);
    }
    printf("\nStudent Averages:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %.2f\n", i + 1, average_score[i]);
    }
    printf("\nQuiz High Scores:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %d\n", i + 1, quiz_max_score[i]);
    }
    printf("\nQuiz Low Scores:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %d\n", i + 1, quiz_min_score[i]);
    }
    printf("\nQuiz Averages Scores:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %.2f\n", i + 1, quiz_averages[i]);
    }

    return 0;
}
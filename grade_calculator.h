#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

int read_score(void);
double calculate_average(int score1, int score2, int score3);
char determine_grade(double average);
void display_result(double average, char grade);

#endif

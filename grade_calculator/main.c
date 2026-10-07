#include <stdio.h>
#include "grade_calculator.h"

int main(void) {
	int score1;
	int score2;
	int score3;
	double average;
	char grade;

	score1 = read_score();
	score2 = read_score();
	score3 = read_score();

	average = calculate_average(score1, score2, score3);
	grade = determine_grade(average);

	display_result(average, grade);

	return 0;
}

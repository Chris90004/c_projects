#include <stdio.h>

int read_score(void) {
	int score;

	while(1) {
		printf("Enter score: ");
		scanf("%d", &score);
		if (score >= 0 && score <= 100) {
			return score;
		}

		printf("Invalid score, score needs to be between 0 and 100\n");
	}
}


double calculate_average(int score1, int score2, int score3) {
	double average = ((score1 + score2 + score3) / 3.0);

	return average;
}

char determine_grade(double average) {
	char grade;

	if (average >= 90) {
		grade = 'A';
	} else if (average >= 80) {
		grade = 'B';
	} else if (average >= 70) {
		grade = 'C';
	} else if (average >= 60) {
		grade = 'D';
	} else {
		grade = 'F';
	}

	return grade;
}

void display_result(double average, char grade) {

	printf("Average: %.2f\n", average);
	printf("Grade: %c\n", grade);
}

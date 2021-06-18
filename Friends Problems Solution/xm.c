#include <stdio.h>

struct stdInfo {
	int ID;
	char name[40];
	int courseNo;
	int credits[9];
	double grades[9];
	double cgpa;
};

int main() {
	int totalStudent;
	printf("Enter the number of students: ");
	scanf("%d", &totalStudent);
    struct stdInfo info[totalStudent];

	for (int i = 0; i < totalStudent; i++) {
		printf("\nStudent-%d information:\n", i + 1);
		printf("ID: ");
		scanf("%d", &info[i].ID);
		printf("Name: ");
		getchar();
		gets(info[i].name);
		printf("#course: ");
		scanf("%d", &info[i].courseNo);
		printf("Credits: ");
		for (int j = 0; j < info[i].courseNo; j++) {
			scanf("%d", &info[i].credits[j]);
		}
		printf("Grades: ");
        for (int j = 0; j < info[i].courseNo; j++) {
			scanf("%lf", &info[i].grades[j]);
		}
	}

	printf("\nSummary:\n");
	printf("ID\tName\tCGPA\n");
	for (int i = 0; i < totalStudent; i++) {
		printf("%d\t%s\t", info[i].ID, info[i].name);
		double ans = 0, total = 0;
		
		for (int j = 0; j < info[i].courseNo; j++) {
			ans += (info[i].credits[j] * info[i].grades[j]);
			total += info[i].credits[j];
		}
		ans /= total;
		printf("%.4lf\n", ans);
	}
}
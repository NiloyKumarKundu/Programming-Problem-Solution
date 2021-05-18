#include <stdio.h>
#include <string.h>

struct student {
	int roll_no;
	char name[50];
	int age;
	char address[200];
};
const int total_student = 5;
struct student st[total_student];

void info_by_name() {
	char test_name[50];
	printf("Enter the name to see the details of the student\n");
	fflush(stdin);
	gets(test_name);
	fflush(stdout);
	int flag = 1;
	for (int i = 0; i < total_student; i++) {
		if (strcmp(test_name, st[i].name) == 0) {
            if (flag) {
                printf("Student's information\n");
            }
			printf("Name: %s\n", st[i].name);
			printf("Roll: %d\n", st[i].roll_no);
            printf("age: %d\n", st[i].age);
            printf("Address: %s\n", st[i].address);
			flag = 0;
		}
	}
    if (flag) {
		printf("No studnet found!\n");
	}
}

void info_by_age() {
	int flag = 1;
	for (int i = 0; i < total_student; i++) {
        if (st[i].age == 14) {
            if (flag) {
				printf("Student's information who have age 14\n");
			}
			printf("%s\n", st[i].name);
			flag = 0;
		}
	}
    if (flag) {
		printf("No studnet found!\n");
	}
}

int main() {
	printf("Enter student information:\n");
	for (int i = 0; i < total_student; i++) {
		printf("Enter roll no: ");
		scanf("%d", &st[i].roll_no);
        printf("Enter name: ");
		fflush(stdin);
		gets(st[i].name);
		fflush(stdout);
        printf("Enter age: ");
		scanf("%d", &st[i].age);
        printf("Enter address: ");
		fflush(stdin);
		gets(st[i].address);
		fflush(stdout);
	}
    info_by_name();
	printf("\n");
	info_by_age();
}
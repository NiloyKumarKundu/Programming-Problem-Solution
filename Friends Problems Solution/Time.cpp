#include <stdio.h>
#include <time.h> 


int main() {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	int controlHour = timeinfo->tm_min;
	controlHour += 4;
	controlHour %= 24;
	while (timeinfo->tm_hour != controlHour) {
		printf("Current local time and date: %s", asctime(timeinfo));
		time(&rawtime);
		timeinfo = localtime(&rawtime);
	}

	return 0;
}
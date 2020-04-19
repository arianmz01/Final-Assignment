/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Arian Mohammadi Zerdeh-Del		 amohammadi-zerdeh-de@myseneca.ca
   2) Arfa Ziaardalan					 azia-ardalan@myseneca.ca
   3) Jairo Oswaldo Martinez Garnica     jomartinez-garnica@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: Funtions.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */
#define _CRT_SECURE_NO_WARNINGS
#define NUMRIDERS 99
#include <stdio.h>
#include <string.h>
#include "file_helper.h"
#include "Functions.h"

void clearKeyboard(void) {
	while (getchar() != '\n');
}

int getInt(void) {
	int flag = 1;
	char newline = ' ';
	int choice;
	do {
		printf(": ");
		scanf("%d%c", &choice, &newline);
		while (newline != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &choice, &newline);
		}
		if (choice >= 0 && choice <= 4) {
			flag = 0;
		}
		else {
			printf("Error, Please pick between 0 and 4 ");
		}
	} while (flag);

	printf("\n");
	return choice;
}

char getCat(void) {
	int flag = 1;
	char newline = ' ';
	char cat = ' ';
	printf("Which category (S, M, L): ");
	scanf("%c%c", &cat, &newline);
	while (newline != '\n') {
		clearKeyboard();
		printf("You must put a singel character: ");
		scanf("%c%c", &cat, &newline);
	}
	do {
		while (newline != '\n') {
			clearKeyboard();
			printf("You must put a singel character: ");
			scanf("%c%c", &cat, &newline);
		}
		if (cat == 's' || cat == 'm' || cat == 'l' || cat == 'S' || cat == 'M' || cat == 'L') {

			if (cat == 's' || cat == 'm' || cat == 'l') {
				cat = toupper(cat);
			}
			flag = 0;
		}

		else {
			printf("Wrong input please select (S, M, L): ");
			scanf("%c%c", &cat, &newline);
		}
	} while (flag);
	return cat;
}

void MenuDisplay(void) {
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a category\n");
	printf("2 - Print all riders in a category\n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories\n");
}


int Choice(struct RiderInfo riders[], int max, int limit[], char choice, int condition) {
	int size;
	for (size = 0; size < max; size++) {
		if (riders[size].raceLength == 0) {
			break;
		}
	}
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (riders[i].raceLength == toupper(choice) && (!condition || !riders[i].withdrawn)) {
			limit[j] = i;
			j++;
		}
	}
	return j;
}

void getOutput(struct RiderInfo* rider, int show, int withdrawn) {
	char age[10] = "N/A";
	if ((*rider).age >= 16 && (*rider).age <= 20) {
		strcpy(age, "Junior");
	}
	else if ( (*rider).age >= 21 && (*rider).age <= 34) {
		strcpy(age, "Adult");
	}
	else if ( (*rider).age >= 35) {
		strcpy(age, "Senior");
	}

	printf("%-30s%-10s", (*rider).name, age);
	if (show < 0) {

		char len[10] = "N/A";

		if ((*rider).raceLength == 'M' || (*rider).raceLength == 'm')
		{
			strcpy(len, "75km");
			printf("%-10s", "75km");
		}
		else if ((*rider).raceLength == 'L' || (*rider).raceLength == 'l')
		{
			strcpy(len, "100km");
			printf("%-10s", "100km");
		}
		else {
			strcpy(len, "50km");
			printf("%-10s", "50km");
		}
	}
	double time = (*rider).finishTime - (*rider).startTime;

	int hours = (int)time;
	int minutes = ((((time - (int)time) * 60) * 10) + 0.001) / 10;

	if (hours < 1) {
		printf("   N/A");
	}
	else {
		printf(" %02d:%02d", hours, minutes);
	}

	if (withdrawn == 1) {
		if ((*rider).withdrawn) {
			printf("%10s", "Yes");
		}
		else {
			printf("%10s", "No");
		}
	}
	printf("\n");
}

void Output(struct RiderInfo riders[], int limit[], int record) {
	int show = 0;
	int withdrawn = 0;
	int status = 0;
	int x = 0;
	int flag = 0;
	riders[limit[99]].raceLength;
	for (int i = 0; i < record; i++) {
		if (riders[limit[i]].withdrawn == 1) {
			withdrawn = 1;
		}
		else if (riders[limit[i]].raceLength == 'S' || riders[limit[i]].raceLength == 's') {
			status = 1;
		}
		else if (riders[limit[i]].raceLength == 'M' || riders[limit[i]].raceLength == 'm') {
			status = 1;
		}
		else if (riders[limit[i]].raceLength == 'L' || riders[limit[i]].raceLength == 'l') {
			status = 1;
		}

		else {
			flag = flag + 1000;
		}
	}
	if (status > 1) {
		show = 1;
	}

	printf("\n");
	printf("%-30s%-10s", "Rider", "Age Group");
	x = x + 40;

	if (flag > 1000) {
		printf("%6s", "Category");
		show = -1;
	}
	printf("%6s", "Time");

	x = x + 6;
	if (withdrawn == 1) {
		printf("%10s", "Withdrew");
		x = x + 10;
	}
	printf("\n");

	if (show < 0) {

		for (int i = 0; i < x + 10; i++) {
			printf("-");
		}
	}
	else {

		for (int i = 0; i < x; i++) {
			printf("-");
		}
	}
	printf("\n");
	for (int i = 0; i < record; i++) {
		getOutput(&riders[limit[i]], show, withdrawn);
	}

	printf("\n");
}

void Output2(struct RiderInfo riders[], int limit[], int record) {
	int show = 0;
	int withdrawn = 0;
	int status = 0;
	int x = 0;
	int flag = 0;
	riders[limit[99]].raceLength;
	for (int i = 0; i < record; i++) {
		if (riders[limit[i]].withdrawn == 1) {
			withdrawn = 1;
		}
		else if (riders[limit[i]].raceLength == 'S' || riders[limit[i]].raceLength == 's') {
			status = 1;
		}
		else if (riders[limit[i]].raceLength == 'M' || riders[limit[i]].raceLength == 'm') {
			status = 1;
		}
		else if (riders[limit[i]].raceLength == 'L' || riders[limit[i]].raceLength == 'l') {
			status = 1;
		}

		else {
			flag = flag + 1000;
		}
	}
	if (status > 1) {
		show = 1;
	}

	printf("\n");
	printf("%-30s%-10s", "Rider", "Age Group");
	x = x + 40;

	if (flag < 1000) {
		printf("%6s", "Category");
		show = -1;
	}
	printf("%6s", "Time");

	x = x + 6;
	if (withdrawn == 1) {
		printf("%10s", "Withdrew");
		x = x + 10;
	}
	printf("\n");

	if (show < 0) {

		for (int i = 0; i < x + 10; i++) {
			printf("-");
		}
	}
	else {

		for (int i = 0; i < x; i++) {
			printf("-");
		}
	}
	printf("\n");
	for (int i = 0; i < record; i++) {
		getOutput(&riders[limit[i]], show, withdrawn);
	}

	printf("\n");
}

int Switch(struct RiderInfo* r1, struct RiderInfo* r2) {
	double t1 = (*r1).finishTime - (*r1).startTime;
	double t2 = (*r2).finishTime - (*r2).startTime;
	int x = 0;
	if ((*r1).withdrawn == 0 && (*r2).withdrawn == 0) {
		if (t1 < t2) {
			x = 0;
		}
		else if (t1 == t2) {
			if ((*r1).mountainTime < (*r2).mountainTime) {
				x = 0;
			}
			else {
				x = 1;
			}
		}
		else {
			x = 1;
		}
	}
	else if ((*r1).withdrawn == 1) {
		x = 1;
	}
	return x;
}

void Swap(struct RiderInfo* r1, struct RiderInfo* r2)
{
	struct RiderInfo tmp;
	tmp = *r1;
	*r1 = *r2;
	*r2 = tmp;
}

void BubbleSort(struct RiderInfo riders[], int max)
{
	int size;
	for (size = 0; size < max; size++) {
		if (riders[size].raceLength == 0) {
			break;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (Switch(&riders[j - 1], &riders[j])) {
				Swap(&riders[j - 1], &riders[j]);
			}
		}
	}
}

void ContentSystem(void) {
	FILE* fp = NULL;
	fp = fopen("data.txt", "r");
	struct RiderInfo riders[NUMRIDERS] = { 0 };
	struct RiderInfo winners[3];
	int limit[NUMRIDERS];
	int i = 0;
	int Record;
	char category;

	while (readFileRecord(fp, &riders[i]) == 0 && i < NUMRIDERS) {
		i++;
	}

	BubbleSort(riders, NUMRIDERS);

	int choice;

	do {

		MenuDisplay();
		choice = getInt();

		switch (choice) {
		case 1:
			Record = Choice(riders, NUMRIDERS, limit, getCat(), 1);
			if (Record > 3) {
				Record = 3;
			}
			Output(riders, limit, Record);
			break;
		case 2:
			Record = Choice(riders, NUMRIDERS, limit, getCat(), 0);
			Output(riders, limit, Record);
			break;
		case 3:
			Record = Choice(riders, NUMRIDERS, limit, getCat(), 1);
			int begin = Record > 3 ? Record - 3 : 0;
			Output(riders, &limit[begin], Record - begin);
			break;
		case 4:
			i = 0;
			Record = Choice(riders, NUMRIDERS, limit, 's', 1);
			if (Record > 0) {
				winners[i] = riders[limit[0]];
				i++;
			}
			Record = Choice(riders, NUMRIDERS, limit, 'm', 1);
			if (Record > 0) {
				winners[i] = riders[limit[0]];
				i++;
			}
			Record = Choice(riders, NUMRIDERS, limit, 'l', 1);
			if (Record > 0) {
				winners[i] = riders[limit[0]];
				i++;
			}
			int Positions[] = { 0, 1, 2 };
			Output2(winners, Positions, i);
			break;

		}
	} while (choice);
}
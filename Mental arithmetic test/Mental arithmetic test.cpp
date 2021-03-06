#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

int answers[400];
char str_input[30];
int test = -1;
int true_num = 0;
int time_start, time_over;
int counter_0 = 1, counter_1 = 1, counter_2 = 1;
char question_name[30], log_name[30];


void creat_questions(int n) {
	FILE *fp0 = fopen(question_name, "w+");
	srand((time(NULL)));
	int a, b, ans, type, i = 0, j = 0, k = 0, l = 0, m = 0;
	while (i < n / 4 || j < n / 4 || k < n / 4 || l < n / 4) {
		type = rand() % 15 + 0;
		if (type == 0 && i < n / 4) {
			a = rand() % 1000 + 0;
			b = rand() % 1000 + 0;
			ans = a + b;
			fprintf(fp0, "%d + %d = %d\n", a, b, ans);
			i++;
			answers[m] = ans;
			m++;
		}
		if (type == 1 && j < n / 4) {
			a = rand() % 1000 + 0;
			b = rand() % 1000 + 0;
			ans = a - b;
			fprintf(fp0, "%d - %d = %d\n", a, b, ans);
			j++;
			answers[m] = ans;
			m++;
		}
		if (type == 2 && k < n / 4) {
			a = rand() % 100 + 0;
			b = rand() % 100 + 0;
			ans = a * b;
			fprintf(fp0, "%d * %d = %d\n", a, b, ans);
			k++;
			answers[m] = ans;
			m++;
		}
		if (type >= 3 && l < n / 4) {
			a = rand() % 100 + 1;
			b = rand() % 100 + 1;
			if (a%b == 0) {
				ans = a / b;
				fprintf(fp0, "%d / %d = %d\n", a, b, ans);
				l++;
				answers[m] = ans;
				m++;
			}
		}
	}
	fclose(fp0);
}

void creat_questions_easy(int n) {
	FILE *fp0 = fopen(question_name, "w+");
	srand((time(NULL)));
	int a, b, ans, type, i = 0, j = 0, k = 0, l = 0, m = 0;
	while (i < n / 4 || j < n / 4 || k < n / 4 || l < n / 4) {
		type = rand() % 15 + 0;
		if (type == 0 && i < n / 4) {
			a = rand() % 100 + 0;
			b = rand() % 100 + 0;
			ans = a + b;
			fprintf(fp0, "%d + %d = %d\n", a, b, ans);
			i++;
			answers[m] = ans;
			m++;
		}
		if (type == 1 && j < n / 4) {
			a = rand() % 100 + 0;
			b = rand() % 100 + 0;
			ans = a - b;
			fprintf(fp0, "%d - %d = %d\n", a, b, ans);
			j++;
			answers[m] = ans;
			m++;
		}
		if (type == 2 && k < n / 4) {
			a = rand() % 10 + 0;
			b = rand() % 10 + 0;
			ans = a * b;
			fprintf(fp0, "%d * %d = %d\n", a, b, ans);
			k++;
			answers[m] = ans;
			m++;
		}
		if (type >= 3 && l < n / 4) {
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			if (a%b == 0) {
				ans = a / b;
				fprintf(fp0, "%d / %d = %d\n", a, b, ans);
				l++;
				answers[m] = ans;
				m++;
			}
		}
	}
	fclose(fp0);
}

int input_ans() {
	FILE *fp3 = fopen(log_name, "a+");
	gets_s(str_input);
	fprintf(fp3, "%d.          %s---", counter_0, str_input);
	fclose(fp3);
	char str_q[] = "quit";
	int if_q = strcmp(str_input, str_q);
	if (if_q != 0) {
		counter_0++;
	}
	return if_q;
}

int int_to_str_1(int n) {
	char a0 = (n + 48);
	char str[2];
	str[0] = a0;
	str[1] = '\0';
	return strcmp(str_input, str);
}

int int_to_str_minus1(int n) {
	n = -n;
	char a0 = (n + 48);
	char str[3];
	str[0] = '-';
	str[1] = a0;
	str[2] = '\0';
	return strcmp(str_input, str);
}

int int_to_str_2(int n) {
	int b = n / 10;
	n -= 10 * b;
	char a0 = (b + 48);
	char a1 = (n + 48);
	char str[3];
	str[0] = a0;
	str[1] = a1;
	str[2] = '\0';
	return strcmp(str_input, str);
}

int int_to_str_minus2(int n) {
	n = -n;
	int b = n / 10;
	n -= 10 * b;
	char a0 = (b + 48);
	char a1 = (n + 48);
	char str[4];
	str[0] = '-';
	str[1] = a0;
	str[2] = a1;
	str[3] = '\0';
	return strcmp(str_input, str);
}

int int_to_str_3(int n) {
	int b = n / 100;
	n -= 100 * b;
	int c = n / 10;
	n -= 10 * c;
	char a0 = (b + 48);
	char a1 = (c + 48);
	char a2 = (n + 48);
	char str[4];
	str[0] = a0;
	str[1] = a1;
	str[2] = a2;
	str[3] = '\0';
	return strcmp(str_input, str);
}

int int_to_str_minus3(int n) {
	n = -n;
	int b = n / 100;
	n -= 100 * b;
	int c = n / 10;
	n -= 10 * c;
	char a0 = (b + 48);
	char a1 = (c + 48);
	char a2 = (n + 48);
	char str[5];
	str[0] = '-';
	str[1] = a0;
	str[2] = a1;
	str[3] = a2;
	str[4] = '\0';
	return strcmp(str_input, str);
}

int int_to_str_4(int n) {
	int b = n / 1000;
	n -= 1000 * b;
	int c = n / 100;
	n -= 100 * c;
	int d = n / 10;
	n -= 10 * d;
	char a0 = (b + 48);
	char a1 = (c + 48);
	char a2 = (d + 48);
	char a3 = (n + 48);
	char str[5];
	str[0] = a0;
	str[1] = a1;
	str[2] = a2;
	str[3] = a3;
	str[4] = '\0';
	return strcmp(str_input, str);
}

void stat(int n) {
	FILE *fp7 = fopen(log_name, "a+");
	float f_true_num = true_num;
	float f_n = n;
	float rate_of_true = 100 * (f_true_num / f_n);
	printf("\nCorrect rate: %4.2f%%\n", rate_of_true);
	fprintf(fp7, "\nCorrect rate: %4.2f%%\n", rate_of_true);
	fclose(fp7);
}

void command_test(int input) {
	FILE *fp4 = fopen(log_name, "a+");
	if (input_ans() == 0) {
		test = -2;
	}
	else {
		if (input >= 0 && input < 10) {
			test = int_to_str_1(input);
		}
		if (input > -10 && input < 0) {
			test = int_to_str_minus1(input);
		}
		if (input >= 10 && input < 100) {
			test = int_to_str_2(input);
		}
		if (input > -100 && input <= -10) {
			test = int_to_str_minus2(input);
		}
		if (input >= 100 && input < 1000) {
			test = int_to_str_3(input);
		}
		if (input > -1000 && input <= -100) {
			test = int_to_str_minus3(input);
		}
		if (input >= 1000 && input < 10000) {
			test = int_to_str_4(input);
		}
	}
	if (test == -2) {
		printf("\n");
		fprintf(fp4, "---break\n");
	}
	if (test == 0) {
		printf("True\n\n");
		fprintf(fp4, "---True\n\n");
		true_num++;
	}
	if (test != -2 && test != 0) {
		printf("False\n\n");
		fprintf(fp4, "---False\n\n");
	}
	fclose(fp4);
}

void command_main() {
	int n;
	printf("\n------Input the number of questions.------\n");
	printf("--------It must be a multiple of 4--------\n\n");
	scanf("%d", &n);
	time_start = clock();
	if (n % 4 == 0 && n <= 400) {
		printf("\n--Input answers for folowing %d questions.-\n\n", n);
		printf("----------Quit by input 'quit'.-----------\n\n");
		creat_questions(n);
		FILE *fp1 = fopen(question_name, "r+");
		FILE *fp2 = fopen(log_name, "a+");
		char str[101];
		char clear;
		while ((clear = getchar()) != EOF && clear != '\n') {
			scanf("%c", &clear);
		}
		int int_if_quit = 0;
		int i = 0;
		while (i < n) {
			if (test != -2) {
				fgets(str, 100, fp1);
				for (int i = 0; str[i] != '='; i++) {
					printf("%c", str[i]);
				}
				printf("\n");
				fprintf(fp2, "%d.          %s", counter_1, str);
				counter_1++;
				command_test(answers[i]);
				i++;
			}
			else {
				printf("---Are you sure to quit the program? (y/n)---\n");
				char if_quit;
				scanf("%c", &if_quit);
				if (if_quit == 'y') {
					char clear;
					int_if_quit += 1;
					break;
				}
				else if (if_quit == 'n') {
					while ((clear = getchar()) != EOF && clear != '\n') {
						scanf("%c", &clear);
					}
					i--;
					for (int i = 0; str[i] != '='; i++) {
						printf("%c", str[i]);
					}
					printf("\n");
					command_test(answers[i]);
					i++;
				}
				else {
					while ((clear = getchar()) != EOF && clear != '\n') {
						scanf("%c", &clear);
					}
					printf("illegal input\n");
				}
			}
		}
		fclose(fp1);
		fclose(fp2);
		if (int_if_quit == 0) {
			stat(n);
		}
	}
	else {
		printf("illegal input\n");
	}
}

void command_main_easy() {
	int n;
	printf("\n------Input the number of questions.------\n");
	printf("--------It must be a multiple of 4--------\n\n");
	scanf("%d", &n);
	time_start = clock();
	if (n % 4 == 0 && n <= 400) {
		printf("\n--Input answers for folowing %d questions.-\n\n", n);
		printf("----------Quit by input 'quit'.-----------\n\n");
		creat_questions_easy(n);
		FILE *fp1 = fopen(question_name, "r+");
		FILE *fp2 = fopen(log_name, "a+");
		char str[101];
		char clear;
		while ((clear = getchar()) != EOF && clear != '\n') {
			scanf("%c", &clear);
		}
		int int_if_quit = 0;
		int i = 0;
		while (i < n) {
			if (test != -2) {
				fgets(str, 100, fp1);
				for (int i = 0; str[i] != '='; i++) {
					printf("%c", str[i]);
				}
				printf("\n");
				fprintf(fp2, "%d.          %s", counter_1, str);
				counter_1++;
				command_test(answers[i]);
				i++;
			}
			else {
				printf("---Are you sure to quit the program? (y/n)---\n");
				char if_quit;
				scanf("%c", &if_quit);
				if (if_quit == 'y') {
					int_if_quit += 1;
					break;
				}
				else if (if_quit == 'n') {
					while ((clear = getchar()) != EOF && clear != '\n') {
						scanf("%c", &clear);
					}
					i--;
					for (int i = 0; str[i] != '='; i++) {
						printf("%c", str[i]);
					}
					printf("\n");
					command_test(answers[i]);
					i++;
				}
				else {
					while ((clear = getchar()) != EOF && clear != '\n') {
						scanf("%c", &clear);
					}
					printf("illegal input\n");
				}
			}
		}
		fclose(fp1);
		fclose(fp2);
		if (int_if_quit == 0) {
			stat(n);
		}
	}
	else {
		printf("illegal input\n");
	}
}

void time_counter(int n) {
	FILE *fp8 = fopen(log_name, "a+");
	int time_s = n / 1000;
	int time_h = time_s / 3600;
	if (time_h != 0) {
		time_s = time_s - 3600 * time_h;
	}
	int time_min = time_s / 60;
	if (time_min != 0) {
		time_s = time_s - 60 * time_min;
	}
	printf("time: %d hour(s) %d minute(s) %d second(s)\n\n", time_h, time_min, time_s);
	fprintf(fp8, "time: %d hour(s) %d minute(s) %d second(s)\n\n", time_h, time_min, time_s);
	fclose(fp8);
}

void test_mode() {
	char clear;
	while ((clear = getchar()) != EOF && clear != '\n') {
		scanf("%c", &clear);
	}
	printf("\n\nPlease input file name for your questions:\n");
	gets_s(question_name);
	printf("\nPlease input file name for your logs:\n");
	gets_s(log_name);
	FILE *fp5 = fopen(log_name, "w+");
	fprintf(fp5, "---------------log---------------\n\n");
	fclose(fp5);
	while (true) {
		FILE *fp6 = fopen(log_name, "a+");
		fprintf(fp6, "\n----------Round %d ----------\n\n", counter_2);
		fclose(fp6);
		counter_0 = 1, counter_1 = 1;
		counter_2++;
		command_main();
		time_over = clock();
		int total_time_ms = time_over - time_start;
		time_counter(total_time_ms);
		if (test != -2) {
			printf("--------Run test mode again? --------(y/n)\n");
			char if_continue;
			scanf("%c", &if_continue);
			if (if_continue == 'y') {
				true_num = 0;
				while ((clear = getchar()) != EOF && clear != '\n') {
					scanf("%c", &clear);
				}
				printf("\n\n");
			}
			else if (if_continue == 'n') {
				printf("\n\n");
				break;
			}
			else {
				printf("illegal input\n\n");
				break;
			}
		}
		else {
			break;
		}
	}
}

void test_mode_easy() {
	char clear;
	while ((clear = getchar()) != EOF && clear != '\n') {
		scanf("%c", &clear);
	}
	printf("\n\nPlease input file name for your questions:\n");
	gets_s(question_name);
	printf("\nPlease input file name for your logs:\n");
	gets_s(log_name);
	FILE *fp5 = fopen(log_name, "w+");
	fprintf(fp5, "---------------log---------------\n\n");
	fclose(fp5);
	while (true) {
		FILE *fp6 = fopen(log_name, "a+");
		fprintf(fp6, "\n----------Round %d ----------\n\n", counter_2);
		fclose(fp6);
		counter_0 = 1, counter_1 = 1;
		counter_2++;
		command_main_easy();
		time_over = clock();
		int total_time_ms = time_over - time_start;
		time_counter(total_time_ms);
		if (test != -2) {
			printf("--------Run test mode again? --------(y/n)\n");
			char if_continue;
			scanf("%c", &if_continue);
			if (if_continue == 'y') {
				true_num = 0;
				while ((clear = getchar()) != EOF && clear != '\n') {
					scanf("%c", &clear);
				}
				printf("\n\n");
			}
			else if (if_continue == 'n') {
				printf("\n\n");
				break;
			}
			else {
				printf("illegal input\n\n");
				break;
			}
		}
		else {
			break;
		}
	}
}

void view_file_mode() {
	char clear;
	while ((clear = getchar()) != EOF && clear != '\n') {
		scanf("%c", &clear);
	}
	FILE *fp9;
	char file_name[30], ch[31];
	printf("\nInput the name of file you want to open:\n");
	gets_s(file_name);
	if ((fp9 = fopen(file_name, "r+")) == NULL) {
		printf("This file does not exist...\n");
		exit(-1);
	}
	printf("\n");
	while (fgets(ch, 30, fp9) != 0) {
		printf("%s", ch);
	}
	printf("\n");
	fclose(fp9);
}

void creat_file_only() {
	char clear;
	while ((clear = getchar()) != EOF && clear != '\n') {
		scanf("%c", &clear);
	}
	printf("\nPlease input file name for your questions:\n");
	gets_s(question_name);
	int n, difficulty;
	printf("\n------Input the number of questions.------\n");
	printf("--------It must be a multiple of 4--------\n\n");
	scanf("%d", &n);
	if (n % 4 == 0 && n <= 400) {
		printf("\n-------------Choose difficulty------------\n");
		printf("--------------easy-------------1----------\n");
		printf("--------------normal-----------2----------\n");
		scanf("%d", &difficulty);
		switch (difficulty) {
		case 1: creat_questions_easy(n); break;
		case 2: creat_questions(n); break;
		default:printf("error\n"); break;
		}
		printf("\ncomplete\n\n\n");
	}
	else {
		printf("illegal input\n");
	}
}

void mode_select() {
	test = -1;
	int mode;
	printf("-------------Mode Selection--------------\n\n");
	printf("-------------Test Mode(Normal)----------1\n");
	printf("--------------Test Mode(Easy)-----------2\n");
	printf("----------------View File---------------3\n");
	printf("-------------Creat Questions------------4\n");
	printf("\n-----------------------------------------\n");
	scanf("%d", &mode);
	switch (mode) {
	case 1: test_mode(); break;
	case 2: test_mode_easy(); break;
	case 3: view_file_mode(); break;
	case 4: creat_file_only(); break;
	default:printf("error\n"); break;
	}
}

int main()
{
	while (1) {
		mode_select();
	}
	return 0;
}


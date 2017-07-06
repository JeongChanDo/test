#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(int size, char ***ps);
char* input_word(char *);
void check_size(int* size, char *** ps);
int check_word(char *temp, char **ps);
int check_exist(char* temp, char **ps);
void save_word(char *temp,char **ps);
void print_words(char **ps);
void free_areas(char ***ps);

int i;
int cnt = 0;

int res; // ���� �� �ڵ� 

void main() {

	int size = 5;
	char temp[100];

	char ** ps;

	init(size, &ps);

	while (1) {

		input_word(temp);

		if (strcmp(temp, "end") == 0)break;

		check_size(&size,&ps);

		if (check_word(temp, ps) >0) {
			save_word(temp, ps);
		}else continue;
		cnt++;
		printf("\n");
	}
	print_words(ps);
	free_areas(&ps);
}


//�Ҵ��� �������� �����Ѵ�.
void free_areas(char ***pps) {

	for (i = 0; i < cnt; i++) {

		free((*pps)[i]);
	}
	free(*pps);
}


//�Էµ� �ܾ���� ����Ѵ�.
void print_words(char **ps) {

	for (i = 0; i < cnt; i++) {
		printf("%s ",ps[i]);
	}
	printf("\n");
}


//���� ũ�⸦ Ȯ���ϰ� ������ �����ϸ� �޸𸮸� �� �Ҵ��Ѵ�.
void check_size(int *size_addr,char *** ps) {
	int size = *size_addr;
	//printf("���� ũ�� : %d\n", size);
	if (cnt == size) {
		//printf("cnt�� ����� �����ϴ�. \n");

		size += 5;
		*ps = (char **)realloc(*ps, size * sizeof(char*));
		//printf("ps�� ���Ҵ� �Ͽ����ϴ�. \n");

		for (i = size - 5; i < size; i++) {
			(*ps)[i] = (char*)malloc(100*sizeof(char));
		}
		//printf("������ ũ�� : %d\n", size);

	}

}

//cnt�� �����Ѵ�.
void save_word(char *temp, char **ps) {
	//printf("cnt : %d\n", cnt);
	//printf("temp : %s\n", temp);
	strcpy(ps[cnt], temp);
	//printf("ps[%d] : %s\n", cnt,ps[cnt]);

}

//�Է��� �����ϸ� 1 �ƴϸ� 0�� �����Ѵ�.
int check_word(char *temp,char **ps) {

	char fore_word[100] = {0};
	int last_index;
	char last_alpa;

	if (cnt > 0) {
		strcpy(fore_word, ps[cnt-1]);

		last_index = strlen(fore_word) - 1;
		last_alpa = fore_word[last_index];

		if (last_alpa == temp[0]) {

			if (check_exist(temp, ps)>0) {
				printf("#�̹� �����ϴ� �ܾ� �Դϴ�!\n");
				return 0;
			}
			return 1;
		}
		else {
			printf("�ܾ� �ձⰡ �Ұ��� �մϴ�!\n");
			return 0;
		}

	}
	else {
		return 1;
	}

}

//temp�� �Է¹޴´�.
char* input_word(char *temp) {

	printf("�ܾ� �Է� : ");
	scanf("%s", temp);
	return temp;
}

//�ش� �ܾ �����ϸ� 1 �������������� 0�� �����Ѵ�.
int check_exist(char* temp, char **ps) {

	for (i = 0; i < cnt; i++) {
		if (strcmp(temp, ps[i]) == 0) return 1;
	}
	return 0;
}

//�ʱ�ȭ �Լ�
void init(int size, char ***ps) {
	
	*ps= (char **)malloc(size * sizeof(char*));
	//printf("ps�� �ʱ�ȭ �Ͽ����ϴ�.\n");

	for (i = 0; i < size; i++) {
		(*ps)[i] = (char *)malloc(100 * sizeof(char));
	}

}

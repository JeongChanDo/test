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

int res; // 내가 쓴 코드 

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


//할당한 영역들을 해제한다.
void free_areas(char ***pps) {

	for (i = 0; i < cnt; i++) {

		free((*pps)[i]);
	}
	free(*pps);
}


//입력된 단어들을 출력한다.
void print_words(char **ps) {

	for (i = 0; i < cnt; i++) {
		printf("%s ",ps[i]);
	}
	printf("\n");
}


//공간 크기를 확인하고 공간이 부족하면 메모리를 더 할당한다.
void check_size(int *size_addr,char *** ps) {
	int size = *size_addr;
	//printf("현재 크기 : %d\n", size);
	if (cnt == size) {
		//printf("cnt와 사이즈가 같습니다. \n");

		size += 5;
		*ps = (char **)realloc(*ps, size * sizeof(char*));
		//printf("ps를 재할당 하였습니다. \n");

		for (i = size - 5; i < size; i++) {
			(*ps)[i] = (char*)malloc(100*sizeof(char));
		}
		//printf("수정된 크기 : %d\n", size);

	}

}

//cnt에 저장한다.
void save_word(char *temp, char **ps) {
	//printf("cnt : %d\n", cnt);
	//printf("temp : %s\n", temp);
	strcpy(ps[cnt], temp);
	//printf("ps[%d] : %s\n", cnt,ps[cnt]);

}

//입력이 가능하면 1 아니면 0을 리턴한다.
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
				printf("#이미 존재하는 단어 입니다!\n");
				return 0;
			}
			return 1;
		}
		else {
			printf("단어 잇기가 불가능 합니다!\n");
			return 0;
		}

	}
	else {
		return 1;
	}

}

//temp에 입력받는다.
char* input_word(char *temp) {

	printf("단어 입력 : ");
	scanf("%s", temp);
	return temp;
}

//해당 단어가 존재하면 1 존재하지않으면 0을 리턴한다.
int check_exist(char* temp, char **ps) {

	for (i = 0; i < cnt; i++) {
		if (strcmp(temp, ps[i]) == 0) return 1;
	}
	return 0;
}

//초기화 함수
void init(int size, char ***ps) {
	
	*ps= (char **)malloc(size * sizeof(char*));
	//printf("ps를 초기화 하였습니다.\n");

	for (i = 0; i < size; i++) {
		(*ps)[i] = (char *)malloc(100 * sizeof(char));
	}

}

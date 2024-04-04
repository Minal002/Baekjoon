#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int compare(const void * a, const void *b);

int main(void) {
	int N;
	char word[9];
	int alpha[26] = {0};
	int i, j, len, result = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) { // 모든 단어들
		scanf("%s", word);
		len = strlen(word);
		for (j = 0; j < len; j++) { // 각 단어별로
			alpha[word[j] - 'A'] += pow(10, len - 1 - j); // 자릿수 저장
		}
	}
	//정렬
	qsort(alpha, 26, sizeof(int), compare);

	for (i = 0; i < 10; i++) {
		result += alpha[i] * (9 - i);
	}
		printf("%d", result);
}

int compare(const void * a, const void *b) {
	return *(int *)b - *(int *)a;
}
#include <stdio.h>

int main (void) {
    int n, i, j, max = 0;
    scanf("%d", &n);
    int a[n];
    int sum[n];
    
    for (i = 0; i < n; i++) { // 수열 입력
        scanf("%d", &a[i]);
    }

    sum[0] = a[0]; // 인덱스 0부터 저장, 앞의 수가 더 작으면 합을 배열에 저장
    for (i = 1; i < n; i++) {
        sum[i] = a[i];
        for (j = 0; j < i; j++) {
            if (a[i] > a[j]) { // i보다 앞 숫자 j가 더 작을 때
                if (sum[i] < sum[j] + a[i]) // j에 들어있는 합과 i값을 더해줌
                sum[i] = sum[j] + a[i];
            }
        }
    }
  
	for(i = 0; i < n ; i++)
	{
		if(sum[i] > max) max = sum[i];
	}
    printf("%d\n", max);
}
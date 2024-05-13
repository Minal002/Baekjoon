#include <stdio.h>
#include <stdlib.h>

int n;
int count = 0;
int board[15];

int promising(int row) { // 같은 열, 대각선 상에 없으면 유효 -> 1반환
    for (int i = 0; i < row; i++) {
        if (board[row] == board[i] || row - i == abs(board[row] - board[i])) {
            return 0;
        }
    }
    return 1;
}

void nQueen(int row) {
    if (row == n) { // 퀸을 다 놓게 되면(행이 끝나면) 카운트
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        board[row] = col; // 보드판의 한 행에서 퀸을 놓는 경우
        if (promising(row)) { // 해당 열에 놓아도 되면
            nQueen(row + 1); // 다음 행 확인 하기 / 함수 호출이 끝나면 다음 열 확인 하기
        }
    }
}

int main (void) {
    scanf("%d", &n);
    nQueen(0);
    printf("%d\n", count);
}
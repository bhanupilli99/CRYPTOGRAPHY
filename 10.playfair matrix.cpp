
#include <stdio.h>
#include <string.h>
void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';  
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptDigraph(char matrix[5][5], char a, char b) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);
    
    if (row1 == row2) {
        printf("%c%c ", matrix[row1][(col1 + 1) % 5], matrix[row2][(col2 + 1) % 5]);
    } else if (col1 == col2) {
        printf("%c%c ", matrix[(row1 + 1) % 5][col1], matrix[(row2 + 1) % 5][col2]);
    } else {
        printf("%c%c ", matrix[row1][col2], matrix[row2][col1]);
    }
}

int main() {
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    
    char message[] = "Must see you over Cadogan West. Coming at once.";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (message[i] == ' ' || message[i] == '.' || message[i] == ',') {
            for (int j = i; j < len; j++) {
                message[j] = message[j + 1];
            }
            len--;
        }
    }
    for (int i = 0; i < len; i += 2) {
        encryptDigraph(matrix, message[i], message[i + 1]);
    }
    
    return 0;
}



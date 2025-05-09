#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // Max. Anzahl der Scheiben (für die Darstellung)

void push(int stack[], int *top, int value) {
    stack[++(*top)] = value;
}

int pop(int stack[], int *top) {
    if (*top == -1) return -1;
    return stack[(*top)--];
}

void zeige_stäbe(int A[], int topA, int B[], int topB, int C[], int topC, int n) {
    printf("\nAktueller Zustand:\n");
    printf("%-10s %-10s %-10s\n", "Stab A", "Stab B", "Stab C");
    for (int i = n - 1; i >= 0; i--) {
        // Gib das i-te Element von oben aus oder leer
        if (i <= topA)
            printf("%-10d ", A[i]);
        else
            printf("%-10s ", "|");

        if (i <= topB)
            printf("%-10d ", B[i]);
        else
            printf("%-10s ", "|");

        if (i <= topC)
            printf("%-10d\n", C[i]);
        else
            printf("%-10s\n", "|");
    }
    printf("------------------------------\n");
}

void move(int from[], int *top_from, int to[], int *top_to, char name_from, char name_to,
          int A[], int topA, int B[], int topB, int C[], int topC, int n) {
    int ring = pop(from, top_from);
    push(to, top_to, ring);
    printf("Bewege Scheibe %d von %c nach %c\n", ring, name_from, name_to);
    zeige_stäbe(A, topA, B, topB, C, topC, n);
}

void hanoi(int n,
           int src[], int *top_src, char name_src,
           int dest[], int *top_dest, char name_dest,
           int aux[], int *top_aux, char name_aux,
           int A[], int *topA, int B[], int *topB, int C[], int *topC, int total) {
    
    if (n == 1) {
        move(src, top_src, dest, top_dest, name_src, name_dest, A, *topA, B, *topB, C, *topC, total);
        return;
    }

    hanoi(n - 1, src, top_src, name_src, aux, top_aux, name_aux,
          dest, top_dest, name_dest, A, topA, B, topB, C, topC, total);

    move(src, top_src, dest, top_dest, name_src, name_dest, A, *topA, B, *topB, C, *topC, total);

    hanoi(n - 1, aux, top_aux, name_aux, dest, top_dest, name_dest,
          src, top_src, name_src, A, topA, B, topB, C, topC, total);
}

int main() {
    int n;
    printf("Anzahl der Scheiben (max. %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX || n <= 0) {
        printf("Ungültige Anzahl.\n");
        return 1;
    }

    int A[MAX], B[MAX], C[MAX];
    int topA = -1, topB = -1, topC = -1;

    for (int i = n; i >= 1; i--) {
        push(A, &topA, i);
    }

    zeige_stäbe(A, topA, B, topB, C, topC, n);

    printf("Züge:\n");
    hanoi(n, A, &topA, 'A', C, &topC, 'C', B, &topB, 'B', A, &topA, B, &topB, C, &topC, n);

    return 0;
}

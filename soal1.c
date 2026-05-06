/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
* Modul : 4 - Dynamic Structure
* Hari dan Tanggal : Rabu, 6 Mei 2026
* Nama File : 
* Pembuat : Joachim (13224034)
* Deskripsi: 
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char nama[50];
} pasien;

typedef struct {
    pasien items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return (q->front == q->rear - 1);
}

void enqueue(Queue *q, char* nama) {
    // Memasukkan data ke posisi rear
    strcpy(q->items[q->rear].nama, nama);
    q->rear++;
}


void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Tidak ada data\n");
        return;
    }

    printf("ORDER ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%s ", q->items[i].nama);
    }
}

int main() {
    Queue antiran;
    initializeQueue(&antiran);
    int N;
    char id[50];
    int waktu = 0; int totalwaktu = 0; int TOTALWAKTU = 0;

    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        totalwaktu = totalwaktu + waktu;
        TOTALWAKTU = TOTALWAKTU + totalwaktu;
        scanf("%s %d", id ,&waktu);
        enqueue(&antiran, id);
    }

    printQueue(&antiran);
    printf("\nWAIT %d", TOTALWAKTU);
}

//4 A01 3 AO2 5 A03 2 A04 4

//AO1 = 0
//A02 = 3
//A03 = 8
//A04 = 11
//TOTAL = 22

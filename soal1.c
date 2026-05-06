/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
* Modul : 4 - Dynamic Structure
* Hari dan Tanggal : Rabu, 6 Mei 2026
* Nama File : antrian.c
* Pembuat : Joachim (13224034)
* Deskripsi: kasih list antrian, hitung jumlah waktu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node of the linked list
typedef struct Node{
    char data[50];
    struct Node *next;
} node;

// Define the structure for the queue
typedef struct Queue{
    node *front;
    node *rear;
} queue;

// Function to create a new queue
queue *createQueue(){
    // Allocate memory for a new queue
    queue *newQueue = (queue *)malloc(sizeof(queue));
    // Initialize the front and rear pointers of the queue
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(queue *q){
    // Check if the front pointer is NULL
    return q->front == NULL;
}

// Function to create a new node
node *createNode(char* data){
    // Allocate memory for a new node
    node *newNode = (node *)malloc(sizeof(node));
    // Check if memory allocation was successful
    if (newNode == NULL)
        return NULL;
    // Initialize the node's data and next pointer
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the queue
void enqueue(queue *q, char *data){
    // Create a new node with the given data

    node *newNode = createNode(data);
    strcpy(newNode->data, data);

    // Add the new node at the end of the queue and update
    // the rear pointer
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;

    q->rear = newNode;
}



void printQueue(queue *q){
    // Traverse the queue and print each element
    node *temp = q->front;
    printf("ORDER");
    while (temp != NULL)
    {
        printf(" %s", temp->data);
        temp = temp->next;
    }
}


int main(){
    int N;
    char id[5];
    int waktu = 0; int totalwaktu = 0; int TOTALWAKTU = 0;
    queue *q = createQueue();

    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        totalwaktu = totalwaktu + waktu;
        TOTALWAKTU = TOTALWAKTU + totalwaktu;
        scanf("%s %d", id ,&waktu);
        enqueue(q, id);
    }
    

    printQueue(q);
    printf("\nWAIT %d", TOTALWAKTU);

}

//4 A01 3 AO2 5 A03 2 A04 4

//AO1 = 0
//A02 = 3
//A03 = 8
//A04 = 11
//TOTAL = 22

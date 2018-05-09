#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define true 1
#define false 0

typedef int datatype;
typedef struct queue {
	datatype sp_queue_array[MAX_QUEUE_SIZE];
	int front;
	int rear;
}sp_queue;

sp_queue queue_init() {
	sp_queue q;
	q.front = q.rear = 0;
	return q;
}

int queue_empty(sp_queue q) {
	return q.front == q.rear;
}

int queue_en(sp_queue *q, datatype e) {
	if(q->rear == MAX_QUEUE_SIZE) {
		return false;
	}
	q->sp_queue_array[q->rear] = e;
	printf("q.sp_queue_array[%d] = %d\n", q->rear, e);
	q->rear += 1;
	return true;
}

int queue_de(sp_queue *q, datatype *e) {
	if(queue_empty(*q)) {
		return false;
	}
	q->rear -= 1;
	*e = q->sp_queue_array[q->rear];
	return true;	
}

void queue_clear(sp_queue *q) {
	q->front = q->rear = 0;
}
int get_front(sp_queue q, datatype *e) {
	if(q.front == q.rear) {
		return false;
	}
	*e = q.sp_queue_array[q.front];
	return true;
}
int queue_len(sp_queue q) {
	return (q.rear - q.front);
}

void queue_traverse(sp_queue q, void(*visit)(sp_queue q)) {
	visit(q);
}

void visit(sp_queue q) {
	if(q.front == q.rear) {
		printf("null queue!\n");
	}
	int temp = q.front;
	while(temp != q.rear) {
		printf("[%d]", q.sp_queue_array[temp]);
		temp += 1;
	}
	printf("\n");
}

int main () {
	sp_queue q = queue_init();
	int i = 0;

	for(; i<15; i++) {
		queue_en(&q, i);
		printf("length = %d\n", queue_len(q));
	}
	queue_traverse(q, visit);
	datatype *e = (datatype *)malloc(sizeof(*e));
	queue_de(&q, e);
	printf("length = %d\n", queue_len(q));
	queue_traverse(q, visit);
	queue_clear(&q);
	queue_traverse(q, visit);
	printf("length = %d\n", queue_len(q));

	free(e);

	return 0;
}







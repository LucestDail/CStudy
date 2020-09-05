#pragma warning(disable: 4996) 

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 100

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType queue;

//error push function
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//initialization function
void init(QueueType* q) {
	q->front = q->rear = 0;
}

//empty check function
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐 포화 상태");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐 공백 상태");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peak(QueueType* q) {
	if (is_empty(q)) {
		error("큐 공백 상태");
	}
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

double random() {
	//srand((unsigned)time(NULL));
	return rand() / (double)RAND_MAX;
}

int duration = 10;
double arrival_prob = 0.7;
int max_serv_time = 5;
int clocker;

int customers;
int served_customers;
int waited_time;

int is_customer_arrived() {
	if (random() < arrival_prob) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void insert_customer(int arrival_time) {
	element customer;
	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time * random()) + 1;
	enqueue(&queue, customer);
	printf("[Arrival Time : %d] [Customer number - %d] => [Service Time : %d]\n", customer.arrival_time, customer.id, customer.service_time);
}

int remove_customer() {
	element customer;
	int service_time = 0;
	if (is_empty(&queue)) {
		return 0;
	}
	customer = dequeue(&queue);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += clocker - customer.arrival_time;
	printf("[Service Time : %d] [Customer number - %d] => [Waiting Time : %d]\n", clocker, customer.id, clocker - customer.arrival_time);
	return service_time;
}

void timeprint(void)
{
	time_t ct;
	struct tm tm;
	ct = time(NULL);
	tm = *localtime(&ct);
	printf("current time: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

print_stat() {
	printf("========================================\n");
	printf("* Served Customer : %d\n",served_customers);
	printf("* Whole Waiting Time : %d\n", waited_time);
	printf("* Average Waiting Time : %f\n", (double)waited_time / served_customers);
	printf("* Waiting Customers : %d\n", customers - served_customers);
	printf("========================================\n");
}

void main() {
	int service_time = 0;
	timeprint();
	clocker = 0;
	while (clocker < duration) {
		clocker++;
		printf("[ Time : %d ]\n", clocker);
		if (is_customer_arrived()) {
			insert_customer(clocker);
		}
		if (service_time > 0) {
			service_time--;
		}
		else {
			service_time = remove_customer();
		}
	}
	print_stat();
}
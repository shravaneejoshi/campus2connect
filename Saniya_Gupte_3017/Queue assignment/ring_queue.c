#include<stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue{

    int data[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;

} rq_t;

int rq_init( rq_t *q)
{
    if( q==NULL ) return -1;
    q->front=0;
    q->rear=0;
    q->count=0;
    return 0;
}

int rq_enqueue( rq_t *q , int value)
{
    if( q==NULL)
    {
        return -1;
    }
    if( q->count == MAX_QUEUE_LEN)
    {
        return -1;
    }

    q->data[q->rear]=value;
    q->rear=(q->rear+1) % MAX_QUEUE_LEN;
    q->count++;
    return 0; 
}

int rq_dequeue( rq_t *q , int *value )
{
    if( q==NULL || value== NULL)
    {
        return -1;
    }
    if( q->count == 0)
    {
        return -1;
    }
    *value = q->data[q->front];
    q->front= ( q->front+1 ) % MAX_QUEUE_LEN;
    q->count--;
    return 0;
}

int main(void)
{
    rq_t q;
    rq_init(&q);

    rq_enqueue(&q , 10);
    rq_enqueue(&q , 20);
    rq_enqueue(&q , 30);

    int val;
    while( rq_dequeue( &q , &val)==0 )
    {
        printf("Dequeued: %d\n" , val);
    }

    return 0;

}
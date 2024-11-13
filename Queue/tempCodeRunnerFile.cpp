#include<iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *queue;
};

// 1. Enqueue() : used to insert new element at rear
void enqueue(struct queue *q, int x)
{
    if(q->rear == q->size-1)
    {
        cout << "Queue is full can't enter any new element." << endl;
    }
    else
    {
        q->rear++;
        q->queue[q->rear] = x;
    }
}


// 2. Dequeue() : used to delete an element from front by just moving the couter 1 step ahead
int dequeue(struct queue *q)
{
    int x = -1; // at last it will return -1 if queue will be empty
    if(q->front == q->rear) // if counter is on rear position or say last position then there will be no element in queue
    {
        cout << "Deletion not performed as no element is inside queue." << endl;
    }
    else
    {
        q->front++;
        x = q->queue[q->front];
        // q->queue[q->front] = 0; not necessary
    }
    return x;
}


// 3. To display the Queue
void display(struct queue *q)
{
    cout << endl << "Below is the queue : " << endl;
    for(int i = q->front+1; i <= q->rear; i++) // here q->front+1 , extra +1 was for printing the next values from the already moved counter and not from the counter itself
    {
        cout << q->queue[i] << " "; 
    }
}


int main()
{
    struct queue q;
    q.size = 5;
    q.front = -1;
    q.rear = -1;
    q.queue = new int[q.size];

    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);

    cout << endl << "Element deleted is : " << dequeue(&q);   // here the dequeue operation is performed at head of queue only as,
    cout << endl << "Element deleted is : " << dequeue(&q);   // people leave from the first position in queue after their work is completed.
    cout << endl << "Element deleted is : " << dequeue(&q);

    
    display(&q);

    delete[] q.queue; // freed the dynamic array created for queue

    return 0;
}

//PRIORITY QUEUE(HEAP)
#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
int i;
void insert(int val)
{
    int i = size;
    heap[size++] = val;

    while(i != 0 && heap[(i-1)/2] < heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void heapify(int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] > heap[largest])
        largest = left;

    if(right < size && heap[right] > heap[largest])
        largest = right;

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(largest);
    }
}

void deleteMax()
{
    if(size == 0)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", heap[0]);
    heap[0] = heap[size-1];
    size--;
    heapify(0);
}

void display()
{
    for(i=0;i<size;i++)
        printf("%d ",heap[i]);
    printf("\n");
}

int main()
{
    int ch,x;
    while(1)
    {
        printf("\n1.Insert\n2.Delete Highest Priority\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                insert(x);
                break;

            case 2:
                deleteMax();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}
#include <iostream>

using namespace std;

template <class T>

class queue
{
private:
    int front, rear;
    T *Q , value;

    int size;

public:
    queue(int size)
    {
        this->front = -1;
        this->rear = -1;
        this->size = size;
        this->Q = new T[size];
    }


    void getdata()
{
    T value;

    cout<<"Enter the value"<<endl;
    cin>>value;
    Enqueue(value);
}
    void Enqueue(T value)
    {
        if (rear == size - 1)
            cout << "Queue is Full \n Cannot enqueue" << endl;

        else
        {
            Q[++rear] = value;
        }
    }

    int Dequeue()
    {
        int x = -1;
        if (front == rear)
            cout << "Cannot Dequeue\n Queue is empty" << endl;

        else
        {
            x = Q[++front];
        }
        return x;
    }

    void display()
    {
        int i;
        cout << "Displaying the queue elements" << endl;
        for (int i = front + 1; i <= rear; i++)
            cout << "Q[" << i << "] = " << Q[i] << endl;
    }
};

int main()
{

    queue<float>Queue(5);
    // Queue.Enqueue(5);
    // Queue.Enqueue(52);
    // Queue.Enqueue(15);
    // Queue.Enqueue(55);
    // Queue.Enqueue(85);

    // Queue.display();

    // Queue.Dequeue();
    //  Queue.display();

    int option;
   
   
    while (1)
    {
         cout << "Enter option" << endl;
    cin >> option;
        switch (option)

        {
        case 1:
            Queue.getdata();
           
            break;

        case 2:
            Queue.Dequeue();
            break;

        case 3:
            Queue.display();
            break;

        case 4:
            exit(0);
            break;
        }
    }

    return 0;
}
// Inserting after given position in LL
// Author: REET

/*
There are two places where we can insert
the element.
    1.Inserting before first node.
    2.Inserting after given position.
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * first;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    cout << "Node Elements are: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

struct Node *insert(int data, int position)
{
    struct Node *p = first;
    struct Node *n = new Node;
    n->data = data;
    for (int i = 0; i < (position - 1); i++)
    {
        p = p->next;
    }
    n->next = p->next;
    p->next = n;
    return first;
}

int main()
{
    int A[] = {3, 5, 17, 10, 15};
    create(A, 5);
    display(first);
    display(insert(28, 4));
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Node Elements are: 3 5 17 10 15 
Node Elements are: 3 5 17 10 28 15
*/
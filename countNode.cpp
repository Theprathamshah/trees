#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *MergeListIterative(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummy = new node(-1);
    node *p3 = dummy;
    while (p1 and p2)
    {
        if (p1->data <= p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
       else if (p1->data > p2->data)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    while (p1)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        InsertAtTail(head, arr[i]);
    }

    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    node *head2 = NULL;
    for (int i = 0; i < n; i++)
    {
        InsertAtTail(head2, arr2[i]);
    }
    Display(head);

    Display(head2);
    Display(MergeListIterative(head,head2));
    return 0;
}

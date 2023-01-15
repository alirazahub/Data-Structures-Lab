#include <iostream>
using namespace std;
class linkedList
{
public:
    struct node
    {
        int info;
        node *next;
    };
    node *list = NULL;
    node *p;
    node *q;
    node *temp;

    void insertAtFront(int value)
    {
        if (list == NULL)
        {
            p = new node;
            p->info = value;
            p->next = NULL;
            list = p;
        }
        else
        {
            p = new node;
            p->info = value;
            p->next = list;
            list = p;
        }
    }
    void deleteFromFront()
    {
        p = list;
        if (list == NULL)
        {
            cout << "No Node to delete" << endl;
        }
        else
        {
            list = list->next;
            delete (p);
        }
    }
    void insertAtEnd(int value)
    {
        if (list == NULL)
        {
            p = new node;
            p->info = value;
            p->next = NULL;
            list = p;
        }
        else
        {
            p = list;
            while (p->next != NULL)
            {
                p = p->next;
            }
            q = new node;
            q->info = value;
            q->next = NULL;
            p->next = q;
        }
    }
    void deleteFromEnd()
    {
        if (list == NULL)
        {
            cout << "No node to delete" << endl;
        }
        else
        {
            p = list;
            q = list;
            while (p->next != NULL)
            {
                q = p;
                p = p->next;
            }
            delete (p);
            q->next = NULL;
        }
    }

    void insertAtSpecfic(int point,int value){
        if (list == NULL)
        {
            p = new node;
            p->info = value;
            p->next = NULL;
            list = p;
        }else{
            q = list;
            while (q->next != NULL){
                if (q->info == point)
                {
                    p = new node;
                    p->info = value;
                    p->next = q->next;
                    q->next = p;
                }
                q=q->next;
            }
        }
    }
    void pairWiseSwapingData()
    {
        if (list == NULL)
        {
            cout << "No node available to Swap" << endl;
        }
        else if (list->next == NULL)
        {
            cout << "Pair not available to SWAP" << endl;
        }
        else
        {
            q = list;
            while (q != NULL && q->next != NULL)
            {
                int temp = q->info;
                q->info = (q->next)->info;
                (q->next)->info = temp;
                q = q->next->next;
            }
        }
    }

    void pairWiseSwapingNodes()
    {
        if (list == NULL)
        {
            cout << "No node available to Swap" << endl;
        }
        else if (list->next == NULL)
        {
            cout << "Pair not available to SWAP" << endl;
        }
        else
        {
            q = list;
            while (q != NULL && q->next != NULL)
            {
                temp = q;
                q = q->next;
                temp->next = q->next;
                q->next = temp;
                if (temp == list)
                    list = q;
                else
                    p->next = q;
                p = temp;
                q = temp->next;
            }
        }
    }

    void reverseNode()
    {
        node *p = list;
        node *q = NULL;
        node *r = NULL;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        list = q;
    }

    void sorting()
    {
        p = list;
        q = p->next;
        while (p->next != NULL)
        {
            while (q != NULL)
            {
                if (q->info < p->info)
                {
                    int temp = p->info;
                    p->info = q->info;
                    q->info = temp;
                }
                q = q->next;
            }
            p = p->next;
            q = p->next;
        }
    }

    void insertInSortedOrder(int value){
        temp = new node;
        temp->info = value;
        temp->next = NULL;

        if(list == NULL)
        {
            list = temp;
        }
        else
        {
            p = list;
            q = NULL;

            while(p != NULL && p->info < value)
            {
                q = p;
                p = p->next;
            }

            if(p == list)
            {
                temp->next = list;
                list = temp;
            }
            else
            {
                temp->next = q->next;
                q->next = temp;
            }
        }
    }
    void display()
    {
        if (list == NULL)
        {
            cout << "No node to print" << endl;
            return;
        }
        node *p;
        p = list;
        cout << "Linked List Contains:" << endl;

        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl
             << endl;
    }
};
int main()
{
    linkedList list;
    list.insertAtEnd(8);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(2);
    list.insertAtEnd(6);
    list.insertAtEnd(9);
    list.insertAtEnd(1);
    list.insertAtEnd(7);
    list.insertAtEnd(0);
    list.display();
    list.insertAtSpecfic(5,10);
    list.display();
    return 0;
}
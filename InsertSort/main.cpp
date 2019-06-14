#include <iostream>
#include <iomanip>

using namespace std;

struct list
{
    string value;
    list *next;
    list *prev;
};

void swapListElements(list *&inserBefore, list *& whatInsert){
    whatInsert->prev->next = whatInsert->next;
    if (whatInsert->next != NULL){
        whatInsert->next->prev = whatInsert->prev;
    }
    whatInsert->prev = inserBefore->prev;
    if (inserBefore->prev != NULL){
        inserBefore->prev->next = whatInsert;
    }
    inserBefore->prev = whatInsert;
    whatInsert->next = inserBefore;
}

void insertSort(list *&begin, list *&end)
{
    list *point = begin;
    list *insertPoint = point;
    bool swapIsDone;
    point = point->next;
    while (point)
    {
        swapIsDone = false;
        if (point->value < insertPoint->value)
        {
            for (; insertPoint->prev != NULL && insertPoint->prev->value > point->value; insertPoint = insertPoint->prev)
                ;
            swapListElements(insertPoint, point);
            swapIsDone = true;
            if (point->prev == NULL)
            {
                begin = point;
            }
        }
        if (swapIsDone)
            point = insertPoint;
        else
            insertPoint = point;
        point = point->next;
    }
};

int main()
{
    int j = 0;
    int i = 0;
    // while (j < 100)
    // {
    // int N = rand() % 14 + 1;
    int N = 4;
    string array[15] = {"4", "3", "2", "1", "8", "7", "2", "4"};
    // for (int i = 0; i < N; i++)
    // {
    //     int length = rand() % 10;
    //     for (int j = 0; j < length; j++)
    //         array[i].insert(j, 1, char(rand() % 25 + 65));
    // }
    list *begin = new list;
    begin->next = begin->prev = NULL;
    list *end = begin;
    for (int i = 1; i < N; i++)
    {
        end->next = new list;
        end->next->prev = end;
        end = end->next;
        end->next = NULL;
    };
    list *pointer = begin;
    for (int i = 0; i < N; i++)
    {
        pointer->value = array[i];
        pointer = pointer->next;
    }
    // for (list *i = begin; i != NULL; i = i->next)
    // {
    //     cout << setw(11) << left << i->value;
    // }
    // cout << setw(11) << left << "| ";
    insertSort(begin, end);
    // swapListElements(end->prev->prev, end->prev);
    i = 0;
    for (i = 0; begin != NULL; begin = begin->next, i++)
    {
        cout << setw(11) << left << begin->value;
    }
    if (i != N)
    {
        cout << "Error!" << endl;
        getchar();
        getchar();
    }
    cout << endl;
    j++;
    // }
};
#include <iostream>
#include <iomanip>

using namespace std;

struct Data
{
    string value;
    Data *prev;
    Data *next;
};

void swapElements(Data *&point1, Data *&point2)
{
    Data *buffer;
    if (point1 == point2)
        return;
    if (point1->prev != NULL)
        point1->prev->next = point2;
    if (point2->next != NULL)
        point2->next->prev = point1;
    if (point1->next != point2)
    {
        point1->next->prev = point2;
        point2->prev->next = point1;
        buffer = point2->prev;
        point2->prev = point1->prev;
        point1->prev = buffer;
        buffer = point2->next;
        point2->next = point1->next;
        point1->next = buffer;
        return;
    }
    point2->prev = point1->prev;
    point1->next = point2->next;
    point2->next = point1;
    point1->prev = point2;
    return;
}

// void swapElements(Data *&point1, Data *&point2){
//     swap(point1->value, point2->value);
// }

Data *partition(Data *&left, Data *&right, Data *&begin, Data *&end)
{
    string pivot = right->value;
    Data *i = left;
    i = i->prev;
    Data *buffer;
    for (Data *j = left; j != right; j = j->next)
    {
        if (j->value < pivot)
        {
            i = (i == NULL) ? left : i->next;
            swapElements(i, j);
            if (j->prev == NULL)
                begin = j;
            if (i->next == NULL)
                end = i;
            buffer = i;
            i = j;
            j = buffer;
        }
    }
    i = (i == NULL) ? left : i->next;
    Data * j = right;
    swapElements(i, j);
    buffer = i;
    i = right;
    right = buffer;
    return i;
}

void quickSort(Data *&left, Data *&right, Data *&begin, Data *&end)
{
    if (!left || !right || left == right || left == right->next)
        return;
    Data *p = partition(left, right, begin, end);
    quickSort(left, p->prev, begin, end);
    quickSort(p->next, right, begin, end);
}

int main()
{
    int j = 0;
    int i = 0;
    int N = 8;
    string array[15] = {"6", "5", "1", "3", "8", "7", "2", "4"};
    Data *begin = new Data;
    begin->next = begin->prev = NULL;
    Data *end = begin;
    for (int i = 1; i < N; i++)
    {
        end->next = new Data;
        end->next->prev = end;
        end = end->next;
        end->next = NULL;
    };
    Data *pointer = begin;
    for (int i = 0; i < N; i++)
    {
        pointer->value = array[i];
        pointer = pointer->next;
    }
    // swapElements(begin, end->prev, begin, end);
    quickSort(begin, end, begin, end);
    i = 0;
    for (i = 0; begin != NULL; begin = begin->next, i++)
    {
        cout << setw(11) << left << begin->value;
    }
}
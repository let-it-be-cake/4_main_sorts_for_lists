#include <iostream>
#include <iomanip>

using namespace std;

struct list
{
    string value;
    list *next;
    list *prev;
};

void swapListElements(list *&point1, list *&point2)
{
    point1->next = point2->next;
    point2->prev = point1->prev;
    if (point2->next != NULL)
        point2->next->prev = point1;
    if (point1->prev != NULL)
        point1->prev->next = point2;
    point1->prev = point2;
    point2->next = point1;
    return;
}

void bubbleSort(list *&begin, list *&end)
{
    list *point = begin;
    list *pointPrev = point;
    list *stopPoint = end;
    point = point->next;
    while (stopPoint != begin)
    {
        while (point != stopPoint->next)
        {
            if (point->value < pointPrev->value)
            {
                swapListElements(pointPrev, point);
                if (pointPrev->prev == stopPoint){
                    stopPoint = stopPoint->next;
                }
                if (point->prev == NULL)
                {
                    begin = point;
                }
                if (pointPrev->next == NULL)
                {
                    end = pointPrev;
                }
                point = pointPrev;
                pointPrev = point->prev;
            }
            pointPrev = point;
            point = point->next;
        }
        pointPrev = begin;
        point = pointPrev->next;
        stopPoint = stopPoint->prev;
    }
};

int main()
{
    int j = 0;
    int i = 0;
    int N = 8;
    string array[15] = {"2", "5", "3", "1", "8", "7", "2", "4"};
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
    bubbleSort(begin, end);
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
};
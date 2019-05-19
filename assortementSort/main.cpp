#include <iostream>
#include <iomanip>

using namespace std;

struct list
{
    string value;
    list *next;
    list *prev;
};

void swapElements(list *&point1, list *&point2)
{
    list *buffer;
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

void assortementSort(list *&begin, list *&end)
{
    list *insertPoint = begin;
    list *slider;
    list *swapBuffer;
    while (insertPoint != end)
    {
        slider = swapBuffer = insertPoint;
        while (slider != NULL)
        {
            if (slider->value < swapBuffer->value)
                swapBuffer = slider;
            slider = slider->next;
        }
        swapElements(insertPoint, swapBuffer);
        if (swapBuffer->prev == NULL)
            begin = swapBuffer;
        if (insertPoint->next == NULL)
            end = insertPoint;
        insertPoint = swapBuffer;
        insertPoint = insertPoint->next;
    }
}

int main()
{
    int j = 0;
    int i = 0;
    int N = 8;
    string array[15] = {"6", "5", "1", "3", "8", "7", "2", "4"};
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
    assortementSort(begin, end);
    // list *begiS, *enS;
    // begiS = begin;
    // enS = end;
    // begiS = begiS->next;
    // enS = enS->prev;
    // swapElements(begiS, enS);
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
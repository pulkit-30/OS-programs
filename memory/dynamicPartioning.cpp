#include <iostream>
using namespace std;
/**
 * @brief
 * @status: false -> not occupied || true -> occupied
 * @size: Memory size
 * @pid: process id init || default 0
 * @prev: next Hole
 * @next: previous Hole
 *
 */
struct Hole
{
    bool status;
    int size;
    int pid;

    struct Hole *prev;
    struct Hole *next;
};

struct Hole *getHole()
{
    struct Hole *newHole = new (Hole);
    return newHole;
}
/**
 * @brief Create Hole given Size
 *
 * @param hole
 * @param size
 */
void Initialize(struct Hole **hole, int size)
{
    (*hole)->size = size;
    (*hole)->next = NULL;
    (*hole)->pid = 0;
    (*hole)->status = false;
}
struct Hole *SearchHole(struct Hole *Start, int size)
{
    struct Hole *P = Start;
    while (P != NULL)
    {
        if (!P->status && P->size >= size)
            return P;
        P = P->next;
    }
    return NULL;
}
void Allocate(struct Hole **start, int pid, int size)
{
    // Allocate the memory
    // Find Hole
    struct Hole *hole = SearchHole(*start, size);
    if (!hole)
    {
        cout << "cannot Allocate the process \n";
        return;
    }
    struct Hole *Next = hole->next;
    // remaining Hole size
    int left_size = hole->size - size;
    // allocate the hole to the process
    hole->size = size;
    // give pid to hole
    hole->pid = pid;
    // status to occupied
    hole->status = true;
    // creating a new Hole
    struct Hole *left_hole = getHole();
    // initialize the hole with left_sie
    Initialize(&left_hole, left_size);
    hole->next = left_hole;
    left_hole->next = Next;
    left_hole->prev = hole;
    if (Next)
        Next->prev = left_hole;
}

void DeAllocate(struct Hole **start, struct Hole **hole)
{
    (*hole)->prev->next = (*hole)->next;
    (*hole)->next->prev = (*hole)->prev;

    delete (*hole);
}

void Display(struct Hole *start)
{
    while (start != NULL)
    {
        cout << start->pid << "  |  " << start->size << "  |  " << endl;
        start = start->next;
    }
}

void compaction(struct Hole **start)
{
    struct Hole *SuperHole = getHole();
    struct Hole *temp = *start;
    struct Hole *Q = getHole();
    while (temp != NULL)
    {
        if (!temp->status)
        {
            SuperHole->size += temp->size;
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp == *start)
            {
                *start = temp->next;
                (*start)->prev = NULL;
            }
            delete (temp);
        }
        temp = temp->next;
    }
    SuperHole->next = *start;
    (*start)->prev = SuperHole;
    *start = SuperHole;
}
int main()
{
    struct Hole *start = getHole();
    // initialize the memory with given size
    int size = 0, pid, psize;
    cout << "Enter the total memory size" << endl;
    cin >> size;
    Initialize(&start, size);
    int run = 1;
    while (run)
    {
        struct Hole *P = start;
        cout << "**** Menu ****\n0.stop\n1.Allocate\n2.Deallocate\n3. compaction\n4. Display\n";
        cin >> run;
        switch (run)
        {
        case 0:
            Display(start);
            break;
        case 1:
            cout << "Enter Process id" << endl;
            cin >> pid;
            cout << "Enter Process size" << endl;
            cin >> psize;
            Allocate(&start, pid, psize);
            break;
        case 2:
            cout << "Enter process id" << endl;
            cin >> pid;
            while (P != NULL && P->pid != pid)
                P = P->next;
            if (P)
                DeAllocate(&start, &P);
            break;
        case 3:
            compaction(&start);
            Display(start);
            break;
        case 4:
            cout << endl;
            Display(start);
            cout << endl;
            break;
        }
    }
    // Allocate(&start, 1, 50);
    // Allocate(&start, 2, 10);
    // Allocate(&start, 3, 20);
    // Allocate(&start, 4, 10);
    // DeAllocate(&start);
    // DeAllocate(&start->next);
    // Display(start);

    return 0;
}
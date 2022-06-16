#include <iostream>
using namespace std;
class Block
{
private:
    int size;
    int fragmentation;

public:
    Block(int s)
    {
        size = s;
        fragmentation = 0;
    }
    int getSize()
    {
        return size;
    }
};
class Memory
{
private:
    int memory_size;
    int top;
    int n;
    Block Memory_arr[];

public:
    Memory(int size, int num)
    {
        n = num;
        top = 0;
        memory_size = size;
    }
    void AddBlock(Block B)
    {
        Memory_arr[top] = B;
        top++;
    }
    void PrintBlocks()
    {
        cout << "-->" << top << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "Memory size of block " << i << " : " << Memory_arr[i].getSize() << endl;
            cout << "End::" << endl;
        }
    }
};

int main()
{
    Memory M(600, 6);
    for (int i = 0; i < 6; i++)
    {
        Block newBlock(100);
        M.AddBlock(newBlock);
    }
    M.PrintBlocks();
    cout << "End::";
    return 0;
}
#include <stdio.h>
#define MAX_MEMORY 1000 // Maximum memory size
#define NUM_BLOCKS 4 // Number of memory blocks
// Structure to represent each block of memory
struct MemoryBlock {
 int size;
 int allocated;
};
// Function to allocate memory using a specified strategy
void allocateMemory(struct MemoryBlock memory[], int processSize, char strategy)
 {
 int idx = -1;
 int fitSize = (strategy == 'B') ? MAX_MEMORY + 1 : -1;
 for (int i = 0; i < NUM_BLOCKS; ++i)
    {
     if (!memory[i].allocated && memory[i].size >= processSize)
     {
      if ((strategy == 'F' && idx == -1) ||
       (strategy == 'B' && memory[i].size < fitSize) ||
     (strategy == 'W' && memory[i].size > fitSize))
     {
       idx = i;
       fitSize = memory[i].size;
     }
     }
 }
 if (idx != -1)
    {
 memory[idx].allocated = 1;
 printf("Memory allocated for process of size %d using %c Fit at block %d\n", processSize, strategy, idx);
    }
 else
  {
 printf("Insufficient memory for process of size %d using %c Fit\n", processSize, strategy);
 }
}
int main()
 {
 struct MemoryBlock memory[] = {{100, 0}, {500, 0}, {200, 0}, {300, 0}}; // Memory blocks
 printf("Contiguous Memory Allocation Techniques:\n");
 allocateMemory(memory, 350, 'F'); // First Fit for a process of size 350
 allocateMemory(memory, 200, 'B'); // Best Fit for a process of size 200
 allocateMemory(memory, 450, 'W'); // Worst Fit for a process of size 450
 return 0;
}

// Shared variable
volatile uint32_t SharedMemory = 0;

// Lock variable
volatile uint8_t lock = 0;

// Enter critical section
void lock_SharedMemory()
{
    while (lock);        // Wait if locked
    lock = 1;            // Lock
}

// Exit critical section
void unlock_SharedMemory()
{
    lock = 0;            // Unlock
}

void Set_SharedMemory(uint32_t value)
{
    lock_SharedMemory();
    SharedMemory = value;
    unlock_SharedMemory();
}

uint32_t Get_SharedMemory(void)
{
    uint32_t value;

    lock_SharedMemory();
    value = SharedMemory;
    unlock_SharedMemory();

    return value;
}

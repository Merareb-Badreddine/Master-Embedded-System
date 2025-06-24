/*
*  Semaphore.c
*
*
*Created on : 
* Author : Merareb.Badreddine
*/

volatile uint32_t SharedCounter = 0;

typedef struct {
    volatile uint8_t flag; 
} Semaphore_t;


void Semaphore_Init(Semaphore_t *sem)
{
    sem->flag = 0;
}


void Semaphore_Wait(Semaphore_t *sem)
{
    while (sem->flag);  
    sem->flag = 1;      
}

void Semaphore_Signal(Semaphore_t *sem)
{
    sem->flag = 0;  
}



void Task1(void)
{
    Semaphore_Wait(&sem);   

    SharedCounter *= 2;
    
    Semaphore_Signal(&sem); 
}

// الدالة الثانية التي تستخدم المتغير المشترك
void Task2(void)
{
    Semaphore_Wait(&sem);   

    SharedCounter *= 2;

    Semaphore_Signal(&sem); 
}

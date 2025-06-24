/*
*  BootLoader.h
*
*
*Created on : 
* Author : Merareb.Badreddine
*/



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

/*
My_Scheduler.c
Eng Merareb.Badreddine
*/

#include "Scheduler.h"
#include "MYRTOS_FIFO.h"
struct {
	Task_ref* OSTasks[100]; //Sch. Table
	unsigned int _S_MSP_Task ;
	unsigned int _E_MSP_Task ;
	unsigned int PSP_Task_Locator ;
	unsigned int NoOfActiveTasks ;
	Task_ref* CurrentTask ;
	Task_ref* NextTask ;
	enum{
		OSsuspend,
		OsRunning
	}OSmodeID;
}OS_Control;

typedef enum {
	SVC_Activatetask,
	SVC_terminateTask,
	SVC_TaskWaitingTime,
	SVC_AquireMutex,
	SVC_ReleaseMutex
}SVC_ID;

FIFO_Buf_t Ready_QUEUE ;

Task_ref* Ready_QUEUE_FIFO[100] ;
Task_ref MYRTOS_idleTask ;


__attribute ((naked)) void PendSV_Handler()
{
	//====================================
	//Save the Context of the Current Task
	//====================================
	//Get the Current Task "Current PSP from CPU register" as CPU Push XPSR,.....,R0
	OS_GET_PSP(OS_Control.CurrentTask->Current_PSP);

	//using this Current_PSP (Pointer) tp store (R4 to R11)
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r4 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r5 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r6 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r7 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r8 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r9 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r10 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP-- ;
	__asm volatile("mov %0,r11 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );

	//save the current Value of PSP
	//already saved in Current_PSP



	//====================================
	//Restore the Context of the Next Task
	//====================================
	if (OS_Control.NextTask != NULL){
	OS_Control.CurrentTask = OS_Control.NextTask ;
	OS_Control.NextTask = NULL ;
	}

	__asm volatile("mov r11,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r10,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r9,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r8,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r7,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r6,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r5,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r4,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;

	//update PSP and exit
	OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
	__asm volatile("BX LR");

}



unsigned char IdleTaskLed ;
void MYRTOS_IdleTask()
{

	//		The "wfi" (Wait For Interrupt) instruction is used to put the processor into a low-power state until an interrupt is received. An exception is a type of interrupt, but it is not the same as the interrupt that "wfi" is waiting for. Exceptions are typically caused by events such as illegal instruction execution, divide-by-zero, or memory access violation, and are typically handled by the processor's exception handler.
	//
	//		"wfi" instruction only waits for external interrupts which are generated by peripherals or external events and not the exceptional interrupts which are generated by the CPU itself.
	//
	//		In general, when you want to wait for any type of interrupt, you can use the "wfi" instruction, but if you want to wait for a specific event, you would use the "wfe" instruction, as it allows you to wait for a specific event, rather than any interrupt.
	//
	while(1)
	{
		IdleTaskLed ^= 1 ;
		__asm("wfe");
	}

}








void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP_Task = &_estack;
	OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - MainStackSize;
	//Aligned 8 Bytes spaces between Main Task and PSP tasks
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task - 8);

	//if (_E_MSP_Task <&_eheap) Error:excedded the availble stack size
}

MYRTOS_errorID MYRTOS_init()
{
	MYRTOS_errorID error = NoError ;

	//Update OS Mode (OSsuspend)
	OS_Control.OSmodeID = OSsuspend ;

	//Specify the MAIN Stack for OS
	MYRTOS_Create_MainStack();

	//Create OS Ready Queue
	if (FIFO_init(&Ready_QUEUE, Ready_QUEUE_FIFO, 100) !=FIFO_NO_ERROR)
	{
		error += Ready_Queue_init_error ;
	}

	//Configure IDLE TASK
	strcpy (MYRTOS_idleTask.TaskName, "idleTask");
	MYRTOS_idleTask.priority = 255 ;
	MYRTOS_idleTask.p_TaskEntry = MYRTOS_IdleTask ;
	MYRTOS_idleTask.Stack_Size = 300 ;

	error += MYRTOS_CreateTask(&MYRTOS_idleTask);

	return error ;

}


void MyRTOS_Create_TaskStack(Task_ref* Tref)
{
	/*Task Frame
	 * ======
	 * XPSR
	 * PC (Next Task Instruction which should be Run)
	 * LR (return register which is saved in CPU while TASk1 running before TaskSwitching)
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 *====
	 *r5, r6 , r7 ,r8 ,r9, r10,r11 (Saved/Restore)Manual
	 */
	Tref->Current_PSP = Tref->_S_PSP_Task ;

	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = 0x01000000;         //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000

	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = (unsigned int)Tref->p_TaskEntry ; //PC

	Tref->Current_PSP-- ; //LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP
	*(Tref->Current_PSP)  = 0xFFFFFFFD ;

	for (int  j=0 ; j< 13 ; j++ )
	{
		Tref->Current_PSP-- ;
		*(Tref->Current_PSP)  = 0 ;

	}



}
MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Tref)
{
	MYRTOS_errorID error = NoError ;

	//Create Its OWN PSP stack
	//Check task stack size exceeded the PSP stack
	Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	Tref->_E_PSP_Task = Tref->_S_PSP_Task - Tref->Stack_Size ;

	//	-				-
	//	- _S_PSP_Task	-
	//	-	Task Stack	-
	//	- _E_PSP_Task	-
	//	-				-
	//	- _eheap		-
	//	-				-
	//
	if(Tref->_E_PSP_Task < (unsigned int)(&(_eheap)))
	{
		return Task_exceeded_StackSize ;
	}

	//Aligned 8 Bytes spaces between Task PSP and other
	OS_Control.PSP_Task_Locator = (Tref->_E_PSP_Task - 8);

	//Initialize PSP Task Stack
	MyRTOS_Create_TaskStack( Tref);

	//update sch Table
	OS_Control.OSTasks[OS_Control.NoOfActiveTasks]= Tref ;
	OS_Control.NoOfActiveTasks++ ;


	//Task State Update -> Suspend
	Tref->TaskState = Suspend ;

	return error ;

}
//Handler Mode
void OS_SVC(int* Stack_Frame)
{
	//r0,r1,r2,r3,r12,LR,return address (PC) and XPSR
	unsigned char SVC_number ;
	SVC_number = *((unsigned char*)(((unsigned char*)Stack_Frame[6])-2)) ;

	switch (SVC_number)
	{
	case SVC_Activatetask:
	case SVC_terminateTask:
		//Update Sch Table, Ready Queue
		MyRTOS_Update_Schadule_tables();
		//OS is in Running State
		if (OS_Control.OSmodeID == OsRunning)
		{
			if (strcmp(OS_Control.CurrentTask->TaskName,"idleTask") != 0)
			{
				//Decide what Next
				Decide_whatNext();

				//trigger OS_pendSV (Switch Context/Restore)
				trigger_OS_PendSV();
			}
		}

		break;
	case SVC_TaskWaitingTime:
		MyRTOS_Update_Schadule_tables();


		break;
	}


}

//Thread Mode
MYRTOS_OS_SVC_Set(SVC_ID ID)
{
	switch (ID)
	{
	case SVC_Activatetask:
		__asm("svc #0x00");
		break;
	case SVC_terminateTask:
		__asm("svc #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm("svc #0x02");
		break;
	case SVC_AquireMutex:
		__asm("svc #0x03");  //Assignment Task
		break;
	case SVC_ReleaseMutex:
		__asm("svc #0x04"); //Assignment Task
		break;
	}
}

void MYRTOS_ActivateTask (Task_ref* Tref)
{
	Tref->TaskState = Waiting ;
	MYRTOS_OS_SVC_Set(SVC_Activatetask);
}
void MYRTOS_TerminateTask (Task_ref* Tref)
{
	Tref->TaskState = Suspend ;
	MYRTOS_OS_SVC_Set(SVC_terminateTask);
}

 MYRTOS – A Real-Time Operating System for ARM Cortex-M
MYRTOS is a fully custom real-time operating system (RTOS) developed in C for ARM Cortex-M microcontrollers, without relying on any external libraries or middleware layers. The project focuses on building a practical RTOS from scratch using low-level concepts to achieve deterministic real-time performance and full control over hardware resources.

📌 Key Technical Features

✅ Preemptive task scheduling using the SysTick and PendSV exceptions
✅ Full context switching, including saving/restoring CPU registers and managing MSP and PSP stacks
✅ Task management: task creation and switching between states (Ready, Running, Blocked)
✅ Clear stack separation between the kernel (MSP) and user tasks (PSP)
✅ Mutex mechanism for protecting shared resources and avoiding race conditions
✅ Custom NVIC configuration to manage interrupt priorities
✅ Timing services using SysTick for delay and time tracking
✅ Modular and extensible design to support Semaphores, Queues, and Event Flags in the future

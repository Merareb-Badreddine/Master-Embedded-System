/************************************************************************/
/*    File Version: V1.06                                               */
/*    Date Generated: 01/09/2021                                        */
/************************************************************************/

    /*reset_program.asm*/

    .list

#ifdef CPPAPP    
___dso_handle:
    .global ___dso_handle
#endif
	
	.global	__rl78_fini
	.type	__rl78_fini,@function
		__rl78_fini:
		br $__rl78_fini


    .extern _HardwareSetup /*! external Sub-routine to initialise Hardware*/
    .extern _data
    .extern _mdata
    .extern _ebss
    .extern _bss
    .extern _edata
    .extern _main 
    .extern _stack

    /*  ;; HL = start of list
        ;; DE = end of list
        ;; BC = step direction (+2 or -2)
    */
    
    .text

    .global	_PowerON_Reset  /*! global Start routine */
    .type	_PowerON_Reset,@function
/* call to _PowerON_Reset */
_PowerON_Reset:
/* initialise user stack pointer */
    movw sp,#_stack /* Set stack pointer */


/* load data section from ROM to RAM */    
;; block move to initialize .data

        ;; we're copying from 00:[_romdatastart] to 0F:[_datastart]
        ;; and our data is not in the mirrored area.
    mov     es, #0
#ifndef __RL78_G10__
    sel     rb0         /*  ;;bank 0 */
#endif    

    movw    de, #_mdata    /* src ROM address of data section in de */
    movw    hl, #_data     /* dest start RAM address of data section in hl */
        
#ifndef __RL78_G10__
    sel     rb1              /* bank 1 */
    movw    hl, #_data     /* dest start RAM address of data section in hl */
#endif
    movw    ax, #_edata   /*    ;; size of romdata section in ax */
    subw    ax,hl          /* store data size */
    shrw    ax,1
1:
    cmpw    ax, #0           /* check if end of data */
    bz      $1f
    decw    ax
#ifdef __RL78_G10__
    movw     bc, ax            /* save ax value in bc */
#endif
    
#ifndef __RL78_G10__
    sel     rb0             /* bank 0 */
#endif
    movw    ax, es:[de]
    movw    [hl], ax
    incw    de
    incw    de
    incw    hl
    incw    hl
#ifndef __RL78_G10__
    sel     rb1         /* bank 1  -  compare and decrement*/
#endif

#ifdef __RL78_G10__
    movw     ax, bc            /* restore ax value */
#endif
    br      $1b
1:

    
/* bss initialisation : zero out bss */
#ifndef __RL78_G10__
    sel     rb0         /* bank 0 */
    movw    ax, #0        /* load AX reg with zero */
    sel     rb1         /* bank 1 */
    movw    ax, #_ebss  /* store the end address (size of) bss section in ax */
    movw    hl, #_bss      /* store the start address of bss in hl */
    subw    ax,hl ;; store data size
    shrw    ax,1
#endif

#ifdef __RL78_G10__
    movw    hl, #_bss      /* store the start address of bss in hl */
    movw    ax, #_ebss  /* store the end address (size of) bss section in ax */
    subw    ax,hl ;; store data size
    shrw    ax,1
#endif    
    
    
1:
    cmpw    ax, #0
    bz      $1f
    decw    ax
#ifdef __RL78_G10__    
    movw     bc, ax        /* save ax value in bc */
    movw    ax, #0
#endif    
#ifndef __RL78_G10__        
    sel     rb0         /* bank 0 */
#endif        
    movw    [hl], ax
    incw    hl
    incw    hl
#ifdef __RL78_G10__        
    movw    ax, bc        /* restore ax value */
#endif        
#ifndef __RL78_G10__        
    sel     rb1
#endif    
    br      $1b
1:
#ifndef __RL78_G10__
    sel     rb0             /* bank 0 */
#endif
    
/* Initialize global constructors in case of CPP app */
#ifdef CPPAPP
	movw    de, #___ctors
1:
	movw	ax, #___ctors_end
	cmpw	ax, de
	bnh	$2f
	mov	es, #0
	movw	ax, es:[de]
	push	de
	call	ax
	pop	de
	incw	de
	incw	de
	br	$1b
2:
#endif


/* call the hardware initialiser */
    call    !!_HardwareSetup
    nop

/* start user program */

    movw    ax, #0
    push    ax      /* envp */
    push    ax      /* argv */
    push    ax      /* argc */
    call    !!_main

/* Initialize global destructors in case of CPP app */
#ifdef CPPAPP
	movw    de, #___dtors
1:
	movw	ax, #___dtors_end
	cmpw	ax, de
	bnh		$2f
	mov		es, #0
	movw	ax, es:[de]
	push	de
	call	ax
	pop		de
	incw	de
	incw	de
	br		$1b
2:
#endif

	.global	_exit
	.type	_exit,@function
/* call to exit*/
_exit:
     br    $_exit

    .end             


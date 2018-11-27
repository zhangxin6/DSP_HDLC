/****************************************************************************\
 *           Copyright (C) 2012 Texas Instruments Incorporated.             *
 *                           All Rights Reserved                            *
 *                                                                          *
 * GENERAL DISCLAIMER                                                       *
 * ------------------                                                       *
 * All software and related documentation is provided "AS IS" and without   *
 * warranty or support of any kind and Texas Instruments expressly disclaims*
 * all other warranties, express or implied, including, but not limited to, *
 * the implied warranties of merchantability and fitness for a particular   *
 * purpose.  Under no circumstances shall Texas Instruments be liable for   *
 * any incidental, special or consequential damages that result from the    *
 * use or inability to use the software or related documentation, even if   *
 * Texas Instruments has been advised of the liability.                     *
 ****************************************************************************
This example shows the features of GPIO on KeyStone DSP
 ****************************************************************************
 * Created by :                                                             *
 *            Brighton Feng                                                 *
 *            Texas Instruments                                             * 
 *            October 24, 2012                                                 *
***************************************************************************/
#include <c6x.h>
#include <stdio.h>
#include <cslr_gpio.h>
#include <csl_bootcfgAux.h>
#include "KeyStone_common.h"
#include "hdlc_cmu.h"


Uint32 num_GPIO=16;


void GPIO_Interrupts_Init(void)
{
	gpCGEM_regs->INTMUX1 = 0;
	gpCGEM_regs->INTMUX2 = 0;

	gpCGEM_regs->EVTMASK[0]= 	0xFFFFFFFF;
	gpCGEM_regs->EVTMASK[1]= 	0xFFFFFFFF;
	gpCGEM_regs->EVTMASK[3]= 	0xFFFFFFFF;

	
	if(C6670_EVM==gDSP_board_type
		||DUAL_NYQUIST_EVM==gDSP_board_type
		||TCI6614_EVM==gDSP_board_type)
	{	
		//combine all GPIO interrupts to INTC event 2
		gpCGEM_regs->EVTMASK[2]= ~((1<<(CSL_GEM_GPINTN- 64))|
			(1<<(78-64))|
			(1<<(79-64))|
			(1<<(80-64))|
			(1<<(81-64))|
			(1<<(CSL_GEM_GPINT8-64))|
			(1<<(CSL_GEM_GPINT9-64))|
			(1<<(CSL_GEM_GPINT10-64))|
			(1<<(CSL_GEM_GPINT11-64))|
			(1<<(CSL_GEM_GPINT12-64))|
			(1<<(CSL_GEM_GPINT13-64))|
			//(1<<(CSL_GEM_GPINT14-64))|
			(1<<(CSL_GEM_GPINT15-64)));

		/*enable GPIO interrupts on CIC3 for ARM on TCI6614*/
		if(TCI6614_EVM==gDSP_board_type)
		{
			CSL_CPINTCRegs* cpIntc3Regs = (CSL_CPINTCRegs*)0x0260c000;
			cpIntc3Regs->ENABLE_REG[1]= 0xFFFFFFFE;
			cpIntc3Regs->ENABLE_REG[2]= 1;

			num_GPIO= 32;
		}
	}
	else if (C6678_EVM==gDSP_board_type)
	{
		//combine all GPIO interrupts to INTC event 2
		gpCGEM_regs->EVTMASK[2]= ~((1<<(CSL_GEM_GPINTN- 64))|
			(1<<(CSL_GEM_GPINT8-64))|
			(1<<(CSL_GEM_GPINT9-64))|
			(1<<(CSL_GEM_GPINT10-64))|
			(1<<(CSL_GEM_GPINT11-64))|
			(1<<(CSL_GEM_GPINT12-64))|
			(1<<(CSL_GEM_GPINT13-64))|
			//(1<<(CSL_GEM_GPINT14-64))|
			(1<<(CSL_GEM_GPINT15-64)));
	}	
	else
	{
		puts("unknown DSP type!");
	}
	
	//map INTC event 2 to INT15
	gpCGEM_regs->INTMUX3 = CSL_GEM_EVT2<<CSL_CGEM_INTMUX3_INTSEL15_SHIFT;

	/*clear interrupt flag*/
	gpCGEM_regs->EVTCLR[2]= 0xFFFFFFFF;

	//enable INT15
	CPU_interrupt_enable(1<<15);
}

void GPIO_init(void)
{
	/*set GPIO direction*/
#if GPIO_LOOP_BACK_TEST
	/*When the GPIO pin is configured as output, software can toggle the 
	GPIO output register to change the pin state and in turn trigger the 
	interrupt and EDMA event.*/
	gpGPIO_regs->BANK_REGISTERS[0].DIR= 0;
#else
	gpGPIO_regs->BANK_REGISTERS[0].DIR= 0xFFFFFFFF;
#endif

	/*enable interrupt*/
	gpGPIO_regs->BINTEN= 3;

	/*trigger interrupt on both rising and falling edge*/	
	gpGPIO_regs->BANK_REGISTERS[0].SET_RIS_TRIG= 0xFFFFFFFF;
	gpGPIO_regs->BANK_REGISTERS[0].SET_FAL_TRIG= 0xFFFFFFFF;

	/*clear output data*/
	gpGPIO_regs->BANK_REGISTERS[0].CLR_DATA= 0xFFFFFFFF;

}

void check_GPIO(void)
{
	//check interrupt status in CIC3 on TCI6614
	if(TCI6614_EVM==gDSP_board_type)
	{
		Uint32 cicStatus1, cicStatus2;
		CSL_CPINTCRegs* cpIntc3Regs;
#ifdef CSL_CP_INTC_3_REGS
		cpIntc3Regs = (CSL_CPINTCRegs*)CSL_CP_INTC_3_REGS;
#else
		cpIntc3Regs = (CSL_CPINTCRegs*)0x0260c000;
#endif
	
		/*read status*/
		cicStatus1= cpIntc3Regs->RAW_STATUS_REG[1]&0xFFFFFFFE;
		cicStatus2= cpIntc3Regs->RAW_STATUS_REG[2]&1;

		/*clear status*/
		cpIntc3Regs->ENA_STATUS_REG[1]= cicStatus1;
		cpIntc3Regs->ENA_STATUS_REG[2]= cicStatus1;
		
		printf("GPIO interrupt event status in CIC3= 0x%x\n",
			(cicStatus1>>1)|(cicStatus2<<31));
	}		

	printf("GPIO IN_DATA= 0x%x\n\n",gpGPIO_regs->BANK_REGISTERS[0].IN_DATA);
}

void GPIO_loopback_test(void)
{
	int i;
	volatile Uint32 PID;

	/*toggle all GPIOs*/
	for(i=0; i<num_GPIO; i++)
	{
		gpGPIO_regs->BANK_REGISTERS[0].SET_DATA= (1<<i);
		PID= gpGPIO_regs->PID; //read to force write out
		TSC_delay_ms(1);
		check_GPIO();

		gpGPIO_regs->BANK_REGISTERS[0].CLR_DATA= (1<<i);
		PID= gpGPIO_regs->PID; //read to force write out
		TSC_delay_ms(1);
		check_GPIO();
	}
}



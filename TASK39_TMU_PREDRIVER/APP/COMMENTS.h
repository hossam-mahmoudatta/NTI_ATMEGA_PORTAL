/*
void t0 (void)
{
	DIO_enuTogglePinValue(DIO_GROUP_C , DIO_PIN_2);
}
void t1 (void)
{
	DIO_enuTogglePinValue(DIO_GROUP_C , DIO_PIN_5);
}
void t2 (void)
{
	DIO_enuTogglePinValue(DIO_GROUP_C , DIO_PIN_7);
}

int
main(void)
{
	DIO_enuSetPinDirection(DIO_GROUP_C , DIO_PIN_2, DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_C , DIO_PIN_5, DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_C , DIO_PIN_7, DIO_OUTPUT);
	TMU_vidInit();

	TMU_vidCreateTask(t0 , 100 , 2);
	TMU_vidCreateTask(t1 , 150 , 1);
	TMU_vidCreateTask(t2 , 200 , 0);

	TMU_vidStartScheduler();
}


int
main(int argc, char const *argv[])
{
	POV_enuInit();
	Light_vidInit();
	Update_vidInit();
	TMU_vidInit();
	Comm_vidInit();


//	TMU_vidCreateTask((void(*)(void*))Comm_vidTask, NULL , 1 , 0);

	 TMU_vidCreateTask(POV_vidDisplayTask,  1 , 0);
	 TMU_vidCreateTask(Light_vidTrafficTask,  50 , 1);
	 TMU_vidCreateTask(Update_vidDecreaseTask, 1 , 2);
	 TMU_vidCreateTask(Update_vidIncreaseTask , 1 , 3);

	TMU_vidStartScheduler();

	return 0;
}
#include <util/delay.h>


#define MASTER 9
#define SLAVE		77

#define MAIN MASTER

#if MAIN == MASTER
int
main(void)
{
	SPI_vidInit();
	u8 data ='M';
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_3,DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_4,DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_5,DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_6,DIO_INPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_7,DIO_OUTPUT);

	while (1)
	{
		DIO_enuSetPinValue(DIO_GROUP_B,DIO_PIN_3,DIO_LOW);
		*((volatile u8*)0x31) = SPI_u8Transcieve(data++);
		DIO_enuSetPinValue(DIO_GROUP_B,DIO_PIN_3,DIO_HIGH);
		_delay_ms(1000);
	}
}
#elif MAIN == SLAVE
int
main (void)
{
	SPI_vidInit();
	u8 data;
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_4,DIO_INPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_5,DIO_INPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_6,DIO_OUTPUT);
	DIO_enuSetPinDirection(DIO_GROUP_B,DIO_PIN_7,DIO_INPUT);

	while (1)
	{
		*((volatile u8*)0x31) = SPI_u8Transcieve('S');
	}
}
#endif


int
main(int argc, char const *argv[])
{
	POV_enuInit();
	Light_vidInit();
	Update_vidInit();
	TMU_vidInit();
	Comm_vidInit();


	TMU_vidCreateTask((void(*)(void*))Comm_vidTask, NULL , 1 , 0);

	// TMU_vidCreateTask((void(*)(void*))POV_vidDisplayTask, NULL , 1 , 0);
	// TMU_vidCreateTask(Light_vidTrafficTask, NULL , 50 , 1);
	// TMU_vidCreateTask(Update_vidDecreaseTask, NULL , 1 , 2);
	// TMU_vidCreateTask(Update_vidIncreaseTask, NULL , 1 , 3);

	TMU_vidStartScheduler();

	return 0;
}


BOOL bCompare(char * s1 , char *s2);
int
main(void)
{
	u8 buf[18]={0};
	DIO_enuSetPinDirection(3,0,0);
	DIO_enuSetPinDirection(3,1,1);
	UART_enuInit();
	GIE_vidEnable();
	UART_enuReceive_IT(buf , 8);

	while (1)
	{
		//UART_enuReceive_IT(buf , 8);
		// if (ES_OK == UART_enuReceive_IT(buf , 17))
		if (ES_OK == UART_enuGetReceiveITState())
		{
			if (TRUE == bCompare((char*)buf, "Ahmed El-Gaafrawy"))
			{
				UART_enuSendString("\r\nLoz El-3enab\r\n");
			}
			else
			{
				UART_enuSendString("\r\nAgain\r\n");
			}
			UART_enuReceive_IT(buf , 17);
		}
	}
}

BOOL bCompare(char * s1 , char *s2)
{
	for (u8 i =0; *(s2+i) != 0 ; i++)
	{
		if (*(s1+i) != s2[i])
		{
			return FALSE;
		}
	}
	return TRUE;
}





int
main(void)
{
	u8 duty;
	u32 freq;
	ICU_vidInit();
	LCD_enuInit();
	DIO_enuSetPinDirection(DIO_GROUP_C , DIO_PIN_3, DIO_OUTPUT);
	// LCD_enuSendString("Distance = ");
	LCD_enuSendString("Duty = ");
	LCD_enuGotoXY(2,1);
	LCD_enuSendString("Freq = ");
			// LCD_enuWriteIntegarNum(-180);

	GIE_vidEnable();
	// ICU_vidEnableReadingUltraSonic();
	ICU_vidStartCapture();
	while(1)
	{
		ICU_vidCalculatePWMParams();
		duty = ICU_u8GetDutyCycle();
		freq = ICU_u32GetFrequency();
		if (duty <= 100)
		{
			LCD_enuGotoXY(1, 8);
			LCD_enuSendString("   %");
			LCD_enuGotoXY(1, 8);
			// s32 dis = ( 34000UL / freq);
			LCD_enuWriteIntegarNum(duty);
			LCD_enuGotoXY(2, 8);
			LCD_enuSendString("      Hz");
			LCD_enuGotoXY(2, 8);
			LCD_enuWriteIntegarNum(freq/10);
			LCD_enuSendData('.');
			LCD_enuWriteIntegarNum(freq%10);

			ICU_vidStartCapture();
		}
		u64 x =10;
		u64 y = x *1.1;
		u64 z = x + y;
	}
}

int
main(int argc, char const *argv[])
{
	// u8 count =0;
	POV_enuInit();
	Light_vidInit();
	Update_vidInit();
	TMU_vidInit();

	TMU_vidCreateTask((void(*)(void*))POV_vidDisplayTask, NULL , 1 , 0);
	TMU_vidCreateTask(Light_vidTrafficTask, NULL , 50 , 1);
	TMU_vidCreateTask(Update_vidDecreaseTask, NULL , 1 , 2);
	TMU_vidCreateTask(Update_vidIncreaseTask, NULL , 1 , 3);

	TMU_vidStartScheduler();

	return 0;
}


void t0(void*pv)
{
	DIO_enuTogglePinValue(2,*((u8*)pv));
}
void t1(void*pv)
{
	DIO_enuTogglePinValue(2,*((u8*)pv));
}
void t2(void*pv)
{
	DIO_enuTogglePinValue(2,*((u8*)pv));
}

int
main(int argc, char const *argv[])
{
	u8 arr[]={7,5,2};
	DIO_enuSetPinDirection (2,arr[0],1);
	DIO_enuSetPinDirection (2,arr[1],1);
	DIO_enuSetPinDirection (2,arr[2],1);

	TMU_vidInit();

	TMU_vidCreateTask(t0, arr+0 , 100 , 0);
	TMU_vidCreateTask(t1, arr+1 , 200 , 1);
	TMU_vidCreateTask(t2, arr+2 , 300 , 2);

	TMU_vidStartScheduler();

	return 0;
}


int
main(void)
{
	// non inv B , phase , A top, 64
	TCCR1A = 0x21;
	TCCR1B = 0x13;

	u8 freq = 50 ;
	u16 Top = ((16000000UL)/(2UL*64UL*freq));
	OCR1AH = (Top>>8);
	OCR1AL = (u8)Top;

	u8 duty = 75   ;
	u16 ocr = (Top * (u32)duty)/ 1000UL;

	OCR1BH = (ocr >>8);
	OCR1BL = (u8)ocr;
	DIO_enuSetPinDirection(3 , 4 , 1);
}



int
main(void)
{
	u8 duty =35;
	//phase , 1024 , non
	TCCR0=0b01100101;
	OCR0 = ((256UL * duty)/100);

	//fast , 1024 , non
//	TCCR0=0b01101101;
//	OCR0 = ((256UL * duty)/100)-1;
	DIO_enuSetPinDirection(1,3,1);

}
u16 Novf, Nisr;
u8 preload;
int
main(void)
{
	DIO_enuSetPinDirection(2,7,1);
	//ovf , 1024
//	TCCR0 = 0b00000101;//0x05
	//ctc , 1024
	TCCR0 = 0b00001101;//0x0D
//	u32 Time = 10;
//	u32 counts  = (Time * 16000ul)/ (1024);
//	Novf = (counts + 255)/256;
//	Nisr = Novf;
//	preload = 256UL - (counts % 256);
//	TCNT0 = preload;
	OCR0 = 156;
	TIMSK |= (1<<1);
	GIE_vidEnable();
	while(1);

//	float N = (Time/16.384f);
//	Novf = (N - ((u16)N) > 0 )? (u16)N+1 : (u16)N;
//	Nisr = Novf;
//	preload = (u8)((256UL) - (256.0f * ((N - (u16)N))));
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	DIO_enuTogglePinValue(2,7);
}
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	Nisr -- ;
	if (! Nisr)
	{
		TCNT0 = preload;
		DIO_enuTogglePinValue(2,7);
		Nisr = Novf;
	}
}

#include <util/delay.h>

struct x
{
BOOL flag;
u16 read;
};

void adc__ (void * pv)
{
	struct x * ptr = (struct x *)pv;
	ADC_enuRead(&(ptr->read));
	(ptr->flag) = TRUE;
}

int
main(void)
{
	u16 MV;
	struct x Param;

	DIO_enuSetPinDirection(DIO_GROUP_A , DIO_PIN_1 , DIO_INPUT);
	DIO_enuSetPinValue(DIO_GROUP_A , DIO_PIN_1 , DIO_FLOAT);
	DIO_enuSetPinDirection(DIO_GROUP_D , DIO_PIN_2 , DIO_INPUT);
	DIO_enuSetPinValue(DIO_GROUP_D , DIO_PIN_2 , DIO_FLOAT);

	ADC_enuInit();
	EXTI_enuInit();
	LCD_enuInit();
	LCD_enuSendString("Volt = ");
	LCD_enuGotoXY(1 ,12);
	LCD_enuSendString(" mV");

	ADC_enuSetCallBack(adc__ ,  &Param);


	ADC_enuSetTriggerSource(12);
	ADC_enuStartConversion();
	GIE_vidEnable();

	while(1)
	{
		if (Param.flag == TRUE)
		{
			Param.flag = FALSE;
			MV = (Param.read * 5000LLU)/1024;
			LCD_enuGotoXY(1, 8);
			LCD_enuSendString("    ");
			LCD_enuGotoXY(1, 8);
			LCD_enuWriteIntegarNum(MV);
		}

	}
}
#include <util/delay.h>

int
main(void)
{
	u16 read;
	DIO_enuSetPinDirection(DIO_GROUP_A , DIO_PIN_1 , DIO_INPUT);
	DIO_enuSetPinValue(DIO_GROUP_A , DIO_PIN_1 , DIO_FLOAT);

	ADC_enuInit();
	LCD_enuInit();
	LCD_enuSendString("Volt = ");
	LCD_enuGotoXY(1 ,12);
	LCD_enuSendString(" mV");
	while(1)
	{
		ADC_enuReadPolling(1 , &read);
		read = (read * 5000LLU)/1024;
		LCD_enuGotoXY(1, 8);
		LCD_enuSendString("    ");
		LCD_enuGotoXY(1, 8);
		LCD_enuWriteIntegarNum(read);
		_delay_ms(500);
	}
}


void tog (void)
{
	DIO_enuTogglePinValue(DIO_GROUP_C , DIO_PIN_7);
}

int
main(void)
{
	DIO_enuSetPinDirection(DIO_GROUP_D , DIO_PIN_2 , DIO_INPUT);
	DIO_enuSetPinValue(DIO_GROUP_D , DIO_PIN_2 , DIO_FLOAT);

	DIO_enuSetPinDirection(DIO_GROUP_C , DIO_PIN_7 , DIO_OUTPUT);
	EXTI_enuInit();

	EXTI_enuSetCallBack(EXTI_INT0 , tog);

	GIE_vidEnable();
	while(1);
}
int
main(void)
{
	u8 keyValue;
	Keypad_enuInit();
	LCD_enuInit();
	while(1)
	{
		Keypad_enuGetPressedKey(&keyValue);
		if (keyValue != KEYPAD_NOT_PRESSED)
		{
			LCD_enuSendData(keyValue);
		}
	}
}
int
main(void)
{
	u8 name []= {
					0x03,0x04,0x1F,0x00,0x04,0x04,0x04,0x04,// aleph
					0x00,0x00,0x06,0x09,0x01,0x1E,0x00,0x00,// 7aa'
					0x00,0x00,0x00,0x00,0x00,0x1F,0x0A,0x06,// mem
					0x00,0x00,0x00,0x0C,0x04,0x1F,0x00,0x00,// dal
				};

//	LCD_enuDrawSpecialChar(name , 4 , 2 , 1 , 14 , LCD_TO_RIGHT);

//	LCD_enuWriteIntegarNum(10730);
//	LCD_enuWriteIntegarNum(-11980);
	LCD_enuInit();
	LCD_enuSendCommand(0x50); // CGRAM P2
	for (u8 i =0 ; i<32 ; i++ )
	{
		LCD_enuSendData(name[i]);
	}
	LCD_enuGotoXY(1 , 14); // DDRAM 1st line , 14th colomn
	LCD_enuSendCommand (0x04);// decresing DDRAM Counter
	LCD_enuSendData(2);
	LCD_enuSendData(3);
	LCD_enuSendData(4);
	LCD_enuSendData(5);
}

int
main(void)
{
	u8 name []= {
					0x03,0x04,0x1F,0x00,0x04,0x04,0x04,0x04// aleph
				};
	u8 right , left;
	BOOL Local_bRightFlag= FALSE , Local_bLeftFlag = FALSE;
	LCD_enuInit();

	LCD_enuSendString("Ahmed Reda El-Gaafrawy");
	Switch_enuInit();
	LCD_enuGotoXY(2,1);

	LCD_enuSendString("Embedded SW Engineer");
	while (1)
	{
		Switch_enuGetSwitchState(SWITCH_BUTTON_0 , &right);
		Switch_enuGetSwitchState(SWITCH_BUTTON_1 , &left);

		if (right == DIO_HIGH && Local_bRightFlag == FALSE)
		{
			LCD_enuSendCommand(0x1C);
			Local_bRightFlag = TRUE;
		}
		else if (right == DIO_LOW && Local_bRightFlag == TRUE)
		{
			Local_bRightFlag = FALSE;
		}
		else
		{

		}

		if (left == DIO_HIGH && Local_bLeftFlag == FALSE)
		{
			LCD_enuSendCommand(0x18);
			Local_bLeftFlag = TRUE;
		}
		else if (left == DIO_LOW && Local_bLeftFlag == TRUE)
		{
			Local_bLeftFlag = FALSE;
		}
		else
		{

		}
	}

}


int
main(void)
{
	u8 Local_u8PinVal , Local_u8Counter = 0;
	BOOL Local_bFlag = FALSE;
	DIO_enuSetPinDirection (DIO_GROUP_D, DIO_PIN_2 , DIO_INPUT);
	DIO_enuSetPinValue(DIO_GROUP_D, DIO_PIN_2 , DIO_FLOAT);

	DIO_enuSetPinDirection(DIO_GROUP_C , DIO_PIN_7 , DIO_OUTPUT);

	POV_enuInit();
	Switch_enuInit();

	while(1)
	{
		Switch_enuGetSwitchState(SWITCH_BUTTON_0 , &Local_u8PinVal);
		if ((Local_u8PinVal == DIO_HIGH) && (Local_bFlag == FALSE))
		{
			Local_u8Counter = (Local_u8Counter < 99)? (Local_u8Counter+1): Local_u8Counter;
			Local_bFlag = TRUE;
		}
		else if (Local_u8PinVal == DIO_LOW && Local_bFlag == TRUE)
		{
			Local_bFlag = FALSE;
		}
		else
		{
		}
		POV_enuDisplayNum (Local_u8Counter);

		// DIO_enuGetPinValue(DIO_GROUP_D, DIO_PIN_2 , &Local_u8PinVal);
		// if (Local_u8PinVal == DIO_HIGH)
		// {
		// 	DIO_enuSetPinValue(DIO_GROUP_C , DIO_PIN_7, DIO_LOW);
		// }
		// else if (Local_u8PinVal == DIO_LOW)
		// {
		// 	DIO_enuSetPinValue(DIO_GROUP_C , DIO_PIN_7, DIO_HIGH);
		// }
	}
}



*/

























/*
#include "stdTypes.h"
#include "DIO_priv.h"
#include <util\delay.h>
  		_delay_ms(milli second)
  		_delay_us(micro second)


int
main (void)
{
	u8 counter =0 ;
	DDRA |= 0xF0; //a4 -> A , a5->B , a6->C , a7->D
	DDRB |= (3<<1); // enable com seg
	DDRD &= ~(1<<2); // sw
	DDRC |= (1<<2); //a
	DDRC |= (1<<5); //b
	DDRC |= (1<<0); //c
	DDRD |= (1<<2); //d
	DDRD |= (1<<5); //e
	DDRD |= (1<<0); //f
	DDRB |= (1<<7); //g
	while(1)
	{
		if (((PIND>>2)&1)==1)
		{
			POV(57);
		}
		else
		{
			PORTB &= ~(3<<1);
		}
		// for (counter =0 ; counter <100 ; counter ++)
		// {
		// 	for ( u8 fix =0 ; fix < (1000/20) ; fix ++)
		// 		POV(counter);

		// }

		// for (u8 i = 0 ; i<10 ; i++)
		// {
		// 	DisplayDecNum(i);
		// 	_delay_ms(500);
		// }
	}
}
*/
/*
int
main(void)
{
	u8 flag =0;
	DDRC |= (1<<2); //out for led
	DDRD &=~(1<<2);
	PORTD &=~(1<<2); //input float
	while (1)
	{
		if ((((PIND>>2)&1)== 1 )  && (flag == 0)) //1st press
		{
			PORTC |=(1<<2);
			flag = 1;
		}
		else if ((((PIND>>2)&1)== 0 )  && (flag == 1)) //1st release
		{
			flag =2;
		}
		else if ((((PIND>>2)&1)== 1 )  && (flag == 2)) //2nd press
		{
			PORTC &=~ (1<<2);
			flag = 3;
		}
		else if ((((PIND>>2)&1)== 0 )  && (flag == 3)) //2nd release
		{
			flag =0;
		}
		else
		{
			//nothing due to hold press
		}
	}
}

int
main(void)
{
	DDRC |= (1<<2); //out for led
	DDRD &=~(1<<2);
	PORTD &=~(1<<2); //input float
	while (1)
	{
		if (((PIND>>2)&1)== 1)
		{
			PORTC |=(1<<2);
		}
		else
		{
			PORTC &=~(1<<2);
		}
	}
}

int
main(void)
{
	DDRC = 0xff;//255//0b11111111
	PORTC = 0x18;
	while(1)
	{
		for (u8 i=5 ; i<8 ;i++)
		{
			PORTC |= (1<<i);
			PORTC |= (1<<(7-i));
			_delay_ms(500);
		}
		for (s8 i=0 ; i<3 ;i++)
		{
			PORTC &=~(1<<i);
			PORTC &=~(1<<(7-i));
			_delay_ms(500);
		}
	}
}

int
main(void)
{
	DDRC = 0xff;//255//0b11111111
	PORTC = 0x55;
	while(1)
	{
				PORTC = ~PORTC;
				_delay_ms(1000);

		//		PORTC = 0x55;//0b01010101
//		_delay_ms(1000);
//		PORTC = 0xAA; //0b10101010
//		_delay_ms(1000);
	}
}

int
main(void)
{
	//DDRC , pin2 out
//	DDRC |= (1<<2);
	asm("SBI 0x14 , 2");
	//PORTC , pin2 high
	while(1) // for(;;)
	{
//		PORTC |=(1<<2);
		__asm("SBI 0x15 , 2");
		_delay_ms(500);
		__asm__("CBI 0x15 , 2");
//		PORTC &=~(1<<2);
		_delay_ms(500);
	}
}
*/

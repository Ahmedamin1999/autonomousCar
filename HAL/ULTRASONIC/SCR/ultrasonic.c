#include "ultrasonic.h"

uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;
uint8_t distance_str[10];

TimerConfStruct SEt_timer_for_ultrasonic = {
	NoPsc,
	Normal,
	Interrupt
	};

void ultrasonic_init(void){

  EXT_INT_ModeSet(EX_INT1,Logical);  
   EXT_INT_Enable(EX_INT1);
  Timer_INIT(&SEt_timer_for_ultrasonic);
  Timer_Start();
}

void ultra_triger(void){
  if(!sensor_working){
	  DIO_WriteChannel(TRIGER,STD_High);
       _delay_us(15);
	  DIO_WriteChannel(TRIGER,STD_Low);
      sensor_working=1;
  }
}

void Display_Distance(uint32 distance)
{
	LCD_MoveCursor(0,10);
	itoa(distance,distance_str,10);
	strcat(distance_str, " cm ");
	LCD_PrintString(distance_str);
	_delay_ms(40);
}

ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
	 TCNT0_REG=0x00;
     rising_edge=1;
     timer_counter=0;
    }
  else{
    distance = (timer_counter * 256 + TCNT0_REG)/ultrasonic_Constant;
	
	Display_Distance(distance);
	

 	Move_Stright(distance);
 	Decision(distance);
	Rotation(distance);

	
	timer_counter=0;
    rising_edge=0;
  }
}}


 ISR(TIMER0_OVF_vect){
     timer_counter++;
     if(timer_counter >730){
       TCNT0_REG=0x00;
       sensor_working=0;
       rising_edge=0;
       timer_counter=0;
     }
 }


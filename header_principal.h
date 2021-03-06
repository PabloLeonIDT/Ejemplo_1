#define CAN_USE_EXTENDED_ID TRUE
#define CAN_BRG_PRESCALAR           1    //Set CAN Baud Rate to 500K
#define CAN_BRG_PHASE_SEGMENT_1     0    //Tq = (2(1+PRESCALAR))/(Fosc/2)
#define CAN_BRG_PHASE_SEGMENT_2     0    //Tq = (2(1+4)/(20000000/2) = 0.000001
#define CAN_BRG_PROPAGATION_TIME    0    //Baud Rate = 1/(((PHASE_SEGMENT_1+1)+(PHASE_SEGMENT_2+1)+(PROPAGATION_TIME+1)+(JUMP_WIDTH+1))*Tq)
#define CAN_BRG_SYNCH_JUMP_WIDTH    0    //Baud Rate = 1/(((1+1)+(1+1)+(2+1)+(0+1))*0.000001) = 500000

#include <18F4580.h>
#device adc=10
#device HIGH_INTS=TRUE 
#FUSES NOWDT, HS, NOLVP
#use delay(clock=20000000)
#use RS232(BAUD=115200,BITS=8,PARITY=N,XMIT=PIN_C6,RCV=PIN_C7,errors)
#include <can-18F4580.c>
#include <crc_8.c>
#ZERO_RAM  

/* Definir variables */
float LecturaVoltajePresion, LecturaPresion, LecturaVoltajeFlujo;
int16 LecturaFlujo;
int CondicionErrorSensor1, CondicionErrorSensor2;

/* Definir funciones */
void PRUEBA_MALA_LECTURA(void);
void RUTINA_PROBAR_SENSORES(void);

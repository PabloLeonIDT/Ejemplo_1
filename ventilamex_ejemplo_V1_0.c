#include "header_principal.h"

void main(){
   can_init(); 
   setup_adc_ports(AN0_TO_AN1); 
   setup_adc(ADC_CLOCK_DIV_32); 
   
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   RUTINA_PROBAR_SENSORES();
   
   while(TRUE){      
      
      PRUEBA_MALA_LECTURA();             
      
      printf("%3.2f, %3.2Lu", LecturaPresion, LecturaFlujo);
   }

}

void RUTINA_PROBAR_SENSORES(void){
   float PruebaVoltajeFlujo, PruebaVoltajePresion;
   float PruebaFlujo, PruebaPresion;
   
   set_adc_channel(0);
   delay_us(50);
   PruebaVoltajeFlujo = read_adc();
   PruebaFlujo = ((5.0*PruebaVoltajeFlujo/1024.0)*1.556)+0.5;            
   
   set_adc_channel(1);
   delay_us(50);
   PruebaVoltajePresion = read_adc();
   PruebaPresion = ((5.0*PruebaVoltajePresion/1024.0));   
   
   
}

void PRUEBA_MALA_LECTURA(void){
   set_adc_channel(0);
   delay_us(50);
   LecturaVoltajeFlujo = read_adc();
   LecturaFlujo = ((5.0*LecturaVoltajeFlujo/1024.0)*1.556)+0.5;            
   
   set_adc_channel(1);
   delay_us(50);
   LecturaVoltajePresion = read_adc();
   LecturaPresion = ((5.0*LecturaVoltajePresion/1024.0));   
}

#include "header_principal.h"
#include "LECTURA_DATOS.c"

void main(){
   can_init(); 
   setup_adc_ports(AN0_TO_AN1); 
   setup_adc(ADC_CLOCK_DIV_32); 
   
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   RUTINA_PROBAR_SENSORES();
   
   while(TRUE){      
      
      PRUEBA_MALA_LECTURA();             
      
      if(CondicionErrorSensor1==1 || CondicionErrorSensor2==1){
         printf("Error en lectura. Verifique Sensor prueba");
      }
      else{            
         printf("%3.2f, %3.2Lu Prueba 2", LecturaPresion, LecturaFlujo);
      }
   }

}



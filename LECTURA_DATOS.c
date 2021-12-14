void RUTINA_PROBAR_SENSORES(void){
   /* PRUEBA */
   float PruebaVoltajeFlujo, PruebaVoltajePresion;
   float PruebaFlujo, PruebaPresion;
   
   CondicionErrorSensor1=0;
   CondicionErrorSensor2=0;
   
   set_adc_channel(0);
   delay_us(50);
   PruebaVoltajeFlujo = read_adc();
   PruebaFlujo = ((5.0*PruebaVoltajeFlujo/1024.0)*1.556)+0.5;            
   
   set_adc_channel(1);
   delay_us(50);
   PruebaVoltajePresion = read_adc();
   PruebaPresion = ((5.0*PruebaVoltajePresion/1024.0));   
   
   if(PruebaFlujo<0.2 || PruebaFlujo>4.5){
      CondicionErrorSensor1=1;
   }
   
   if(PruebaPresion<0.2 || PruebaPresion>4.5){
      CondicionErrorSensor2=1;
   }
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

void volt_alarm(){  
  
  voltage = (analogRead(A3)/1023.0) * 5.0;

    if(voltage <= 3.6){
      
        digitalWrite(7, HIGH);

    }

}    

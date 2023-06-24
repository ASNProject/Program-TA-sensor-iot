//Variabel String
String phDataString, ppmDataString, suhu_airDataString, suhu_udaraDataString, NTUDataString;

void GetData() {
  //Data sensor
  voltage_pH = analogRead(PH_PIN) / ESPADC * ESPVOLTAGE;
  phData = ph.readPH(voltage_pH, temperatureph);
  suhuudara = sensorUdara.getTempCByIndex(0);
  suhuair = sensorAir.getTempCByIndex(0);
  ppmData = gravityTds.getTdsValue();
  ADCtur = analogRead(tur_pin);
  voltagetur = ADCtur * 3.3 / 4095;
  
    
  //Convert to String
  phDataString = String(phData);
  ppmDataString = String(ppmData);
  suhu_udaraDataString = String(suhuudara);
  suhu_airDataString = String(suhuair);
  NTUDataString = String(voltagetur); 
  
}

void inc_dec_pap(int pos) {                          // resolucion (PWMmax / grados) >>> 250/561 = 0.4629
  int error = abs(actual - pos);
  int pulsos = error*200;
  lcd.setCursor(10,0);
  lcd.print(pulsos);
  // loop de Pasos:
  for (int x = 0; x < pulsos; x++) {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
  }
  actual = pos;
  lcd.setCursor(2,0);
  lcd.print("     ");
  lcd.setCursor(2,0);
  lcd.print(actual);
}

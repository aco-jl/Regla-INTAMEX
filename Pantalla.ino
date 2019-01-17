void pantalla0() {
  lcd.backlight();                              // iniciamos el fondo retroiluminado
  lcd.init();                                   // inicializamos lcd
  lcd.clear();                                  //Limpiamos Pantalla
  lcd.setCursor(0,0);
  lcd.print("A=      P=");
  lcd.setCursor(0,1);
  lcd.print("LARGO DE:     mm");
  
  lcd.setCursor(2,0);
  lcd.print(actual);
}

void show(String y) {
  lcd.setCursor(9,1);
  lcd.print("    ");
  //int numLength = y.length();
  //lcd.setCursor(15-numLength,1);
  lcd.setCursor(9,1);
  lcd.print(y); 
}

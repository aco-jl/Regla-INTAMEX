void checknumber(int x) {
  if (numero[0] == 99) {
    numero[0]=x;
    String displayvalue = String(numero[0]);
    show(displayvalue);
  } else {
    if (numero[1] == 99) {
      numero[1]=x;
      String displayvalue = String(numero[0]) + String(numero[1]);
      show(displayvalue);
    } else {
      if (numero[2] == 99) {
        numero[2]=x;
        String displayvalue = String(numero[0]) + String(numero[1]) + String(numero[2]);
        show(displayvalue);
      } else {
        if (numero[3] == 99) {
          numero[3]=x;
          String displayvalue = String(numero[0]) + String(numero[1]) +String(numero[2]) +String(numero[3]);
          show(displayvalue);
        }
        }
      }
    }
}

void deletenumber() {
  if (numero[3] != 99) {
    String displayvalue = String(numero[0]) + String(numero[1]) +String(numero[2]);
    show(displayvalue);
    numero[3]=99;
  } else {
    if (numero[2] != 99) {
      String displayvalue = String(numero[0]) + String(numero[1]);
      show(displayvalue);
      numero[2]=99;
    } else {
      if (numero[1] != 99) {
        String displayvalue = String(numero[0]);
        show(displayvalue);
        numero[1]=99;
      } else {
        if (numero[0] != 99) {
          String displayvalue = "";
          show(displayvalue);
          numero[0]=99;
        }
        }
      }
    }
}

void calcnumber() {
  if (numero[0] != 99 && numero[1] == 99 && numero[2] == 99 && numero[3] == 99) {
    fullnumber = numero[0];
  }
  if (numero[1] != 99 && numero[2] == 99 && numero[3] == 99) {
    fullnumber = (numero[0]*10) + numero[1];
  }
  if (numero[2] != 99 && numero[3] == 99) {
    fullnumber = (numero[0]*100) + (numero[1]*10) + numero[2];
  }
  if (numero[3] != 99) {
    fullnumber = (numero[0]*1000) + (numero[1]*100) + (numero[2]*10) + numero[3];
  }
  resetnumber();
}

void resetnumber() {
  numero[0] = 99;
  numero[1] = 99;
  numero[2] = 99;
  numero[3] = 99;
}

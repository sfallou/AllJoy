#include "Keyboard.h"


// lecture des joysticks et émulation du clavier pour des entrées analogiques (accéléromètre + potentiomètres)
#define JOY1_X 0 // pin 0
#define JOY1_Y 1 // pin 1
#define JOY2_X 2 // pin 2
#define JOY2_Y 3 // pin 3

#define DZONE1 128 //dead zone premier joystick à calibrer
#define DZONE2 128 //dead zone second joystik à calibrer

// calibrage des joysticks
int calibjoy1_x = 512 ; // valeur lue en analogique sur [0 ; 1023]
int calibjoy1_y = 512 ;
int calibjoy2_x = 512 ;
int calibjoy2_y = 512 ;

void setup() {
  // possibilité de calibrer les joysticks selon leur position initiale :
  calibjoy1_x = analogRead(JOY1_X) ;
  calibjoy1_y = analogRead(JOY1_Y) ;
  calibjoy2_x = analogRead(JOY2_X) ;
  calibjoy2_y = analogRead(JOY2_Y) ;

  Keyboard.begin() ;
}

void loop() {
  // put your main code here, to run repeatedly:
  int X1 ;
  int Y1 ;
  int X2 ;
  int Y2 ;

  X1 = analogRead(JOY1_X) ;
  Y1 = analogRead(JOY1_Y) ;
  X2 = analogRead(JOY2_X) ;
  Y2 = analogRead(JOY2_Y) ;

  simulation(X1, calibjoy1_x, DZONE1, KEY_LEFT_ARROW, KEY_RIGHT_ARROW) ;
  simulation(Y1, calibjoy1_y, DZONE1, KEY_DOWN_ARROW, KEY_UP_ARROW) ;
  simulation(X2, calibjoy2_x, DZONE2, 'a', 'b') ;
  simulation(Y2, calibjoy2_y, DZONE2, 'x', 'y') ;

}

void simulation(int axe, int cal, int deadzone, char touche1, char touche2) {
  if (axe < (cal - deadzone)) {
    Keyboard.press(touche1) ;
  }
  else if (axe > (cal + deadzone)) {
    Keyboard.press(touche2) ;
  }
  else {
    Keyboard.release(touche1) ;
    Keyboard.release(touche2) ;
  }
}


#define sensor1 10
#define sensor2 12
#define led_azul 3
#define Buzzer 11
#include <LiquidCrystal.h>

int acionamento1;
int acionamento2;
int tempo1 = 250;
int tempo2 = 500;

LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

void setup(){
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop(){
  acionamento1 = digitalRead(sensor1);
  acionamento2 = digitalRead(sensor2);
  
  if(acionamento1 == LOW && acionamento2 == LOW){
  suave();
  digitalWrite(Buzzer, LOW);
  }else{
  alerta();
  }
}

void suave(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Tudo Suave");
  lcd.setCursor(1, 1);
  lcd.print("Nada Suspeito");
  delay(100);
}

void alerta(){
  piscapisca();
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("!!!ALERTA!!!");
  lcd.setCursor(1, 1);
  lcd.print("ALGO SUSPEITO");
}

void piscapisca(){
  digitalWrite(led_azul, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(tempo1);
  digitalWrite(led_azul, LOW);
  digitalWrite(Buzzer, LOW);
  delay(tempo1);
}
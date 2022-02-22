//d=s*t/2 34cm/ms x t ms
#include<LiquidCrystal.h>
const double rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int const tp = 2 ;
int const ep = 3 ;
int const b =  4 ;
bool boo=true;
void setup()
{
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
  pinMode(b,OUTPUT);
  Serial.begin(115200);
  lcd.begin(20, 4);
}
void loop()
{
  int t,dis,d,t_d;
  digitalWrite(tp,HIGH);
  delay(5000);
  digitalWrite(tp,LOW);
  t = pulseIn(ep,HIGH);
  dis = (t/2)/29.1;
  //t_d=d*dis;
 // Serial.print("distance = ");Serial.println(dis);
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print("distance ="); lcd.print(dis);// lcd.print(Num2); 
  boo=true;
  //delay(500);
 if (boo==true)
 { 
  for (int i=0;i<dis;i++)
    {
    digitalWrite(b,HIGH);
    delay(250);
    digitalWrite(b,LOW);
    delay(250);
    }
    boo=false;
  }
}

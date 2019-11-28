

#include <TimeLib.h>
#include <TimeAlarms.h>


AlarmId id;

#define LED_light 2
#define LED1 3
#define LED2 4
#define fanPIN 5
#define interval 2000


unsigned long Millis1 = 0;

long OnTime1 = 900000;
long OffTime1 = 3600000;

int ledState1 = LOW;


void setup() {

  
  Serial.begin(9600);

  pinMode(fanPIN, OUTPUT); 
  pinMode(LED_light, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

 
  pinMode(5, OUTPUT);

  
  while (!Serial) ; 

  setTime(7,30,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011

 
  Alarm.alarmRepeat(7,31,00, lightON);  
  Alarm.alarmRepeat(13,30,30, lightOFF);

  Alarm.alarmRepeat(14,31,00, lightON);  
  Alarm.alarmRepeat(18,30,30, lightOFF);

  Alarm.alarmRepeat(14,30,30, Test1_ON);
  Alarm.alarmRepeat(15,40,30, Test1_OFF);
  
  Alarm.alarmRepeat(16,30,30, Test2_ON);
  Alarm.alarmRepeat(17,40,30, Test2_OFF);

}

void loop() {

    digitalClockDisplay();
    Alarm.delay(1000); // wait one second between clock display

          
         unsigned long currentMillis = millis();
         
          if((ledState1 == HIGH) && (currentMillis - Millis1 >= OnTime1))
          {
            ledState1 = LOW;  
            Millis1 = currentMillis;  
            digitalWrite(fanPIN, ledState1);  
          }
          
          else if ((ledState1 == LOW) && (currentMillis - Millis1 >= OffTime1))
          {
            ledState1 = HIGH; 
            Millis1 = currentMillis;   
            digitalWrite(fanPIN, ledState1);    
          }

}




void lightON() 
{


  digitalWrite(LED_light, HIGH);

}

  void lightOFF() 
  {
  
   digitalWrite(LED_light, LOW);
  
  }

    void Test1_ON()
    {
      digitalWrite(LED1, HIGH);
    }
      
      void Test1_OFF()
      {
        digitalWrite(LED1, LOW);
      }

        void Test2_ON()
        {
          digitalWrite(LED2, HIGH);
        }

          void Test2_OFF()
          {
            digitalWrite(LED2, LOW);
          }

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
 
}


void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
  Serial.print('0');
  Serial.print(digits);
  
}


/*
* Bluetooh Basic: LED ON OFF - Avishkar
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/
char data = 0; //Variable for storing received data
String checkval = "";

int defaultchk=0;
int blinkchk=0;
int pulsechk=0;
int led1=0;
int led2=0;
int led3=0;
int led4=0;
int blinkRate=1000;


void setup()
{
    Serial.begin(9600); //Sets the baud for serial data transmission                               
    pinMode(9, OUTPUT); //Sets digital pin 13 as output pin
     pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
    pinMode(2, OUTPUT);
}
void loop()
{

   if(defaultchk==0)
   {
    blinkled();
    
   }
   if(Serial.available() > 0)  // Send data only when you receive data:
   {
      defaultchk=1;
      data = Serial.read();        //Read the  incoming  data and store it into variable data

    if(data == 'X') 
      {
        stopBlink();  
      }
         
    if(data == 'D')              // Checks whether value of data is equal to 1
      {
        if(blinkchk==1|pulsechk==1)
                {
                stopBlink();
                }
        
        ledfourOn();
        
             }
     if(data == 'S')         //  Checks  whether value of data is equal to 0
         {
           if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
        ledfourOff();
         }
//led3
        
    if(data == 'G')              // Checks whether value of data is equal to 1
         {
           if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
         //digitalWrite(4, HIGH);   //If value is 1 then LED turns ON
          ledthreeOn();
         }
     if(data == 'F')         //  Checks  whether value of data is equal to 0
         { 
          if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
         ledthreeOff();
         }
         
         //led2
           if(data == 'J')              // Checks whether value of data is equal to 1
         {
           if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
         ledtwoOn();
         }
     if(data == 'H')         //  Checks  whether value of data is equal to 0
         {
           if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
         ledtwoOff();
         }
         //led1

          if(data == 'L')              // Checks whether value of data is equal to 1
         {
           if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
          ledoneOn();
         }
     if(data == 'K')         //  Checks  whether value of data is equal to 0
         {
           if(blinkchk==1|pulsechk==1)
               {
                stopBlink();
                }
         ledoneOff();
         }

//

         
     if (data=='b')
          {           
        blinkchk=1;
        pulsechk=0;
          }
      if(data=='p')
          {
            blinkchk=0;
            pulsechk=1;
          }
          if(data=='0')
          {
            blinkRate=50;
            
          }
          if(data=='1')
          {
            blinkRate=150;
            
          }
           if(data=='2')
          {
            blinkRate=500;
            
          }
           if(data=='3')
          {
            blinkRate=1000;
            
          }
           if(data=='4')
          {
            blinkRate=1500;
            
          }
           if(data=='5')
          {
            blinkRate=2000;
            
          }
 
   }
    if (blinkchk==1)
      {
         blinkled();
      }
    if(pulsechk==1)
     {
       pulse();
     }

    //end of loop
}

void ledoneOn()
  {
    //Serial.println("LED1-On");
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
   }
  void ledoneOff()
  {
    //Serial.println("LED1-Off");
    digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  }
void ledtwoOn()
  {
    //Serial.println("LED1-On");
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  void ledtwoOff()
  {
    //Serial.println("LED1-Off");
    digitalWrite(4, LOW);   // turn the LED on (HIGH is the voltage level)
  }

  void ledthreeOn()
  {
    //Serial.println("LED1-On");
    digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
   
  }
  void ledthreeOff()
  {
    //Serial.println("LED1-Off");
    digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)
 
  }

  void ledfourOn()
  {
    //Serial.println("LED1-On");
    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
 
    
   
  }
  void ledfourOff()
  {
    //Serial.println("LED1-Off");
    digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
    
  }

  
void blinkled()
   
   {
       
    pulsechk=0;
    
            digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(blinkRate);           // wait for a second
            digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
            delay(blinkRate);    
            digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(blinkRate);           // wait for a second
            digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
            delay(blinkRate);
            digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(blinkRate);              // wait for a second
            digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
            delay(blinkRate);  
            digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(blinkRate);             // wait for a second
            digitalWrite(9, LOW);
            blinkchk=1;
     // Serial.println("blink "+blinkRate);        
   }

void pulse()
{
  blinkchk=0;
 digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)         
   digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)         
   digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(blinkRate);
digitalWrite(4, LOW); 
 digitalWrite(7, LOW);
digitalWrite(9, LOW);
digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)         

delay(blinkRate);
 //Serial.println("pulse");
//Serial.print("pulse "+blinkRate); 
 
}
void stopBlink()
{
  blinkchk=0;
  pulsechk=0;
  digitalWrite(2, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
}

   

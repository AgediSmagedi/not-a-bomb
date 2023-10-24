// define any pins

const int upPin = 8; // increase time
const int downPin = 9; // de crease time
const int buttonPin = 0; // the number of the activation button pin
const int ledPin = 13;    // the number of the LED pin
const int buzzerPin = 12;
const int shortbeep = 400;   // for when up or down buttons are pressed, feel free to tweak


// these ones change
int buttonState = 0;  // variable for reading the buttons status
int upState = 0;
int downState = 0;
int timer = 5; // how long countdown will last
int displayTime = timer; // what the display displays (might not need)
int displayThousands = 0;
int displayHundreds = 0;
int displayTens = 0;
int displayUnits = 0;

#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

//function for counting down, uses timer variable (may need referencing or some shit)
void countdown(){
  for (int i = timer; i != 0; i = i - 1){
    lcd.clear();
    lcd.print(i);
    beep(500);
    delay(500);
  }
  // put any explodey code here
}

// beeps and turns lights on for an amount of time
void beep(int length){
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(length);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void setup() {
  // initialize the output pins as outputs:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // initialize the buttons' pins as inputs:
  pinMode(buttonPin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  
   lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
   lcd.print("timer");
}

void loop() {
  // read the state of the buttons
  buttonState = digitalRead(buttonPin);
  upState = digitalRead(upPin);
  downState = digitalRead(downPin);

  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH
  if (buttonState == LOW) {
    // turn LED on:
    countdown();
} if (upState == LOW) {
    timer += 5;
    lcd.clear();   //buttons need to be connected
    lcd.print(timer);
    beep(shortbeep);
} if (downState == LOW) {
    timer += -5;
    lcd.clear();
    lcd.print(timer);
    beep(shortbeep);
  }
}

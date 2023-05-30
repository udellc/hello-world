/*
  My first conditional circuit code
  Author: Chet Udell
  Date: Spring 2021
*/

const int switchPin = 5;
const int buttPin = 6;

bool switchState = false;
bool buttState = false;

void setup() {
  //start serial connection
  Serial.begin(9600);
  
  //configure pin 2 as an input and enable the internal pull-up resistor
 pinMode(switchPin, INPUT_PULLUP);
 pinMode(buttPin, INPUT_PULLUP);
  
  // Set LED pin (13) as output to turn LED on or off
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // read the pushbutton value into a variable
  // Digital States can only be HIGH or LOW, 1 or 0, True or False
  switchState = digitalRead(switchPin);
  buttState = digitalRead(buttPin);

  // Keep in mind the pull-up means the pushbutton and switch logic is inverted. Voltage goes
  // HIGH when open, and LOW when it's pressed.
  // We call this "LOW-True" Logic and is common in circuits
  
  // We can invert this to "HIGH-True" Logic by using the !, which makes a 1 become 0, or a 0 become 1
  // Invert the switch value Logic 
  switchState = !switchState;
  // Invert the button value Logic
  buttState = !buttState;

  // print out the value of the switch and pushbutton
  // A value of 0 at this point in the program means "false" and 1 means "true"
  Serial.print("Switch logic is");
  Serial.println(switchState);
  Serial.print("Button logic is");
  Serial.println(buttState);
  Serial.println(" ");

  // Turn on LED pin 13 when the
  // button or switch is active, and off when it's not:
  if (switchState == true) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  delay(100); // Pause the program 100ms before starting over again at the top of Loop
  
}

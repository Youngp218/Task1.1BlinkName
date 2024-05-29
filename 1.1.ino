const int BTNPIN = 9;
const int LEDPIN = 14;
bool interrupt = false;
bool startMorse = false;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BTNPIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BTNPIN), interruptMorse, RISING);
  Serial.begin(9600);
}

void interruptMorse() {
  Serial.println("interrupt");
  if (!startMorse) {
    startMorse = true;
  } else {
    interrupt = true;
  } 
}
void loop() {
  Serial.println("loop");
  if (startMorse) {
    if (interrupt) {
  Serial.println(interrupt);
  Serial.println(startMorse);
      interrupt = false;
      clear();
    }
    if (interrupt) return;
    parseMorse(".--."); //P
  Serial.println("P");
    if (interrupt) return;
    parseMorse(".");    //E
  Serial.println("E");
    if (interrupt) return;
    parseMorse("-");    //T
  Serial.println("T");
    if (interrupt) return;
    parseMorse(".");    //E
  Serial.println("E");
    if (interrupt) return;
    parseMorse(".-.");  //R
  Serial.println("R");
    if (interrupt) return;
    startMorse = false;
  }
}

void parseMorse(String code) {
  // loop through code and call dot or dash until end of string
  for(char& c : code) {
    if(c == '.') {
      dot();
    } else {
      dash();
    }
}
}
void dot() {                      // wait for a second
  digitalWrite(LEDPIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(LEDPIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LEDPIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);
}

void dash() {                      
  digitalWrite(LEDPIN, LOW);
  delay(100);
  digitalWrite(LEDPIN, HIGH);
  delay(100);                      
  digitalWrite(LEDPIN, LOW);   
  delay(100);
}

void clear() {                      
  digitalWrite(LEDPIN, LOW);
  delay(100);
  digitalWrite(LEDPIN, HIGH);
  delay(2000);                      
  digitalWrite(LEDPIN, LOW);   
  delay(1000);
}
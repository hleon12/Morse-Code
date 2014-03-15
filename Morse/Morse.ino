char letter; //Store a char
String message = ""; //Message to encode to Morse Code
int messageLen = 0; //Message's lenght
int led = 13; //Pin #13

//Headers
void line(int pTimes);
void dot(int pTimes);

void setup() {
  Serial.begin(9600); //Start connection with Arduino
  pinMode(led, OUTPUT);
}
void loop() {
  while(Serial.available()){ //Wait for the message
    //Store a letter from the message.
    letter = Serial.read();
    message.concat(letter);
    messageLen++;
  }
  if (message != "" || !Serial.available()) {
    delay(500); //Wait before turns the LED on.
    for(int i = 0; i < messageLen; i++){
      if(message[i] == 'A'){
        dot(1);
        line(1);
      }
      if(message[i] == 'B'){
        line(1);
        dot(3);
      }
      if(message[i] == 'C'){
        line(1);
        dot(1);
        line(1);
        dot(1);
      }
      if(message[i] == 'D'){
        line(1);
        dot(2);
      }
      if(message[i] == 'E'){
        dot(1);
      }
      if(message[i] == 'F'){
        dot(2);
        line(1);
        dot(1);
      }
      if(message[i] == 'G'){
        line(2);
        dot(1);
      }
      if(message[i] == 'H'){
        dot(4);
      }
      if(message[i] == 'I'){
        dot(2);
      }
      if(message[i] == 'J'){
        dot(1);
        line(3);
      }
      if(message[i] == 'K'){
        line(1);
        dot(1);
        line(1);
      }
      if(message[i] == 'L'){
        dot(1);
        line(1);
        dot(2);
      }
      if(message[i] == 'M'){
        line(2);
      }
      if(message[i] == 'N'){
        line(1);
        dot(1);
      }
      if(message[i] == 'Ñ'){
        line(2);
        dot(1);
        line(2);
      }
      if(message[i] == 'O'){
        line(3);
      }
      if(message[i] == 'P'){
        dot(1);
        line(2);
        dot(1);
      }
      if(message[i] == 'Q'){
        line(2);
        dot(1);
        line(1);
      }
      if(message[i] == 'R'){
        dot(1);
        line(1);
        dot(1);
      }
      if(message[i] == 'S'){
        dot(3);
      }
      if(message[i] == 'T'){
        line(1);
      }
      if(message[i] == 'U'){
        dot(2);
        line(1);
      }
      if(message[i] == 'V'){
        dot(3);
        line(1);
      }
      if(message[i] == 'W'){
        dot(1);
        line(2);
      }
      if(message[i] == 'X'){
        line(1);
        dot(2);
        line(1);
      }
      if(message[i] == 'Y'){
        line(1);
        dot(1);
        line(2);
      }
      if(message[i] == 'Z'){
        line(2);
        dot(2);
      }
      if(message[i] == ' '){
        delay(1000);
      }
      delay(1000);
    }
    //Clean the message
    message = "";
    messageLen = 0;
  }
}

void line(int pTimes){
  int times = 0;
  while(times < pTimes){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(300);
    times++;
  }
}

void dot(int pTimes){
  int times = 0;
  while(times < pTimes){
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
    times++;
  }
}

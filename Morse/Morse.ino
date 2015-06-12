const int led = 13; //Pin 13

char letter; //Stores a char
String morse; //Stores the translation of a letter to morse code

//Lookup table of the alphabet in Morse code
String lookupTable[] = {
  ".-", "-...", "-.-.", "-..", ".", //A-E
  "..-.", "--.", "....", "..", ".---", //F-J
  "-.-", ".-..", "--", "-.", //K-N
  "---", ".--.", "--.-", ".-.", "...", //O-S
  "-", "..-", "...-", ".--", "-..-", //T-X
  "-.--", "--.." //Y-Z
};

//Prototypes
void line();
void dot();

void setup() {
  Serial.begin(9600); //Starts connection with Arduino
  pinMode(led, OUTPUT);
}

void loop() {
  while(Serial.available()){ //Waits for a word
    letter = Serial.read(); //Gets a byte from the serial port
    morse = "";
    
    if(64 < letter && letter < 91){ //Letter A to Z
      letter-=65;
    }
    else if(96 < letter && letter < 123){ //Letter a to z
      letter-=97;
    }
    
    if(letter > 0 and letter < 27){
      morse = lookupTable[letter]; //Gets translation
    }
    
    if(morse.length() > 0){
      for(int i = 0; i < morse.length(); i++){
        if(morse[i] == '-'){
          line();
        }
        else{
          dot();
        }
      }
    }
    
    delay(500); //Delay before the next letter
    
  }
}
//'Flashs' a line
void line(){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(300);
}

//'Flashs' a dot
void dot(){
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(300);
}

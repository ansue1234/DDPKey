const int inputGas = A1;
const int inputMic = A0;
const int out = 9;
const int pwLed = 13;
const int signalLed = 10;

const double threGas = 50;
const double threMic = 50;

double gasVal;

boolean blown;

void setup() {
  pinMode(out, OUTPUT);
  pinMode(pwLed, OUTPUT);
  pinMode(signalLed, OUTPUT);
  blown = false;
  
  //gather environmental data reference for gas sensor
  initialization();
}

void loop() {
  //show that the code is running
  digitalWrite(pwLed, HIGH);
  
  //Check if human is actually blowing
  start();
  
  //Check alcohol lvl and the corresponding actions
  if(blown){
    delay(500);
    digitalWrite(signalLed, LOW);
    if(alcLvlTest()){
      digitalWrite(out,HIGH);
      delay(6000);
      digitalWrite(out, LOW);
      blown = false;
    }
    blown = false;
  }
}

//Checks alcohol level
boolean alcLvlTest(){
  if(blown&&(analogRead(inputGas)-gasVal)< threGas){
    blown = false;
    return true;
  }else{
    blown = false;
    return false;
  }
}

//Gather enviromental references
void initialization(){
  if(!blown){
    delay(1000);
    gasVal = analogRead(inputGas);
    delay(1000);
    digitalWrite(signalLed, HIGH);
  }
}

//signal the beginning of check alcohol level by verifing an actual human breathed
void start(){
  if(analogRead(inputMic)>threMic){
    blown = true;
  }
  blown = false;
}

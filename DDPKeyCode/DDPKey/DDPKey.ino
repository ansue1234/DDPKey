const int inputGas = 1;
const int inputMic = 0;
const int out = 9;
const int pwLed = 13;
const int signalLed = 10;

//if too sensitive 
const double threGas = 50;
const double threMic = 800;

double gasVal;
double micVal;

boolean blown;

int count = 0;

void setup() {
  pinMode(out, OUTPUT);
  pinMode(pwLed, OUTPUT);
  pinMode(signalLed, OUTPUT);
  blown = false;
  Serial.begin(9600);
  //gather environmental data reference for gas sensor
  initialization();
}

void loop() {
  //show that the code is running
  micVal =  analogRead(inputMic);
  digitalWrite(pwLed, HIGH);
  Serial.println("gasVal:");
  Serial.println(gasVal);
  Serial.println("micVal:");
  Serial.println(micVal);
  Serial.println(blown);
  //Check if human is actually blowing
  start();
  
  //Check alcohol lvl and the corresponding actions
  if(blown&&count<=0){
    Serial.println(blown);
    delay(500);
    digitalWrite(signalLed, HIGH);
    
    if(alcLvlTest()){
      digitalWrite(out,HIGH);
      delay(6000);
      digitalWrite(out, LOW);
      blown = false;
      count++;
    }else{
      blown = false;
    }
  }
}

//Checks alcohol level
boolean alcLvlTest(){
  if(blown&&((analogRead(inputGas)-gasVal)< threGas)){
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
    digitalWrite(pwLed, HIGH);
    delay(1000);
    gasVal = analogRead(inputGas);
    delay(1000);
    Serial.println("initialized");
    //blown = true;
  }
}

//signal the beginning of check alcohol level by verifing an actual human breathed
void start(){
  if(analogRead(inputMic)<threMic){
    blown = true;
  }else{
    blown = false;
  }
}


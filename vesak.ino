const int led0Pin = 0; 
const int led1Pin = 1; 
const int led2Pin = 2; 
const int led3Pin = 3; 
const int led4Pin = 4;
int pwmSpeed;

void setup() {
  pinMode(led0Pin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
}


void loop() {
  pwmSpeed=35;
  OnAndOff(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin);
  OneByOne(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,1000);
  TwoByTwo(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,1000);
    OneDirection(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,500);
  BiDirection(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,1000);
  OneTwoOne(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,1000);
  

  pwmSpeed=10;
  OnAndOff(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin);
  OneByOne(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,500);
  TwoByTwo(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,500);
    OneDirection(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,300);
  BiDirection(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,500);
  OneTwoOne(led0Pin,led1Pin, led2Pin,led3Pin,led4Pin,500);
  

}

void BiDirection(int led0,int led1, int led2,int led3,int led4,int delayTime){
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  for(int i=0;i<5;i++){
      digitalWrite(led0, HIGH);
      delay(delayTime); 
        digitalWrite(led0, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(delayTime); 
      digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(delayTime); 
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(delayTime); 
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW); 
  }
}

void OneDirection(int led0,int led1, int led2,int led3,int led4,int delayTime){
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  for (int i=0;i<3;i++){
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
        delay(delayTime);
        digitalWrite(led0, LOW);
        digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
        delay(delayTime);
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    }
}

void TwoByTwo(int led0,int led1, int led2,int led3,int led4,int delayTime) {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  for(int i=0;i<5;i++){
    digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      
        digitalWrite(led0, HIGH);
        digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
        delay(delayTime);
        digitalWrite(led0, LOW);
        digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(delayTime);
  }
}


void OneTwoOne(int led0,int led1, int led2,int led3,int led4,int delayTime) {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  for(int i=0;i<5;i++){
    digitalWrite(led0, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
        delay(delayTime); 
      digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        delay(delayTime);
        digitalWrite(led0, HIGH);
        delay(delayTime/2);
        digitalWrite(led0, LOW);
        delay(delayTime/2);
        digitalWrite(led0, HIGH);
        delay(delayTime/2);
        digitalWrite(led0, LOW);
        delay(delayTime/2);
        digitalWrite(led0, HIGH);
        delay(delayTime/2);
        
  }
 
}


void OneByOne(int led0, int led1, int led2,int led3,int led4,int delayTime) {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  for(int i=0;i<5;i++){
    digitalWrite(led0, HIGH);
      delay(delayTime); 
        digitalWrite(led0, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(delayTime); 
      digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(delayTime); 
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
  }
 
}



void OnAndOff(int led0,int led1, int led2,int led3 , int led4) {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    for(int i=0;i<5;i++){
        for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
            digitalWrite(led0, HIGH);
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            delayMicroseconds(dutyCycle * pwmSpeed);
            digitalWrite(led0, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);

            delayMicroseconds((255 - dutyCycle) * pwmSpeed);
        }
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(500);

        for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
            digitalWrite(led0, HIGH);
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);

            delayMicroseconds(dutyCycle * pwmSpeed);
            digitalWrite(led0, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);

            delayMicroseconds((255 - dutyCycle) * pwmSpeed);
        }

        delay(500); 
    }
}

/**
 * This test turns the motor each direction 
 * while measuring its position with the pot.
 * It will ignore up to 5 false readings by the 
 * pot.
 */
const int controlPin1 = 2;
const int controlPin2 =3;
const int enablePin = 9;

const int buttonPin = 5;

const int posPotPin = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //on button press
  delay(100);
  int x = 1;
  //if(digitalRead(buttonPin) == HIGH){
  if(x == 1){
    x = 0;
    int startPos = analogRead(posPotPin);
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);

    analogWrite(enablePin, 255);

    int disconnects = 0;

    bool endReached = false;
    while(!endReached){
      int currentPos = analogRead(posPotPin);
      //if disconnect happens once 
      if(abs(currentPos - startPos)>100 &&
        disconnects < 5){
          disconnects ++;
          Serial.println("Error");
          //ignore
        }
       else if(currentPos < 200){
        analogWrite(enablePin, 0);
        endReached = true;
        //stop once destination is reached
       }
       else if(disconnects >= 5){
        Serial.println("DISCONNECT ERROR");
        endReached = true;
       }
       Serial.println(currentPos);
       delay(10);
    }

    Serial.println("End reached");
    delay(100);
    
     
    //and now back
    startPos = analogRead(posPotPin);
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);

    analogWrite(enablePin, 255);

    disconnects = 0;

    endReached = false;
    while(!endReached){
      int currentPos = analogRead(posPotPin);
      //if disconnect happens once 
      if(abs(currentPos - startPos)>100 &&
        disconnects < 5){
          Serial.println("ERROR");
          disconnects ++;
          //ignore
        }
       else if(currentPos > 800){
        analogWrite(enablePin, 0);
        analogWrite(controlPin1, LOW);
        analogWrite(controlPin2,LOW);
        endReached = true;
        //stop once destination is reached
       }
       else if(disconnects >= 5){
        Serial.println("DISCONNECT ERROR");
        endReached = true;
       }
       startPos = currentPos;
       Serial.println(currentPos);
       delay(10);
       
    }
    Serial.println("End Reached");
  }
}

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
  if(digitalRead(buttonPin) == HIGH){
    //set direction
    //This direction is CCW at pot
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);

    analogWrite(enablePin, 255);

    delay(1000);

    analogWrite(enablePin, 0);
  }
  Serial.println(analogRead(posPotPin));
  delay(10);  
}

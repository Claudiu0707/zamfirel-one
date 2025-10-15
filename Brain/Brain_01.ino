//Right IR sensor
#define IR_R 52
//Left IR sensor
#define IR_L 53
//Front H-Bridge Motor Driver
//Front-Left Motor
#define enA 2
#define IN1 22
#define IN2 23
//Front-Right Motor
#define enB 3
#define IN3 24
#define IN4 25

//Back H-Bridge Motor Driver
//Back-Left Motor
#define enC 4
#define IN5 26
#define IN6 27
//Back-Right Motor
#define enD 5
#define IN7 28
#define IN8 29

int motorSpeed=200;
int sensorRight=0;
int sensorLeft=0;
void setup() {
  Serial.begin(9600);
  pinMode(IR_R, INPUT);
  pinMode(IR_L, INPUT);

  //Front-Left Motor
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Front-Right Motor
  pinMode(enB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //Back-Left Motor
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Back-Right Motor
  pinMode(enB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  //IR=0 => detects white surface
  //IR=1 => detects black surface
  sensorRight=digitalRead(IR_R);
  sensorLeft=digitalRead(IR_L);
  /*Serial.print("Sensor right ");
  Serial.print(sensorRight);
  Serial.println();
  Serial.print("Sensor left ");
  Serial.print(sensorLeft);
  Serial.println();
  Serial.println();
  Serial.println();*/
  if(sensorRight==1&&sensorLeft==1){
    Forward();
  }
  if(sensorRight==0&&sensorLeft==0){
    Parking();
  }
  if(sensorRight==0||sensorLeft==0)
  {
    if(sensorRight==1&&sensorLeft==0)
    {
      Right();
    }
    if(sensorRight==0&&sensorLeft==1)
    {
      Left();
    }
  }

}
void Forward(){
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  analogWrite(enC, motorSpeed);
  analogWrite(enD, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}

void Backward(){
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  analogWrite(enC, motorSpeed);
  analogWrite(enD, motorSpeed);

  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);

  
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

void Left(){
  
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  analogWrite(enC, motorSpeed);
  analogWrite(enD, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);

  
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  if(sensorRight==0&&sensorLeft==1)
  {
    delay(350);
  }
}

void Right(){
  
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  analogWrite(enC, motorSpeed);
  analogWrite(enD, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  if(sensorRight==1&&sensorLeft==0)
  {
    delay(350);
  }
}

void Parking(){
  //Forward();
  //delay(50);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  analogWrite(enD, 0);
}
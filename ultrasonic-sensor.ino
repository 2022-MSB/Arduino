#include <afstandssensor.h>

#define n 300

AfstandsSensor afstandssensor(13, 12);


//초음파 센서의 핀번호를 설정한다.
int echoPin = 12;
int trigPin = 13;

void setup() {
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  float duration, distance;
  float sum = 0;
  
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  for(int i=0; i<n; i++){
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); 
    distance = ((float)(340 * duration) / 10000) / 2;  
    sum += distance;
  }
  Serial.print(sum / n);
}

void loop() {
}

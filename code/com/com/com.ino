void setup(){

  Serial.begin(115200);

  while(!Serial){
    ;
  }
}

const char stopPoint = '|';

void loop(){

  if (Serial.available()>0) {

    String commandFromJetson = Serial.readStringUntil(stopPoint);

    String ackMsg = "Message :" + commandFromJetson;

    Serial.print(ackMsg);

  }
  
  delay(500);

}
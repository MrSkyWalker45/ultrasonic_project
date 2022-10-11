
const int trig_pin = 11;  
const int echo_pin = 12;
const int led_pin = 9; 
const int buzzer_pin = 10;


long duration; 
float cm;  

void setup(){

    Serial.begin(9600);
    pinMode(trig_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
    pinMode(led_pin,OUTPUT);
    pinMode(buzzer_pin,OUTPUT);

}

void loop(){
    
    digitalWrite(trig_pin,LOW);
    delayMicroseconds(5);
    digitalWrite(trig_pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin,LOW);

    duration = pulseIn(echo_pin,HIGH);
    cm = (duration /2 ) / 29.1; 
    Serial.print(cm);
    Serial.println("cm");
    delay(250);
    for(int i=0;i<=cm;i++){
        analogWrite(led_pin,cm);
    }
    for(int i=cm;i>=0;i--){
        analogWrite(led_pin,cm);
    }

}

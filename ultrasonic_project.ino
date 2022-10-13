#define NOTE_C4 262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


const int trig_pin = 11;  
const int echo_pin = 12;


const int array[4] = {9,8,7,6};
const int led_pin = 9; 
const int led2 = 8; 
const int led3 = 7; 
const int led4 = 6;
const int buzzer_pin = 10;


long duration; 
float cm;  

int tune[] = { 
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4

}; 


int time_d [] = {  4, 8, 8, 4, 4, 4, 4, 4}; 
int duration_note ; 
int pause;
void setup(){

    Serial.begin(9600);
    pinMode(trig_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
    for(int i=0;i<=sizeof(array)/sizeof(array[0]);i++){
      pinMode(array[i],OUTPUT);
    }
    pinMode(buzzer_pin,OUTPUT);


}

void loop(){
    measure();
    if (cm <= 4){
      digitalWrite(led_pin,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH); 
      digitalWrite(led4,HIGH);
      duration_note = 1000/ time_d[0];
      tone(buzzer_pin,tune[0],duration_note);
      pause = duration_note * 1.30;
      delay(pause);
      noTone(buzzer_pin);
      

    }
    else if(cm <= 8){ 
      digitalWrite(led_pin,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);   
      duration_note = 1000/time_d[1] ; 
      tone(buzzer_pin,tune[1],duration_note);
      pause = duration_note * 1.30; 
      delay(pause);
      noTone(buzzer_pin);
    }
    else if(cm <= 12) { 
      digitalWrite(led_pin,HIGH); 
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      duration_note = 1000/time_d[2]; 
      tone(buzzer_pin,tune[2],duration_note);
      pause = duration_note * 1.30;
      delay(pause);
      noTone(buzzer_pin);
    }
    else if(cm <= 16){
      digitalWrite(led_pin,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW); 
      duration_note = 1000/time_d[3]; 
      tone(buzzer_pin,tune[3],duration_note);
      pause = duration_note * 1.30;
      delay(pause); 
      noTone(buzzer_pin);
    }
    else{
      digitalWrite(led_pin, LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      noTone(buzzer_pin);

    }
}


void measure(){
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
}



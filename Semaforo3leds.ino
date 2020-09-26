const int LEDV = 8; 
const int LEDA = 9; 
const int LEDR = 10; 
const int Piezo = 11; 
const int Microfono = 0; 

int val = 0;        
int threshold = 280;

void setup() {
  pinMode(LEDV, OUTPUT); 
  pinMode(LEDA, OUTPUT); 
  pinMode(LEDR, OUTPUT); 
  pinMode(Piezo, OUTPUT); 
  pinMode(Microfono, INPUT); 
  Serial.begin(9600);
}


void loop() {

  val = analogRead(0); 
  if (val>threshold){
  if (val<=288) {
    digitalWrite(LEDV, HIGH); 
    digitalWrite(LEDA, LOW); 
    digitalWrite(LEDR, LOW); 
    analogWrite(Piezo, LOW); 
  }
  else if ((val>288) and (val<320)){
    digitalWrite(LEDA, HIGH); 
    digitalWrite(LEDV, LOW); 
    digitalWrite(LEDR, LOW); 
    analogWrite(Piezo, LOW); 
    delay (50); 
  }
  else{
    digitalWrite(LEDR, HIGH); 
    analogWrite(Piezo, 1023); 
    digitalWrite(LEDV, LOW); 
    digitalWrite(LEDA, LOW); 

    delay (500); 
  }
  }
  else{
    digitalWrite(LEDV, HIGH); 
    digitalWrite(LEDA, LOW); 
    digitalWrite(LEDR, LOW); 
    analogWrite(Piezo, LOW); 
    }
  Serial.println(val);   
  delay(100); 
}

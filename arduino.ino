#define pin_led1 11
#define pin_led2 12
int ventileur=2;
#define buzzer 6
int inputPin = 4;    
int inputPin2 = 5; // choose the input pin (for PIR sensor)
          int pirState = LOW;             // we start, assuming no motion detected
          int val = 0; 
          int pirState2 = LOW;             // we start, assuming no motion detected
          int val2 = 0; // variable for reading the pin status
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_led1, OUTPUT);
  digitalWrite(pin_led1, LOW);
pinMode(ventileur, OUTPUT);
  digitalWrite(ventileur, LOW);
  pinMode(inputPin, INPUT);     // declare sensor as input
            pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  pinMode(pin_led2, OUTPUT);
  digitalWrite(pin_led2, LOW);
    pinMode(inputPin2, INPUT);
            Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int valeur_brute = analogRead(A0);

  float temperature_celcius = valeur_brute * (5.0 / 1023.0 * 100.0);

  Serial.println(temperature_celcius);
  if (temperature_celcius>30)
     digitalWrite(ventileur,HIGH);
     else
     digitalWrite(ventileur,LOW);


      val = digitalRead(inputPin);  // read input value
            if (val == HIGH) {            // check if the input is HIGH
              if (pirState == LOW) {
                // we have just turned on
                Serial.println("Motion detected!");
                digitalWrite(buzzer,HIGH);
                digitalWrite(pin_led2,HIGH);
                // We only want to print on the output change, not state
                pirState = HIGH;
              }
            } else {  
              if (pirState == HIGH){
                // we have just turned of
                  digitalWrite(buzzer,LOW);
                digitalWrite(pin_led2,LOW);
                Serial.println("Motion ended!");
                // We only want to print on the output change, not state
                pirState = LOW;
              }
            }


            //senario1
            val2 = digitalRead(inputPin2);  // read input value
            if (val2 == HIGH) {            // check if the input is HIGH
              if (pirState2 == LOW) {
                // we have just turned on
                Serial.println("Motion detected!");
                digitalWrite(buzzer,HIGH);
               
                // We only want to print on the output change, not state
                pirState2 = HIGH;
              }
            } else {  
              if (pirState2 == HIGH){
                // we have just turned of
                  digitalWrite(buzzer,LOW);
               
                Serial.println("Motion ended!");
                // We only want to print on the output change, not state
                pirState2 = LOW;
              }
            }
     
  delay(250);
}

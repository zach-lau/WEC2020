#define LEFT 3
#define RIGHT 10
#define CLAW 6
#define A 8
#define B 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A,INPUT_PULLUP);
  pinMode(B,INPUT_PULLUP);
}

int a_state = 4;
int b_state = 0;
bool a_press = false;
bool b_press = false;

int value = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  if( (digitalRead(A) == LOW) && !a_press) {
     Serial.println("A"); 
     a_state = (a_state + 1) % 5;
     Serial.println(a_state);
     a_press = true;
     }
  else if (digitalRead(A) == HIGH){
     a_press = false;    
    }
  if((digitalRead(B) == LOW) && !b_press) {
      Serial.println("B");
      b_state = (b_state + 1) % 2;
      b_press = true;
    }

  else if (digitalRead(B) == HIGH){
      b_press = false;
    }
  
  switch(a_state){
    case 0: 
      analogWrite(LEFT, 250);
      analogWrite(RIGHT, 250);
    break;
    case 1: 
      analogWrite(LEFT, 100);
      analogWrite(RIGHT, 100);
    break;
    case 2:
    //forward
      analogWrite(LEFT, 100);
      analogWrite(RIGHT, 250); 
    break;
    case 3: 
    //back
      analogWrite(LEFT, 250);
      analogWrite(RIGHT, 100);
    break;
    case 4: 
    //stop
      analogWrite(LEFT, 255);
      analogWrite(RIGHT, 255);
    break;
  }

  switch(b_state){
    case 0: 
      analogWrite(CLAW, 10);
    break;
    case 1: 
      analogWrite(CLAW, 150);
    break;
  }
  delay(10);
}

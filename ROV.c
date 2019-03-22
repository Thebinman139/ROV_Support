#define CUTTOFF 675 // would have to test to find the desired cut off value. Currentley roughley set to 3.3 volts 
          // 0-1024 range and 0-5v thus (1024/5)*x where x is your desired voltage cuttoff should give a rough value 
#define inPin  A0
#define pwmPin  1
#define PWMMAX  255
#define PWMMIN  0


void setup(){
  pinMode(inPin, INPUT);
  pinMode(pwmPin, OUTPUT);
  
}

/*
// Returns a 'safe' value for the PWM
// @param int pwm is the currently desired PWM value
*/
int safeVal(int pwm){
  if (pwm > PWMMAX){
    pwm = PWMMAX;
  }
  if (pwm < PWMMIN){
    pwm = PWMMIN;
  }
  return pwm;
}


void loop(){
  
  
  int val = analogRead(inPin);
  if (val >= CUTTOFF){
    int pwm = map(val, CUTTOFF, 1023, 0, 255);
    analogWrite(pwmPin, safeVal(pwm));
  }else if(val < CUTTOFF){
    analogWrite(pwmPin, 0);
  }
}
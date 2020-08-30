/****************************************************************************/
/*MADE FOR  : Control motor (board h-bridge) 
/*DESIGN BY : Pattharapol Choonarong <BiGCaT> 
/*DESIGN AT : Suratthani Technical College, Electronics Department , ET313   
/*VESRSION  : 1.0 BETA 
/****************************************************************************/

/******** Set Pin Motor Left *********/
#define PWM_Motor_L   10 
#define IN_A_Motor_L  11
#define IN_B_Motor_L  12
/*************************************/

/******** Set Pin Motor Right ********/
#define PWM_Motor_R   9
#define IN_A_Motor_R  8
#define IN_B_Motor_R  7
/*************************************/

void setup() {
  Serial.begin(115200);
  for(int i=7 ; i>=12 ; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {

  /* Motor(A,B);
   * A = Left wheel speed
   * B = Right wheel speed
   *
   * positive = front
   * minus    = back
   */
  
  /******* front *******/
  Motor(100,100); 
  /*********************/
  delay(5000);
  /******** back *******/
  Motor(-100,-100); 
  /*********************/
  delay(5000);
  /***** Turn left *****/
  Motor(0,100);
  /*********************/
  delay(5000);
  /**** Turn Right *****/
  Motor(100,0);
  /*********************/
  delay(5000);
  /******* Stop ********/
  Motor_Stop();
  /*********************/
  
  /******* Other *******/
  /* Motor(100,-50);
   * Motor(-100,100);
   * Motor(25,50);
   * Motor(-50,-100);
   */ 
}

void Motor_Stop(){
  digitalWrite(IN_A_Motor_R,HIGH);
  digitalWrite(IN_B_Motor_R,HIGH);
  digitalWrite(PWM_Motor_R,LOW);

  digitalWrite(IN_A_Motor_L,HIGH);
  digitalWrite(IN_B_Motor_L,HIGH);
  digitalWrite(PWM_Motor_L,LOW);
}

void Motor(int Motor_L ,int Motor_R){
  
  if(Motor_L >= 100){
    Motor_L = 100;
  }
  if(Motor_R >= 100){
    Motor_R = 100;
  }
  if(Motor_R <= -100){
    Motor_R <= -100;
  }
  if(Motor_L <= -100){
    Motor_L <= -100;
  }
  
  if(Motor_L > 0 && Motor_R > 0){
    digitalWrite(IN_A_Motor_L,LOW);
    digitalWrite(IN_B_Motor_L,HIGH);
    
    digitalWrite(IN_A_Motor_R,HIGH);
    digitalWrite(IN_B_Motor_R,LOW);

    analogWrite(PWM_Motor_L,Motor_L);
    analogWrite(PWM_Motor_R,Motor_R);

  }else if(Motor_L < 0 && Motor_R > 0){
    digitalWrite(IN_A_Motor_L,HIGH);
    digitalWrite(IN_B_Motor_L,LOW);
    
    digitalWrite(IN_A_Motor_R,HIGH);
    digitalWrite(IN_B_Motor_R,LOW);

    analogWrite(PWM_Motor_L,Motor_L);
    analogWrite(PWM_Motor_R,Motor_R);
    
  }else if(Motor_L > 0 && Motor_R < 0){
    digitalWrite(IN_A_Motor_L,LOW);
    digitalWrite(IN_B_Motor_L,HIGH);
    
    digitalWrite(IN_A_Motor_R,LOW);
    digitalWrite(IN_B_Motor_R,HIGH);

    analogWrite(PWM_Motor_L,Motor_L);
    analogWrite(PWM_Motor_R,Motor_R);
    
  }else if(Motor_L < 0 && Motor_R < 0){
    digitalWrite(IN_A_Motor_L,HIGH);
    digitalWrite(IN_B_Motor_L,LOW);
    
    digitalWrite(IN_A_Motor_R,LOW);
    digitalWrite(IN_B_Motor_R,HIGH);

    analogWrite(PWM_Motor_L,Motor_L);
    analogWrite(PWM_Motor_R,Motor_R);
    
  }else if(Motor_L == 0 && Motor_R == 0){
    digitalWrite(IN_A_Motor_R,HIGH);
    digitalWrite(IN_B_Motor_R,HIGH);
    digitalWrite(PWM_Motor_R,LOW);

    digitalWrite(IN_A_Motor_L,HIGH);
    digitalWrite(IN_B_Motor_L,HIGH);
    digitalWrite(PWM_Motor_L,LOW);
  }
}

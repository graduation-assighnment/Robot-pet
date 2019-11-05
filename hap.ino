#include <Servo.h>
#include "LedControl.h"
//#include "SoftReset.h"
int trig = 52;
int echo = 50;
LedControl lc = LedControl(22, 26, 24, 2);
int touchSensor = 13;  // 터치센서 핀 설정
int initstateflag = 0; //이게0이면 가만히있는거 1이면 움직이는상태

int servoPin1 = 4;
int servoPin2 = 5;
int servoPin3 = 6;
int servoPin4 = 7;
int servoPin5 = 8;
int servoPin6 = 9; 
int servoPin7 = 10;
int servoPin8 = 11;
int servoPin9=  12;
int servoPin10=  36;

Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7; 
Servo servo8;
Servo servo9;
Servo servo10;

String myString="";


void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);                             //여긴 초음파
 ////////////////////////////////////////////////////////////
  Serial.println("Hello!");                         //여긴 블루투스 셋업
  Serial1.begin(9600);
  pinMode(touchSensor, INPUT);                      //여긴 터치센서셋업
  /////////////////////////////////////////////////////////
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  lc.shutdown(1, false);                            //여긴 도트매트릭스 셋업
  lc.setIntensity(1, 1);
  lc.clearDisplay(1);
  ////////////////////////////////////////////////////////////////////
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);                         //여긴 서보모터 셋업
  servo6.attach(servoPin6); 
  servo7.attach(servoPin7);
  servo8.attach(servoPin8); 
  servo9.attach(servoPin9);
  servo10.attach(servoPin10);
}

void initeye(){                                     //initstate일때의 동그란 눈동자
  lc.setLed(0,3,1,true);
  lc.setLed(0,4,1,true);
  lc.setLed(0,2,2,true);
  lc.setLed(0,3,2,true);
  lc.setLed(0,4,2,true);
  lc.setLed(0,5,2,true);
  lc.setLed(0,1,3,true);
  lc.setLed(0,2,3,true);
  lc.setLed(0,3,3,true);
  lc.setLed(0,4,3,true);
  lc.setLed(0,5,3,true);
  lc.setLed(0,6,3,true);
  lc.setLed(0,1,4,true);
  lc.setLed(0,2,4,true);
  lc.setLed(0,3,4,true);
  lc.setLed(0,4,4,true);
  lc.setLed(0,5,4,true);
  lc.setLed(0,6,4,true);
  lc.setLed(0,2,5,true);
  lc.setLed(0,3,5,true);
  lc.setLed(0,4,5,true);
  lc.setLed(0,5,5,true);
  lc.setLed(0,3,6,true);
  lc.setLed(0,4,6,true);
  //////////
  lc.setLed(1,3,1,true);
  lc.setLed(1,4,1,true);
  lc.setLed(1,2,2,true);
  lc.setLed(1,3,2,true);
  lc.setLed(1,4,2,true);
  lc.setLed(1,5,2,true);
  lc.setLed(1,1,3,true);
  lc.setLed(1,2,3,true);
  lc.setLed(1,3,3,true);
  lc.setLed(1,4,3,true);
  lc.setLed(1,5,3,true);
  lc.setLed(1,6,3,true);
  lc.setLed(1,1,4,true);
  lc.setLed(1,2,4,true);
  lc.setLed(1,3,4,true);
  lc.setLed(1,4,4,true);
  lc.setLed(1,5,4,true);
  lc.setLed(1,6,4,true);
  lc.setLed(1,2,5,true);
  lc.setLed(1,3,5,true);
  lc.setLed(1,4,5,true);
  lc.setLed(1,5,5,true);
  lc.setLed(1,3,6,true);
  lc.setLed(1,4,6,true); 
}

void jjinkguteye(){                                   //걸어갈때의 찡긋 눈동자

  lc.setLed(0,2,3,true);
  lc.setLed(0,2,4,true);
  lc.setLed(0,3,2,true);
  lc.setLed(0,3,5,true);
  lc.setLed(0,4,1,true);
  lc.setLed(0,4,6,true);
  lc.setLed(0,5,0,true);
  lc.setLed(0,5,7,true);

  lc.setLed(1,2,3,true);
  lc.setLed(1,2,4,true);
  lc.setLed(1,3,2,true);
  lc.setLed(1,3,5,true);
  lc.setLed(1,4,1,true);
  lc.setLed(1,4,6,true);
  lc.setLed(1,5,0,true);
  lc.setLed(1,5,7,true);
}
void hearteye(){                                //꼬리흔들고 손내밀때의 하트모양 눈동자
  
  lc.setLed(0,2,6,true);
  lc.setLed(0,3,6,true);
  lc.setLed(0,5,6,true);
  lc.setLed(0,6,6,true);
  
  lc.setLed(0,1,5,true);
  lc.setLed(0,2,5,true);
  lc.setLed(0,3,5,true);
  lc.setLed(0,4,5,true);
  lc.setLed(0,5,5,true);
  lc.setLed(0,6,5,true);
  lc.setLed(0,7,5,true);

  lc.setLed(0,1,4,true);
  lc.setLed(0,2,4,true);
  lc.setLed(0,3,4,true);
  lc.setLed(0,4,4,true);
  lc.setLed(0,5,4,true);
  lc.setLed(0,6,4,true);
  lc.setLed(0,7,4,true);
  
  lc.setLed(0,2,3,true);
  lc.setLed(0,3,3,true);
  lc.setLed(0,4,3,true);
  lc.setLed(0,5,3,true);
  lc.setLed(0,6,3,true);
  
  lc.setLed(0,3,2,true);
  lc.setLed(0,4,2,true);
  lc.setLed(0,5,2,true);
  
  lc.setLed(0,4,1,true);

//////////////////////////////////////////
  lc.setLed(1,1,6,true);
  lc.setLed(1,2,6,true);
  lc.setLed(1,4,6,true);
  lc.setLed(1,5,6,true);
  
  lc.setLed(1,0,5,true);
  lc.setLed(1,1,5,true);
  lc.setLed(1,2,5,true);
  lc.setLed(1,3,5,true);
  lc.setLed(1,4,5,true);
  lc.setLed(1,5,5,true);
  lc.setLed(1,6,5,true);

  lc.setLed(1,0,4,true);
  lc.setLed(1,1,4,true);
  lc.setLed(1,2,4,true);
  lc.setLed(1,3,4,true);
  lc.setLed(1,4,4,true);
  lc.setLed(1,5,4,true);
  lc.setLed(1,6,4,true);
 
  lc.setLed(1,1,3,true);
  lc.setLed(1,2,3,true);
  lc.setLed(1,3,3,true);
  lc.setLed(1,4,3,true);
  lc.setLed(1,5,3,true);
  
  lc.setLed(1,2,2,true);
  lc.setLed(1,3,2,true);
  lc.setLed(1,4,2,true);
  
  lc.setLed(1,3,1,true);
}

void xeye(){
  lc.setLed(0,0,0,true);
  lc.setLed(0,0,7,true);
  lc.setLed(0,1,1,true);
  lc.setLed(0,1,6,true);
  lc.setLed(0,2,2,true);
  lc.setLed(0,2,5,true);
  lc.setLed(0,3,3,true);
  lc.setLed(0,3,4,true);
  lc.setLed(0,4,3,true);
  lc.setLed(0,4,4,true);
  lc.setLed(0,5,2,true);
  lc.setLed(0,5,5,true);
  lc.setLed(0,6,1,true);
  lc.setLed(0,6,6,true);
  lc.setLed(0,7,0,true);
  lc.setLed(0,7,7,true);

  lc.setLed(1,0,0,true);
  lc.setLed(1,0,7,true);
  lc.setLed(1,1,1,true);
  lc.setLed(1,1,6,true);
  lc.setLed(1,2,2,true);
  lc.setLed(1,2,5,true);
  lc.setLed(1,3,3,true);
  lc.setLed(1,3,4,true);
  lc.setLed(1,4,3,true);
  lc.setLed(1,4,4,true);
  lc.setLed(1,5,2,true);
  lc.setLed(1,5,5,true);
  lc.setLed(1,6,1,true);
  lc.setLed(1,6,6,true);
  lc.setLed(1,7,0,true);
  lc.setLed(1,7,7,true);
}

void forward1(){
  servo1.write(60);
  servo5.write(150);
  servo4.write(90);
  servo8.write(0);

  servo3.write(120);
  servo7.write(40);
  servo2.write(90);
  servo6.write(180);
}

void forward2(){
  servo1.write(60);
  servo5.write(150);
  servo4.write(90);
  servo8.write(30);

  servo3.write(120);
  servo7.write(40);
  servo2.write(90);
  servo6.write(150);
}

void forward3(){
  servo1.write(90);
  servo5.write(180);
  servo4.write(120);/////
  servo8.write(30);

  servo3.write(90);
  servo7.write(10);
  servo2.write(60);/////
  servo6.write(150);
}

void forward4(){
  servo1.write(90);
  servo5.write(150);
  servo4.write(120);
  servo8.write(30);

  servo3.write(90);
  servo7.write(40);
  servo2.write(60);
  servo6.write(150);
}

void walk(){                                      //앞으로 걷기
  forward1();
  delay(500);
  forward2();
  forward3();
  delay(500);
  forward4();
}

void morihundul(){                               //머리흔들기
  servo10.write(70);
  delay(1500);
  servo10.write(130);
  delay(1500);
}

void ggorihundul(){                               //꼬리흔들기
  for(int i=0; i<2; ++i){
    servo9.write(70);
    delay(1000);
    servo9.write(110);
    delay(1000);
  }
}

void stand(){                                     //initstate일때 가만히 서있는 동작
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(180);
  servo6.write(180);
  servo7.write(10);
  servo8.write(0);
}
//////////////////////////////////////////////////////////////////////////////////////////////
void initstate(){                                 //초기상태 가만히서있음 플래그값이 0인 유일한상태
  stand();
  initeye();
  initstateflag=0;
  servo9.write(90);//꼬리 세우기
  servo10.write(90);
}

void iriwa(){                                     //걸어가기 -> 서있는 상태가 아니니까 플래그값이 1임
  jjinkguteye();
  walk();
  initstateflag = 1;
}

void hand(){                                       //손주기
  hearteye();
  servo1.write(0);
  initstateflag=1;
}

void sitdown(){                                     //앉기 -> 서있는 상태가 아니니까 플래그값이 1임
  initeye();
  servo6.write(90);
  servo7.write(90);
  initstateflag = 1;
}

void jalhesso(){
  hearteye();
  stand();
  ggorihundul();
}

void jalmot(){
  xeye();
  morihundul();
}

void die(){
  xeye();
  servo5.write(140);
  servo6.write(90);
  servo7.write(90);
  servo8.write(40);
  initstateflag = 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  unsigned long duration = pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;
  int touchValue = digitalRead(touchSensor);
  if(Serial1.available()){      //블루투스로 들어오는 값이 있으면
    myString = "";              //mystring을 초기화시킴
    lc.clearDisplay(0);         //led초기화
    lc.clearDisplay(1);
    initstateflag=1;            //플래그값1 -> 이제이동할 거란말
  }
  else if(!Serial1.available()&&initstateflag==0){ //블투로 들어오는값없고, 현재 정지상태면
    initstate();                //계속 정지상태유지, 계속 플래그값0 으로 유지
  }

  while(Serial1.available())  //블투로 들어오는 값이 있으면 아래의 while문 실행
  { 
    char myChar = (char)Serial1.read();  //한글자씩 받음
    //myString += myChar;
    myString += myChar;                 //한글자씩받은걸 위에서 초기화된 myString에 add시킴
    Serial.println(myString);           //한글자씩 추가되고있는 myString을 보여줘
    delay(5);          
  }

  if(initstateflag==0){                 //플래그가0이면 == 현재정지상태이면
   //initstate();                        
    if(touchValue == HIGH){///            터치를 하면///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      Serial.println("TOUCHED");        //시리얼에 touched 출력
      lc.clearDisplay(0) ;              //도트매트릭스 초기화
      lc.clearDisplay(1) ;
      jalhesso();                        //함수 잘해쏘 실행 -> 눈하트, 다리는펴고, 꼬리흔들

      lc.clearDisplay(0) ;                //눈 하트인 도트매트릭스 다시초기화
      lc.clearDisplay(1) ;
      initstate();                        //초기상태로 돌아가자
      delay(1000);
    }
    else{                                 //터치안하면(그냥 가만히 놔두면)
      initstate();                       
      Serial.println("NOT TOUCHED");      //시리얼에 not touched 출력
    }
  }
  else{                     //initstateflag플래그값이 1이면 -> 블투로 음성값이 들어오면 
                            //                -> 이제 움직일거면
                     
      if(myString=="가"||myString=="각"||myString=="이리와"||myString=="이리 와"||myString=="이 리와")  //myString 값이 '가' 이라면
      {
        iriwa();         //함수 이리와 실행 -> 눈찡긋, 앞으로걷기, 플래그값1로 업뎃
        if (distance < 10) {
          lc.clearDisplay(0) ;                //눈 하트인 도트매트릭스 다시초기화
          lc.clearDisplay(1) ;
          initstateflag=0;
          //soft_restart;
        }
      }
      else if(myString=="손"){ //myString 값이 '손' 이면 
        hand();                //함수 hand실행 -> 눈하트, 앞발 들었다 다시 제자리로
        //lc.clearDisplay(0) ;   //도트매트릭스 초기화
        //lc.clearDisplay(1) ;
      }
      else if(myString=="앉아"||myString=="안자"||myString=="안 자"||myString=="혼자"||myString=="현자"||myString=="한자"||myString=="1장"||myString=="은자"){ //myString이 '앉아' 이면
        sitdown();              //함수 sitdown 실행 플래그값 1로 초기화
      }
      else if(myString=="빵야"||myString=="아니야"||myString=="아냐"||myString=="뻥이야"||myString=="땅이야"||myString=="방년"||myString=="빵이야"){
        die();
      }
      else if(myString=="그만"){    //걷다가 서기 플래그값 0됨
        initstate();
        //myString="";
      }
      else if(myString=="서"||myString=="일어서"||myString=="일어 서"||myString=="6"||myString=="이라서"){       //앉았다 일어서기 플래그값 0됨
        initstate();
      }
      else if(myString=="바로"){       //앉았다 일어서기 플래그값 0됨
        initstate();
      }
      else{
        //jalmot();
      }
    //}///
  }
  delay(100);
}

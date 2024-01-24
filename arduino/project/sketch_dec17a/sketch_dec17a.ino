//参考にしたプログラムは自分の過去のProcessingのプログラムとrgbバックライト液晶のサンプルプログラムです
#include <Servo.h>
Servo myservo; //サーボモータライブラリ

#include <rgb_lcd.h>
rgb_lcd lcd; //RGBバリエーションライブラリ

int confirm = 0;
int left = 0;
int right = 0; //スイッチ制御用

String scene = "gn0"; //液晶に表示するプログラムの管理

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);//液晶の一行当たりの字数、行数を決める
  lcd.print("Select the title");//「Select the title」と表示する

  myservo.attach(A2);//A2にサーボモータをセット
  pinMode(11, INPUT);//スイッチを読み込む
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  right = digitalRead(11);
  left = digitalRead(12);
  confirm = digitalRead(13);//スイッチの初期値を格納
  
  if (scene == "gn0") gn0();//液晶の表示情報をシーンで管理
  else if (scene == "gn1") gn1();
  else if (scene == "gn2") gn2();
  else if (scene == "gn3") gn3();
  else if (scene == "gn4") gn4();
  else if (scene == "gn5") gn5();
  //gn = game number
}

void gn0() {
  delay(125);//入力が連続してしまうことを防止
  lcd.setRGB(125,33,45);//背景色を確定
  lcd.setCursor(0,2);//入力箇所を二行目に設定
  lcd.print("GIRL'S GARDEN  ");//タイトルの入力
  if (right == 1) {
    tone(9,622.254,100);//右のゲームを選択
    scene = "gn1";
  }
  if (left == 1){
    tone(9,622.254,100);//左のゲームを選択
    scene = "gn5";  
  }
  if (confirm == 1){
    tone(9,1244.508,100);//決定して台を回転
    delay(100);
    tone(9,1108.731,100);
    delay(100);
    myservo.write(0);
    }
}


void gn1() {
  delay(125);
  lcd.setRGB(0,0,255);
  lcd.setCursor(0, 2);
  lcd.print("Fantsy Zone 2  ");
  if (right == 1) {
    tone(9,622.254,100);
    scene = "gn2";
  }
  if (left == 1){
    tone(9,622.254,100);
    scene = "gn0";  
  }
  if (confirm == 1){
    tone(9,1244.508,100);
    delay(100);
    tone(9,1108.731,100);
    delay(100);
    myservo.write(45);
    }
}

void gn2() {
  delay(125);
  lcd.setRGB(160,60,160);
  lcd.setCursor(0, 2);
  lcd.print("ASHURA         ");
  if (right == 1) {
    tone(9,622.254,100);
    scene = "gn3";
  }
  if (left == 1){
    tone(9,622.254,100);
    scene = "gn1";  
  }
  if (confirm == 1){
    tone(9,1244.508,100);
    delay(100);
    tone(9,1108.731,100);
    delay(100);
    myservo.write(90);
    }
}


void gn3() {
  delay(125);
  lcd.setRGB(255,255,255);
  lcd.setCursor(0, 2);
  lcd.print("N-SUB           ");
  if (right == 1) {
    tone(9,622.254,100);
    scene = "gn4";
  }
  if (left == 1){
    tone(9,622.254,100);
    scene = "gn2";  
  }
  if (confirm == 1){
    tone(9,1244.508,100);
    delay(100);
    tone(9,1108.731,100);
    delay(100);
    myservo.write(135);
    }
}


void gn4() {
  delay(125);
  lcd.setRGB(80,80,255);
  lcd.setCursor(0, 2);
  lcd.print("Hokuto no Ken   ");
  if (right == 1) {
    tone(9,622.254,100);
    scene = "gn5";
  }
  if (left == 1){
    tone(9,622.254,100);
    scene = "gn3";  
  }
  if (confirm == 1){
    tone(9,1244.508,100);
    delay(100);
    tone(9,1108.731,100);
    delay(100);
    myservo.write(180);
    }
}

void gn5() {
  delay(125);
  lcd.setRGB(0,255,0);
  lcd.setCursor(0, 2);
  lcd.print("Space Harrier   ");
  if (right == 1) {
    tone(9,622.254,100);
    scene = "gn0";
  }
  if (left == 1){
    tone(9,622.254,100);
    scene = "gn4";  
  }
  if (confirm == 1){
    tone(9,1244.508,100);
    delay(100);
    tone(9,1108.731,100);
    delay(100);
    myservo.write(180);
    }
}

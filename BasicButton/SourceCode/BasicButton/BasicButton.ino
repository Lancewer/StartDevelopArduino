/*
 * Basic Button
 * 
 */

//定义常量，常量一旦定义变无法改变其值
const int buttonPin = 2; //按键所接入的端口
const int ledPin = 13; //LED所接入的端口

//定义按键状态的变量，并初始化值为低电平，变量的值允许在程序运行过程中改变
int buttonState = LOW;

void setup() {
  // 初始化LED端口为输出模式
  pinMode(ledPin, OUTPUT);
  
  //初始化按键端口为输入模式
  pinMode(buttonPin, INPUT);

}

void loop() {
  // 读取按键端口的值
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
  //将LED端口设为高电平，即点亮LED
  digitalWrite(ledPin, HIGH);
  } else {
    //将LED端口设为低电平，即熄灭LED
  digitalWrite(ledPin, LOW);
  }
}

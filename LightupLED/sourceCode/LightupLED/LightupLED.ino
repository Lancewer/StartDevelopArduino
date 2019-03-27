/*
  点亮LED
  
  本程序是根据官方示例Blink修改。用于演示Arduino的数字输出功能来点亮板载LED功能。
  效果为板载LED灯(在Uno上为端口13)每间隔1秒闪烁一次。
  
  原官方示例参见http://www.arduino.cc/en/Tutorial/Blink
  
  @modified by Lancewer 2019

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// 初始化方法，只在arduino上电时或者复位按钮后执行一次
void setup() {
  // 初始化Arduino Uno上第13个数字输入输出口(也就是LED_BUILTIN)的模式为“输出”
  pinMode(LED_BUILTIN, OUTPUT);
}

// 程序运行的主要部分，会一直循环执行
void loop() {
  // 因为是数字输出模式，因此使用digitalWrite函数
  digitalWrite(LED_BUILTIN, HIGH);   // 点亮LED (即为设置端口输出电压为高(HIGH))
  delay(1000);                       // 延时1秒
  digitalWrite(LED_BUILTIN, LOW);    // 关闭LED (即为设置端口输出电压为低(LOW))
  delay(1000);                       // 延时1秒
}

#define led 3
#define button 2
int bright = 0, defaultup = 5, trangthai = 10, sensor = A0;

void setup() {
    Serial.begin(115200);
    //pinMode(led, OUTPUT);
    //pinMode(button, INPUT);
}

void loop() {   
    // int stt = digitalRead(button);  
    // trangthai = (trangthai + stt) % 2;
    // if(trangthai){   
    //     analogWrite(led, bright);
    //     bright += defaultup;
    //     if(bright == 10 || bright == 225)
    //         defaultup = -1 * defaultup;
    // }
    // else analogWrite(led, 0);
    // //Serial.println(trangthai);
    // delay(30);
    int reading = analogRead(sensor);
    float voltage = reading * 5.0 / 1024.0;
    float temp = voltage * 100.0;
    Serial.println(temp);
    delay(1000);
}

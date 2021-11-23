// 定義一串音高:Do, Sol, Sol, La, Sol, 空, Ti, Do 
int melody[] = {
  262, 196, 196, 220, 196, 0, 247, 262
};

// 定義一串節奏，4為4分音符(一拍)，8為8分音符(半拍)
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // 用for迴圈一一發出聲響
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // 計算每個音符長度並發聲
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(13, melody[thisNote], noteDuration);
    // 在音符間保留一小段空白時間，長度為音符長度的30%
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // 停止演奏
    noTone(13);
  }
}

void loop() {
  // 只演奏一次，不需要寫loop()的部分
}

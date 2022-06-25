#define N 4000
#define S 2

esp_timer_handle_t timer;
int16_t raw[S * N] = {0};
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(34, INPUT);
  esp_timer_create_args_t timer_args;
  timer_args.callback = &func;
  timer_args.name = "periodic";
  ESP_ERROR_CHECK(esp_timer_create(&timer_args, &timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(timer, 1000000 / N));
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void output() {
  for (int i = 0; i < S * N; i++)
    Serial.println(raw[i]);
}

static void func(void *arg) {
  if (cnt < S * N) {
    int16_t R = analogRead(34) + 1;
    raw[cnt++] = R;

    if (cnt == S * N)
      output();
  }
//  byte B[3] = {
//    (byte) (0x00), 
//    (byte) (R >> 8), 
//    (byte) (R & ((1 << 8) - 1))
//  };
//  Serial.write(B, 3);
}

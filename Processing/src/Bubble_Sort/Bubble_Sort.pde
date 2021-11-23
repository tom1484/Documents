import java.util.Random;
import java.util.Arrays;

int sz = 500, delayTime = 1;
int width = sz * 3, height = sz * 2, rh = height + int(width / sz);
int[] arr = new int[sz];
int C1 = 0, C2 = 0;
boolean finish = false;

void setup(){
  surface.setSize(width, rh);
  for (int i = 0; i < sz; i ++){
    arr[i] = (i + 1) * int((height) / sz);
  }
  shuffleArray(arr);
}

void keyPressed(){
  if (key == ENTER) thread("bSort");
}

void draw(){
  printC(C1, C2);
  if (finish){
    printN();
    noLoop();
  }
}

// ==================================================================================================================

void bSort(){
  bSort(sz - 1);
}

void bSort(int len){
  for (int i = len; i > 1; i --){
    for (int j = 0; j < i; j ++){
      if (arr[j] > arr[j + 1]){
        C1 = j;
        C2 = j + 1;
        swap(j, j + 1);
        delay(delayTime);
      }
    }
  }
  finish = true;
}

// ==================================================================================================================

void printC(int com1, int com2){
  background(0);
  noStroke();
  for (int i = 0; i < sz; i ++){
    if (i != com1 && i != com2) fill(255);
    else fill(0, 255, 0);
    rect(i * 3, rh - arr[i], 3, arr[i] * 2);
  }
}

void printN(){
  background(0);
  noStroke();
  for (int i = 0; i < sz; i ++){
    fill(255);
    rect(i * 3, rh - arr[i], 3, arr[i] * 2);
  }
}

void shuffleArray(int[] array) {
  Random rng = new Random();
  for (int i = array.length; i > 1; i--) {
    int j = rng.nextInt(i);
    int tmp = array[j];
    array[j] = array[i-1];
    array[i-1] = tmp;
  }
}

void swap(int i, int j){
  arr[i] += arr[j];
  arr[j] = arr[i] - arr[j];
  arr[i] -= arr[j];
}

import java.util.*;

int cell_size = 40;
int preview_size = 25;
int window_width = cell_size * 10;
int window_height = cell_size * 20;

class Block {
  int block_color = -1;
  int x_position, y_position;
  boolean is_preview = false;
  
  void show(){
    if (block_color == -1) fill(0);
    if (block_color == 0) fill(24, 196, 239);
    if (block_color == 1) fill(255, 255, 20);
    if (block_color == 2) fill(210, 24, 239);
    if (block_color == 3) fill(240, 175, 23);
    if (block_color == 4) fill(58, 65, 255);
    if (block_color == 5) fill(255, 58, 58);
    if (block_color == 6) fill(24, 239, 20);
    if (block_color == 7) fill(40);
    if (!is_preview) rect(x_position, y_position, cell_size, cell_size);
    else rect(x_position, y_position, preview_size, preview_size);
  }
  
  Block(int x, int y){
    x_position = x;
    y_position = y;
  }
  
  Block(){}
}

int[][][][] shape_list = 
{  
  {
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 1, 1}, 
    }, 
    {
      {1, 0, 0, 0}, 
      {1, 0, 0, 0}, 
      {1, 0, 0, 0}, 
      {1, 0, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 1, 1}, 
    }, 
    {
      {0, 0, 0, 1}, 
      {0, 0, 0, 1}, 
      {0, 0, 0, 1}, 
      {0, 0, 0, 1}, 
    }
  }, 
  
  // ==============================
  
  {
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 1, 0, 0}, 
    }
  }, 
  
  // ==============================
  
  {
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {1, 1, 1, 0}, 
      {0, 0, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {0, 1, 1, 0}, 
      {0, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 1, 0}, 
      {0, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {1, 1, 0, 0}, 
      {0, 1, 0, 0}, 
    }
  }, 
  
  // ==============================
  
  {
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {0, 0, 1, 0}, 
      {1, 1, 1, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {1, 0, 0, 0}, 
      {1, 0, 0, 0}, 
      {1, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 1, 0}, 
      {1, 0, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 1, 0}, 
      {0, 0, 1, 0}, 
      {0, 0, 1, 0}, 
    }
  }, 
  
  // ==============================
  
  {
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 0, 0, 0}, 
      {1, 1, 1, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 0, 0, 0}, 
      {1, 0, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 1, 0}, 
      {0, 0, 1, 0},  
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 1, 0}, 
      {0, 0, 1, 0}, 
      {0, 1, 1, 0}, 
    }
  }, 
  
  // ==============================
  
  {
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {0, 1, 1, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 0, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0},
      {0, 0, 0, 0}, 
      {1, 1, 0, 0}, 
      {0, 1, 1, 0} 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {1, 1, 0, 0}, 
      {1, 0, 0, 0}, 
    }
  }, 
  
  // ==============================
  
  {
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {0, 1, 1, 0}, 
      {1, 1, 0, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {0, 1, 1, 0}, 
      {0, 0, 1, 0}, 
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 0, 0, 0}, 
      {0, 1, 1, 0}, 
      {1, 1, 0, 0}
    }, 
    {
      {0, 0, 0, 0}, 
      {0, 1, 0, 0}, 
      {0, 1, 1, 0}, 
      {0, 0, 1, 0}, 
    }
  }
};

int time = 0;

int status = 0;
int shape = 0;

int x_offset = 0;
int y_offset = 0;
int[] shape_up_offset = {-2, -2, -1, -2, -2, -2, -2};
int[] shape_left_offset = {-2, -1, -1, -1, -2, -1, -2};

boolean stop = false;
boolean left_stop = false;
boolean right_stop = false;
boolean shadow_down_stop = false;
boolean down_stop = false;
boolean left_over = false;
boolean right_over = false;
boolean down_over = false;
boolean up_stop = false;
int stop_time = 0;

int press_delay = 200;
int drag_delay = 40;
boolean[] keys = {false, false, false, false};
boolean[] key_mode = {false, false, false, false};
int[] press_time = {0, 0, 0, 0};

int block_num = 0;
int next = 0;
boolean[] first_seven = {false, false, false, false, false, false, false};
boolean space_released = true;
boolean space = false;

ArrayList <ArrayList <Block> > Base = new ArrayList <ArrayList <Block> >();
ArrayList <Block> dropping, backup, shadow, preview;

int last_move = -1;
int score = 0;
int speed = 800;

boolean gameover = false;
boolean playing = false;

ArrayList <Integer> erase = new ArrayList<Integer>();
boolean clearing = false;

class FrequencyControll{
  int[] arr = new int[2];
  int[] arr2 = new int[2];
  int num = 0;
  int num2 = 0;
  
  FrequencyControll(){
    for (int i = 0; i < 2; i ++){
      arr[i] = -1;
      arr2[i] = -1;
    }
  }
  
  void update(){
    for (int i = 0; i < 2; i ++){
      if (block_num - arr[i] >= 7 && arr[i] != -1){
        arr[i] = -1;
        num --;
      }
      if (block_num - arr2[i] >= 10 && arr2[i] != -1){
        arr2[i] = -1;
        num2 --;
      }
    }
  }
  
  void add(int n){
    for (int i = 0; i < 2; i ++){
      if (arr[i] == -1){
        arr[i] = n;
        num ++;
        break;
      }
      if (arr2[i] == -1){
        arr2[i] = n;
        num2 ++;
        break;
      }
    }
  }
}

ArrayList <FrequencyControll> freq = new ArrayList <FrequencyControll>();

void setup(){
  size(551, 801);
  background(0);
  initialize_base();
  for (int i = 0; i < 7; i ++) freq.add(new FrequencyControll());
  generate_new_shape();
  playing = false;
}

void reset(){
  background(0);
    
  initialize_base();       
  for (int i = 0; i < 7; i ++) freq.set(i, new FrequencyControll());
    
  time = 0;
  status = 0;
  shape = 0;
  
  x_offset = 0;
  y_offset = 0;
  
  stop = false;
  left_stop = false;
  right_stop = false;
  down_stop = false;
  left_over = false;
  right_over = false;
  down_over = false;
  up_stop = false;
  stop_time = 0;
  
  press_delay = 180;
  drag_delay = 40;
  for (int i = 0; i < 4; i ++) keys[i] = false;
  for (int i = 0; i < 4; i ++) key_mode[i] = false;;
  for (int i = 0; i < 4; i ++) press_time[i] = 0;
  
  block_num = 0;
  for (int i = 0; i < 7; i ++) first_seven[i] = false;
  space_released = true;
  space = false;
    
  score = 0;
  speed = 800;
    
  last_move = 0;
  gameover = false;
    
  delay(3000);
  generate_new_shape();
  playing = false;
}

void keyPressed(){
  if (keyCode == LEFT && !keys[0] && playing){
    keys[1] = false;
    keys[0] = true;
    key_mode[0] = false;
    press_time[0] = millis();
    update_x_position(-1);
  }
  if (keyCode == RIGHT && !keys[1] && playing){
    keys[0] = false;
    keys[1] = true;
    key_mode[1] = false;
    press_time[1] = millis();
    update_x_position(1);
  }
  if (keyCode == UP && !keys[2] && playing){
    keys[2] = true;
    key_mode[2] = false;
    press_time[2] = millis();
    update_rotate(1);
  }
  if (keyCode == DOWN && !keys[3] && playing){
    keys[3] = true;
    key_mode[3] = false;
    press_time[3] = millis();
    update_y_position(1);
  }
  if (key == ' ' && space_released && playing){
    space_released = false;
    space = true;
    
    while (!down_stop)
      update_y_position(1);
    fixed();
    generate_new_shape();
    x_offset = 0;
    y_offset = 0;
    down_stop = false;
  }
  if (keyCode == ENTER) {
    playing = true;
    time = millis();
  }
}

void keyReleased(){
  if (keyCode == LEFT){
    keys[0] = false;
    key_mode[0] = false;
  } 
  if (keyCode == RIGHT){
    keys[1] = false;
    key_mode[1] = false;
  }
  if (keyCode == UP){
    keys[2] = false;
    key_mode[2] = false;
  }
  if (keyCode == DOWN){
    keys[3] = false;
  }
  if (key == ' '){
    space_released = true;
  }
}

void draw(){
  if (playing){
    draw_graph();
    
    if (!gameover){
      check_keys();
    
      if (!down_stop) stop_time = millis();
      if (down_stop && millis() - stop_time >= 800){
        down_stop = false;
        fixed();
        generate_new_shape();
        x_offset = 0;
        y_offset = 0;
      }
    
      if (millis() - time >= speed){
        update_y_position(1);
        time = millis();
      }
    }
    else{
      reset();
    }
  }
  else {
    background(0);
    fill(255);
    rect(401, 0, 150, 800);
    fill(0);
    rect(405, 4, 142, 142);
    rect(405, 450, 142, 47);
  
    noFill();
    strokeWeight(1);
    stroke(40);
    for (int i = 0; i <= 400; i += cell_size)
      line(i, 0, i, 800);
    for (int i = 0; i <= 800; i += cell_size)
      line(0, i, 400, i);
    
    textSize(40);
    fill(255);
    textAlign(CENTER);
    text("PRESS ENTER\nTO START", 200, 400);
  }
}

void check_keys(){
  if (keys[0]){
    if (!key_mode[0] && millis() - press_time[0] >= press_delay){
      update_x_position(-1);
      key_mode[0] = true;
      press_time[0] = millis();
    }
    if (key_mode[0] && millis() - press_time[0] >= drag_delay){
      update_x_position(-1);
      press_time[0] = millis();
    }
  }
  
  if (keys[1]){
    if (!key_mode[1] && millis() - press_time[1] >= press_delay){
      update_x_position(1);
      key_mode[1] = true;
      press_time[1] = millis();
    }
    if (key_mode[1] && millis() - press_time[1] >= drag_delay){
      update_x_position(1);
      press_time[1] = millis();
    }
  }
  
  if (keys[2]){
    if (!key_mode[2] && millis() - press_time[2] >= press_delay){
      update_rotate(1);
      key_mode[2] = true;
      press_time[2] = millis();
    }
    if (key_mode[2] && millis() - press_time[2] >= drag_delay){
      update_rotate(1);
      press_time[2] = millis();
    }
  }
  
  if (keys[3]){
    if (!key_mode[3] && millis() - press_time[3] >= press_delay){
      update_y_position(1);
      key_mode[3] = true;
      press_time[3] = millis();
    }
    if (key_mode[3] && millis() - press_time[3] >= drag_delay){
      update_y_position(1);
      press_time[3] = millis();
    }
  }
}

void draw_graph(){  
  if (!playing) return;
  background(0);
  
  fill(255);
  rect(401, 0, 150, 800);
  fill(0);
  rect(405, 4, 142, 142);
  rect(405, 450, 142, 47);
  textSize(30);
  fill(255);
  textAlign(CENTER);
  text(score, 476, 483);
  
  noFill();
  strokeWeight(1);
  stroke(40);
  for (int i = 0; i <= 400; i += cell_size)
    line(i, 0, i, 800);
  for (int i = 0; i <= 800; i += cell_size)
    line(0, i, 400, i);
   
  generate_shadow(); 
  for (int i = 0; i < 4; i ++)
    shadow.get(i).show();
  
  for (int i = 0; i < 20; i ++){
    for (int j = 0; j < 10; j ++){
      Base.get(i).get(j).show();
    }
  }

  for (int i = 0; i < 4; i ++){
    dropping.get(i).show();
    preview.get(i).show();
  }
    
}

void generate_new_shape(){
  time = millis();
  left_over = false;
  right_over = false;
  left_stop = false;
  right_stop = false;
  down_over = false;
  down_stop = false;
  up_stop = false;
  
  status = 0;
  randomSeed(millis());
  
  for (int n = 0; n < 2; n ++){
    if (n == 0 && block_num > 0){
      shape = next;
      continue;
    }
    next = millis() % 7;
  
    if (block_num < 7){
      while (first_seven[next]) next = millis() % 7;
      first_seven[next] = true;
    }
    block_num += 1;
    for (int i = 0; i < 7; i ++) freq.get(i).update();
    while (freq.get(next).num >= 2) next = millis() % 7;
    
    //for (int i = 0; i < 7; i ++) 
    //  if (freq.get(i).num2 == 0 && next != i && block_num >= 7) next = i;
    freq.get(next).add(block_num);
  
    if (block_num == 1) shape = next;
  }
  
  int up_offset = 4, right_offset = 4, down_offset = 4;
  preview = new ArrayList<Block>();
  for (int i = 0; i < 4; i ++)
    for (int j = 0; j < 4; j ++)
      if (shape_list[next][0][i][j] == 1){
        up_offset = min(up_offset, i);
        right_offset = min(right_offset, 3 - j);
        down_offset = min(down_offset, 3 - i);
      }
      
  for (int i = 0; i < 4; i ++)
    for (int j = 0; j < 4; j ++)
      if (shape_list[next][0][i][j] == 1){
        preview.add(new Block(j * preview_size, (i - up_offset) * preview_size));
        preview.get(preview.size() - 1).block_color = next;
        preview.get(preview.size() - 1).is_preview = true;
      }
      
  for (int i = 0; i < 4; i ++){
    preview.get(i).x_position += 405 + int(float(preview_size * 4) * float(right_offset) / 2.0 / 4.0) + (142 - preview_size * 4) / 2;
    preview.get(i).y_position += 4 + int(float(preview_size * 4) * float(up_offset) / 2.0 / 4.0) + 
                                 int(float(preview_size * 4) * float(down_offset) / 2.0 / 4.0) + (142 - preview_size * 4) / 2;
  }
  
  dropping = new ArrayList <Block>();
  for (int i = 0; i < 4; i ++){
    for (int j = 0; j < 4; j ++){
      if (shape_list[shape][0][i][j] == 1){
        Block blk = new Block();
        blk.block_color = shape;
        blk.x_position = (j + shape_left_offset[shape]) * cell_size + window_width / 2;
        blk.y_position = (i + shape_up_offset[shape]) * cell_size;
        dropping.add(blk);
      }
    }
  }
  backup = dropping;
  draw_graph();
  check_touch();
}

void update_x_position(int offset){
  if ((offset == 1 && !right_stop) || (offset == -1 && !left_stop)){
    if (offset == 1) last_move = 0;
    else last_move = 1;
    x_offset += offset;
    for (int i = 0; i < 4; i ++){
      dropping.get(i).x_position += offset * cell_size;
    }
  }
  draw_graph();
  check_touch();
}

void update_y_position(int offset){
  if (!down_stop){
    last_move = 2;
    y_offset += offset;
    for (int i = 0; i < 4; i ++){
      dropping.get(i).y_position += offset * cell_size;
    }
  }
  draw_graph();
  check_touch();
}

void update_rotate(int offset){
  status = (status + offset) % 4;
  if (status < 0) status += 4;
  
  dropping = new ArrayList <Block>();
  for (int i = 0; i < 4; i ++){
    for (int j = 0; j < 4; j ++){
      if (shape_list[shape][status][i][j] == 1){
        Block blk = new Block();
        blk.block_color = shape;
        blk.x_position = (j + shape_left_offset[shape] + x_offset) * cell_size + window_width / 2;
        blk.y_position = (i + shape_up_offset[shape] + y_offset) * cell_size;
        dropping.add(blk);
      }
    }
  }
  check_touch();
  
  if (left_over && !right_over){
    while (left_over){
      if (right_stop){
        dropping = backup;
        break;
      }
      update_x_position(1);
    }
  }
  if (!left_over && right_over){
    while (right_over){
      if (left_stop){
        dropping = backup;
        break;
      }
      update_x_position(-1);
    }
  }
  if (left_over && right_over) dropping = backup;
  
  check_touch();
  backup = dropping;
}

void fixed(){
  Block tb;
  
  for (int i = 0; i < 4; i ++){
    tb = dropping.get(i);
    if (tb.y_position / cell_size >= 0 && tb.x_position / cell_size >= 0)
      Base.get(tb.y_position / cell_size).set(tb.x_position / cell_size, tb);
  }
  erase = new ArrayList<Integer>();
  boolean all_block = true;
  for (int i = 0; i < 20; i ++){
    all_block = true;
    for (int j = 0; j < 10; j ++)
      if (Base.get(i).get(j).x_position < 0) all_block = false;
    if (all_block) erase.add(i);
  }
  
  score += erase.size();
  speed = 800;
  for (int i = 0; i < score / 3; i ++)
    speed = int(float(speed) * 0.75);
  if (speed <= 70) speed = 70;
  
  for (int i = 0; i < erase.size(); i ++){
    for (int ii = erase.get(i); ii >= 1; ii --){
      for (int jj = 0; jj < 10; jj ++){
        Base.get(ii).set(jj, Base.get(ii - 1).get(jj));
        Base.get(ii).get(jj).y_position += cell_size;
      }
    }
  }
  
  //if (erase.size() > 0) delay(500);
}

void initialize_base(){
  for (int i = 0; i < 20; i ++){
    Base.add(new ArrayList <Block>());
    for (int j = 0; j < 10; j ++){
      Base.get(i).add(new Block());
    }
  }
  for (int i = 0; i < 20; i ++){
    for (int j = 0; j < 10; j ++){
      Base.get(i).set(j, new Block(-100, -100));
    }
  }
}

void check_touch(){
  Block tb, tb2;
  
  left_over = false;
  right_over = false;
  left_stop = false;
  right_stop = false;
  down_over = false;
  down_stop = false;
  up_stop = false;
  for (int i = 0; i < 4; i ++){
    tb = dropping.get(i);
    if (tb.x_position == 0) left_stop = true;
    if (tb.x_position < 0) left_over = true;
    if (tb.x_position + cell_size == window_width) right_stop = true;
    if (tb.x_position + cell_size > window_width) right_over = true;
    if (tb.y_position + cell_size == window_height) down_stop = true;
    if (tb.y_position + cell_size > window_height) down_over = true;
    if (tb.y_position <= 0) up_stop = true;
    
    for (int j = 0; j < 20; j ++)
      for (int k = 0; k < 10; k ++){
        tb2 = Base.get(j).get(k);
        if (tb.y_position == tb2.y_position){
          if (tb.x_position + cell_size == tb2.x_position) right_stop = true;
          if (tb.x_position == tb2.x_position + cell_size) left_stop = true;
          if (tb.x_position == tb2.x_position) right_over = true;
          if (tb.x_position == tb2.x_position) left_over = true;
        }  
        if (tb.x_position == tb2.x_position){
          if (tb.y_position + cell_size == tb2.y_position) down_stop = true;
          if (tb.y_position == tb2.y_position && last_move == 2) down_over = true;
        }
      }
  }
  
  if (up_stop && down_stop)
    gameover = true;
}

void check_shadow_stop(){
  Block tb, tb2;
  
  for (int i = 0; i < 4; i ++){
    tb = shadow.get(i);
    
    for (int j = 0; j < 20; j ++)
      for (int k = 0; k < 10; k ++){
        tb2 = Base.get(j).get(k);
        if (tb.y_position + cell_size == window_height) shadow_down_stop = true;
        if (tb.x_position == tb2.x_position)
          if (tb.y_position + cell_size == tb2.y_position) shadow_down_stop = true;
      }
  }
}

void generate_shadow(){
  shadow = new ArrayList<Block>();
  for (int i = 0; i < 4; i ++){
    shadow.add(i, new Block(dropping.get(i).x_position, dropping.get(i).y_position));
    shadow.get(i).block_color = 7;
  }
  for (int i = 0; i < 4; i ++){
    shadow_down_stop = false;
    check_shadow_stop();
    while (!shadow_down_stop){
      for (int j = 0; j < 4; j ++){
        shadow.get(j).y_position += cell_size;
      }
      check_shadow_stop();
    }
  }
}

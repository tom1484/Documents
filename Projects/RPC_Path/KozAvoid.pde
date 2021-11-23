import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class KozAvoid {

  PVector center;
  
  KozAvoid(int pattern, PVector center, PVector end, PVector start, boolean targetScanned) {
    if (!targetScanned){
      this.center = center;
      getPossibleKOZ(pattern, end);
      //avoidPossibleKOZ(start, end);
    }
  }

  private class P_int {
    int x, y, z;

    P_int(int x, int y, int z) {
      this.x = x;
      this.y = y;
      this.z = z;
    }
  }
  
  private class Block {
    PVector min_point, max_point;

    Block(PVector min_p, PVector max_p) {
      this.min_point = min_p;
      this.max_point = max_p;
    }
  }

  double aware_dist = 0;
  PVector KIZ_min_PVector= new PVector(10.3, -10.2, 4.32);
  PVector KIZ_max_PVector= new PVector(11.55, -7.4, 5.57);
  PVector KOZ2_min_PVector= new PVector(10.71, -8.8, 4.32);
  PVector KOZ2_max_PVector= new PVector(11.55, -8.5, 5.57);
  double target_y = -10.585;//not true ,will know later

  int meter_to_cm(double meter) {
    return (int) Math.round(meter * 100);
  }
  double cm_to_meter(int cm) {
    return cm * 1.0 / 100;
  }

  ArrayList<Block> KOZList = new ArrayList<Block>();

  void addPossibleKOZ(PVector center, PVector min_PVector_add_value, PVector max_PVector_add_value) {
    ////A_prime:meter PVector,add_value: cm PVector
    PVector min = new PVector(
        (float) (center.x - aware_dist + min_PVector_add_value.x / 100),
        (float) (target_y - aware_dist + min_PVector_add_value.y / 100),
        (float) (center.z - aware_dist + min_PVector_add_value.z / 100));
    PVector max = new PVector(
        (float) (center.x + aware_dist + max_PVector_add_value.x / 100),
        (float) (target_y + aware_dist + max_PVector_add_value.y / 100),
        (float) (center.z + aware_dist + max_PVector_add_value.z / 100));
    Block tmp = new Block(min, max);
    KOZList.add(tmp);
  }
  void addPossibleKOZ(PVector min_PVector, PVector max_PVector) {
    PVector min = new PVector(
        (float) (center.x - aware_dist),
        (float) (target_y - aware_dist),
        (float) (center.z - aware_dist));
    PVector max = new PVector(
        (float) (center.x + aware_dist),
        (float) (target_y + aware_dist),
        (float) (center.z + aware_dist));
    Block tmp = new Block(min, max);
    KOZList.add(tmp);
  }

  void getPossibleKOZ(int pattern, PVector center) {
    //addPossibleKOZ(KOZ2_min_PVector,KOZ2_max_PVector);
    switch (pattern) {
      //case 1:
      //  addPossibleKOZ(center, new PVector(14 ,0 , 23.5), new PVector(21.5 ,178.5 , 46));
      //  addPossibleKOZ(center, new PVector(-46 ,0 , 16), new PVector(14 ,178.5 , 46));
      //  addPossibleKOZ(center, new PVector(-16 ,0 , 16), new PVector(-46 ,178.5 , -14));
      //  addPossibleKOZ(center, new PVector(-46 ,0 , -21.5), new PVector(-23.5 ,178.5 , -14));
      //  break;
      //case 2:
      //  addPossibleKOZ(center, new PVector(-46 ,0 , 16), new PVector(46 ,178.5 , 46));
      //  break;
      //case 3:
      //  addPossibleKOZ(center, new PVector(-21.5 ,0 , 23.5), new PVector(46 ,178.5 , 46));
      //  addPossibleKOZ(center, new PVector(-14 ,0 , 16), new PVector(46 ,178.5 , 46));
      //  addPossibleKOZ(center, new PVector(16 ,0 , -14), new PVector(46 ,178.5 , 46));
      //  addPossibleKOZ(center, new PVector(23.5 ,0 , -21.5), new PVector(46 ,178.5 , 46));
      //  break;
      //case 4:
      //  addPossibleKOZ(center, new PVector(-46 ,0 , -46), new PVector(-16 ,178.5 , 46));
      //case 5:
      //  addPossibleKOZ(center, new PVector(23.5 ,0 , 14), new PVector(46 ,178.5 , 21.5));
      //  addPossibleKOZ(center, new PVector(16 ,0 , -46), new PVector(46 ,178.5 , 14));
      //  addPossibleKOZ(center, new PVector(-14 ,0 , -46), new PVector(16 ,178.5 , -16));
      //  addPossibleKOZ(center, new PVector(-21.5 ,0 , -46), new PVector(-14 ,178.5 , -23.5));
      //  break;
      //case 6:
      //  addPossibleKOZ(center, new PVector(-46 ,0 , -46), new PVector(46 ,178.5 , -16));
      //  break;
      //case 7:
      //  addPossibleKOZ(center, new PVector(-46 ,0 , 14), new PVector(-23.5 ,178.5 , 21.5));
      //  addPossibleKOZ(center, new PVector(-46 ,0 , -46), new PVector(-16 ,178.5 , 14));
      //  addPossibleKOZ(center, new PVector(-46 ,0 , -46), new PVector(14 ,178.5 , -16));
      //  addPossibleKOZ(center, new PVector(14 ,0 , -46), new PVector(21.5 ,178.5 , -23.5));
      //  break;
      //case 8:
      //  addPossibleKOZ(center, new PVector(16 ,0 , -46), new PVector(46 ,178.5 , 46));
      //  break;
      case 1:
        addPossibleKOZ(center, new PVector(-12 - 30 - 4, 0, 12 - 30 - 4), new PVector(-12 - 7.5 + 4, 178.5, 12 + 0 + 4));
        addPossibleKOZ(center, new PVector(-12 - 0 - 4, 0, 12 + 7.5 - 4), new PVector(-12 + 30 + 4, 178.5, 12 + 30 + 4));
        addPossibleKOZ(center, new PVector(-12 - 30 - 4, 0, 12 + 0 - 4), new PVector(-12 + 0 + 4, 178.5, 12 + 30 + 4));
        break;
      case 2:
        addPossibleKOZ(center, new PVector(12 - 30 - 4, 0, 12 + 0 - 4), new PVector(12 + 30 + 4, 178.5, 12 + 30 + 4));
        break;
      case 3:
        addPossibleKOZ(center, new PVector(12 + 7.5 - 4, 0, 12 - 30 - 4), new PVector(12 + 30 + 4, 178.5, 12 + 0 + 4));
        addPossibleKOZ(center, new PVector(12 - 30 - 4, 0, 12 + 7.5 - 4), new PVector(12 + 0 + 4, 178.5, 12 + 30 + 4));
        addPossibleKOZ(center, new PVector(12 + 0 - 4, 0, 12 + 0 - 4), new PVector(12 + 30 + 4, 178.5, 12 + 30 + 4));
        break;
      case 4:
        addPossibleKOZ(center, new PVector(12 + 0 - 4, 0, 12 - 30 - 4), new PVector(12 + 30 + 4, 178.5, 12 + 30 + 4));
        break;
      case 5:
        addPossibleKOZ(center, new PVector(12 - 30 - 4, 0, -12 - 30 - 4), new PVector(12 + 0 + 4, 178.5, -12 - 7.5 + 4));
        addPossibleKOZ(center, new PVector(12 + 7.5 - 4, 0, -12 + 0 - 4), new PVector(12 + 30 + 4, 178.5, -12 + 30 + 4));
        addPossibleKOZ(center, new PVector(12 + 0 - 4, 0, -12 - 30 - 4), new PVector(12 + 30 + 4, 178.5, -12 + 0 + 4));
        break;
      case 6:
        addPossibleKOZ(center, new PVector(12 - 30 - 4, 0, -12 - 30 - 4), new PVector(12 + 30 + 4, 178.5, -12 + 0 + 4));
        break;
      case 7:
        addPossibleKOZ(center, new PVector(-12 + 0 - 4, 0, -12 - 30 - 4), new PVector(-12 + 30 + 4, 178.5, -12 - 7.5 + 4));
        addPossibleKOZ(center, new PVector(-12 - 30 - 4, 0, -12 + 0 - 4), new PVector(-12 - 7.5 + 4, 178.5, -12 + 30 + 4));
        addPossibleKOZ(center, new PVector(-12 - 30 - 4, 0, -12 - 30 - 4), new PVector(-12 + 0 + 4, 178.5, -12 + 0 + 4));
        break;
      case 8:
        addPossibleKOZ(center, new PVector(-12 - 30 - 4, 0, 12 - 30 - 4), new PVector(-12 + 0 + 4, 178.5, 12 + 30 + 4));
        break;
    }
  }

  boolean checkInKOZ(P_int P) {
    for (Block now_block : KOZList) {
      if (now_block.min_point.x < P.x && P.x < now_block.max_point.x
       && now_block.min_point.y < P.y && P.y < now_block.max_point.y
       && now_block.min_point.z < P.z && P.z < now_block.max_point.z) {
        return true;
      }
    }
    return false;
  }

//  //----------------------------------------------------------------------------------------------
//  //目前的路徑避障生成法(BFS)

//  //BFS是否走訪過
//  Integer[][][] visited = new Integer[130][285][130];
//  //對於每個BFS走訪過的點，記錄從哪過來的
//  P_int[][][] source = new P_int[130][285][130];
//  //BFS queue
//  Queue<P_int> bfsQueue = new LinkedList<>();

//  //判斷是否能&需要走訪P點
//  boolean ok(P_int P) {
//    if (P.x > 125) return false;
//    if (P.x < 0) return false;
//    if (P.y > 280) return false;
//    if (P.y < 0) return false;
//    if (P.z > 125) return false;
//    if (P.z < 0) return false;
//    if (visited[P.x][P.y][P.z] != null) return false;
//    return !checkInKOZ(P);
//  }

//  //簡便的增加點到BFS queue
//  void pushToQueue(int d, int from_now, P_int from) {
//    if (d == 1) {
//      if (ok(new P_int(from.x + from_now, from.y, from.z) ) ) {
//        bfsQueue.add(new P_int(from.x + from_now, from.y, from.z) );
//        visited[from.x + from_now][from.y][from.z] = 1;
//        source[from.x + from_now][from.y][from.z] = from;
//      }
//    } else if (d == 2) {
//      if (ok(new P_int(from.x, from.y + from_now, from.z) ) ) {
//        bfsQueue.add(new P_int(from.x, from.y + from_now, from.z) );
//        visited[from.x][from.y + from_now][from.z] = 1;
//        source[from.x][from.y + from_now][from.z] = from;
//      }
//    } else if (d == 3) {
//      if (ok(new P_int(from.x, from.y, from.z + from_now) ) ) {
//        bfsQueue.add(new P_int(from.x, from.y, from.z + from_now) );
//        visited[from.x][from.y][from.z + from_now] = 1;
//        source[from.x][from.y][from.z + from_now] = from;
//      }
//    }
//  }

//  //BFS 主體
//  void avoidPossibleKOZ(PVector start, PVector dest) {
//    P_int from = new P_int(meter_to_cm(start.x - KIZ_min_PVector.x ),
//        meter_to_cm(start.y - KIZ_min_PVector.y ),
//        meter_to_cm(start.z - KIZ_min_PVector.z ) );
//    P_int to = new P_int(meter_to_cm(dest.x - KIZ_min_PVector.x ),
//        meter_to_cm(dest.y - KIZ_min_PVector.y ),
//        meter_to_cm(dest.z - KIZ_min_PVector.z ) );

//    bfsQueue.add(from);
//    visited[from.x][from.y][from.z] = 2;
//    while (!bfsQueue.isEmpty()) {
//      from = bfsQueue.peek();
//      bfsQueue.poll();
//      for (int d = 1; d <= 3; d++){
//        for (int i = 5; i <= 9; i++) {
//          pushToQueue(d, i, from);
//        }
//        for (int i = 5; i <= 9; i++) {
//          pushToQueue(d, -i, from);
//        }
//      }
//    }
//    Stack<P_int> ans = new Stack<>();
//    while (visited[to.x][to.y][to.z] != 2) {
//      ans.push(to);
//      to = source[to.x][to.y][to.z];
//    }
//    while (!ans.isEmpty()) {
//      double X = cm_to_meter(ans.peek().x) + KIZ_min_PVector.x;
//      double Y = cm_to_meter(ans.peek().y) + KIZ_min_PVector.y;
//      double Z = cm_to_meter(ans.peek().z) + KIZ_min_PVector.z;
//      if (service == null) {
//        System.out.printf("move to PVector %.2f %.2f %.2f\n", X, Y, Z);
//      } else {
//        Log.d("avoidKOZ", "move to PVector " + X + " " + Y + " " + Z);
//        service.moveToWrapper(new PVector(X, Y, Z), MainService.QUAT_A_PRIME);
//      }
//      ans.pop();
//    }
//  }
}

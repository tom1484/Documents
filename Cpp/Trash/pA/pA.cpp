#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

map<char, int> num_map = {
    {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'X', 10}, {'J', 11}, {'Q', 12}, {'K', 13}
};

map<char, int> suit_map = {
    {'S', 0}, {'H', 1}, {'D', 2}, {'C', 3}
};


class Poker {

    public:

        int num, suit;

        Poker() {}

        Poker(int n, int s): num(n), suit(s) {}

};

bool check_straight(vector<Poker>& pokers) {
    
    for (int i = 1; i < 5; i ++) {
        if (pokers[i - 1].num - pokers[i].num != 1)
            return false;
    }

    return true;
}

bool check_flush(vector<Poker>& pokers) {
    
    for (int i = 1; i < 5; i ++) {
        if (pokers[i - 1].suit != pokers[i].suit)
            return false;
    }

    return true;
}

bool check_four(vector<Poker>& pokers) {

    if ((pokers[0].num == pokers[1].num) && 
        (pokers[1].num == pokers[2].num) &&
        (pokers[2].num == pokers[3].num)) {

        return true;
    }

    if ((pokers[1].num == pokers[2].num) && 
        (pokers[2].num == pokers[3].num) &&
        (pokers[3].num == pokers[4].num)) {

        return true;
    }

    return false;
}

int count_three(vector<Poker>& pokers) {

    int res = 0;

    int q = 0;
    while (q < 5) {
        int n = pokers[q].num;
        int cnt = 1;
        
        while (q < 5 && pokers[q + 1].num == n) {
            q ++;
            cnt ++;
        }

        if (cnt == 3)
            res ++;

        q ++;
    }

    return res;
}

int count_pair(vector<Poker>& pokers) {

    int res = 0;

    int q = 0;
    while (q < 5) {
        int n = pokers[q].num;
        int cnt = 1;
        
        while (q < 5 && pokers[q + 1].num == n) {
            q ++;
            cnt ++;
        }

        if (cnt == 2)
            res ++;

        q ++;
    }

    return res;
}

int main() {

    fstream Input;
    Input.open("input_pokerB.txt");

    int N;
    Input >> N;

    while (true) {

        for (int i = 0; i < N; i ++) {

            char numc, suitc;
            int num, suit;

            vector<Poker> pokers(0);

            for (int j = 0; j < 5; j ++) {
                /* getchar(); */
                Input.get();
                numc = Input.get();
                suitc = Input.get();

                num = num_map.at(numc);
                suit = suit_map.at(suitc);

                pokers.push_back(Poker(num, suit));
            }

            bool straight = check_straight(pokers);
            bool flush = check_flush(pokers);
            bool four = check_four(pokers);
            int pairs = count_pair(pokers);
            int three = count_three(pokers);

            if (straight && flush) {
                cout << "Straight flush" << endl;
                continue;
            }
            if (straight) {
                cout << "Straight" << endl;
                continue;
            }
            if (flush) {
                cout << "Flush" << endl;
                continue;
            }
            if (four) {
                cout << "Four of a kind" << endl;
                continue;
            }
            if (three == 1 and pairs == 1) {
                cout << "Full house" << endl;
                continue;
            }
            if (three == 1 and pairs == 0) {
                cout << "Three of a kind" << endl;
                continue;
            }
            if (three == 0 and pairs == 1) {
                cout << "One pair" << endl;
                continue;
            }
            if (three == 0 and pairs == 2) {
                cout << "Two pair" << endl;
                continue;
            }
        }

        Input >> N;
        if (N == 0)
            break;
        cout << endl;
    }

    return 0;
}

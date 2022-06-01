#include <bits/stdc++.h>
using namespace std;

class Item {
    public:
        Item() {}
};

class IntItem : public Item {

public:

    int value;
    IntItem(int v): value(v) {}

    bool operator ==(IntItem item) {
        return value == item.value;
    }

};

class CharItem : public Item {

public:

    char value;
    CharItem(char v): value(v) {}

    bool operator ==(CharItem item) {
        return value == item.value;
    }

};

template <class T>
vector<Item> countItemFrequency(vector<Item> array, T tar) {

    vector<Item> result;

    for (int i = 0; i < array.size(); i ++) {
        Item* item = &array[i];
        IntItem *intItem = nullptr;
        CharItem *charItem = nullptr;

        if (is_same<T, int>::value) {
            intItem = dynamic_cast<IntItem*>(item);
            cout << intItem->value;
        }
    }

}

int main() {


    vector<Item> vec;

    vec.push_back(IntItem(1));
    vec.push_back(CharItem('A'));

    countItemFrequency(vec, 1);

    return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class FlowerVO_YH {
private:
    string name;
    string color;
    int quantity;

public:
    FlowerVO_YH(string name, string color, int quantity) {
        this->name = name;
        this->color = color;
        this->quantity = quantity;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getColor() {
        return color;
    }

    void setColor(string color) {
        this->color = color;
    }

    int getQuantity() {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

class FlowerBO_YH {
private:
    vector<FlowerVO_YH> flowerList;

public:
    FlowerBO_YH() {
    }

    void addFlower(FlowerVO_YH flower) {
        flowerList.push_back(flower);
    }

    void deleteFlower(FlowerVO_YH flower) {
        for (vector<FlowerVO_YH>::iterator iter = flowerList.begin(); iter != flowerList.end(); iter++) {
            if (iter->getName() == flower.getName()) {
                cout << "delete " << iter->getName() << "'s information" << endl;
                flowerList.erase(iter);
                break;
            }
        }
    }

    vector<FlowerVO_YH> getAllFlowers() {
        return flowerList;
    }

    FlowerVO_YH getFlower(string name) {
        for (vector<FlowerVO_YH>::iterator iter = flowerList.begin(); iter != flowerList.end(); iter++) {
            if (iter->getName() == name) {
                return *iter;
            }
        }
        return FlowerVO_YH("", "", -1);
    }

    void updateFlower(FlowerVO_YH flower) {
        for (vector<FlowerVO_YH>::iterator iter = flowerList.begin(); iter != flowerList.end(); iter++) {
            if (iter->getName() == flower.getName()) {
                cout << flower.getName() << "'s number change from " << iter->getQuantity() << " to " << flower.getQuantity() << endl;
                iter->setQuantity(flower.getQuantity());
                break;
            }
        }
    }
};

void testTransferObject();
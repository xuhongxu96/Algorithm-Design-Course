#include <iostream>
#include <string>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Ship {
    int stopTime;
    int id;
    Ship(int i) : id(i) {
        stopTime = 4 + rand() % 41;
    }
};

class Dock {
    Ship *ship;
public:
    Dock() : ship(nullptr) {}
    int simulate(int months = 60) {
        ship = nullptr;
        stack<Ship*> waitingShips;
        int hours = 0;
        int waitingHours = 0;
        int n = 0;
        while (hours < months * 30 * 24) {
            int interval = 15 + rand() % 31;
            hours += interval;
            while (ship != NULL && interval >= ship->stopTime) {
                waitingHours += waitingShips.size() * ship->stopTime;
                interval -= ship->stopTime;
                delete ship;
                ship = nullptr;
                if (waitingShips.size()) {
                    ship = waitingShips.top();
                    waitingShips.pop();
                }
            }
            if (ship) {
                ship->stopTime -= interval;
            }
            Ship *tempShip = new Ship(++n);
            if (ship) {
                waitingShips.push(tempShip);
            } else {
                ship = tempShip;
            }
        }
        while (ship != NULL) {
            waitingHours += waitingShips.size() * ship->stopTime;
            delete ship;
            ship = nullptr;
            if (waitingShips.size()) {
                ship = waitingShips.top();
                waitingShips.pop();
            }
        }
        return waitingHours;
    }

};


int main() {
    Dock dock;
    srand(time(0));
    int sum = 0;
    for (int i = 0; i < 1000; ++i)
        sum += dock.simulate();
    double average = sum / 1000.0;
    cout << "1000次模拟后，等待成本为";
    cout << average / 10.0 << "万元" << endl;
    if (average >= 13500) 
        cout << "超过1350万元，扩建！" << endl;
    else
        cout << "未超过1350万元，不扩建！" << endl;
    return 0;
}

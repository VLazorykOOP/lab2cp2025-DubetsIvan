#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void car(int id) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    int position = 0;
    int direction = 0;
    int speed = 100;
    while (true) {
        cout << "Car #" << id << " position: " << position << "\nCar #" << id << " speed: " << speed << endl;
        if (position <= 0) {
            direction = 0;
        }
        else if (position >= 400) {
            direction = 1;
        }
        switch (direction)
        {
        case 0:
            position += speed;
            break;
        case 1:
            position -= speed;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void motorcycle(int id) {
    this_thread::sleep_for(chrono::milliseconds(500));
    int direction = 0;
    int position = 0;
    int speed = 50;
    while (true) {
        cout << "Motorcycle #" << id << " position: " << position << "\nMotorcycle #" << id << " speed: " << speed << endl;
        if (position <= 0) {
            direction = 0;
        }
        else if (position >= 400) {
            direction = 1;
        }
        switch (direction)
        {
        case 0:
            position += speed;
            break;
        case 1:
            position -= speed;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread cars[3];
    thread motorcycles[2];

    for (int i = 0; i < 3; i++) {
        cars[i] = thread(car, i + 1);
    }

    for (int i = 0; i < 2; i++) {
        motorcycles[i] = thread(motorcycle, i + 1);
    }

    for (int i = 0; i < 3; i++) {
        cars[i].join();
    }
    for (int i = 0; i < 2; i++) {
        motorcycles[i].join();
    }

    return 0;
}

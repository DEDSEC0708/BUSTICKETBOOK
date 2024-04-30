#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class for all guns
class Gun {
protected:
    string name;
    int damage;

public:
    Gun(string _name, int _damage) : name(_name), damage(_damage) {}

    virtual void shoot() = 0; // Virtual function for shooting
};

// Derived class for a Sniper Rifle
class SniperRifle : public Gun {
public:
    SniperRifle() : Gun("Sniper Rifle", 100) {}

    void shoot() override {
        cout << "Shooting with Sniper Rifle. Damage: " << damage << endl;
    }
};

// Derived class for a Submachine Gun
class SubmachineGun : public Gun {
public:
    SubmachineGun() : Gun("Submachine Gun", 30) {}

    void shoot() override {
        cout << "Shooting with Submachine Gun. Damage: " << damage << endl;
    }
};

// Main game class
class Game {
private:
    vector<Gun*> guns; // Vector to store different guns
    int currentGunIndex;

public:
    Game() {
        // Initialize guns
        guns.push_back(new SniperRifle());
        guns.push_back(new SubmachineGun());
        currentGunIndex = 0; // Start with the first gun
    }

    ~Game() {
        // Clean up memory
        for (Gun* gun : guns) {
            delete gun;
        }
    }

    void switchGun() {
        currentGunIndex = (currentGunIndex + 1) % guns.size(); // Switch to the next gun
        cout << "Switched to " << guns[currentGunIndex]->name << endl;
    }

    void shoot() {
        guns[currentGunIndex]->shoot(); // Shoot with the current gun
    }
};

int main() {
    Game game;

    // Game loop
    while (true) {
        cout << "Press 's' to shoot, 'g' to switch gun, or 'q' to quit: ";
        char choice;
        cin >> choice;

        switch (choice) {
            case 's':
                game.shoot();
                break;
            case 'g':
                game.switchGun();
                break;
            case 'q':
                cout << "Quitting game.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

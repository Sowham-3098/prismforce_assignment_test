#include <iostream>
#include <vector>
using namespace std;

const int totalenemies = 11; // total number of enemies in the chakravyuha

int initialpower; // initial power of Abhimanyu

// Function declarations
bool handleEnemyBehind(int& currentpower, int& enemybehind);
bool skipEnemy(vector<int>& enemypower, int currentenemy, int currentpower, int skipsleft, int rechargesleft, int enemybehind);
bool fightEnemy(vector<int>& enemypower, int currentenemy, int& currentpower, int skipsleft, int rechargesleft, int& enemybehind);
bool canabhimanyupass(vector<int>& enemypower, int currentenemy, int currentpower, int skipsleft, int rechargesleft, int enemybehind);

// Function to handle enemy attacks from behind
bool handleEnemyBehind(int& currentpower, int& enemybehind) {
    if (currentpower >= enemybehind) {
        currentpower -= enemybehind;
        enemybehind = 0;
        return true;
    }
    return false;
}

// Function to handle skipping an enemy
bool skipEnemy(vector<int>& enemypower, int currentenemy, int currentpower, int skipsleft, int rechargesleft, int enemybehind) {
    if (skipsleft > 0) {
        return canabhimanyupass(enemypower, currentenemy + 1, currentpower, skipsleft - 1, rechargesleft, enemybehind);
    }
    return false;
}

// Function to handle fighting an enemy
bool fightEnemy(vector<int>& enemypower, int currentenemy, int& currentpower, int skipsleft, int rechargesleft, int& enemybehind) {
    if (currentpower >= enemypower[currentenemy]) {
        if (currentenemy == 2 || currentenemy == 6) {
            enemybehind = enemypower[currentenemy] / 2; // Set up the enemy behind attack.
        }
        return canabhimanyupass(enemypower, currentenemy + 1, currentpower - enemypower[currentenemy], skipsleft, rechargesleft, enemybehind);
    }
    return false;
}

// Function to check if Abhimanyu can pass through the chakravyuha
bool canabhimanyupass(vector<int>& enemypower, int currentenemy, int currentpower, int skipsleft, int rechargesleft, int enemybehind) {
    // Base case: all enemies are defeated.
    if (currentenemy == totalenemies)
        return true;

    bool canpass = false;

    // Option 1: Recharge if available and beneficial.
    if (rechargesleft > 0 && currentpower < initialpower) {
        canpass |= canabhimanyupass(enemypower, currentenemy, initialpower, skipsleft, rechargesleft - 1, enemybehind);
    }

    // Handle enemy attacking from behind if applicable.
    if (!handleEnemyBehind(currentpower, enemybehind)) {
        return false;
    }

    // Option 2: Skip the current enemy if skips are available.
    canpass |= skipEnemy(enemypower, currentenemy, currentpower, skipsleft, rechargesleft, enemybehind);

    // Option 3: Fight the current enemy.
    canpass |= fightEnemy(enemypower, currentenemy, currentpower, skipsleft, rechargesleft, enemybehind);

    return canpass;
}

int main() {
    vector<int> enemypower(totalenemies); // Powers of each enemy in the chakravyuha.

    for (int i = 0; i < totalenemies; i++)
        cin >> enemypower[i];

    int maxskips, maxrecharges; // Maximum skips and recharges available.
    cin >> initialpower >> maxskips >> maxrecharges;

    // Ensure skips and recharges do not exceed the number of enemies.
    maxskips = min(maxskips, totalenemies);
    maxrecharges = min(maxrecharges, totalenemies);

    // Check if Abhimanyu can successfully cross the chakravyuha.
    if (canabhimanyupass(enemypower, 0, initialpower, maxskips, maxrecharges, 0))
        cout << "Abhimanyu successfully crossed the chakravyuha!" << endl;
    else
        cout << "Abhimanyu could not cross the chakravyuha." << endl;

    return 0;
}
/*
Test Case 1 (Success):
Description: Abhimanyu has enough power and a few skips and recharges.
Input:
enemyPower = [3, 2, 1, 4, 3, 5, 2, 1, 3, 2, 1]
power = 8
skips = 2
recharges = 2
Explanation: Abhimanyu can use his power and recharges effectively to defeat or skip enemies, managing to cross the Chakravyuha.
Output:
Abhimanyu successfully crossed the chakravyuha!



Test Case 2 (Failure):
Description: The initial power is insufficient, and recharges are limited.
Input:
enemyPower = [5, 7, 8, 4, 3, 6, 5, 9, 10, 4, 2]
power = 6
skips = 1
recharges = 1
Explanation: With limited initial power and recharges, Abhimanyu will struggle to get past several enemies, and even though he has one skip, he may not be able to cross all enemies.
Output:
Abhimanyu could not cross the chakravyuha.
*/

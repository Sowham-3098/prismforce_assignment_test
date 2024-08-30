# prismforce_assignment_test

## Problem Statement: 

Abhimanyu is inside the Chakravyuha, which consists of 11 concentric circles, each guarded by a different enemy. Abhimanyu needs to traverse all 11 circles to reach the Pandavas' army. He starts from the innermost circle and must overcome each enemy in the circles to move forward.

### Given:
- There are 11 circles in the Chakravyuha, each guarded by an enemy with a specific power.
- Abhimanyu starts with an initial power `p`.
- Abhimanyu can skip fighting enemies `a` times.
- Abhimanyu can recharge his power `b` times.
- Battling an enemy in a circle will reduce Abhimanyu's power by the enemy's power.
- If Abhimanyu's power is less than the enemy's power when entering a circle, he loses the battle.
- Enemies in circles 3 and 7 have the ability to regenerate themselves with half of their initial power and can attack Abhimanyu from behind if he continues fighting in the next circles.

### Objective:
Write an algorithm to determine if Abhimanyu can successfully cross all 11 circles and reach the Pandavas' army.

### Algorithm:
1. **Input:**
   - An array `enemyPower` of size 11 where `enemyPower[i]` represents the power of the enemy in the `(i+1)`-th circle.
   - Initial power `p`.
   - Number of skips `a`.
   - Number of recharges `b`.

2. **Output:**
   - "Abhimanyu successfully crossed the Chakravyuha!" if Abhimanyu can cross all circles.
   - "Abhimanyu could not cross the Chakravyuha." if he cannot.

3. **Approach:**
   - Use a recursive approach with backtracking to explore all possible strategies (battling, skipping, recharging).
   - Handle the regeneration of enemies in circles 3 and 7.
   - Ensure to track the power and the number of skips and recharges left.

### Test Cases:

#### Test Case 1 (Success):
- **Description:** Abhimanyu has enough initial power and a few skips and recharges.
- **Input:**
  ```plaintext
  enemyPower = [3, 2, 1, 4, 3, 5, 2, 1, 3, 2, 1]
  initialPower = 8
  maxskips = 2
  maxrecharges = 2
- **Output**
  ```plaintext
  Abhimanyu successfully crossed the Chakravyuha!
#### Test Case 2 (Failure):
- **Description:** The initial power is insufficient, and recharges are limited.
- **Input:**
  ```plaintext
  enemyPower = [5, 7, 8, 4, 3, 6, 5, 9, 10, 4, 2]
  initialPower = 6
  maxskips = 1
  maxrecharges = 1
- **Output**
  ```plaintext
   Abhimanyu could not cross the Chakravyuha.

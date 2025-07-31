#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Player {
public:
    string name;
    string avatar;
    int score;
    bool hintUsed;

    Player() : score(0), hintUsed(false) {}

    void createProfile(int playerNum = 1) {
        cout << "Player " << playerNum << ", Enter your name: ";
        getline(cin, name);
        cout << "Choose your Avatar Symbol: ";
        getline(cin, avatar);
        if (avatar.empty()) avatar = "*";
        cout << "Welcome " << avatar << " " << name << "!\n";
    }

    void reset() {
        score = 0;
        hintUsed = false;
    }

    void showProfile() const {
        cout << "Player: " << avatar << " " << name << " | Score: " << score << "\n";
    }
};

class Game {
private:
    int number;
    int level;
    int maxRange;
    int maxAttempts;

public:
    Game() : level(1) {
        srand(time(0));
    }

    void setupLevel() {
        maxRange = level * 50;
        maxAttempts = max(3, 10 - level);
        number = rand() % maxRange + 1;
        cout << "\n--- Level " << level << " ---\n";
        cout << "Guess the number between 1 and " << maxRange << " in " << maxAttempts << " attempts.\n";
    }

    bool playLevel(Player& player) {
        int attemptsLeft = maxAttempts;
        while (attemptsLeft > 0) {
            cout << "[" << player.avatar << " " << player.name << "] Enter your guess: ";
            int guess;
            while (!(cin >> guess)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a number: ";
            }

            if (guess == number) {
                int scoreGained = (attemptsLeft + 1) * 10;
                cout << "✅ Correct! You earned " << scoreGained << " points!\n";
                player.score += scoreGained;
                return true;
            } else {
                if (guess < number)
                    cout << "🔻 Too low!\n";
                else
                    cout << "🔺 Too high!\n";
                attemptsLeft--;

                // Hint logic (one time use)
                if (!player.hintUsed && attemptsLeft == maxAttempts - 2) {
                    cout << "Want a hint? (y/n): ";
                    char c;
                    cin >> c;
                    cin.ignore();
                    if (c == 'y' || c == 'Y') {
                        cout << "Hint: The number is " << (number % 2 == 0 ? "EVEN\n" : "ODD\n");
                        player.hintUsed = true;
                    }
                }
            }
        }
        cout << "❌ No attempts left! The number was: " << number << "\n";
        return false;
    }

    bool nextLevel() {
        return ++level <= 5;
    }

    void showAchievements(const Player& player) {
        cout << "\n🎉 Game Over for " << player.avatar << " " << player.name << " 🎉\n";
        cout << "Final Score: " << player.score << "\n";
        cout << "Achievements:\n";
        if (player.score >= 100) cout << "⭐ Score Star (Score ≥ 100)\n";
        if (level >= 5) cout << "🏅 Level Master (Reached Level 5)\n";
        if (!player.hintUsed) cout << "🕵️ No Clues Champ (No hint used)\n";
        cout << "-----------------------------\n";
    }

    void reset() {
        level = 1;
    }
};

void playSinglePlayer() {
    Player p;
    Game g;
    cout << "\n🎮 SINGLE PLAYER MODE\n";
    p.createProfile();

    while (true) {
        g.setupLevel();
        if (!g.playLevel(p)) break;
        if (!g.nextLevel()) break;
    }

    g.showAchievements(p);
}

void playMultiPlayer() {
    Game g1, g2;
    Player p1, p2;
    cout << "\n🎮 MULTIPLAYER MODE (2 players)\n";
    p1.createProfile(1);
    p2.createProfile(2);

    while (true) {
        cout << "\n🎲 " << p1.avatar << " " << p1.name << "'s Turn\n";
        g1.setupLevel();
        if (!g1.playLevel(p1)) break;
        if (!g1.nextLevel()) break;

        cout << "\n🎲 " << p2.avatar << " " << p2.name << "'s Turn\n";
        g2.setupLevel();
        if (!g2.playLevel(p2)) break;
        if (!g2.nextLevel()) break;
    }

    cout << "\n⚔ Final Scores ⚔\n";
    cout << p1.name << ": " << p1.score << "\n";
    cout << p2.name << ": " << p2.score << "\n";

    if (p1.score > p2.score) {
        cout << "🏆 Winner: " << p1.name << "!\n";
    } else if (p2.score > p1.score) {
        cout << "🏆 Winner: " << p2.name << "!\n";
    } else {
        cout << "🤝 It's a tie!\n";
    }

    g1.showAchievements(p1);
    g2.showAchievements(p2);
}

int main() {
    while (true) {
        cout << "===== Number Guessing Adventure Game =====\n";
        cout << "1. Single Player\n";
        cout << "2. Multiplayer\n";
        cout << "3. Exit\n";
        cout << "Choose mode: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                playSinglePlayer();
                break;
            case 2:
                playMultiPlayer();
                break;
            case 3:
                cout << "Thank you for playing!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }

        cout << "\nPlay again? (y/n): ";
        char again;
        cin >> again;
        cin.ignore();
        if (again != 'y' && again != 'Y') break;
    }

    cout << "👋 Goodbye!\n";
    return 0;
}
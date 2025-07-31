🎯 Number Guessing Adventure Game:

A fun terminal-based number guessing game built in C++ using Object-Oriented Programming (OOP) principles.

📦 Includes:

	• ✅ Single-player mode

	• 🧑🤝🧑 Multiplayer mode (2 players)

	• 🧠 One-time hint system

	• ⭐ Dynamic scoring and achievements

	• 🔁 Replay support

🕹️ How to Play

Choose a mode:

	• Single Player: Play solo, level up and earn points.

	• Multiplayer: Two players take turns to compete—you Vs a friend!

🎮 The goal is to guess a random number within a limited number of attempts. Each correct guess moves you to the next level:

	• Range increases (level × 50)

	• Attempts decrease (max(3, 10 - level))

💡 Each player gets one hint per game (“Even or Odd”).

🎯 Score = (remaining attempts + 1) × 10
🎓 Game ends after Level 5 or on wrong guesses

🏅 Unlock achievements:

	• ⭐ Score ≥ 100 → Score Star

	• 🥇 Reach Level 5 → Level Master

	• 🙅♂️ Don’t use hint → No Clues Champ

✏️ Controls
	• Input numbers to guess

	• Enter y/n for yes/no prompts

	• For multiplayer, each player's turn happens separately

🧱 Built With
	• 🔤 C++

	• 🧠 OOP Concepts (Classes, Encapsulation)

	• 🎲 rand() + srand(time(0)) for randomness

	• 📟 Console UI

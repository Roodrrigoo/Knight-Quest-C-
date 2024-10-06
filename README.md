# C++ Game Project: “Knight Quest”

This project consists of the development of a game in C++ where the player embarks on an epic journey with the goal of defeating the evil king and his henchmen, to free the kingdom from the corruption, misery, and oppression in which it has been mired for years.

## Game History

The once prosperous and peaceful kingdom has fallen under the shadow of a tyrant king who, along with his dark army of sorcerers and evil warriors, has plunged its people into fear and despair. The player assumes the role of a brave hero, who must make his way through multiple scenarios and confront various enemies to restore peace to the land.

Along his journey, the player will encounter powerful sorcerers, who will test his skills in combat and strategy. These wizards, with their dark magical powers, represent the first great challenges that the hero will have to overcome. But his mission does not stop there: the final destiny brings him face to face with the Evil King, in an epic final battle where the fate of the kingdom will be decided.

In addition to his confrontations with enemies, the player will also have the opportunity to interact with friendly characters, such as warriors who fight for justice and inhabitants of the kingdom who offer their help. These interactions will be key, since some characters can provide support and objects that will help you advance in your mission.


## Game Execution Screenshots

### Execution 1
![Execution 1](https://github.com/Roodrrigoo/Knight-Quest-C-/blob/main/imgs/ejecucion%201%20kingdom%20.png?raw=true)

### Execution 2
![Execution 2](https://github.com/Roodrrigoo/Knight-Quest-C-/blob/main/imgs/ejecucion%202%20kingdom%20.png?raw=true)

### Execution 3
![Execution 3](https://github.com/Roodrrigoo/Knight-Quest-C-/blob/main/imgs/ejecucion%203%20kingdom.png?raw=true)

### Execution 4
![Execution 4](https://github.com/Roodrrigoo/Knight-Quest-C-/blob/main/imgs/ejecucion%204%20kingdom.png?raw=true)



## Technical Implementation

The game was developed with a clear focus on Object Oriented Programming (OOP), taking advantage of several fundamental concepts of this paradigm, such as:

### Inheritance

The player and the different characters of the game, both allies and enemies, were implemented through classes that inherit from a base class called `Character`. This allows the reuse of code and facilitates the creation of new classes with specific behaviors for each type of character.

### Polymorphism

The use of polymorphism allows the game characters to interact with each other dynamically, depending on their roles in the story. For example, the `interactWithFriend` method is designed so that the player can have conversations or receive help from friendly characters, while the combat methods behave differently depending on the enemy they face.

### Abstract Classes

Abstract classes define the general structure of characters, ensuring that they all share certain common characteristics, such as life points and special abilities, but leaving the implementation specific to each character type. The base class `Character` is abstract, and classes such as `Warrior`, `Sorcerer`, and `FriendlyCharacter` inherit from it.

## Project Objective

The main objective of this game was to apply in a practical way the key concepts of object-oriented programming in C++, taking advantage of advanced language features such as inheritance, polymorphism, operator overloading, and exception handling. In addition, the goal was to create an immersive and dynamic experience for the player, combining strategic combat with the narrative of an epic story.


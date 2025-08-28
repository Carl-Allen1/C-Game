#include "../headers/main.hpp"
#include "../headers/item.hpp"
#include "../headers/roles/fighter.hpp"
#include "../headers/weapons/stweapon.hpp"
#include "../headers/weapons/aoeweapon.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <random>

Main::Main(double playerHealth) : player(10, playerHealth) {
    started = false;
    generateEnemies(10, 15, 3, 7, 3);
    runGame();
}

void Main::generateEnemies(int minHealth, int maxHealth, int minDamage, int maxDamage, int amt) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> damageDist(minDamage, maxDamage);
    std::uniform_int_distribution<> healthDist(minHealth, maxHealth);
    
    for(int i = 0; i < amt; i++) {
        int randDamage = damageDist(gen);
        int randHealth = healthDist(gen);
        enemies.emplace_back(randDamage, randHealth);
    }
}

void Main::runGame() {
    if(!started) {
        pickRole();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        pickWeapon();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        started = true;
    }
    
    while(!enemies.empty() && player.getHealth() > 0) {
        attack();
        if(enemies.empty()) break;
        getAttacked();
    }

    if(player.getHealth() <= 0) {
        std::cout << "You died!" << std::endl;
    } else {
        std::cout << "You win!" << std::endl;
    }

    gameOver();
}

void Main::pickRole() {
    std::cout << "Pick a role to have!\n"
        << "1. Fighter" << std::endl;
    
    int chosenRole = 0;

    while(true) {
        std::cout << "Enter the number of your choice: " << std::endl;

        if(std::cin >> chosenRole && chosenRole == 1) break;

        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Please enter a number 1-1!" << std::endl;
    }

    switch(chosenRole) {
        case 1: player.setRole(std::make_unique<Fighter>(3, 3)); break;
    }
}

void Main::pickWeapon() {
    std::cout << "Pick a weapon to start with!\n"
        << "1. Sword\n"
        << "2. Warhammer" << std::endl;
    
    int chosenWeapon = 0;

    while(true) {
        std::cout << "Enter the number of your choice: " << std::endl;

        if(std::cin >> chosenWeapon && chosenWeapon >= 1 && chosenWeapon <= 2) break;

        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Please enter a number 1-2!" << std::endl;
    }

    switch(chosenWeapon) {
        case 1: player.setWeapon(std::make_unique<STWeapon>(10, "Sword")); break;
        case 2: player.setWeapon(std::make_unique<AOEWeapon>(3, 7, "Warhammer")); break;
    }
}

void Main::attack() {
    std::cout << "It is your turn to attack!" << std::endl;
    std::cout << "You have " << player.getHealth() << " health!" << std::endl;
    std::cout << "Choose a weapon to attack with!" << std::endl;
    
    const auto& printWeapons = player.getInventory().getWeapons();

    for(int i = 0; i < static_cast<int>(printWeapons.size()); i++) {
        std::cout << i + 1 << ": " << printWeapons[i]->toString() << std::endl;
    }

    int chosenIndex;
    if(!(std::cin >> chosenIndex)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Please enter a valid input!" << std::endl;
        return;
    }
    chosenIndex--;

    const auto& weapons = player.getInventory().getWeapons();

    if(chosenIndex < 0 || chosenIndex >= static_cast<int>(weapons.size())) {
        std::cout << "Not a valid item!" << std::endl;
        return;
    }

    std::cout << "Attacking enemy with " << weapons[chosenIndex]->toString() << std::endl;
    weapons[chosenIndex]->attack(enemies);

    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
            [](const Enemy& enemy){
                return enemy.getDead();
            }
        ),
        enemies.end()
    );
}

void Main::getAttacked() {
    for(int i = 0; i < static_cast<int>(enemies.size()); i++) {
        std::cout << "It is enemy " << i + 1 << "'s turn to attack!" << std::endl;

        double prevHealth = player.getHealth();
        
        if(player.roleHasArmor()) {
            player.takeDamage(enemies[i].getDamage(), player.getRoleArmor());
        } else {
            player.takeDamage(enemies[i].getDamage(), 0);
        }
        
        double damageTaken = prevHealth - player.getHealth();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "You were hit for " << damageTaken << " damage!" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        if(player.getHealth() <= 0) {
            std::cout << "You died!" << std::endl;
            gameOver();
            break;
        }
    }
}

void Main::gameOver() {
    std::string choice;

    std::cout << "Would you like to play again? Y/N" << std::endl;
    std::cin >> choice;

    if(choice == "Y" || choice == "y") {
        Main newGame(50);
    } else {
        std::cin.clear();
        std::cout << "Bye!" << std::endl;
    }
}

int main() {
    Main game(50);
    return 0;
}
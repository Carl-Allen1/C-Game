#include "../headers/main.hpp"
#include "../headers/item.hpp"
#include "../headers/roles/fighter.hpp"
#include "../headers/weapons/stweapon.hpp"
#include "../headers/weapons/aoeweapon.hpp"
#include <iostream>
#include <cmath>

Main::Main(double playerHealth) : player(10, playerHealth) {
    started = false;
    generateEnemies(10, 15, 3, 7, 3);
    runGame();
}

void Main::generateEnemies(int minHealth, int maxHealth, int minDamage, int maxDamage, int amt) {
    for(int i = 0; i < amt; i++) {
        int randDamage = std::round(rand() % (maxDamage - minDamage + 1) + minDamage);
        int randHealth = std::round(rand() % (maxHealth - minHealth + 1) + minHealth);
        enemies.push_back(Enemy(randDamage, randHealth));
    }
}

void Main::runGame() {
    if(!started) {
        pickRole();
        pickWeapon();
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
        case 1: player.setWeapon(std::make_unique<STWeapon>(10)); break;
        case 2: player.setWeapon(std::make_unique<AOEWeapon>(3, 7)); break;
    }
}

void Main::attack() {
    std::cout << "It is your turn to attack!" << std::endl;
    std::cout << "You have " << player.getHealth() << " health!" << std::endl;
    std::cout << "Choose a weapon to attack with!" << std::endl;
    player.getInventory().toString();

    int chosenIndex;
    if(!(std::cin >> chosenIndex)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Please enter a valid input!" << std::endl;
        return;
    }
    chosenIndex--;

    const auto& items = player.getInventory().getItems();
    if(chosenIndex < 0 || chosenIndex >= items.size()) {
        std::cout << "Not a valid item!" << std::endl;
        return;
    }

    if(items[chosenIndex]->type() != Item::Type::Weapon) {
        std::cout << "Please choose a weapon!" << std::endl;
        return;
    }

    auto chosenWeapon = std::dynamic_pointer_cast<Weapon>(items[chosenIndex]);
    std::cout << "Attacking enemy with " << chosenWeapon->toString() << std::endl;

    chosenWeapon->attack(enemies);
}

void Main::getAttacked() {
    for(int i = 0; i < enemies.size(); i++) {
        std::cout << "It is enemy " << i + 1 << "'s turn to attack!" << std::endl;

        double prevHealth = player.getHealth();
        
        if(player.roleHasArmor()) {
            player.takeDamage(enemies[i].getDamage(), player.getRoleArmor());
        } else {
            player.takeDamage(enemies[i].getDamage(), 0);
        }
        
        double damageTaken = prevHealth - player.getHealth();

        std::cout << "You were hit for " << damageTaken << " damage!" << std::endl;

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
        std::cout << "Bye!" << std::endl;
    }
}

int main() {
    Main game(50);
    return 0;
}
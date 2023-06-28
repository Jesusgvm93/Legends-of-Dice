#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Character.h"
#include "Warrior.h"
#include "Archer.h"
#include "Wizard.h"

using namespace std;

int main()
{
    srand(time(0)); // Función del Random
    
    cout << "Welcome to Legends of Dice" << endl;
    int rdmCharacter = rand() % 4;
    Race mainRace = static_cast<Race>(rdmCharacter);
    Character* mainCharacter = nullptr;


    switch (mainRace) // Generar MainCharacter Aleatorio Raza y Clase
    {
    case Race::Human:
    {
        int rdmClass = rand() % 3;
        switch (rdmClass)
        {
        case 0:
            mainCharacter = new Warrior(mainRace);
            cout << "Race: Human // Class: Warrior" << endl;
            break;
        case 1:
            mainCharacter = new Wizard(mainRace);
            cout << "Race: Human // Class: Wizard" << endl;
            break;
        case 2:
            mainCharacter = new Archer(mainRace);
            cout << "Race: Human // Class: Archer" << endl;
            break;
        }
        break;
    }
    case Race::Elf:
    {
        int rdmClass = rand() % 3;
        switch (rdmClass)
        {
        case 0:
            mainCharacter = new Warrior(mainRace);
            cout << "Race: Elf // Class: Warrior" << endl;
            break;
        case 1:
            mainCharacter = new Wizard(mainRace);
            cout << "Race: Elf // Class: Wizard" << endl;
            break;
        case 2:
            mainCharacter = new Archer(mainRace);
            cout << "Race: Elf // Class: Archer" << endl;
            break;
        }
        break;
    }
    case Race::Dwarf:
    {
        int rdmClass = rand() % 3;
        switch (rdmClass)
        {
        case 0:
            mainCharacter = new Warrior(mainRace);
            cout << "Race: Dwarf // Class: Warrior" << endl;
            break;
        case 1:
            mainCharacter = new Wizard(mainRace);
            cout << "Race: Dwarf // Class: Wizard" << endl;
            break;
        case 2:
            mainCharacter = new Archer(mainRace);
            cout << "Race: Dwarf // Class: Archer" << endl;
            break;
        }
        break;
    }
    case Race::Orc:
    {
        int rdmClass = rand() % 3;
        switch (rdmClass)
        {
        case 0:
            mainCharacter = new Warrior(mainRace);
            cout << "Race: Orc // Class: Warrior" << endl;
            break;
        case 1:
            mainCharacter = new Wizard(mainRace);
            cout << "Race: Orc // Class: Wizard" << endl;
            break;
        case 2:
            mainCharacter = new Archer(mainRace);
            cout << "Race: Orc // Class:: Archer" << endl;
            break;
        }
        break;
    }
    default:
        break;

    }

    cout << "Heroe Stats" << endl; //Imprimir stats iniciales
    mainCharacter->printStatistics();
    std::cout << std::endl;

    vector<Character*> enemies; // Creación del Vector con los 10 enemigos

    for (int i = 0; i < 10; ++i) {
        int rdmCharacter = rand() % 4;
        Race enemyRace = static_cast<Race>(rdmCharacter);
        Character* enemy = nullptr;

        switch (enemyRace) // Generación de enemigos aleatorio Raza y Clase
        {
        case Race::Human:
        {
            int rdmClass = rand() % 3;
            switch (rdmClass)
            {
            case 0:
                enemy = new Warrior(enemyRace);
                break;
            case 1:
                enemy = new Wizard(enemyRace);
                break;
            case 2:
                enemy = new Archer(enemyRace);
                break;
            }
            break;
        }
        case Race::Elf:
        {
            int rdmClass = rand() % 3;
            switch (rdmClass)
            {
            case 0:
                enemy = new Warrior(enemyRace);
                break;
            case 1:
                enemy = new Wizard(enemyRace);
                break;
            case 2:
                enemy = new Archer(enemyRace);
                break;
            }
            break;
        }
        case Race::Dwarf:
        {
            int rdmClass = rand() % 3;
            switch (rdmClass)
            {
            case 0:
                enemy = new Warrior(enemyRace);
                break;
            case 1:
                enemy = new Wizard(enemyRace);
                break;
            case 2:
                enemy = new Archer(enemyRace);
                break;
            }
            break;
        }
        case Race::Orc:
        {
            int rdmClass = rand() % 3;
            switch (rdmClass)
            {
            case 0:
                enemy = new Warrior(enemyRace);
                break;
            case 1:
                enemy = new Wizard(enemyRace);
                break;
            case 2:
                enemy = new Archer(enemyRace);
                break;
            }
            break;

        }
        default:
            break;

        }
        enemies.push_back(enemy);
    }

    Character* currentEnemy = enemies[0];
    int numDefeatedEnemies = 0; //Inicio de verificación de enemigos

    cout << "Enemy Stats" << endl;
    currentEnemy->printStatistics();
    std::cout << std::endl;

    while (mainCharacter->getHealth() > 0 && numDefeatedEnemies < enemies.size()) //Bucle mientras el personaje tenga vida y no se hayan acabado los enemigos
    {                                                                             //seguir los combates 
        cout << "----- Combat Start -----" << endl;
        cout << "Main Character Health: " << mainCharacter->getHealth() << endl;
        cout << "Main Character Damage: " << mainCharacter->getDamage() << endl;
        cout << "Main Character Mana: " << mainCharacter->getMana() << endl;
        cout << "Enemy Health: " << currentEnemy->getHealth() << endl;
        cout << endl;

        int action;
        cout << "Choose an action:" << endl;
        cout << "1) Normal Attack" << endl;
        cout << "2) Charged Attack" << endl;
        cout << "3) Super Attack" << endl;
        cout << "4) Rest" << endl;
        cin >> action;

        switch (action)  //Una vez iniciado el combate, se chequean los niveles de mana, de ser mayores a 0
        {               //el mainCharacter puede atacar, de lo contrario, descansara automaticamente 
            case 1:    //para recuperar 10 de mana
                if (mainCharacter->getMana() > 0)
                {
                    cout << "Heroe attacks!" << endl;
                    mainCharacter->attack();
                    currentEnemy->reduceHealth(mainCharacter->getDamage());
                }
                else
                {
                    cout << "Heroe needs to rest to restore mana." << endl;
                    mainCharacter->rest();
                }
               
            break;
            case 2:
                if (mainCharacter->getMana() > 0)
                {
                    cout << "Heroe Charged attack!" << endl;
                    mainCharacter->chargedAttack();
                    currentEnemy->reduceHealth(mainCharacter->getDamage());
                }
                else
                {
                    cout << "Heroe needs to rest to restore mana." << endl;
                    mainCharacter->rest();
                }
                
            break;
            case 3:
                if (mainCharacter->getMana() > 0)
                {
                    cout << "Heroe Super attack!" << endl;
                    mainCharacter->superAttack();
                    currentEnemy->reduceHealth(mainCharacter->getDamage());
                }
                else
                {
                    cout << "Main Character needs to rest to restore mana." << endl;
                    mainCharacter->rest();
                }
                
            break;
            case 4:
                mainCharacter->rest();
            break;
            default:
            cout << "Invalid action. Skipping turn." << std::endl;
            break;
        }
        
        int enemyRdn = rand() % 4; //Generación random de opciones de los enemigos 
                                  //Con la misma verificación del mana que se realizo para el mainCharacter
        switch (enemyRdn) {
        case 1:
            if (currentEnemy->getMana() > 0)
            {
                cout << "Enemy attacks!" << endl;
                currentEnemy->attack();
                mainCharacter->reduceHealth(currentEnemy->getDamage());
            }
            else
            {
                cout << "The enemy needs to rest to restore mana." << endl;
                mainCharacter->rest();
            }
           
            break;
        case 2:
            if (currentEnemy->getMana() > 0)
            {
                cout << "Enemy performs a charged attack!" << endl;
                currentEnemy->chargedAttack();
                mainCharacter->reduceHealth(currentEnemy->getDamage());
            }
            else
            {
                cout << "The enemy needs to rest to restore mana." << endl;
                mainCharacter->rest();
            }
        
            break;
        case 3:
            if (currentEnemy->getMana() > 0)
            {
                cout << "Enemy unleashes a super attack!" << endl;
                currentEnemy->superAttack();
                mainCharacter->reduceHealth(currentEnemy->getDamage());
            }
            else
            {
                cout << "The enemy needs to rest to restore mana." << endl;
                mainCharacter->rest();
            }
            
            break;
        case 4:
            cout << "Enemy rests and recovers mana." << endl;
            currentEnemy->rest();
            break;
        }

        if (currentEnemy->getHealth() <= 0) //Inicio de verificación si quedan enemigos en el vector.
        {
            cout << "You defeated the enemy!" << endl;
            numDefeatedEnemies++;
            mainCharacter->increasHealth(40.0f);

            // Obtener el siguiente enemigo en la lista
            if (numDefeatedEnemies < enemies.size())
            {
                currentEnemy = enemies[numDefeatedEnemies];
            }
               

            // Imprimir estadísticas del nuevo enemigo
            cout << "Enemy Stats" << endl;
            currentEnemy->printStatistics();
            cout << endl;
        }

    }

    cout << endl;

    cout << "----- Combat End -----" << endl;
    cout << "Main Character Health: " << mainCharacter->getHealth() << endl;
    cout << "Main Character Damage: " << mainCharacter->getDamage() << endl;
    cout << "Enemy Health: " << currentEnemy->getHealth() << endl;
    cout << "Enemy Damage: " << currentEnemy->getDamage() << endl;
    cout << endl;

    cout << "Remaining Enemies: " << enemies.size() - numDefeatedEnemies << endl;


    if (mainCharacter->getHealth() <= 0) {
        cout << "You lost the combat." << endl;
        cout << "Enemy Stats:" << endl;
        currentEnemy->printStatistics();
    }
    else
    {
        cout << "You won the combat!" << endl;
        mainCharacter->rest();
        mainCharacter->printStatistics();
    }

  

    delete mainCharacter;
    for (auto enemy : enemies)
        delete enemy;

    return 0;

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unistd.h>

using namespace std;

class Creature {

private:

    string _name;
    int _value;

public:

    Creature(string name, int value)
    {
        _name = name;
        _value = value;
    }

    string get_name()
    {
        return _name;
    }

    int get_value()
    {
        return _value;
    }
};

class Player {

private:

    int _hit_points;

public:

    Player(int hit_points)
    {
        _hit_points = hit_points;
    }

    int get_hit_points()
    {
        return _hit_points;
    }

    bool is_dead()
    {
        if (_hit_points == 0) {
            return true;
        } else {
            return false;
        }
    }

    void encounter(Creature x)
    {
        cout << "\nYou've encountered " << x.get_name() << "!\n";
        sleep(2);
        if (x.get_value() < 0) {
            cout << "You must fight for your life!\n";
            sleep(2);
            cout << "Fighting...\n";
            sleep(2);
            if (_hit_points + x.get_value() > 0) {
                cout << "You have defeated " << x.get_name() << ",\n";
                cout << "but you have suffered " << -x.get_value();
                cout << " hit points of damage.\n";
                _hit_points += x.get_value();
            } else {
                cout << x.get_name() << " has defeated you!\n";
                _hit_points = 0;
            }
            sleep(2);
        } else {
            cout << "That was very fortunate!\n";
            sleep(2);
            cout << "You get " << x.get_value();
            cout << " additional hit points.\n";
            sleep(2);
            _hit_points += x.get_value();
        }
    }
};

class AdventureGameApp {

private:

    Player _player {5};
    vector<Creature> _creatures;

public:

    AdventureGameApp()
    {
        _creatures.push_back(Creature {"Mr. Tumnus the Faun", 3});
        _creatures.push_back(Creature {"Aslan the Lion", 10});
        _creatures.push_back(Creature {"Reepicheep the Mouse", 2});
        _creatures.push_back(Creature {"Jadis the White Witch", -8});
        _creatures.push_back(Creature {"Ginarrbrik the Dwarf", -3});
        _creatures.push_back(Creature {"Maugrim the Wolf", -4});
        shuffle(
            _creatures.begin(),
            _creatures.end(),
            default_random_engine { random_device {} ()}
        );
    }

    void run_game()
    {
        cout << "ADVENTURE GAME\n";
        cout << "==============\n";
        cout << "By Ariel Ortiz, 2020.\n";
        int option;
        do {
            cout << endl;
            cout << "== Menu ==\n";
            cout << "1) Show player's stats\n";
            cout << "2) Encounter a creature\n";
            cout << "3) Quit\n";
            cout << "Please choose an option: ";
            cin >> option;
            switch (option) {
            case 1:
                show_player_stats();
                break;
            case 2:
                perform_encounter();
                break;
            case 3:
                cout << "\nQuitting...\n";
                sleep(2);
                break;
            }
        } while (!(option == 3 || _player.is_dead() || _creatures.empty()));

        if (_player.is_dead()) {
            cout << "\nYou're dead!\n";
        } else if (_creatures.empty()) {
            cout << "\nWell done. You've survived all the creature encounters\n";
            cout << "with " << _player.get_hit_points() << " hit points to spare.\n";
        }
        cout << "\nEnd of game.\n";
    }

    void show_player_stats()
    {
        cout << "\n==  Player's stats ==\n";
        cout << "Hit points: " << _player.get_hit_points() << endl;
        sleep(2);
    }

    void perform_encounter()
    {
        Creature c = _creatures.back();
        _creatures.pop_back();
        _player.encounter(c);
    }
};

int main()
{
    AdventureGameApp app;
    app.run_game();
    return 0;
}
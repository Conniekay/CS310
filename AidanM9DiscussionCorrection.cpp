#include <iostream>
using namespace std;

class weapon {
    private:
        string name;
        int damage;
        double crit;

    public:
        weapon(string name, int damage, double crit) {
            this->name = name;
            this->damage = damage;
            this->crit = crit;
        }
        string getName() {
            return name;
        }
        int getDamage() {
            return damage;
        }
        double getCrit() {
            return crit;
        }

        void setName(string name) {
            this->name = name;
        }
        void setDamage(int damage) {
            this->damage = damage;
        }
        void setCrit(double crit) {
            this->crit = crit;
        }
};
class melee : public weapon {
    private:
        string type;
    public:
        melee(string name, int damage, double crit, string type) : weapon(name, damage, crit) {
            this->type = type;
        }

        string getType() {
            return type;
        }
        void setType(string type) {
            this->type = type;
        }

        void print() {
            cout << getName() << " the " << getType() << "\n\nDamage: " << getDamage() << "\nCritical Damage: " << getCrit();
        }
};
class ranged : public weapon {
    private:
        string gunType;
        int ammo;
        double reloadSpeed;
    public:
        ranged(string name, int damage, double crit, string gunType, int ammo, double reloadSpeed) : weapon(name, damage, crit) {
            this->gunType = gunType;
            this->ammo = ammo;
            this->reloadSpeed = reloadSpeed;
        }

        string getType() {
            return gunType;
        }
        int getAmmo() {
            return ammo;
        }
        double getReload() {
            return reloadSpeed;
        }
        void setType(string gunType) {
            this->gunType = gunType;
        }
        void setAmmo(int ammo) {
            this->ammo = ammo;
        }
        void setReload(double reloadSpeed) {
            this->reloadSpeed = reloadSpeed;
        }

        void print() {
            cout << getName() << " the " << getType() << "\n\nDamage: " << getDamage() << "\nCritical Damage: " << getCrit() << "\nAmmo: " << getAmmo() << "\nReload Speed: " << getReload();
        }
};
int main()
{
    int weaponType;
    string type;
    string weaponName;
    int damage;
    double crit;
    int ammo;
    double reload;

    cout << "Hello and Welcome to Build-A-Gun™!\n" << endl;
    cout << "To Begin, Please Choose Either Melee Or Ranged. \nTo Pick Melee, Press 1.  To Pick Ranged, Press 2: ";
        cin >> weaponType;
        if (weaponType == 1) {
            cout << "\n\nNext, What Kind of Melee Weapon Is Yours?\n";
            cin >> type;
            cout << "How Much Damage Does It Do?\n";
            cin >> damage;
            cout << "How Much Is Damage Multiplied On Crits?\n";
            cin >> crit;
            cout << "Finally, What Is The Weapon's Name?\n";
            cin >> weaponName;

            melee myWeapon(weaponName, damage, crit, type);
            myWeapon.print();

        }
        else if (weaponType == 2) {
            cout << "\n\nNext, What Kind of Ranged Weapon Is Yours?\n";
            cin >> type;
            cout << "How Much Damage Does It Do?\n";
            cin >> damage;
            cout << "How Much Is Damage Multiplied On Crits?\n";
            cin >> crit;
            cout << "How Much Ammo Does It Have?\n";
            cin >> ammo;
            cout << "How Quickly Does It Reload?\n";
            cin >> reload;
            cout << "Finally, What Is The Weapon's Name?\n";
            cin >> weaponName;

            ranged myWeapon(weaponName, damage, crit, type, ammo, reload);
            myWeapon.print();
        }
}
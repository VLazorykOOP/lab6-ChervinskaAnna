#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;
namespace SpaceExample3 {
    // MultipleiInherance.cpp 
// Ієрархія типів складається з сутностей: 
// машина, пасажирський транспорт і автобус.
//


    class Transport {
    public:
        int NumCrew;
        string TypeTransport;
        Transport() {
        }
        Transport(int numCrew, string typeTransport) {
            this->NumCrew = numCrew;
            this->TypeTransport = typeTransport;
        }
    };

    ostream& operator<<(ostream& os, Transport& n) {
        cout << " Number of crew: " << n.NumCrew << endl << " Type of transport " << n.TypeTransport << endl;
        return os;
    }


    class PassengerTransport : public Transport {
    public:
        int NumPassengers;
        PassengerTransport() {
        }
        PassengerTransport(int numCrew, string typeTransport, int numPassengers) : Transport(numCrew, typeTransport) {
            this->NumPassengers = numPassengers;
        }
    };

    ostream& operator<<(ostream& os, PassengerTransport& n) {
        cout << " Number of crew: " << n.NumCrew << endl << " Type of transport " << n.TypeTransport << endl << " Number of Passengers " << n.NumPassengers << endl;
        return os;
    }
 
    class Ship : public Transport { 
    public:
        int Lifeboat;
        int Lifebuoy;
        Ship() {
        }
        Ship(int numCrew, string typeTransport, int lifeboat, int lifebuoy) : Transport(numCrew, typeTransport) {
            this->Lifeboat = lifeboat;
            this->Lifebuoy = lifebuoy;
        }
    };

    ostream& operator<<(ostream& os, Ship& n) {
        cout << " Number of crew: " << n.NumCrew << endl << " Type of transport " << n.TypeTransport << endl;
        cout << " Number of Lifeboat " << n.Lifeboat << endl << " Number of Lifebuoy " << n.Lifebuoy << endl;
        return os;
    }

    class PassengerShip : public PassengerTransport, public Ship {
    public:
        int CabinNum;
        PassengerShip() {
        }
        PassengerShip (int numCrew, string typeTransport, int lifeboat, int lifebuoy, int numPassengers, int cabinNum) 
            : PassengerTransport(numCrew, typeTransport, numPassengers), Ship(numCrew, typeTransport, lifeboat, lifebuoy)
                {
            this->CabinNum = cabinNum;
        }
    };

    ostream& operator<<(ostream& os, PassengerShip& n) {
        cout << " Number of crew: " << ( (PassengerTransport) n).NumCrew << endl << " Type of transport " << ((PassengerTransport) n).TypeTransport << endl;
        cout << " Number of Lifeboat " << n.Lifeboat << endl << " Number of Lifebuoy " << n.Lifebuoy << endl;
        cout << " Number of Passengers " << n.NumPassengers << endl << " Cabin numbers" << n.CabinNum << endl;
        return os;
    }
   

    int mainExample3()
    {
        Transport obj1 = Transport(470, "Airplane");
        cout << "OBJ1: " << obj1 << endl;
        PassengerTransport obj2 = PassengerTransport(3, "Trolley", 28);
        cout << "OBJ2: " << obj2 << endl;
        Ship obj3 = Ship(356, "Ship", 49, 289);
        cout << "OBJ3: " << obj3 << endl;
        PassengerShip obj4 = PassengerShip(265, "Passenger Ship", 187, 365, 678, 245);
        cout << "OBJ4: " << obj4 << endl;
      
        return 0;
    }


}
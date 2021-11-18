# include <iostream>

using namespace std;

// New Coffee Machine Interface
class CoffeeMachineInterface {
    public:
        void firstSelection(){
            cout << "Machine_ID: NEW ----> Select First Flavour" << endl;
        }
        void secondSelection(){
            cout << "Machine_ID: NEW ----> Select Second Flavour" << endl;
        }
};

// Old Coffee Machine Interface, but assume it needs to be accessed via touch screen
class OldCoffeeMachine {
    public:
        void firstSelection(){
            cout << "Machine_ID: OLD ----> Select First Flavour" << endl;
        }
        void secondSelection(){
            cout << "Machine_ID: OLD ----> Select Second Flavour" << endl;
        }
};

// Adapter pattern to direct touchscreen commands to old coffee machine
class CoffeeTouchscreenAdapter :  public CoffeeMachineInterface {
    private:
        OldCoffeeMachine* OldVendingMachine;
    public:
        // Constructor
        CoffeeTouchscreenAdapter(OldCoffeeMachine* OldVendingMachine){
            OldVendingMachine = OldVendingMachine;
        }
        void firstSelection(){
            OldVendingMachine -> firstSelection();
        }
        void secondSelection(){
            OldVendingMachine -> secondSelection();
        }
};

int main(){

    CoffeeMachineInterface* newCoffeeMachine = new CoffeeMachineInterface;
    OldCoffeeMachine* oldCoffeeMachine = new OldCoffeeMachine;
    CoffeeTouchscreenAdapter* adapter = new CoffeeTouchscreenAdapter(oldCoffeeMachine);

    // Case I - The First Flavour is selected using touch screen 
    newCoffeeMachine -> firstSelection();
    adapter -> firstSelection();

    // Case II - The Second Flavour is selected using touch screen 
    newCoffeeMachine -> secondSelection();
    adapter -> secondSelection();

    return 0;
}

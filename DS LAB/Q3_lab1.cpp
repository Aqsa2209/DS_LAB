#include <iostream>
#include <cstring>

using namespace std;

class Box {
private:
    int* data; // Pointer to an integer

public:
    // Constructor
    Box(int value) {
        data = new int(value);
        cout << "Constructed Box with value: " << *data << endl;
    }

    // Destructor
    ~Box() {
        delete data;
        cout << "Destructed Box" << endl;
    }

    // Copy Constructor (Deep Copy)
    Box(const Box& other) {
        data = new int(*other.data);
        cout << "Copy constructed Box with value: " << *data << endl;
    }

    // Copy Assignment Operator (Deep Copy)
    Box& operator=(const Box& other) {
        if (this != &other) { // Check for self-assignment
            delete data; // Free existing resource
            data = new int(*other.data); // Allocate new memory and copy the value
            cout << "Copy assigned Box with value: " << *data << endl;
        }
        return *this;
    }

    // Function to get the value
    int getValue() const {
        return *data;
    }
};

void demonstrateShallowCopy() {
    cout << "Demonstrating shallow copy:" << endl;
    Box box1(90);
    Box box2 = box1; // This will invoke the copy constructor (Deep Copy)
    
    cout << "Box1 value: " << box1.getValue() << endl;
    cout << "Box2 value: " << box2.getValue() << endl;
}

void demonstrateDeepCopy() {
    cout << "Demonstrating deep copy:" << endl;
    Box box1(20);
    Box box2(30);
    
    box2 = box1; // This will invoke the copy assignment operator (Deep Copy)

    cout << "Box1 value: " << box1.getValue() << endl;
    cout << "Box2 value: " << box2.getValue() << endl;
}

int main() {
    demonstrateShallowCopy();
    demonstrateDeepCopy();
    return 0;
}

#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    // Constructor
    Student(const std::string& newName, int newAge) : name(newName), age(newAge) {}

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age
    void setAge(int newAge) {
        age = newAge;
    }
};

int main() {
    // Create an instance of the Student class and initialize it with name and age
    Student student("Alice", 20);

    // Print the initial name and age
    std::cout << "Initial Name: " << student.getName() << std::endl;
    std::cout << "Initial Age: " << student.getAge() << std::endl;

    // Change the name and age of the student
    student.setName("Bob");
    student.setAge(22);

    // Print the updated name and age
    std::cout << "Updated Name: " << student.getName() << std::endl;
    std::cout << "Updated Age: " << student.getAge() << std::endl;

    return 0;
}


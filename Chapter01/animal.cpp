#include <iostream>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
        Animal(string name): m_name(name)
        {

        }

        virtual string MakeSound() = 0;
        string GetName()
        {
            return m_name;
        }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}

    void operator = (const Dog &D)
    {
        m_name = D.m_name;
    }

    string MakeSound() override
    {
        return "hav hav";
    }
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}

    void operator = (const Cat &C)
    {
        m_name = C.m_name;        
    }

    string MakeSound() override
    {
        return "miyav miyav";
    }
};

template <typename T>
void GetNameAndMakeSound(T& theAnimal)
{
    cout << theAnimal.GetName() << " goes ";
    cout << theAnimal.MakeSound() << endl;
};

template <typename T>
class AnimalTemplate
{
private:
    T m_animal;

public:
    AnimalTemplate(T animal) : m_animal(animal) {}

    void GetNameAndMakeSound()
    {
    cout << m_animal.GetName() << " goes ";
    cout << m_animal.MakeSound() << endl;
    }
};

int main()
{
    Dog dog = Dog("Bulldog");
    AnimalTemplate<Dog> dogTemplate(dog);
    dogTemplate.GetNameAndMakeSound();
    Cat cat = Cat("Persian Cat");
    AnimalTemplate<Cat> catTemplate(cat);
    catTemplate.GetNameAndMakeSound();
    return 0;
}
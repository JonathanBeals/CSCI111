#include <iostream>
#include <string>

//Struct definition
struct Item
{
	std::string name;
	std::string type;
	double weight, value;
};

//Function prototypes

//Add items to inventory
void addItem(Item inventory[], int &count, int maxItems);

//Calculate total weight and check if its over limit
double calculateTotalWeight(const Item inventory[], int count);

//Find most valuable item
Item findMostValuableItem(const Item inventory[], int count);

//Prints details of each item in inventory
void displayInventory(const Item inventory[], int count);



int main(int argc, const char* argv[])
{
	const int maxItems = 5;
	Item inventory[maxItems];
	int itemCount;

	//Add item function
	addItem(Item inventory, itemCount, maxItems);
	addItem(Item inventory, itemCount, maxItems);
	addItem(Item inventory, itemCount, maxItems);

	std::cout << "Player inventory contains:\n";
	displayInventory(inventory, itemCount);

	//calculate weight
	double totalWeight = calculateTotalWeight(inventory, itemCount);
	std::cout << "Player inventory weighs:\t" << totalWeight << "units\n";

	if (itemCount > 0)
	{
		Item mostValuable = findMostValuableItem(inventory, itemCount);
		std::cout << "Player's inventory most valuable item is:\t"
			<< mostValuable.name << " valued at " << mostValuable.value << " units.\n";
	}
	else
		std::cout << "Player inventory is empty\n";



	return 0;
}

void addItem(Item inventory[], int& count, int maxItems)
{
	if (count >= maxItems)
	{
		std::cout << "Sorry inventory is full\n";
		return;
	}
	Item newItem;
	std::cout << "\nEnter the item name: ";
	std::getline(std::cin, newItem.name);

	std::cout << "\nEnter item type (e.g. Weapon, Potion, Armor):";
	std::getline(std::cin, newItem.type);

	std::cout << "\nEnter item weight: ";
	std::cin >> newItem.weight;

	std::cout << "\nEnter item value: ";
	std::cin >> newItem.value;
	std::cin.ignore();

	inventory[count] = newItem;
	count++;
	std::cout << "New item added to inventory\n"
}




double calculateTotalWeight(const Item inventory[], int count)
{
	double totalWeight = 0.0;
	for (int i = 0; i < count; ++i)
	{
		totalWeight += inventory[i].weight;
	}
	return totalWeight;
}




Item findMostValuableItem(const Item inventory[], int count)
{
	Item mostValuable = inventory[0];
	for (int i = 0; i < count; ++i)
	{
		if (inventory[i].value > mostValuable.value)
			mostValuable = inventory[i];
	}

	return mostValuable;
}



void displayInventory(const Item inventory[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << "Item: " << i + 1 ": " inventory[i].name << " Weighs: "
			<< inventory[i].weight << ", Value: " << inventory[i].value << '\n';
	}
}
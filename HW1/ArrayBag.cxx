//
#include <cstddef>

// Constructor; creates and initializes an empty Bag
template <class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
	numberOfItems = 0;
}

// Return the number of Items being stored in the Bag
template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return numberOfItems;
}

// Return the capacity of the bag (the maximum Items it can store) 
template <class ItemType>
int ArrayBag<ItemType>::getCapacity( ) const
{
	return DEFAULT_CAPACITY;
}

// Report whether the Bag is empty
// Return true if the Bag is empty (storing no Items);
// Return false if Items exist in the Bag
template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	if (numberOfItems == 0)
		return true;
	else
		return false;
}

// Report whether the Bag is full
// Return true if the Bag is filled to capacity
// Return false if there is still room
template <class ItemType>
bool ArrayBag<ItemType>::isFull() const
{
	if (numberOfItems == DEFAULT_CAPACITY)
		return true;
	else
		return false;
}

// Give the Bag a new Item to store
// If Bag is full, nothing changes
// Else, Bag must add this Item to its Item array and update its numberOfItems
// If Bag is full after this, return true; else return false
template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newItem)
{
	if (numberOfItems == DEFAULT_CAPACITY){
		return false;
	}
	else {
		itemArray[numberOfItems] = newItem;
		numberOfItems++;
		return true;
	}
}

// Make the Bag act like an empty Bag again
template <class ItemType>
void ArrayBag<ItemType>::clear()
{
	numberOfItems = 0;
}

// Remove an Item from the bag
// If Item is not there, nothing changes and we return false
// Else, we fill in its spot in that Item array and count number of Items down
template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anItem)
{
	if (numberOfItems == 0)
		return false;
	else {
		for (int i = 0; i < numberOfItems; i++)
		{
			if (itemArray[i] == anItem){
				itemArray[i] = itemArray[numberOfItems-1];
				numberOfItems--;
			}	
		}
		return true;
	}
}

// Check if an Item is in the Bag
// Return true if it is in the Bag, and false if not
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anItem) const
{
	if (numberOfItems == 0){
		return false;
	}
	else {
		for (int i = 0; i < numberOfItems; i++){
			if (itemArray[i] == anItem)
			return true;
		}
		return false;
	}
}

// Check how many times an Item is in the Bag
// return 0 if it's not there; otherwise,
// return the number of times it occurs
template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anItem) const
{
	int count = 0;
	if (numberOfItems == 0)
		return 0;
	else {
		for (int i = 0; i < numberOfItems; i++) {
			if (itemArray[i] == anItem) {
				count++;
			}	
		}
		return count;
	}
}

// Make an output vector of Items from the bag (for checking)
template <class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < numberOfItems; i++){
		bagContents.push_back(itemArray[i]);
	}
	return bagContents;				
}

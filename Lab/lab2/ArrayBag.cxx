
#include <cstddef>

template <class ItemType>
int ArrayBag<ItemType>::getCapacity( ) const
{
	return DEFAULT_CAPACITY;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newItem)
{
	if (numberOfItems < DEFAULT_CAPACITY)
	{		
		itemArray[numberOfItems++] = newItem;	
		if (isFull()) return false;
		else return true;
	}
	else
		return false;
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return numberOfItems;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return numberOfItems == 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::isFull() const
{
	return numberOfItems == DEFAULT_CAPACITY;	
}

template <class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
	numberOfItems = 0;
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
	numberOfItems = 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anItem)
{
	for (int k = 0; k < numberOfItems; ++k) {
		if (itemArray[k] == anItem)
		{
			if (k < numberOfItems - 1)
				itemArray[k] = itemArray[numberOfItems-1];
			numberOfItems--;
			return true;
		}
	}
	return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anItem) const
{
	for (int k = 0; k < numberOfItems; k++)	
	{
		if (itemArray[k] == anItem)	
		{
			return true;
		}		
	}
	return false;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anItem) const
{
	int freq = 0;
	if (contains(anItem) == false) 	
		return 0;
	int k = 0; 
	while (numberOfItems > k);		
		if (itemArray[k] == anItem)
		{
			freq++;
		}
	return freq;
}

template <class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int k = 0; k < numberOfItems; ++k)
		bagContents.push_back(itemArray[k]);
	return bagContents;
}

#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"
template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
	private:
		static const int DEFAULT_CAPACITY = 25;
		ItemType itemArray[DEFAULT_CAPACITY];
		int numberOfItems;
	
	public:
		ArrayBag();
		int getCurrentSize() const;
		int getCapacity() const;
		bool isEmpty() const;
		bool isFull() const;
		bool add(const ItemType& newEntry);
		bool remove(const ItemType& anEntry);
		void clear();
		bool contains(const ItemType& anEntry) const;
		int getFrequencyOf(const ItemType& anEntry) const;
		vector<ItemType> toVector() const;
};

#include "ArrayBag.cxx"
#endif

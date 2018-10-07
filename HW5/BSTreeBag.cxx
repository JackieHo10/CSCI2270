#ifndef BAG6_CXX 
#define BAG6_CXX
#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "BSTreeBag.h"
using namespace std;

namespace hw5
{
template <class ItemType>
BSTreeBag<ItemType>::BSTreeBag()
	{
		root_ptr=NULL;
	}

template <class ItemType>
BSTreeBag<ItemType>::BSTreeBag(const BSTreeBag& source)
    {
root_ptr=tree_copy(source.root_ptr);
    }

template <class ItemType>
BSTreeBag<ItemType>::~BSTreeBag()
	{
		tree_clear(root_ptr);
		delete root_ptr;
		root_ptr=NULL;
	}

template <class ItemType>
void BSTreeBag<ItemType>::insert(const ItemType& entry)
{
	if (root_ptr==NULL)
	{
	root_ptr=new binary_tree_node<ItemType>(entry, NULL,NULL);
	return;
	}
	binary_tree_node<ItemType>*cursor;
	cursor=root_ptr;
	while (true)
	{
		if(entry<=cursor->data())
			{
				if (cursor->left()==NULL)
					{
						cursor->left()=new binary_tree_node<ItemType>(entry,NULL,NULL);
						return;
					}
				cursor=cursor->left();
			}
		else
			{
				if (cursor->right()==NULL)
					{
						cursor->right()=new binary_tree_node<ItemType>(entry,NULL,NULL);
						return;
					}
				cursor=cursor->right();
			}
	}
}

template <class ItemType>
void BSTreeBag<ItemType>:: operator =(const BSTreeBag& source)
{	
	if (this == &source)
		{
			return;
		}
	tree_clear(root_ptr);
	root_ptr=tree_copy(source.root_ptr);
}
	
template <class ItemType>
void BSTreeBag<ItemType>:: operator +=(const BSTreeBag& addend)
{
	binary_tree_node<ItemType>*addroot_ptr;
	if(this==&addend)
	{
		addroot_ptr= tree_copy(addend.root_ptr);
		insert_all(addroot_ptr);
		tree_clear(addroot_ptr);
	}
	else
	insert_all(addend.root_ptr);
}

template <class ItemType>	
void BSTreeBag<ItemType>::insert_all(binary_tree_node<ItemType>*addroot_ptr)
{
	if (addroot_ptr==NULL)
	return;
	else
		{
			insert(addroot_ptr->data());
			insert_all(addroot_ptr->left());
			insert_all(addroot_ptr->right());
		}
}
	
template <class ItemType>
typename BSTreeBag<ItemType>::size_type BSTreeBag<ItemType>:: erase(const ItemType& target)
{
	return bst_remove_all (root_ptr,target);
}
	

template <class ItemType>
typename BSTreeBag<ItemType>::size_type BSTreeBag<ItemType>:: count(const ItemType& target) const
{
	unsigned int count=0;
	binary_tree_node<ItemType>* cursor;
	cursor=root_ptr;
	if(cursor==NULL)
	return count;
	if(target==cursor->data())
	count++;
	while (cursor!=NULL)
	{
		if (target>cursor->data())
			{
				cursor=cursor->right();
				if(cursor==NULL)
				return count;
				else if(target==cursor->data())
				count++;
			}
		else
			{
				cursor=cursor->left();
				if(cursor==NULL)
				return count;
				else if(target==cursor->data())
				count++;
			}
	}
	
return count;
}

template <class ItemType>
typename BSTreeBag<ItemType>::size_type BSTreeBag<ItemType>::size( )
const
{
		return tree_size(root_ptr);
}

template <class ItemType>
bool BSTreeBag<ItemType>:: erase_one(const ItemType& target)
{
	return  bst_remove(root_ptr,target);
}
	
template <class ItemType>
BSTreeBag<ItemType> operator +(const BSTreeBag<ItemType>& b1, const BSTreeBag<ItemType>& b2)
{
	BSTreeBag <ItemType> b=b1;
	
	b+=b2;

	return b;
}

template <class ItemType>
bool bst_remove(binary_tree_node<ItemType>*& root_ptr, const ItemType&
target)
{
if(root_ptr==NULL)
return false;
else if(root_ptr->data()>target)
	{
		return bst_remove(root_ptr->left(), target);
	}
else if(root_ptr->data()<target)	
	{
		return bst_remove(root_ptr->right(), target);
	}
else
	{
		if(root_ptr->left()==NULL)
		{
			binary_tree_node<ItemType>* old_root_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete old_root_ptr;
		}
		else
			bst_remove_max(root_ptr->left(), root_ptr->data());
		return true;
	}
return false;
}

template <class ItemType>
void bst_remove_max(binary_tree_node<ItemType>*& root_ptr, ItemType& removed)
{
    
  if( root_ptr -> right() == NULL)
    {
		removed=root_ptr -> data();
        binary_tree_node <ItemType>* to_delete = root_ptr;
        root_ptr = root_ptr -> left();
        delete to_delete;
    }
    else
    {
        bst_remove_max(root_ptr -> right(), removed);
    }
}

template <class ItemType>
typename BSTreeBag<ItemType>::size_type bst_remove_all (binary_tree_node<ItemType>*& root_ptr, const ItemType& target)
{
    binary_tree_node<ItemType> *oldroot_ptr;
    if (root_ptr == NULL)
		{   
			return 0;
		}

    if (target < root_ptr->data( ))
		{   
			bst_remove(root_ptr -> left(), target);
		}

    if (target > root_ptr->data( ))
		{  
			bst_remove(root_ptr -> right(), target);
		}

    if (root_ptr->left( ) == NULL)
		{  
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right( );
			delete oldroot_ptr;
			return 1;
		}
    bst_remove_max(root_ptr->left( ), root_ptr->data( ));
    return 1 + bst_remove_all(root_ptr, target);
}
}
#endif




// Write your name and date here
#include "PlayList.h"
#include <iostream>
#include <typeinfo>

// PlayList method implementations go here

using namespace std;

// Working 
PlayList::PlayList() 
{
    head = nullptr;
    song_count = 0;
}

//Working
PlayList::PlayList( const PlayList& pl)
{

    PlayListNode* temp = pl.head;

    if ( temp != nullptr)
    {
        Song* sng = new Song( pl.head->song.getName(),pl.head->song.getArtist(),pl.head->song.getLength());
        head = new PlayListNode( *sng , nullptr);
        PlayListNode* current = head;

        temp = temp->next;


        while( temp != nullptr )
        {
            Song* sng = new Song (temp->song.getName(),temp->song.getArtist(),temp->song.getLength());
            current->next = new PlayListNode(*sng , nullptr);
            current = current->next;
            temp = temp->next;
            

        }

        song_count = pl.size();
    }
    else
    {
        head = nullptr;
        song_count = 0;
    }



  
}

//Working
PlayList::~PlayList()
{
    PlayListNode* temp = head;

    while( temp )
    {
        temp = temp->next;
        delete head;
        head = temp->next;
    }

}

//working
PlayList& PlayList::operator=(const PlayList & pl)
{
    // check for self assigment
    if( this == &pl )
    {
        return *this;
    }  

    // Resting this to a nullptr
    // make a ptr to the head of the node to be copied to 
    PlayListNode* current = this->head; 

    //clear the linked list
    while( current )
    {
        current = current->next;
        delete head;
        head = current;
    }

    // if the head of the list to be copied is nullptr then return this->head as nullptr
    if( pl.head != nullptr)
    {
        //make a song ptr that has all the atributes of pl
        // make the head of the linked list contain the new song 

        Song* sng = new Song( pl.head->song.getName(), pl.head->song.getArtist(), pl.head->song.getLength());
        this->head = new PlayListNode(*sng);

        // ptr to the head of the linked lists

        PlayListNode* current = this->head;
        PlayListNode* temp = pl.head->next;

        // make a deep copy of the linked list 

        while( temp )
        {
            current->next = new PlayListNode(temp->song);
            current = current->next;
            temp = temp->next;
        }

    }

    //retrun the linked list
    return *this;

    

    



}

// working
void PlayList::insert(Song sng , unsigned int pos)
{
    // if the position to insert is larger then length + 1 then return
    if( pos > song_count + 1)
    {
        return;
    }

    PlayListNode* temp = head; // makes a node for iterating  
    PlayListNode* new_node = new PlayListNode(sng); // makes a new node to insert

    // If there are no elements then put in the first slot
    if( head == nullptr)
    {
        head = new_node;
        song_count++;
        return;
    }

    // if the position is 0 then the new node is the head
    if( pos == 0)
    {
        new_node->next = head->next;
        head = new_node;
        return;

    }

    //loop to the index right before the spot to insert
    // make the node at index pos-1 point to new node and new node point to pos
    for( int i = 0; i < pos-1 ; i++)
    {
        temp = temp->next;
    }
    
    new_node->next = temp->next;
    temp->next = new_node;

    song_count++;
}

//working
Song PlayList::remove(unsigned int pos)
{
   //make a ptr for the current and prev nodes
    PlayListNode* temp = head;
    PlayListNode* prev = nullptr;

    // if there is nothing to remove from the linked list
   

    // if index is the head of the list
    // remove the head and make the head ptr to the next node
    if( pos == 0 )
    {
        head = head->next;
        song_count--;
        return temp->song;
    }

    //loop to the pos of the node

    for(int i = 0; i < pos;i++)
    {
        prev = temp;
        temp = temp->next;
    }

    //make the prev ptr point to the node after the index
    // delete the temp variable 

    Song* sng = new Song( temp->song.getName(), temp->song.getArtist(), temp->song.getLength()); 
    prev->next = temp->next;
    delete temp;
    song_count--;
    return *sng;
    
}
 
 //working
Song PlayList::get( unsigned int pos) const
{
    PlayListNode *temp = head;

    for( int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }

    return temp->song;
}

//working
void PlayList::swap(unsigned int pos1 , unsigned int pos2)
{
    //points to the nodes before the nodes we are swapping
    PlayListNode *prev1 = nullptr;
    PlayListNode *prev2 = nullptr;
    PlayListNode *swapping = nullptr;
    PlayListNode *temp1 = head;
    PlayListNode *temp2 = head;

    // if the positions are the same or the index is out of the bounds then return
    if( pos1 == pos2 || pos1 > song_count || pos2 > song_count)
    {
        return;
    }

    for( unsigned int i = 0; i < pos1; i++)
    {
        prev1 = temp1;
        temp1 = temp1->next;
    }

    for( unsigned int i = 0; i < pos2; i++)
    {
        prev2 = temp2;
        temp2 = temp2->next;
    }

    cout << (prev1 == nullptr) << endl;
    
    if( prev1 != nullptr)
    {
        prev1->next = temp2;
    }
    else{
        head = temp2;
    }


    if ( prev2 != nullptr)
    {
        prev2->next = temp1;
    }
    else{
        head = temp1;
    }

    swapping = temp1->next;
    temp1->next = temp2->next;
    temp2->next = swapping;

    




}

unsigned int PlayList::size() const
{
    return song_count;
}
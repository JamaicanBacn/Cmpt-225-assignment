#include "playlist.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void print_menu();
void print_list( PlayList *pl);

int main()
{

  PlayList* ls = new PlayList();
  Song a = Song{"a","a",1};
  Song b = Song{"b","b",2};
  Song c = Song{"c","c",3};
  ls->insert(a,0);
  ls->insert(b,1);
  ls->insert(c,2);
  ls->swap(1,0);


  print_list(ls);

  




  return 1;
}

void print_menu()
{
    cout << "Menu:" << endl;
    cout << "1 - Enter a song in the play list at a given position" << endl;
    cout << "2 - Remove a song from the play list at a given position" << endl;
    cout << "3 - Swap two songs in the play list" << endl;
    cout << "4 - Swap two songs in the play list "  << endl;
    cout << "5 - Print all the songs in the play list" << endl;
}

void print_list( PlayList *pl)
{
  int songs = pl->size();


  for( int i = 0 ; i < songs; i++)
  {
   cout << "Song: " << i << " ====> " << pl->get(i).getArtist() << " <==== " << endl; 
  }

  cout << " PlayList end " << endl;

}
/*
A playlist is considered a repeating playlist if any of the songs contain a pointer to a previous
song in the playlist. Otherwise, the playlist will end with the last song which points to NULL.

Implement a function isRepeatingPlaylist that, efficiently with respect to time used,
returns true if a playlist is repeating or false if it is not.

For example, the following code prints "true" as both songs point to each other.

Song* first = new Song("Hello");
Song* second = new Song("Eye of the tiger");

first->next(second);
second->next(first);

std::cout << std::boolalpha << first->isRepeatingPlaylist();
*/

#include <stdexcept>
#include <iostream>
#include <map>

using namespace std;
class Song
{
public:
    Song(string name): name(name), nextSong(NULL) {}
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist(){
        Song* CurrentSong = this;
        map<string, int> MapCheck;
        for (; CurrentSong != NULL; CurrentSong = CurrentSong->nextSong) {
            auto MapResult = MapCheck.insert(pair<string, int>(CurrentSong->name, 1));
            if (MapResult.second == false)
                return 1;
        }
        return 0;
    }

private:
    const string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");

    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif

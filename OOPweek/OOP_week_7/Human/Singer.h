#include "Human.h"

class Singer : public Human
{
private:
    string genre;
    int shows;
    int albums;
public:
    void setInfo();
    void getInfo();
    string getGenre();
    void setGenre(string genre);
    int getShows();
    void setShows(int shows);
    int getAlbums();
    void setAlbums(int albums);
    Singer();
    ~Singer();
};


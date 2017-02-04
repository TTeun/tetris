#ifndef SET_BLOCK__H
#define SET_BLOCK__H

#include <iostream>
#include <vector>
#include "../renderable/renderable.h"

using namespace std;

class SetBlock : public Renderable {
public:
    SetBlock(size_t w, size_t h);
    void updateBuffers(size_t w, size_t h);

    vector <vector<bool> > matrix; 



};

#endif
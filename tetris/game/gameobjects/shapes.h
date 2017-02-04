#ifndef SHAPES__H
#define SHAPES__H

#include <vector>
#include <assert.h>     /* assert */

using namespace std;

class Shapes {

public:
    Shapes() {

        shapes1[0] = {
            {   0b0100,
                0b0100,
                0b0110,
                0b0000
            },

            {   0b0100,
                0b0100,
                0b1100,
                0b0000
            },

            {   0b0100,
                0b0100,
                0b0100,
                0b0100
            },

            {   0b0000,
                0b0110,
                0b0110,
                0b0000
            }
        };

        for (int i = 0; i < NUMSHAPES; ++i) {
            shapes1[1].push_back(rotate(shapes1[0][i]));
            shapes1[2].push_back(rotate(shapes1[1][i]));
            shapes1[3].push_back(rotate(shapes1[2][i]));
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                std::cout << ((shapes1[0][0][i] & (1 << j)) != 0);
            std::cout << '\n';
        }
        std::cout << '\n';
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                std::cout << ((shapes1[1][0][i] & (1 << j)) != 0);
            std::cout << '\n';
        }
        std::cout << '\n';
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                std::cout << ((shapes1[2][0][i] & (1 << j)) != 0);
            std::cout << '\n';
        }
        std::cout << '\n';
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                std::cout << ((shapes1[3][0][i] & (1 << j)) != 0);
            std::cout << '\n';
        }


    }

    enum SHAPES_TYPES
    {
        L1,
        L2,
        LINE,
        SQUARE,
        NUMSHAPES
    };

    vector <short int> rotate(vector <short int> &input) {
        vector <short int> result = {0, 0, 0, 0};
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (input[i] & (1 << j))
                    result[3 - j] |= (1 << i);
        return result;
    }

    vector <vector <short int> > shapes1[4];

};

#endif
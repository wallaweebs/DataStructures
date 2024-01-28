// Written by Debasree Sen
// ID: 24242663
//The work in this assignment is my own. Any outside sources have been properly cited.
#include "stats.h"

namespace main_savitch_2C {
    bool operator==(const statistician &s1, const statistician &s2){
        if (s1.length() < 1 && s2.length() < 1){
            return true;
        }
        else {
            return
                    s1.length() == s2.length() &&
                    s1.mean( ) == s2.mean( ) &&
                    s1.sum( ) == s2.sum( ) &&
                    s1.minimum( ) == s2.minimum( ) &&
                    s1.maximum( ) == s2.maximum( );
        }
    }
}
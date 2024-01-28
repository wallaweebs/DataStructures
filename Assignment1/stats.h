#pragma once
// Provided by:   ____________Debasree Sen__________
// Email Address: ____________dsen000@citymail.cuny.edu________
// ID: 24242663›
//The work in this assignment is my own. Any outside sources have been properly cited.
// FILE: stats.h
// CLASS PROVIDED: statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the statistician class:
//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//   
// PUBLIC CONSTANT member functions for the statistician class:
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions for the statistician class:
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum, 
//     the same maximum, and the same sum.
//     
// VALUE SEMANTICS for the statistician class:
// Assignments and the copy constructor may be used with statistician objects.

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H

#include <iostream>

namespace main_savitch_2C {
    class statistician {
    public:
        // CONSTRUCTOR
        statistician() : count(0), total(0.0) {};

        // MODIFICATION MEMBER FUNCTIONS
        void next(double r) { //increments the private member variable to keep track of how many numbers have been seen
            count++;

            total = r + total; //sum

            if (count == 1) {
                tinyest = r;
                largest = r;
            }
            if (count > 1 && r < tinyest) {
                tinyest = r;
            }
            if (count > 1 && r > largest) {
                largest = r;
            }
        };

        void reset() {
            count = 0;
            total = 0;
            tinyest = 0;
            largest = 0;
        };

        // CONSTANT MEMBER FUNCTIONS
        int length() const {
            return count;
        };

        double sum() const {
            return total;

        };

        double mean() const {
            return total / count;
        };

        double minimum() const { //if next num is smaller, tinyest is set
            return tinyest;
        };

        double maximum() const {
            return largest;
        };

        // FRIEND FUNCTIONS
        friend statistician operator+(const statistician &s1, const statistician &s2) {
            statistician q;

            if (s1.length() == 0) {
                return s2;
            }
            else if (s2.length() == 0) {
                return s1;
            }
            else {
                q.count = s1.length() + s2.length();
                q.total = s1.sum() + s2.sum();

                if(s1.minimum() < s2.minimum()){
                    q.tinyest = s1.minimum();
                }
                else{
                    q.tinyest = s2.minimum();
                }

                if(s1.maximum() > s2.maximum()){
                    q.largest = s1.maximum();
                }
                else{
                    q.largest = s2.maximum();
                }


                return q;
            }
        };

        friend statistician operator*(double scale, const statistician &s) {
            statistician p;

            if (s.length() == 0) {
                return s;
            }
            else {
                p.count = s.length();
                p.total = s.sum() * scale;

                if(scale < 0){
                    p.tinyest = s.maximum() * scale;
                    p.largest = s.minimum() * scale;
                }
                else{
                    p.tinyest = s.minimum() * scale;
                    p.largest = s.maximum() * scale;
                }

                return p;
            }

        };

    private:
        int count;       // How many numbers in the sequence
        double total;    // The sum of all the numbers in the sequence
        double tinyest;  // The smallest number in the sequence
        double largest;  // The largest number in the sequence
    };

// NON-MEMBER functions for the statistician class
    bool operator==(const statistician &s1, const statistician &s2);
}

#endif
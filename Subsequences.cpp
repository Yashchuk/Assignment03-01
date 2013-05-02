/*
 * File: Subsequences.cpp
 * ----------------------
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 3 - Pt. 1 - Subsequences
 */

#include <iostream>
#include <string>
#include "console.h"
#include "AdvancedSubsequences.h"
#include "Subsequences.c"
using namespace std;

/* Perform unit tests on the isSubsequence() function. */
void runTests();

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subseq);

/*
 * Recursively determine whether a string is a
 *   subsequence of another string.
 */
bool isSubsequence(string text, string subseq) {
    if (subseq == "") {
        // base case: special isntance of empty subsequence
        return true;
    } else if (text == "") {
        // base case: not a subsequence
        return false;
    } else {
        // recursive case
        if (subseq.substr(0, 1) == text.substr(0, 1)) {
            // first chars match; recursively decompose problem
            //   to simply be evaluation of remaining chars in both strs
            //   (i.e., original strings will be subsequence if remaining
            //   substrings are)
            return isSubsequence(text.substr(1), subseq.substr(1));
        } else {
            // first char of subsequence doesn't match; remove a char in text
            //   and keep looking
            return isSubsequence(text.substr(1), subseq);
        }
    }
}

int main() {
    runTests();

    // Run two extensions to the core original assignment
    runAdvancedSubsequences();
    runSubsequencesC();
    return 0;
}

////////// UNIT TESTS //////////

/*
 * Unit test helper function to determine whether two booleans are equal.
 */
bool assertTrue(const bool expected, const bool actual) {
    if (expected == actual) {
        return true;
    } else {
        cout << "Expected: " << expected << "; Returned: " << actual << endl;
        return false;
    }
}

/*
 * Perform unit tests on the isSubsequence() method.
 */
void runTests() {
    assertTrue(true, isSubsequence("programming", "pin"));
    assertTrue(true, isSubsequence("springtime", "singe"));
    assertTrue(false, isSubsequence("least", "steal"));
    assertTrue(false, isSubsequence("aggreable", "AGREE"));
    assertTrue(false, isSubsequence("kAGREe", "AGREE"));
    assertTrue(false, isSubsequence("team", "i"));
    assertTrue(true, isSubsequence("team", "t"));
    assertTrue(true, isSubsequence("team", "m"));
    assertTrue(true, isSubsequence("team", "a"));
    assertTrue(true, isSubsequence("team", ""));
    assertTrue(true, isSubsequence("", ""));
}

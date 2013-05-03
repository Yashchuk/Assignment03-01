/*
 * File: Subsequences.c
 * ----------------------
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 3 - Pt. 1 - Subsequences (Extension)
 */

/*
 * This extension to Part 1 of assignment 3 implements the subsequences
 *   function in the C language.
 */

#include <stdio.h>
#include <stdbool.h>

/*
 * Return a substring starting from a specific position.
 */
const char* substr(const char* str, int start) {
    return &str[start];
}

/*
 * Recursively determine whether a string is a
 *   subsequence of another string.
 */
bool isSubsequenceC(const char* text, const char* subseq) {
    if (strcmp(subseq, "") == 0) {
        // base case: special isntance of empty subsequence
        return true;
    } else if (strcmp(text, "") == 0) {
        // base case: not a subsequence
        return false;
    } else {
        // recursive case
        if (subseq[0] == text[0]) {
            // first chars match; recursively decompose problem
            //   to simply be evaluation of remaining chars in both strs
            //   (i.e., original strings will be subsequence if remaining
            //   substrings are)
            return isSubsequenceC(substr(text, 1), substr(subseq, 1));
        } else {
            // first char of subsequence doesn't match; remove a char in text
            //   and keep looking
            
            //text.substr(1), subseq
            return isSubsequenceC(substr(text, 1), subseq);
        }
    }
}

/*
 * Run the C-based subsequence function.
 */
void runSubsequencesC() {
    isSubsequenceC("kAGREe", "AGREE");
}

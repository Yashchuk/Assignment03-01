/*
 * File: AdvancedSubsequences.h
 * ----------------------
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 3 - Pt. 1 - Subsequences (Extension)
 */

#ifndef Subsequences_AdvancedSubsequences_h
#define Subsequences_AdvancedSubsequences_h

/*
 * This extension to Part 1 of assignment 3 searches through a container and
 *   finds the a string such that all strings in the container are subsequences
 *   of that other string.
 */

#include <string>
#include "set.h"

/*
 * Recursively determine whether a string is a
 *   subsequence of another string.
 */
bool isSubseq(string text, string subseq) {
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
            return isSubseq(text.substr(1), subseq.substr(1));
        } else {
            // first char of subsequence doesn't match; remove a char in text
            //   and keep looking
            return isSubseq(text.substr(1), subseq);
        }
    }
}

/*
 * Find a string for which every member of a set is itself a subset of that
 *   string. This is not necessarily the smallest.
 */
string runAdvancedSubsequences() {
    Set<string> collection;
    collection += "set", "sesttings", "united";

    Set<string> noSubsets = collection;
    for (string subseq : collection) {
        for (string text : collection) {
            if (text != subseq && isSubseq(text, subseq)) {
                noSubsets.remove(subseq);
            }
        }
    }
    
    string text;
    for (string s : noSubsets) {
        text += s;
    }
    return text;
}

#endif

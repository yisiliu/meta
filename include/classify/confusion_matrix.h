/**
 * @file confusion_matrix.h
 * @author Sean Massung
 */

#ifndef _CONFUSION_MATRIX_H_
#define _CONFUSION_MATRIX_H_

#include <iostream>
#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "meta.h"

namespace meta {
namespace classify {

/**
 * Allows interpretation of classification errors.
 */
class confusion_matrix
{
    public:
        
        /**
         * Creates an empty confusion matrix.
         */
        confusion_matrix();

        /**
         * @param predicted
         * @param actual
         */
        void add(const class_label & predicted, const class_label & actual);

        /**
         * Prints this matrix to cout.
         */
        void print_stats(std::ostream & out = std::cout) const;

        /**
         * Prints this matrix to cout.
         */
        void print(std::ostream & out = std::cout) const;

    private:

        /**
         * Prints precision, recall, and F1 for each class and as a whole.
         * @param out The stream to print to
         * @param label The current class label to get statistics for
         * @param prec The precision for this class
         * @param rec The recall for this class
         * @param f1 The F1 score for this class
         */
        void print_class_stats(std::ostream & out, const class_label & label,
                double & prec, double & rec, double & f1) const;

        /**
         * Implements a hash function for a pair of strings.
         * @param str_pair The pair of strings
         * @return the hash
         */
        static size_t string_pair_hash(const std::pair<std::string, std::string> & strPair);

        /** maps predicted class to actual class frequencies */
        std::unordered_map<std::pair<class_label, class_label>, size_t,
            decltype(&confusion_matrix::string_pair_hash)> _predictions;

        /** keeps track of the number of classes */
        std::unordered_set<class_label> _classes;

        /** how many times each class was predicted */
        std::unordered_map<class_label, size_t> _counts;

        /** total number of classification attempts */
        size_t _total;
};

}
}

#endif

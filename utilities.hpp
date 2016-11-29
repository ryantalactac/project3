#pragma once

#include <fstream>
#include <string>
#include "SearchTree.h"


SearchTree<Entry<string, string>>* buildBST_fromDatafile(const std::string& filename) {
    std::ifstream f(filename.c_str());
    if (!f)
        throw std::runtime_error("cannot open data file");       //throws an error if datafile cannot be opened
    
    std::string s;
    getline(f, s);
    
    std::string magic("CPSC131 Project3 raw data file");
    if (!f || !std::equal(magic.begin(), magic.end(), s.begin()))    //checks to see if the datafile matches the title
       throw std::runtime_error("incorrect data file");
  
   SearchTree<Entry<string, string>> *bst = new SearchTree<Entry<string, string>>;        //create a new search tree
    
    getline(f, s);
    
    while (!f.eof()){
        
        std::string firstName, movie;

        getline(f, firstName, ',');                        //gets the line with a comma delimiter for the first name
        getline(f, movie);                                  //gets the next line with the new line delimiter
        if (movie == ""){                                   //checks if movie is white space
            f.close();
            return bst;
        }
        
        movie.erase(movie.length()-1);                          //deletes the new line after movie
        bst->insert(firstName, movie);                          //inserts entry in search tree
        
    }
    f.close();
    
    return bst;
}

// TO DO: You need to implement a function to print a singly linked list in reverse order
void printInReverseOder(SNode<Entry<string,string> >* node)
{
    if (node) {
        
        printInReverseOder(node->getnext());                       //prints in reverse order recursibely
        std::cout << node->getElem().key() << ":";
        std::cout << node->getElem().value() << ":" << endl;
        
    }
}


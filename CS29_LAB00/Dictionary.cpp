//
//  Dictionary.cpp
//  CS29_LAB00
//
//  Created by Christian on 9/28/20.
//
#include <utility>

#include <stdio.h>
#include <vector>
#include <string>



struct KeyValue : std::pair <int,std::string>
{
public:
    
    int key;
    std::string value;
    
    
    KeyValue()
    {
        key = 0;
        value = " ";
        
    }
    

    
    KeyValue(int n, std::string s)
    {
        key = first = n;
        value = second =  s;
        
        
    }
    
    
    
};

class Dictionary
{
public:
    std::vector<KeyValue> dictionary;
    
    
    
    Dictionary(int newSize)
    {
        dictionary.resize(newSize);
    }
    
    KeyValue &operator[](int key)
    {
        return dictionary[key];
    }
    
    //add more functions
    
    
};

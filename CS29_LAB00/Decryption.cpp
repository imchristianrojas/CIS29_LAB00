
#include <stdio.h>
#include "Dictionary.cpp"
#include <iostream>


class Decryption
{
    
public:
    
    std::string Decrypt(std::vector<KeyValue>::iterator begin,std::vector<KeyValue>::iterator end)
    {
    
        
         int dictSize = 256;
        
        Dictionary dictionary(dictSize);
        
        for(int i = 0; i < dictSize; i++)
        {
            dictionary[i].key = i;
            dictionary[i].value = std::string(1,i);
        }
        
        
        
        std::string word(1,begin++->value[0]);

        std::string result = word;
        std::string entry;
        
        
        int myKey;
        
        while(begin != end)
        {
            myKey = begin->key;
            
            if(myKey>=0 && myKey < dictSize)
                entry = dictionary[myKey].value;
            else if(myKey == dictSize)
                entry = word + word[0];
            else
                throw "Invalid Key";
            
            result += entry;
            
            dictionary[dictSize].value = word + entry[0];
            
            dictSize++;
            word = entry;
            begin++;
            
            
                
            
        }
        
        std::cout<<result<<std::endl;
        return result;
    
    }
    
    
};

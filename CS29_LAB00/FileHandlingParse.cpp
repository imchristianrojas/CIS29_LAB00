//
//  FileHandlingParse.cpp
//  CS29_LAB00
//
//  Created by Christian on 9/28/20.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "Decryption.cpp"


using namespace std;

class FileHandling
{
    
private:
    std::string fileName;
    fstream myFile;
    
public:
    
    
    FileHandling(std::string fn)
    {
        fileName = fn;
        
    }
    
    void openFile()
    {
        
        
        myFile.open(fileName);
        ofstream outPutFile;
        outPutFile.open("test.txt");
        
        
        if(myFile.fail())
        {
            cerr<<"Cannot Open File! "<<endl;
            exit(1);
            
        }
        
        vector<KeyValue>container;
        
        std::string feeder;
        
        int def = 0;
        
        while(!myFile.eof())
        {
            getline(myFile, feeder,',');
            
            if(feeder == " ")
                std::cout<<"\n  "<<std::endl;
                else{
            KeyValue val(stoi(feeder),feeder);
            container.push_back(val);
                }
            

           // outPutFile << feeder <<" "<<endl;
            
            def++;
            
            
        
        }
        
        
        Decryption mo;
        
        mo.Decrypt(container.begin(), container.end());
        
        
        
        
        
    }
    
    void closeFile()
    {
        
        myFile.close();     
        
    }
    

    
    
   
    
    
};

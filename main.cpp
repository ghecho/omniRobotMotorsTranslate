//
//  main.cpp
//  motorsTranslate
//
//  Created by Diego on 9/1/13.
//  Copyright (c) 2013 Diego. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, const char * argv[])
{
    vector<string> valores;
    string cadena;
    int numLinea=1;
    float l,r,t;
    float elapsedTime=0.0;
    ifstream infile ("/Users/diego/Desktop/in.m");
    ofstream outFile ("/Users/diego/Desktop/out.m");
        
    if (infile.is_open() && outFile.is_open())
    {
        outFile << "function [dphi1, dphi2] = motores(t,ZZ,r,l)\n\ndphi1 = 0;\ndphi2 = 0;\n\n";
        while (infile.good())
        {
            getline(infile, cadena);
            valores=split(cadena, ',');
            l=0.0;
            r=0.0;
            t=0.0;
            if(valores.size()!=3)
            {
                cerr << "Error en la linea: " << numLinea << endl;
                return 1;
            }
            else
            {
                l=::atof(valores[0].c_str());
                r=::atof(valores[1].c_str());
                t=::atof(valores[2].c_str());
                
                outFile << "if t>=" << elapsedTime << " && t<" << elapsedTime+t << endl << "dphi1 = " << r << ";\ndphi2 = " << l << ";\nend\n\n";
                
                elapsedTime+=t;
            }
            
            numLinea++;
        }
        
        infile.close();
        outFile.close();
    }
    else cout << "Unable to open file";
    
    return 0;
}



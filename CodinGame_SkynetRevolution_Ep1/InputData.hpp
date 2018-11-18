//
//  InputData.hpp
//  CodinGame_SkynetRevolution_Ep1
//
//  Created by Woody on 07/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#pragma once

#include <vector>
#include <string>

using namespace std;

struct InputData{
public:
    InputData() = default;
    InputData(int nods, int links, int exits);
    
    void AddLink(const int n1, const int n2);
    string CheckAndRemoveLink(const int & virusPosition, const bool usingAStar = false);
    void AddExit(const int exit);
    
    int NumberOfNods() const;
    int NumberOfLinks() const;
    int NumberOfExits() const;
    vector< vector<int> > GetLinks() const;
    vector<int> GetExits() const;
    
private:
    int numberOfNods = 0;
    int numberOfLinks = 0;
    int numberOfExits = 0;
    vector< vector<int> > links;
    vector<int> exits;
    
    //Scynet Revolution Episode1 solution:
    //https://www.codingame.com/ide/puzzle/skynet-revolution-episode-1
    int GetLinkIndexToRemove(const int & virusPos);
    
    //Scynet Revolution Episode2 solution:
    //https://www.codingame.com/ide/puzzle/skynet-revolution-episode-2
    int GetLinkIndexToRemoveByShortestWay(const int & virusPos);

};

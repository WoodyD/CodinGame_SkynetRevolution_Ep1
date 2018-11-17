//
//  main.cpp
//  CodinGame_SkynetRevolution_Ep1
//
//  Created by Woody on 07/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//
//  Test cases here:
//  https://www.codingame.com/ide/puzzle/skynet-revolution-episode-1

#include <iostream>
#include <string>
#include <vector>

#include "InputData.hpp"

using namespace std;

int main()
{
    int N; cerr << "N - the total number of nodes in the level, including the gateways" << endl;
    int L; cerr << "L - the number of links" << endl;
    int E; cerr << "E - the number of exit gateways" << endl;
    cerr << "Enter N L E: " << endl;
    cin >> N >> L >> E; cin.ignore();
    
    InputData data(N, L, E);
    
    cerr << "N1 and N2 defines a link between these nodes. " << endl;
    for (int i = 0; i < L; i++) {
        int N1; cerr << "Enter N1 N2: " << endl;
        int N2;
        cin >> N1 >> N2; cin.ignore();
        data.AddLink(N1, N2);
    }
    
    for (int i = 0; i < E; i++) {
        int EI; cerr << "Enter the index of a gateway node: " << endl;
        cin >> EI; cin.ignore();
        data.AddExit(EI);
    }
    
    // game loop
    while (1) {
        int SI; cerr << "The index of the node on which the Skynet agent is positioned this turn :" << endl;
        cin >> SI; cin.ignore();
        
        string link = data.CheckAndRemoveLink(SI);
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << link << endl;
    }
}


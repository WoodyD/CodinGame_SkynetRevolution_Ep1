//
//  main.cpp
//  CodinGame_SkynetRevolution_Ep1
//
//  Created by Woody on 07/11/2018.
//  Copyright © 2018 Woody. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "InputData.hpp"

using namespace std;

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    InputData data(N, L, E);
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        data.AddLink(vector<int>(N1, N2));
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        data.AddExit(EI);
    }
    
    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << "0 1" << endl;
    }
}

//
//  main.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 06/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include <iostream>

#include "Controller1_Intro.hpp"

#include "LifeCycle.hpp"

int main(int argc, const char * argv[]) {
   
    LifeCycle lifeCycle;
    
    lifeCycle.InitMedia();
    
    lifeCycle.Play();
    
    
    return 0;
}

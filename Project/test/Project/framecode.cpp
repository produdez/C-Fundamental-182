//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "core.h"

void Process() {
    LoadConfiguration();// load program configuration before starting
    while (!__isExiting) {
        DisplayMenu();
        ProcessUserChoice();
   }
}

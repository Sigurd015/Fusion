#include "Test.h"

#include <iostream>

void DefaultTest::OnAttach()
{
    std::cout << "DefaultTest::OnAttach\n";
}

void DefaultTest::OnUpdate(float deltaTime)
{
    //std::cout << "DefaultTest::OnUpdate: " << deltaTime << "s\n";
}

void DefaultTest::OnDetach()
{
    std::cout << "DefaultTest::OnDetach\n";
}
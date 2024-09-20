#pragma once

class BaseTest
{
public:
    BaseTest() = default;
    ~BaseTest() = default;

    virtual void OnAttach() = 0;
    virtual void OnUpdate(float deltaTime) = 0;
    virtual void OnDetach() = 0;
};

class DefaultTest : public BaseTest
{
public:
    DefaultTest() = default;
    ~DefaultTest() = default;

    void OnAttach() override;
    void OnUpdate(float deltaTime) override;
    void OnDetach() override;
};
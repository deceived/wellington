#include "order_component.hpp"

const std::string OrderComponent::name_ = "OrderComponent";


bool OrderComponent::Init(Properties::ptr data)
{
    return true;
}

bool OrderComponent::Init(Properties::pointer data)
{
    return true;
}

void OrderComponent::PostInit()
{
}

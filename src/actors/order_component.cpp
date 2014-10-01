#include "order_component.hpp"

const std::string OrderComponent::name_ = "OrderComponent";


bool OrderComponent::Init(Properties::ptr data)
{
    return true;
}

void OrderComponent::PostInit()
{
}

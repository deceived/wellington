#include "order_component.hpp"

const std::string OrderComponent::name_ = "OrderComponent";



bool OrderComponent::Init(pugi::xml_node data)
{
    return true;
}

void OrderComponent::PostInit()
{
}

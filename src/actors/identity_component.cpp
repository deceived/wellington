#include "identity_component.hpp"

const std::string IdentityComponent::name_ = "IdentityComponent";


bool IdentityComponent::Init(Properties::ptr data)
{
    return true;
}

bool IdentityComponent::Init(Properties::pointer data)
{
    return true;
}

void IdentityComponent::PostInit()
{
}

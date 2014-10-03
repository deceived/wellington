#include "identity_component.hpp"

const std::string IdentityComponent::name_ = "IdentityComponent";


bool IdentityComponent::Init( pugi::xml_node data )
{
    return true;
}

void IdentityComponent::PostInit()
{
}

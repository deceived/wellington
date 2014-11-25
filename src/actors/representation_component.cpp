#include "representation_component.hpp"

const std::string RepresentationComponent::name_ = "RepresentationComponent";


bool RepresentationComponent::Init( pugi::xml_node data )
{
    return true;
}

void RepresentationComponent::PostInit()
{
}

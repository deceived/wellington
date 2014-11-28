#include "identity_component.hpp"

extern Log logger;

const std::string IdentityComponent::name_ = "IdentityComponent";


bool IdentityComponent::Init( pugi::xml_node data )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );
    }
    return true;
}

void IdentityComponent::PostInit()
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

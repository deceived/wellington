#include "fire_component.hpp"

extern Log logger;

const std::string FireComponent::name_ = "FireComponent";



bool FireComponent::Init(pugi::xml_node data)
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );
    }
    return true;
}

void FireComponent::PostInit()
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

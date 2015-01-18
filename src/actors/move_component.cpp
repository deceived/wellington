#include "move_component.hpp"

extern Log logger;

const std::string MoveComponent::name_ = "MoveComponent";



bool MoveComponent::Init(pugi::xml_node data)
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
    return true;
    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );
        if( child.name() == std::string( "Front" ) )
        {
	    	front_ = boost::lexical_cast<std::size_t>( child.child_value() );
        }
        if( child.name() == std::string( "Normal" ) )
        {
	    	normal_ = boost::lexical_cast<std::size_t>( child.child_value() );
		}
        if( child.name() == std::string( "Action" ) )
		{
	    	action_ = boost::lexical_cast<std::size_t>( child.child_value() );
		}
        if( child.name() == std::string( "StartX" ) )
		{
	    	startX_ = boost::lexical_cast<int>( child.child_value() );
		}
        if( child.name() == std::string( "StartY" ) )
		{
	    	startY_ = boost::lexical_cast<int>( child.child_value() );
		}
    }
}

void MoveComponent::PostInit()
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
}

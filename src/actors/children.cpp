    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );
    }

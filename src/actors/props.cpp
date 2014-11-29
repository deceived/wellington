        if( child.name() == std::string( "Type" ) )
        {
	    weapon_ = child.child_value();
        }
        if( child.name() == std::string( "Range" ) )
        {
            if( child.child_value() == std::string( "NA" ) )
 	    {
		range_ = 0;
	    }
	    else
	    {
	        range_ = boost::lexical_cast<std::size_t>( child.child_value() );
 	    }
        }

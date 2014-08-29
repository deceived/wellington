#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/smart_ptr.hpp>

class ICommand
{

public:

    virtual ~ICommand()
    {}
 
    virtual void Execute() = 0;
    virtual std::string ToString() = 0;
};

/***

  move [to <destination>] [via <location>]* 
  move [for <distance> to the <compass direction>] [via <location>]*
  move [towards <destination>] [via <location>]*

***/
class MoveCommand : public ICommand
{

public:

    MoveCommand( const std::vector< std::string >& commands )
        : commands_( commands )
    {
        ParseCommands();
    }

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return commands_[0];
    }
    
private:

    void ParseCommands()
    {
    }

    std::vector< std::string > commands_;

    std::string destination_;
    std::list< std::string > location_;
    std::string direction_;
    unsigned int distance_;

};


/***

    attack [if inferior force encountered] || [if no alternative] [<unit specification> [at <location>]]
    defend [at <location>] || [if attacked [and retreat [to <location>]]] 

***/
class EngagementCommand : public ICommand
{

public:

    EngagementCommand( const std::vector< std::string >& commands )
        : commands_( commands )
    {
        ParseCommands();
    }

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return commands_[0];
    }

private:

    void ParseCommands()
    {
    }

    std::string location_;
    std::vector< std::string > commands_;

};

/***
    ldrules <filename>
    ldmap <filename>
    ldunits <filename> 
    ldmoves <filename> 

***/



class LoadRulesCommand : public ICommand
{

public:

    LoadRulesCommand( const std::vector< std::string >& commands )
        : commands_( commands )
    {
        ParseCommands();
    }

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return commands_[0];
    }

private:

    void ParseCommands()
    {
    }

    std::vector< std::string > commands_;
};



class LoadMapCommand : public ICommand
{

public:

    LoadMapCommand( const std::vector< std::string >& commands )
        : commands_( commands )
    {
        ParseCommands();
    }

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return commands_[0];
    }

private:

    void ParseCommands()
    {
        
    }

    std::vector< std::string > commands_;
};



class LoadUnitsCommand : public ICommand
{

public:

    LoadUnitsCommand( const std::vector< std::string >& commands )
        : commands_( commands )
    {
        ParseCommands();
    }

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return commands_[0];
    }

private:

    void ParseCommands()
    {
    }

    std::vector< std::string > commands_;
};



class LoadMovesCommand : public ICommand
{

public:

    LoadMovesCommand( const std::vector< std::string >& commands )
        : commands_( commands )
    {
        ParseCommands();
    }

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return commands_[0];
    }

private:

    void ParseCommands()
    {
    }

    std::vector< std::string > commands_;
};



class CommandFactory
{

public:

    static boost::shared_ptr<ICommand> Create( std::vector<std::string>& params )
    {
        if( params[0] == "move" )
        {
            return boost::make_shared<MoveCommand>( params ); 
        }
        if( params[0] == "defend" )
        {
            return boost::make_shared<EngagementCommand>( params ); 
        }
        if( params[0] == "attack" )
        {
            return boost::make_shared<EngagementCommand>( params ); 
        }
        if( params[0] == "ldmap" )
        {
            return boost::make_shared<LoadMapCommand>( params );
        }
        if( params[0] == "ldunits" )
        {
            return boost::make_shared<LoadUnitsCommand>( params );
        }
        if( params[0] == "ldrules" )
        {
            return boost::make_shared<LoadRulesCommand>( params );
        }
        if( params[0] == "ldmoves" )
        {
            return boost::make_shared<LoadMovesCommand>( params );
        }

        return boost::shared_ptr<ICommand>();
    }
 
};

boost::shared_ptr<ICommand>   ParseCommand( const std::string& line )
{
    std::vector< std::string > split_vector;

    boost::split(  split_vector, line, boost::is_any_of( " " ) );
   
    return CommandFactory::Create( split_vector );
}

#endif

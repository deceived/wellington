#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/smart_ptr.hpp>

using namespace boost;

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
  move [<compass direction>] [for <distance>] [via <location>]
  move [towards <destination`>] [via <location>]*

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

    attack [if inferior force encountered] || [if no alternative] || [<unit specification>] [at <location>] 
    defend [position] || [if attacked [and retreat [to <location>]]] 

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


class CommandFactory
{

public:

    static shared_ptr<ICommand> Create( std::vector<std::string>& params )
    {
        if( params[0] == "move" )
        {
            return make_shared<MoveCommand>( params ); 
        }
        if( params[0] == "defend" )
        {
            return make_shared<EngagementCommand>( params ); 
        }
        if( params[0] == "attack" )
        {
            return make_shared<EngagementCommand>( params ); 
        }
        return shared_ptr<ICommand>();
    }
 
};

shared_ptr<ICommand>   ParseCommand( const std::string& line )
{
    std::vector< std::string > split_vector;

    split(  split_vector, line, is_any_of( " " ) );
   
    return CommandFactory::Create( split_vector );
}

int main( int argc, char** argv )
{

    std::string line;

    do
    {
        std::cout << ". ";
        std::getline( std::cin, line );

        shared_ptr<ICommand> command = ParseCommand( line );

        if( command != 0 )
        {
            std::cout << command->ToString() << std::endl;
        }

    } while( line != "done" );    

    return 0;
}

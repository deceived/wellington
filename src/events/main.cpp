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

class MoveCommand : public ICommand
{

public:

    MoveCommand( const std::string& command )
        : command_( command )
    {}

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return command_;
    }
    
private:

// state
    std::string command_;

};

class EngagementCommand : public ICommand
{

public:

    EngagementCommand( const std::string& command )
        : command_( command )
    {}

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return command_;
    }

private:

// state
    std::string command_;

};

class ExitCommand : public ICommand
{

public:

    ExitCommand( const std::string& command )
        : command_( command )
    {}

    virtual void Execute()
    {}

    virtual std::string ToString()
    {
        return command_;
    }

private:

// state
    std::string command_;

};

class CommandFactory
{

public:

    static shared_ptr<ICommand> Create( const std::string name )
    {
        if( name == "move" )
        {
            return make_shared<MoveCommand>( name ); 
        }
        if( name == "defend" )
        {
            return make_shared<EngagementCommand>( name ); 
        }
        if( name == "attack" )
        {
            return make_shared<EngagementCommand>( name ); 
        }
        return shared_ptr<ICommand>();
    }
 
};

shared_ptr<ICommand>   ParseCommand( const std::string& line )
{
    std::vector< std::string > split_vector;

    split(  split_vector, line, is_any_of( " " ) );
    
    return CommandFactory::Create( split_vector[0] );
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

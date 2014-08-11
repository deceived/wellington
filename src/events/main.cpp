#include <iostream>
#include <string>

class ICommand
{

public:

    virtual ~ICommand();
 
    virtual void Execute() = 0;

};

class MoveCommand : public ICommand
{

public:

    virtual void Execute();

private:

// state

};

class EngagementCommand : public ICommand
{

public:

    virtual void Execute();

private:

// state

};

class ExitCommand : public ICommand
{

public:

    virtual void Execute();

private:

// state

};


ICommand*   ParseCommand( const std::string& line )
{
    return 0;
}

int main( int argc, char** argv )
{

    std::string line;

    do
    {
        std::cout << ". ";
        std::getline( std::cin, line );

        ICommand* command = ParseCommand( line );

        std::cout << line << std::endl;

    } while( line != "done" );    

    return 0;
}

#ifndef UNITS_HPP
#define UNITS_HPP



class   IUnit
{

public:

    virtual unsigned int Range() = 0;

    virtual unsigned int Move() = 0;
    virtual unsigned int Charge() = 0;
    virtual unsigned int Manhandled() = 0;

    virtual unsigned int Front() = 0;

    virtual unsigned int Points() = 0;
};



class   Riflemen    : public IUnit
{

public:

private:

};

class   LightInfantry : public IUnit
{

public:

private:

};

class   LineInfantry : public IUnit
{

public:

private:

};





class   RocketArtillery : public IUnit
{

public:

private:

};

class   SeigeArtillery : public IUnit
{

public:

private:

};

class   HeavyFieldArtillery : public IUnit
{

public:

private:

};

class   LightFieldArtillery : public IUnit
{

public:

private:

};

class   HeavyHorseArtillery : public IUnit
{

public:

private:

};

class   LightHorseArtillery : public IUnit
{

public:

private:

};




class  General : public IUnit 
{

public:

    virtual unsigned int Range()
    {
        return 0;
    }

    virtual unsigned int Move()
    {
        return 140;
    }

    virtual unsigned int Charge()
    {
        return 260;
    }

    virtual unsigned int Manhandled()
    {
        return 0;
    }

    virtual unsigned int Front()
    {
        return 20;
    }

    virtual unsigned int Points()
    {
        return 75;
    }

private:

};

class  Officer : public IUnit 
{

public:

    virtual unsigned int Range()
    {
        return 0;
    }

    virtual unsigned int Move()
    {
        return 140;
    }

    virtual unsigned int Charge()
    {
        return 260;
    }

    virtual unsigned int Manhandled()
    {
        return 0;
    }

    virtual unsigned int Front()
    {
        return 20;
    }

    virtual unsigned int Points()
    {
        return 50;
    }

private:

};

class  HeavyCavalry : public IUnit
{

public:

    virtual unsigned int Range()
    {
        return 0;
    }

    virtual unsigned int Move()
    {
        return 100;
    }

    virtual unsigned int Charge()
    {
        return 240;
    }

    virtual unsigned int Manhandled()
    {
        return 0;
    }

    virtual unsigned int Front()
    {
        return 25;
    }

    virtual unsigned int Points()
    {
        return 5;
    }


private:

};

class  MediumCavalry : public IUnit
{

public:

    virtual unsigned int Range()
    {
        return 0;
    }

    virtual unsigned int Move()
    {
        return 100;
    }

    virtual unsigned int Charge()
    {
        return 240;
    }

    virtual unsigned int Manhandled()
    {
        return 0;
    }

    virtual unsigned int Front()
    {
        return 25;
    }

    virtual unsigned int Points()
    {
        return 5;
    }


private:

};

class  LightCavalry : public IUnit
{

public:

    virtual unsigned int Range()
    {
        return 0;
    }

    virtual unsigned int Move()
    {
        return 140;
    }

    virtual unsigned int Charge()
    {
        return 260;
    }

    virtual unsigned int Manhandled()
    {
        return 0;
    }

    virtual unsigned int Front()
    {
        return 25;
    }

    virtual unsigned int Points()
    {
        return 5;
    }


private:

};

class  Lancers : public IUnit 
{

public:

private:

};



#endif


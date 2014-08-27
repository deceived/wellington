#ifndef UNITS_HPP
#define UNITS_HPP

class   IUnit
{

public:

    unsigned int Range();

    unsigned int Move();
    unsigned int Charge();
    unsigned int Manhandled();

};

class   Infantry    : public IUnit
{

public:

private:

};

class   Riflemen    : public Infantry
{

public:

private:

};

class   Light : public Infantry
{

public:

private:

};

class   Line : public Infantry 
{

public:

private:

};





class   Artillery   : public IUnit
{

public:

private:

};

class   Rocket : public Artillery
{

public:

private:

};

class   Seige : public Artillery
{

public:

private:

};

class   HeavyField : public Artillery
{

public:

private:

};

class   LightField : public Artillery
{

public:

private:

};

class   HeavyHorse : public Artillery
{

public:

private:

};

class   LightHorse : public Artillery
{

public:

private:

};




class   Cavalry : public IUnit
{

public:

private:

};

class  Officer : public Cavalry
{

public:

private:

};

class  Heavy : public Cavalry
{

public:

private:

};

class  Medium : public Cavalry
{

public:

private:

};

class  Light : public Cavalry
{

public:

private:

};

class  Lancers : public Cavalry
{

public:

private:

};



#endif


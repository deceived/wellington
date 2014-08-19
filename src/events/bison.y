%{

%}

%%

command :   move move_qualifiers 
        |   attack attack_qualifiers
        |   defend defend_qualifiers
        ;

move_qualifiers :   TO destination VIA location
                |   FOR distance TO THE compass_direction VIA location
                |   TOWARDS destination VIA location
                ;

attack_qualifiers   :   IF INFERIOR FORCE ENCOUNTERED
                    |   IF NO ALTERNATIVE
                    |   unit AT location 
                    ;

defend_qualifiers   :   AT location
                    |   IF ATTACKED AND RETREAT TO location
                    ;



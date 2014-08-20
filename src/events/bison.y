%{


%oken   MOVE,
   ATTACK,
   TO,
   TO_THE,
   VIA,
   FOR,
   TOWARDS,
   THE,
   N,
   S,
   E,
   W,
   NW,
   NE,
   SW,
   SE,
   M,
   YD,
   IF_INFERIOR_FORCE_ENCOUNTERED,
   IF_NO_ALTERNATIVE,
   AT,
   IF_ATTACKED,
   AND_RETREAT,
   DEFEND,
   POSITION,
   LOCATION,
   UNIT_SPECIFICATION,
   PERIOD

%%

command :   MOVE move_qualifiers PERIOD 
        |   ATTACK attack_qualifiers PERIOD
        |   DEFEND defend_qualifiers PERIOD
        ;

move_qualifiers :   TO destination location_list 
                |   FOR distance TO_THE compass_direction location_list 
                |   TOWARDS destination location_list 
                ;

location_list   :   
                |   location_list VIA location
                ;

compass_direction   :   N
                    |   S
                    |   E
                    |   W
                    |   NW
                    |   NE
                    |   SW
                    |   SE
                    ;

attack_qualifiers   :   IF_INFERIOR_FORCE_ENCOUNTERED
                    |   IF_NO_ALTERNATIVE
                    |   unit AT location 
                    ;

defend_qualifiers   :   AT location
                    |   IF_ATTACKED 

retreat_clause      :   
                    |   AND_RETREAT to_location
                    |   AND_RETREAT location_list
                    ;

to_location         :
                    |   TO location location_list
                    ;

distance            :   M
                    |   YD 
                    ;

location            :   WORD
                    ;

unit                :   UNIT_SPECIFICATION
                    ;


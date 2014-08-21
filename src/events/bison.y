%token   MOVE
   ATTACK
   TO
   VIA
   FOR
   TOWARDS
   THE
   N
   S
   E
   W
   NW
   NE
   SW
   SE
   M
   YD
   IF
   AND
   INFERIOR
   FORCE
   ENCOUNTERED
   NO
   ALTERNATIVE
   AT
   ATTACKED
   RETREAT
   DEFEND
   POSITION
   LOCATION
   UNIT_SPECIFICATION
   PERIOD
   WORD

%%

command :   MOVE move_qualifiers PERIOD 
        |   ATTACK attack_qualifiers PERIOD
        |   DEFEND defend_qualifiers PERIOD
        ;

move_qualifiers :   TO location location_list 
                |   FOR distance TO THE compass_direction location_list 
                |   TOWARDS location location_list 
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

attack_qualifiers   :   IF INFERIOR FORCE ENCOUNTERED
                    |   IF NO ALTERNATIVE
                    |   unit AT location 
                    ;

defend_qualifiers   :   AT location
                    |   IF ATTACKED retreat_clause
                    ;

retreat_clause      :   
                    |   AND RETREAT retreat_location 
                    ;

retreat_location    :
                    |   TO location
                    |   location_list TO location
                    ;

distance            :   M
                    |   YD 
                    ;

location            :   WORD
                    ;

unit                :   UNIT_SPECIFICATION
                    ;


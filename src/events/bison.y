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
   NUMBER
   WORD

%%

command             :   MOVE move_qualifiers PERIOD
                    |   ATTACK attack_qualifiers PERIOD
                    |   DEFEND defend_qualifiers PERIOD
                    ;

move_qualifiers     :   TO location location_list
                    |   FOR distance TO THE compass_direction location_list
                    |   TOWARDS location location_list
                    ;

location            :   WORD
                    ;

location_list       :   
                    |   location_list VIA location
                    ;

distance            :   NUMBER unit
                    ;

unit                :   M
                    |   YD
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

attack_qualifiers   :   IF if_commands 
                    |   unit_name AT location 
                    ;

if_commands         :   INFERIOR FORCE ENCOUNTERED
                    |   NO ALTERNATIVE
                    ;

unit_name           :   UNIT_SPECIFICATION
                    ;

defend_qualifiers   :   AT location
                    |   IF ATTACKED retreat_clause
                    ;

retreat_clause      :   
                    |   AND RETREAT retreat_location 
                    ;

retreat_location    :
                    |   location_list TO location
                    ;


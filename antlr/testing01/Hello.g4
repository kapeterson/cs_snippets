grammar Hello;


r: 'hello' ID;
ID : [a-z0-9A-Z];
WS : [ \t\r\n]+ -> skip;

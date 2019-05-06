-module(cw5).
-export([move/3,solve/2]).

move(A,B,C)->
	B1={element(1,B),element(2,B)++[lists:last(element(2,A))]},
	A1={element(1,A),lists:sublist(element(2,A),(lists:flatlength(element(2,A))-1))},
	io:format("~w:~p~n",[element(1,A1),element(2,A1)]),
	io:format("~w:~p~n",[element(1,B1),element(2,B1)]),
	io:format("~w:~p~n~n",[element(1,C),element(2,C)]),
	{A1,B1,C}.

%cw5:solve(3,{{tower1,[3,2,1]},{tower2,[]},{tower3,[]}}).

solve(N,T)->
if
	N==1 -> 
		move(element(1,T),element(2,T),element(3,T));
	N>1 ->
		%io:format("~p,~p,~p~n",[element(1,T),element(3,T),element(2,T)]),
		T1=solve(N-1,{element(1,T),element(3,T),element(2,T)}),
		T_1={element(1,T1),element(3,T1),element(2,T1)},
		io:format("~p~n",[T_1]),
		T2=move(element(1,T_1),element(2,T_1),element(3,T_1)),	
		T3=solve(N-1,{element(3,T2),element(2,T2),element(1,T2)}),
		{element(3,T3),element(2,T3),element(1,T3)}
end.
	
	
-module(cw3).
-export([move/2]).

move(A,B)->
	B1=B++[lists:last(A)],
	A1=lists:sublist(A,(lists:flatlength(A)-1)),
	io:format("A:~p~n",[A1]),
	io:format("B:~p~n",[B1]).

	


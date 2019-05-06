-module(cw4).
-export([create/1,create_towers/1,display_towers/1,move/2,solve/1]).

create(0)->[];
create(X)->
	[X|create(X-1)].

create_towers(M)->
	{{tower1,lists:reverse(create(M))},{tower2,[]},{tower3,[]}}.

display_towers(T)->
	io:format("tower1:~p~n",[lists:reverse(element(2,element(1, T)))]),
	io:format("tower2:~p~n",[element(2,element(2, T))]),
	io:format("tower3:~p~n",[element(2,element(3, T))]).

move(A,B)->
	B1=B++[lists:last(A)],
	A1=lists:sublist(A,(lists:flatlength(A)-1)),
	io:format("A:~p~n",[A1]),
	io:format("B:~p~n",[B1]).

solve(N,A,B,C)->
if
	N<=0 -> io:format("Finished.~n");
	N=1 -> move(A,C);
	N>1 ->
		move(A,B);
		move(A,C);
		move(B,C);
		solve(N-1)
end.

driver(T)->
	
	
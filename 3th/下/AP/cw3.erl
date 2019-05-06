-module(cw1).
-export([create/1,create_towers/1,display_towers/1,move/3,solve/2]).

%This project realize the hanoi tower through create,create_towers,display_towers,move,solve functions
%"create" function can create a decreasing list by input the length of list
create(0)->[];
create(X)->
	[X|create(X-1)].

%"create_towers" function can represents the number of disks in the tower by input the length of list
%It can invoke "create" function automatically
create_towers(M)->
	{{tower1,create(M)},{tower2,[]},{tower3,[]}}.

%"display_towers" function can take a representation of tower state and print it to the screen
display_towers(T)->
	io:format("~p:~p~n",[element(1,element(1, T)),element(2,element(1, T))]),
	io:format("~p:~p~n",[element(1,element(2, T)),element(2,element(2, T))]),
	io:format("~p:~p~n~n",[element(1,element(3, T)),element(2,element(3, T))]).

%"move" function can move the top disk from a given tower to another tower
move(A,B,C)->
	B1={element(1,B),element(2,B)++[lists:last(element(2,A))]}, %move the top disk from A given tower B
	A1={element(1,A),lists:sublist(element(2,A),(lists:flatlength(element(2,A))-1))}, %remove the top disk from A
	display_towers({A1,B1,C}), %show the state
	{A1,B1,C}.

%"solve" function solve the puzzle using the recursive solution and show a representation of the completed game state
solve(N,T)->
if
	N==1 -> 
		move(element(1,T),element(2,T),element(3,T)); %Move the n-1 disk from B to C
	N>1 ->
		T1=solve(N-1,{element(1,T),element(3,T),element(2,T)}), %Move the n-1 disk to from A to B
		T_1={element(1,T1),element(3,T1),element(2,T1)}, %Keep the monment state of squence of disk
		T2=move(element(1,T_1),element(2,T_1),element(3,T_1)),	%Move the bottom disk to from A to C
		T3=solve(N-1,{element(3,T2),element(2,T2),element(1,T2)}), %Move the n-1 disk from A to C
		{element(3,T3),element(2,T3),element(1,T3)} %Keep the monment state of squence of disk
end.	

%test: T=cw1:create_towers(3).  cw1:display_towers(T). cw1:solve(3,{{tower1,[3,2,1]},{tower2,[]},{tower3,[]}}).
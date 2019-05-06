-module(cw2).
-export([create/1]).

create(0)->[];
create(X)->
	[X|create(X-1)].

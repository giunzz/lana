for /l %%i in (1,1,40) do (
	md %%i
	ren %%i.inp robots.inp
	robots <robots.inp >robots.out
	move robots.inp %%i/robots.inp
	move robots.out %%i/robots.out
)
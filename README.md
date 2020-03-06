# Without any optimization 
```
nirmoy@brihaspati:~/SwitchvsMap> gcc main.c
nirmoy@brihaspati:~/SwitchvsMap> ./a.out
TESTING data size 100000
0.000528 sec, total time taken by static map conversion
0.001396 sec, total time taken by switch conversion
TESTING data size 100000
0.000390 sec, total time taken by static map conversion
0.001409 sec, total time taken by switch conversion
TESTING data size 1000000
0.002703 sec, total time taken by static map conversion
0.007394 sec, total time taken by switch conversion
```
# with O2 optimization
```
nirmoy@brihaspati:~/SwitchvsMap> gcc main.c -O2
nirmoy@brihaspati:~/SwitchvsMap> ./a.out
TESTING data size 100000
0.000206 sec, total time taken by static map conversion
0.000137 sec, total time taken by switch conversion
TESTING data size 100000
0.000075 sec, total time taken by static map conversion
0.000142 sec, total time taken by switch conversion
TESTING data size 1000000
0.000873 sec, total time taken by static map conversion
0.000746 sec, total time taken by switch conversion
```
# with O3 optimization
```
nirmoy@brihaspati:~/SwitchvsMap> gcc main.c -O3
nirmoy@brihaspati:~/SwitchvsMap> ./a.out
TESTING data size 100000
0.000198 sec, total time taken by static map conversion
0.000029 sec, total time taken by switch conversion
TESTING data size 100000
0.000075 sec, total time taken by static map conversion
0.000028 sec, total time taken by switch conversion
TESTING data size 1000000
0.001059 sec, total time taken by static map conversion
0.000379 sec, total time taken by switch conversion
```

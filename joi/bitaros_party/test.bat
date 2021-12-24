@echo off
gen >int 
copy int int_backup
bf <int >bf_out 
sol <int >sol_out
fc sol_out bf_out
if errorlevel 0 test
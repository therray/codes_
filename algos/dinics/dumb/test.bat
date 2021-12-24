@echo off
gen >int
matching <int >out
kactl <int >kout
fc out kout > nul
if errorlevel 1 exit
test

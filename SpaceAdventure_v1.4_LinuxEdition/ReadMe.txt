The makefile is in the Debug Folder

Fix:
1) error: XDG_RUNTIME_DIR not set in the environment

open eclipse settings and try setting up environment variable "XDG_RUNTIME_DIR" as "/run/user/1000" and apply.

open drop down menu near to "Run button" -->den open "Run configuration" --> open "Environment" -->> "new" >> variable as "XDG_RUNTIME_DIR" and value as "/run/user/1000"

2)Set the credits from the credit menu to be updated with the value from the xml file, or set to 0 if the file is not present

TODO:
Update the credits in View3_Slot after the bonus game ends
Check why Bonus Games behaves strangely when a win occurrs

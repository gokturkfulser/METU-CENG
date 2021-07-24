Grader usage:

Put the files mygrader.properties, logisim.jar and e1234567.circ in the same folder

To run the grader:

Open powershell and go to your directory ( using cd ) to run this code

java -jar logisim.jar -grader mygraderfile.properties e1234567.circ

If there is any non-gradable problem (a pin cannot be found, etc), the grader will exit with a non-zero status. Error
messages are printed to STDERR, grading messages are printed to STDOUT.

In the first line, "CHIPS PASS" or "CHIPS FAIL" is printed based on allowed chips & chips in the file.

When a run passes thru its last state, "PASS" is printed. If a run fails (if a "set-inputs & check-outputs" state fails,
or if maximum loop limit is reached for conditional jump states), "FAIL" is printed.

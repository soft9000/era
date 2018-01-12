Once we have installed cygwin, we can use ezlog.run
outside of cygwin.

There are several ways to do so, but since cygwin's DLL 
support files are now hidden, the easiest way to use
EZLOG as a console application under Microsoft Windows
at the moment is to: 

(1) Download era & make cpp_logger.
(2) Rename the ezlog.run to ezlog.exe
(3) Copy ezlog.exe into your cygwin folder (*)
(4) Update your %PATH% to include your cygwin folder
(5) Close & re-open any command-line sessions!

In addition to CYGWIN proper, you will now be able to 
run ezlog (as well as many other cygwin tools!) from 
a MSDOS Console application, as well.


PATH MANAGEMENT (Microsoft Windows)
===============
(*) Rather than using the POSIX `find,` we can use 
the ATTRIB command discover where the cygwin folder 
is:

ATTRIB C:\c++.exe /S

Since our GNU C++ compiler was located in c:\cygwin64\bin 
( c:\cygwin64\bin\c++.exe ) we only had to add the folder
c:\cygwin64\bin to our Microsoft Windows PATH.


C/C++ Community
===============
Ideas and suggestions for improvement are always welcome!

Group: https://www.facebook.com/GnuCpp9000/

Friends: https://www.facebook.com/randall.nagy/

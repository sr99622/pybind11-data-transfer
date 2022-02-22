pybind11 data transfer

Requirements:

opencv
python
numpy
cmake
eigen
pybind11 

These libraries need to be installed on your system.  If they are installed properly, cmake will
automagically find them on your machine and configure the project.  If other methods were used to 
install these libraries, you can manually feed the data into cmake using the -D syntax.

The pybind headers require a different approach for configuration.  After the headers have been 
downloaded to your system, use a symbolic link to create an image of the pybind11 directory in
the project folder.  The procedure for doing this on windows is to open an Administrator powershell
and use the command 

New-Item -ItemType SymbolicLink -Path "pybind11" -Target "path-to-pybind11-downloaded-header-directory"

Replace the Link portion with the path to the symbolic link you want to create and the Target with the
location of the directory to be linked

For the convenience of Visual Studio Code use, json configuration files are created by the cmake script.
This behavior can be suppressed if desired by using the -DSUPRESS_JSON flag.

The standard cmake process can be used to build the project from the console:

mkdir build

cd build

cmake ..

cmake --build . --config Release

Add the Release directory to the PYTHONPATH environment variable so python can find the extension

set PYTHONPATH=%PYTHONPATH%Release

To run the test

python ../python/test.py
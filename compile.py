import os

os.system("g++ -o compile encryption.cpp")
os.system("g++ -o maincompile interface.cpp")
os.system("./maincompile")


import os

os.system("g++ -o encryptText encryption.cpp")
os.system("g++ -o un_encryptText unencrypt.cpp")
os.system("g++ -o SecretMachine interface.cpp")
os.system("./SecretMachine")


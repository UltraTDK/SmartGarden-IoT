from gpio import *
from time import *

def inputHandler():
    value = ((analogRead(A0) - 0) * (100 - -100))/(1023-0)) + -100
    customWrite(0,value)

def main():
    add_event_detect(A0,inputHandler)

    while True:
        delay(1000)

if name == "main"
    main()


    from gpio import *
from time import *

def inputHandler():
    value = ((analogRead(A0) - 0) * (100 - -100))/(1023-0)) + -100
    customWrite(0,value)

def main():
    add_event_detect(A0,inputHandler)

    while True:
        delay(1000)

if name == "main"
    main()


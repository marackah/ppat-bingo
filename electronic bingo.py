import tkinter
import serial
from tkinter import messagebox
from tkinter import PhotoImage
from tkinter import *

top = tkinter.Tk()

#top.attributes("-fullscreen", True)

#top.geometry("1700x1000")
top.minsize(width=950, height=750)

frame = Frame(top)


## initializes pyserial
ser = serial.Serial('COM4', 9600)

## holds states of each light; True = on, False = off
state = [False,False,False,False,False,False,False,False]

## test function
def helloCallBack():
   #messagebox.showinfo( "Hello Python", "Hello World")
   print(1)

## toggle function
#  function to toggle each light from on to off
#  n is the number of the light which should be toggled
#  that light should switch states from on to off or off to on by the
#   end of the function
##

##### function to change button state    
def toggle(n, tog=[0]):
    print('#' + str(n) + ' light selected') #prints the light #
    string = '';
    code = [1,3,5,7,'s', 'f', 'h','k', 'a','d','g','j'] #helps convert light #
                                                        #into digit for toggle command
    if isinstance(code[n-1], int)==True:  #top row of 4 buttons
        if state[n-1]:  #if already on
            print('turning off')
            string = str(code[n-1] +1)
            print('encoded string ' + string)
            ser.write(string.encode('utf-8'))   #send via serial to arduino
        else:  #if already off
            print('turning on')
            string = str(code[n-1])
            print('encoded string ' + string)
            ser.write(string.encode('utf-8'))   #send via serial to arduino
    else:   #bottom row of 4 buttons
        if state[n-1]:  #if already on
            print('turning off')
            string = code[n-1]
            print('encoded string' + string)
            ser.write(string.encode('utf-8'))   #send via serial to arduino      
        else:  #if already off
            print('turning on')
            string = code[n+3]
            print('encoded string ' + string)
            ser.write(string.encode('utf-8'))   #send via serial to arduino
    state[n-1] = not state[n-1]  #denote that the state of the light has switched
    print('current state: ' + str(state)) #current set of all light states

#####function for reset button
def reset(button=1):
    #off_state = ['2', '4', '6', '8', 's', 'f', 'h','k']
    #for i in range(len(off_state)):
       string = '2468sfhk' #off_state[i]
       ser.write(string.encode('utf-8'))
       print('Button #' + str(button) + ': off.')
       button = button + 1
       
#####button image files 
#img = PhotoImage(file='IMG_2650.gif')
imgr = PhotoImage(file='red.gif')
imgo = PhotoImage(file='orange.gif')
imgy = PhotoImage(file='yellow.gif')
imgg = PhotoImage(file='green.gif')
imgb = PhotoImage(file='blue.gif')
imgpr = PhotoImage(file='purple.gif')
imgpk = PhotoImage(file='pink.gif')
imgw = PhotoImage(file='white.gif')

######creating and styling the buttons and labels
button1 = tkinter.Button(top, text ="A", command = lambda:toggle(1), image=imgr)#, height=h, width=w)
button2 = tkinter.Button(top, text ="B", command = lambda:toggle(2), image=imgo)#, height=h, width=w)
button3 = tkinter.Button(top, text ="C", command = lambda:toggle(3), image=imgy)#, height=h, width=w)
button4 = tkinter.Button(top, text ="D", command = lambda:toggle(4), image=imgg)#, height=h, width=w)
button5 = tkinter.Button(top, text ="E", command = lambda:toggle(5), image=imgb)#, height=h, width=w)
button6 = tkinter.Button(top, text ="F", command = lambda:toggle(6), image=imgpr)#, height=h, width=w)
button7 = tkinter.Button(top, text ="G", command = lambda:toggle(7), image=imgpk)#, height=h, width=w)
button8 = tkinter.Button(top, text ="H", command = lambda:toggle(8), image=imgw)#, height=h, width=w)
reset = tkinter.Button(top, text ="reset board", font=("Helvetica", 20), command = reset)
bingo = Label(top, text="bingo!", font=("Helvetica", 72))

#####positions for button placement
x1=0
x2=1/4
x3=1/2
x4=3/4
y1=0
y2=1/3
y3=2/3
w=1/4
h=1/3

#####top row button placement
bingo.place(relheight=h, relwidth=.75, rely=y1, relx=x2)
reset.place(relheight=h, relwidth=.25, rely=y1, relx=x1)

#####main rows button placement
button1.place(relheight=h, relwidth=w, rely=y2)
button2.place(relheight=h, relwidth=w, rely=y2, relx=x2)
button3.place(relheight=h, relwidth=w, rely=y2, relx=x3)
button4.place(relheight=h, relwidth=w, rely=y2, relx=x4)
button5.place(relheight=h, relwidth=w, rely=y3)
button6.place(relheight=h, relwidth=w, rely=y3, relx=x2)
button7.place(relheight=h, relwidth=w, rely=y3, relx=x3)
button8.place(relheight=h, relwidth=w, rely=y3, relx=x4)

#add functions (commands) for undo and reset ## reset is done

top.mainloop()

raw_input()

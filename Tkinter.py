import tkinter as tk
root = tk.Tk()
root.geometry("500x500")
label = tk.Label(root, text =  "Hello Peter")
label.pack(pady = 10)
def on_button_click():

button = tk.Button(
    root, 
    text = "Click me",
    command = on_button_click,
)
button.pack()
entry = tk.Entry(root, width = 30)
entry.pack(pady = 10)
root.mainloop()

import tkinter as tk
import subprocess

def on_button_click():
    # Run Zalo app
    zalo_path = "/Applications/Zalo.app/Contents/MacOS/Zalo"
    subprocess.run([zalo_path])

root = tk.Tk()
root.geometry("500x500")

label = tk.Label(root, text="Hello Peter")
label.pack(pady=10)

button = tk.Button(
    root,
    text="Click me",
    command=on_button_click,
)
button.pack()

root.mainloop()
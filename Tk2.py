import tkinter as tk  # Import the tkinter library

# Create the main application window
root = tk.Tk()  # This initializes the main window (called the "root" window)
root.geometry("200x300")  
root.title("Interactive Tkinter Example")  # Set the title of the window

# Define a function to handle button click events
def on_button_click():
    """
    This function is executed when the button is clicked.
    It updates the label text to indicate the button was clicked.
    """
    label.config(text="Button clicked!")  # Update the label's text

# Add a label to the window
label = tk.Label(root, text="Click the button below!")  # Create a label widget with initial text
label.pack(pady=10)  # Add the label to the window and add vertical padding

# Add a button to the window
button = tk.Button(
    root,  # The parent window (root)
    text="Click Me"  # The text displayed on the button
    command=on_button_click, # The function to call when the button is clicked
)
button.pack(pady=10)  # Add the button to the window and add vertical padding

# Add an entry box for user input
entry = tk.Entry(root, width=30)  # Create an entry widget for text input, with a width of 30 characters
entry.pack(pady=10)  # Add the entry box to the window and add vertical padding

# Add another button to show entered text
def on_show_text():
    """
    This function retrieves the text from the entry box
    and updates the label to display the entered text.
    """
    user_text = entry.get()  # Get the text entered in the entry box
    label.config(text=f"You entered: {user_text}")  # Update the label with the entered text

show_text_button = tk.Button(
    root,  # The parent window (root)
    text="Show Text",  # The text displayed on this button
    command=on_show_text  # The function to call when this button is clicked
)
show_text_button.pack(pady=10)  # Add this button to the window and add vertical padding

# Run the tkinter event loop
root.mainloop()  # Start the main loop, which keeps the window open and responsive

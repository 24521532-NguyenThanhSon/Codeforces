# quizz game 
questions  = ["how many dogs", " how many elements in the wolrd", "what colors"]
options = [["A: 1", "B = 2", "C = 3", "D = 4"],
           ["A: 1", "B = 2", "C = 3", "D = 4"],
           ["A: 1", "B = 2", "C = 3", "D = 4"]
        ]
questionnum = 0
for answer in questions:
    print(answer)
    for option in options[questionnum]:
        print(option, end = " ")
    print()
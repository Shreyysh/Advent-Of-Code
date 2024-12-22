with open("../test-cases/inp4.txt", "r") as inpfile:
    cards = inpfile.readlines()
    totalPoints = 0
    
    for card in cards:
        cardVal = 0
        card = card.split(":")
        numbers = card[1].split("|")
        
        winning_numbers = [wnum for wnum in numbers[0].split() if wnum]
        my_numbers = [mnum for mnum in numbers[1].split() if mnum]
        
        for i in range(len(my_numbers)):
            for j in range(len(winning_numbers)):
                if winning_numbers[j] == my_numbers[i]:
                    cardVal = 1 if cardVal == 0 else cardVal*2
        
        totalPoints += cardVal
    
print(f"Total points are: {totalPoints}")
inpfile.close()